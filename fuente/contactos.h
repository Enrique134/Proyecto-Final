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
    Contacto(string& nombre, string& telefono) : nombre(nombre), telefono(telefono) {}

    void eliminar() {
      
    }
    
    void imprimir() {
        cout << "Nombre: " << nombre << ", Teléfono: " << telefono << endl;
    }
};

namespace contactos {
  Contacto* crear() {

  }

  void actualizar(Contacto* contacto) {
    
  }

}