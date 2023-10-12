//Librería Contactos

#include "BaseDeDatos.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contacto 
{
  private:
    string nombre;
    string telefono;

  public:
    // Constructor
    Contacto(string& nombre, string& telefono) : nombre(nombre), telefono(telefono) {}

    // Función para cambiar el número de teléfono del contacto
    void cambiarTelefono(string& nuevoTelefono) {
        telefono = nuevoTelefono;
    }

    // Función para eliminar el contacto
    void eliminarContacto() {
        // Puedes implementar aquí la lógica para eliminar el contacto de tu lista de contactos.
        // Por ejemplo, si los contactos se almacenan en un vector, puedes usar erase() para eliminarlo.
    }

    // Función para mostrar la información del contacto
    void mostrarContacto() {
        cout << "Nombre: " << nombre << ", Teléfono: " << telefono << endl;
    }
};

namespace contactos {

int main() {
  // Ejemplo de uso de la clase Contacto
  Contacto contacto1("Juan", "123-456-7890");
  Contacto contacto2("Maria", "987-654-3210");

  // Mostrar la información de los contactos
  contacto1.mostrarContacto();
  contacto2.mostrarContacto();

  // Cambiar el número de teléfono de un contacto
  contacto1.cambiarTelefono("555-555-5555");

  // Mostrar la información actualizada del contacto
  contacto1.mostrarContacto();

  // Eliminar un contacto (debe implementarse en la función eliminarContacto)
  contacto2.eliminarContacto();

  return 0;
}

Contacto* crear() {
  Contacto nuevoContacto;
  
  return &nuevoContacto;
}

void actualizar(Contacto* contacto) {

}

}
