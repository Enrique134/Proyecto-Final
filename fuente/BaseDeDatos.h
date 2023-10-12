//Librería Base De Datos
//@Autor Enrique Sosa

#include <map>
#include <stdio.h>

using namespace std;

// contenedor para las ubicaciónes de los archivos de almacenamiento

BaseDePatiosParaLosDatos

map<string, string> BaseDeDatos = {
  {"DatosDeContactos", "datos/datos_de_contactos"},
  {"índices", "datos/índices"}
};

int buscarÍndice() {
  FILE* índices = fopen(BaseDeDatos.at("Índices", "r"));

  for(int i = 0; i < sizeof(índices); i++) {
    
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
    case Almacenes.DatosDeContactos:
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
