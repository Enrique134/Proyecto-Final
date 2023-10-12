//Librería Base De Datos
//@Autor Enrique Sosa

#include <map>
#include <stdio.h>

using namespace std;

// contenedor para las ubicaciónes de los archivos de almacenamiento
map<string, string> BaseDeDatos = {
  {"DatosDeContactos", "datos/datos_de_contactos"}
};

namespace base_de_datos {

enum Almacenes = {
  DatosDeContactos,
};

template T<Clase>
void guardar(Almacenes almacen, Clase datos) {
  string ubicación; // ubicación para el archivo de almacenamiento de datos

  switch(almacen)
  {
    case Almacenes.DatosDeContactos:
      ubicación = BaseDeDatos.at("DatosDeContactos");
      break;

    default:
      break;
  }

  FILE* archivo = fopen(ubicación);
  
}

}
