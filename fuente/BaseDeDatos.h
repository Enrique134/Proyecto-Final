// Libreria Base De Datos
//@autor Enrique Sosa
/*_____________________________
 | 'una base de datos simple y | 
 |  deficiente :)'             |
 |-----------------------------|
 | /!\ no es adaptable a otros |
 | algoritmos ya que su        |
 | implementacion es manual    |
 |_____________________________|
*/

#include <map>

#include <stdio.h>
#include <string.h>

using namespace std;

class Contacto;

static class Indice {
  string identificador;
  int posicion[2];
};

Indice indiceNulo;

static map<string, string> BaseDeDatos = {
  {"DatosDeContactos", "datos/datos_de_contactos"},
  {"indices", "datos/indices"}
};

static void guardarIndice(string identificador, int posicion[2]) {
  FILE* indices = fopen(BaseDeDatos.at("Indices", "a"));

  Indice indice;
  indice.identificador = identificador;
  indice.posicion[0] = posicion[0];
  indice.posicion[1] = posicion[1];

  fwrite(indice, sizeof(Indice), 1, indices);
  fclose(indices);
}

static void quitarIndice(string identificador) {
  FILE* indices = fopen(BaseDeDatos.at("Indices", "r+"));
  Indice ultimoIndice;

  fseek(indices, sizeof(indices) - sizeof(Indice), SEEK_SET);
  fread(&ultimoIndice, sizeof(Indice), 1, indices);
  fwrite(NULL, sizeof(Indice), 1, indices);
  rewind(indices);

  Indice indice;
  int posicion = 0; 

  while (posicion < sizeof(indices)) {
    fread(&indice, sizeof(Indice), 1, indices);

    if(strcmp(indice.identificador, identificador) == 0) {
      fwrite(ultimoIndice, sizeof(Indice), 1, indices);
      fclose(indices);
      return;
    }

    posicion += sizeof(Indice);
    fseek(indices, posicion, SEEK_SET);
  }
}

static actualizarIndice(string identificador, Indice nuevoIndice) {
  FILE* indices = fopen(BaseDeDatos.at("Indices", "r+"));

  Indice indice;
  int posicion = 0; 

  while (posicion < sizeof(indices)) {
    fread(&indice, sizeof(Indice), 1, indices);

    if(strcmp(indice.identificador, identificador) == 0) {
      fwrite(nuevoIndice, sizeof(Indice), 1, indices);
      fclose(indices);
      return;
    }

    posicion += sizeof(Indice);
    fseek(indices, posicion, SEEK_SET);
  }
}

static Indice obtenerIndice(string identificador) {
  FILE* indices = fopen(BaseDeDatos.at("Indices", "r"));

  static Indice indice;
  int posicion = 0; 

  while (posicion < sizeof(indices)) {
    fread(&indice, sizeof(Indice), 1, indices);

    if(strcmp(indice.identificador, identificador) == 0) {
      fclose(indices);
      return indice;
    }

    posicion += sizeof(Indice);
    fseek(indices, posicion, SEEK_SET);
  }
}

namespace base_de_datos 
{
  void guardar(string identificador, Contacto contacto) {
    int posicion[2] = {sizeof(archivo), sizeof(archivo) + sizeof(Contacto)}
    guardarindice(identificador, posicion);
    
    FILE* archivo = fopen(BaseDeDatos.at("DatosDeContactos"), "a");
    fwrite(contacto, sizeof(Contacto), 1, archivo);

    fclose(archivo);
  }

  void eliminar(string identificador) {
    FILE* archivo = fopen(BaseDeDatos.at("DatosDeContactos"), "r+");
    Indice indice = obtenerIndice(identificador);
    Contacto ultimoContacto;

    fseek(archivo, sizeof(archivo) - sizeof(Contacto), SEEK_SET);
    fread(&ultimoContacto, sizeof(Contacto), 1, archivo);
    fwrite(NULL, sizeof(Contacto), 1, archivo);
    fseek(archivo, indice.posicion[0], SEEK_SET);
    fwrite(ultimoContacto, sizeof(Contacto), 1, archivo);
    quitarIndice(identificador);

    fclose(archivo);
  }

  void actualizar(string identificador, Contacto datosNuevos) {
    FILE* archivo = fopen(BaseDeDatos.at("DatosDeContactos"), "r+");
    Indice indice = obtenerIndice(identificador);

    fseek(archivo, indice.posicion[0], SEEK_SET);
    fwrite(datosNuevos, sizeof(Contacto), 1, archivo);

    fclose(archivo);
  }

  Contacto obtener(string identificador) {
    FILE* archivo = fopen(BaseDeDatos.at("DatosDeContactos"), "r");
    Indice indice = obtenerIndice(identificador);

    static Contacto contacto;
    fseek(archivo, indice.posicion[0], SEEK_SET);
    fread(&contacto, sizeof(Contacto), 1, archivo);

    fclose(archivo);
    return contacto;
  }

  Contacto obtenerPorIndice(int indice) {
    FILE* archivo = fopen(BaseDeDatos.at("DatosDeContactos"), "r");
    Contacto contacto;

    int _indice = indice * sizeof(Contacto);

    if(_indice >= sizeof(archivo)) {
      _indice -= sizeof(archivo);
    }

    fseek(archivo, _indice, SEEK_SET);
    fread(&contacto, sizeof(Contacto), 1, archivo);

    fclose(archivo);
    return contacto;
  }

  bool verificarExistencia(string identificador) {
    Indice indice = obtenerIndice(identificador);

    if(indice.posicion[0] != indice.posicion[1]) {
      return true;
    }

    return false;
  }
}




