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
      base_de_datos::guardar(correo, this);
    }

    void actualizar(string nombre = nombre, string apellido = apellido, string telefono = telefono, string correo = correo) {
      nombre = nombre;
      apellido = apellido;
      telefono = telefono;
      correo = correo;
      base_de_datos::actualizar(identificador, this);
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

  void eliminar(Contacto contacto) {
    base_de_datos::eliminar(contacto.identificador);
  }

  void listar() {
    Contacto primerContacto = base_de_datos::siguiente(0);
    contacto contacto, int indice;
    while(strcmp(primerContacto.identificador, contacto.identificador) != 0) {
      indice++;
      contacto = base_de_datos::siguiente(indice);
      contacto.imprimir();
    }
  }
}