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
    Contacto(string nombre, string apellido, string telefono, string correo) : nombre(nombre), apellido(apellido), telefono(telefono), correo(correo) {
      base_de_datos();
    }

    void actualizar(string nombre = nombre, string apellido = apellido, string telefono = telefono, string correo = correo) {
      nombre = nombre;
      apellido = apellido;
      telefono = telefono;
      correo = correo;
      base_de_datos::actualizar(identificador, this);
    }

    void eliminar() {
      base_de_datos::eliminar(identificador);
    }
    
    void imprimir() {
        printf("\nnombre:%s\napellido:%s\nteléfono:%s\ncorreo:%s\n", nombre, apellido, telefono, correo);
    }
};

namespace contactos {
  Contacto crear(string nombre, string apellido, string telefono, string correo) {
    Contacto nuevoContacto(nombre, apellido, telefono, correo);
    return nuevoContacto;
  }

  void listar() {
    do {

    } while 
  }

}