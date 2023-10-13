//Librería Base De Datos
//@Autor Enrique Sosa
/*____________________________
 | 'una base de datos simple' |
 |____________________________|
*/

#include <map>

#include <stdio.h>
#include <string.h>

using namespace std;

class Índice {
  string ubicación;
  string identificador;
  int posición[2];
};

map<string, string> BaseDeDatos = {
  {"DatosDeContactos", "datos/datos_de_contactos"},
  {"índices", "datos/índices"}
};

static void guardarÍndice(string ubicación, string identificador, int posición[2]) {
  FILE* índices = fopen(BaseDeDatos.at("Índices", "a"));

  Índice índice;
  índice.ubicación = ubicación;
  índice.identificador = identificador;
  índice.posición[0] = posición[0];
  índice.posición[1] = posición[1];

  fwrite(índice, sizeof(índice), 1, índices);
  fclose(índices);
}

static Índice* obtenerÍndice(string identificador) {
  FILE* índices = fopen(BaseDeDatos.at("Índices", "r"));

  static Índice índice;
  int posición = 0; 

  while (posición < sizeof(índices)) {
    fread(&índice, sizeof(índice), 1, índices);

    if(strcmp(índice.identificador, identificador) == 0) {
      fclose(índices);
      return índice;
    }

    posición += sizeof(índice);
    fseek(índices, posición, SEEK_SET);
  }
}

static void quitarÍndice(string identificador) {
  FILE* índices = fopen(BaseDeDatos.at("Índices", "r+"));
  Índice últimoÍndice;

  fseek(índices, sizeof(índices) - sizeof(últimoÍndice), SEEK_SET);
  fread(&últimoÍndice, sizeof(últimoÍndice), 1, índices);
  fwrite(NULL, sizeof(últimoÍndice), 1, índices);
  rewind(índices);

  Índice índice;
  int posición = 0; 

  while (posición < sizeof(índices)) {
    fread(&índice, sizeof(índice), 1, índices);

    if(strcmp(índice.identificador, identificador) == 0) {
      fwrite(últimoÍndice, sizeof(últimoÍndice), 1, índices);
      fclose(índices);
      return;
    }

    posición += sizeof(índice);
    fseek(índices, posición, SEEK_SET);
  }
}

static actualizarÍndice(string ídentificador, Índice nuevoÍndice) {
  FILE* índices = fopen(BaseDeDatos.at("Índices", "r+"));

  Índice índice;
  int posición = 0; 

  while (posición < sizeof(índices)) {
    fread(&índice, sizeof(índice), 1, índices);

    if(strcmp(índice.identificador, identificador) == 0) {
      fwrite(nuevoÍndice, sizeof(nuevoÍndice), 1, índices);
      fclose(índices);
      return;
    }

    posición += sizeof(índice);
    fseek(índices, posición, SEEK_SET);
  }
}

namespace base_de_datos 
{
  enum Almacenes {
    DatosDeContactos,
  };

  template T<Clase>
  void guardar(Almacenes almacen, string identificador, Clase datos) {
    string ubicación;

    switch (almacen) 
    {
      case DatosDeContactos:
        ubicación = BaseDeDatos.at("DatosDeContactos");
        break;

      default:
        break;
    }

    int posición[2] = {sizeof(archivo), sizeof(archivo) + sizeof(datos)}
    guardaríndice(ubicación, identificador, posición);

    FILE* archivo = fopen(ubicación, "a");
    fwrite(datos, sizeof(datos), 1, sizeof(archivo));

    fclose(archivo);
  }

  template T<Clase>
  void actualizar(string identificador, Clase datos) {
    FILE* archivo = fopen
    Índice índice = obtenerÍndice(identificador);
  }

  void eliminar(string identificador) {
    
  }

}
