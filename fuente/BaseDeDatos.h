//Librería Base De Datos
//@Autor Enrique Sosa

#include <map>

#include <stdio.h>
#include <string.h>

using namespace std;

map<string, string> BaseDeDatos = {
  {"DatosDeContactos", "datos/datos_de_contactos"},
  {"índices", "datos/índices"}
};

class Índice {
  string identificador;
  int posición[2];
};


static void guardarÍndice(string identificador, int índice) {
  FILE* índices = fopen(BaseDeDatos.at("Índices", ""));
  fwrite(índice, sizeof(índice), 1, índices);
}

static void quitarÍndice() {
  
}

static Índice* buscarÍndice(string identificador) {
  FILE* índices = fopen(BaseDeDatos.at("Índices", "r"));

  int posición = 0; static Índice índice;
  while(posición < sizeof(índices)) 
  {
    fread(&índice, sizeof(índice), 1, índices);

    if(strcmp(índice.identificador, identificador) == 0) {
      return índice;
    }

    posición += sizeof(índice);
    fseek(índices, posición, SEEK_SET);
  }
}

namespace base_de_datos {

enum Almacenes = {
  DatosDeContactos,
};

template T<Clase>
void guardar(Almacenes almacen, string identificador, Clase datos) {
  string ubicación; // ubicación para el archivo de almacenamiento de datos

  switch(almacen)
  {
    case DatosDeContactos:
      ubicación = BaseDeDatos.at("DatosDeContactos");
      break;
    
    default:
      break;
  }

  FILE* archivo = fopen(ubicación, "a");
  FILE* índices = fopen(base_de_datos.at("índices"), "a");

  int tamañoDelArchivo = sizeof(archivo);

  fwrite(&identificador, sizeof(string), 1, índices);
  fwrite(tamañoDelArchivo, sizeof(int), 1, índices);
  fwrite(&datos, sizeof(datos), 1, archivo);

  fclose(archivo);
  fclose(índices);
}

void actualizar(string identificador) {
  
}

void eliminar(string identificador) {

}

}
