// Modulo de Contactos

#include "BaseDeDatos.h"

#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>

using namespace std;

class Contacto 
{
  private:
    string nombre;
    string apellido;
    string telefono;
    string correo;
    string identificador;

  public:
    Contacto(string nombre, string apellido, string telefono, string correo) : nombre(nombre), telefono(telefono), apellido(apellido) {}

    void actualizar(string nombre = nombre, string apellido = apellido, string telefono = telefono) {
      base_de_datos::actualizar(iden);
    }

    void eliminar() {
      
    }
    
    void imprimir() {
        printf("\nnombre:%s\napellido:%s\nteléfono:%s\ncorreo:%s\n", nombre, apellido, telefono);
    }
};

namespace contactos {
  Contacto* crear() {
    Contacto nuevoContacto();

  }

  void actualizar(Contacto* contacto) {
    
  }

  void listar() {

  }

}