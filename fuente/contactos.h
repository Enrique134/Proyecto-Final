//Librería Contactos

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
    string teléfono;
    string correo;
    string identificador;

  public:
    Contacto(string nombre, string apellido, string teléfono, string correo) : nombre(nombre), telefono(teléfono), apellido(apellido) {}

    void actualizar() {
      base_de_datos::actualizar
    }

    void eliminar() {
      
    }
    
    void imprimir() {
        printf("\nnombre:%s\napellido:%s\nteléfono:%s\ncorreo:%s\n", nombre, apellido, teléfono);
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