#include "contactos.h"

#include <iostream>

#include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
	int opc;

	cout<<"\n\n\n\t\tBienvenid@!";
	cout<<"\n\n\t\tENTER para ingresar ";
	getch();
	system("cls");
  
  	do{
    	cout<<"\n\n\t\tContactos\n";
  		cout<<"\n\t1. Agregar nuevos contactos";
		cout<<"\n\t3. Lista de contactos";
	    cout<<"\n\t2. Buscar contactos";
		cout<<"\n\t4. Editar contactos";
	  	cout<<"\n\t5. Eliminar contactos";
		cout<<"\n\t6. Salir";
	 	cout<<"\n\n\tElija una opcion: ";
	 	cin>>opc;
		system("cls");

	  	///funcionalidad del menu
	  	switch(opc){
  			case 1: //llamada a la funcion de agregar contactos
			RegistrarContactos();
			break;
		 
			case 2: //llamada a la funcion de listar contactos 
			ImprimirContactos();
			break;
		
		  	case 3: //llamada a la funcion de buscar contactos
			BuscarContactos();
			break;
			
			case 4: //llamada a la funcion de editar contactos
			EditarContactos();
			break;
				
			
			case 5: //llamada a la funcion de eliminar contactos
			EliminarContactos();
			break;

			default:
			break
		}

		system("cls");
  } while (opc != 6);

  return 0;	
}

//funcion para busqueda de contactos
void BuscarContactos() {
	while(true) {
		printf("Buscar Contactos\n");
		printf("\n¿desea buscar un contacto?\nS para proceder N para cancelar... ");
		char ch = getch();

		if(ch == "n" || ch == "N") {
			return;
		}

		string correo;

		printf("Buscar Contactos\n");
		printf("\ncorreo: ");
		cin>> correo;
		system("cls");
		
		bool existencia = base_de_datos::verificarExistencia(correo);

		if(existencia) {
			Contacto contacto = base_de_datos::obtener(correo);

			printf("Buscar Contactos\n");
			contacto.imprimir();

		} else {
			printf("Buscar Contactos\n");
			printf("\nno pudimos encontrar el correo \"%s\" dentro de tus contactos... ", correo)
		}

		getch();
		system("cls");
	}
}

//funcion para registro de contactos
void RegistrarContactos() {
	while(true) {
		printf("Registrar Contactos\n");
		printf("\n¿desea registrar un nuevo contacto?\nS para proceder N para cancelar... ");
		char ch = getch();

		if(ch == "n" || ch == "N") {
			return;
		}

		string nombre, apellido, telefono, correo;

		printf("Registrar Contactos\n");
		printf("\nNombre: "); cin>> nombre;
		printf("Apellido: "); cin>> apellido;
		printf("Teléfono: "); cin>> telefono;
		printf("Correo: "); cin>> correo;

		contactos::crear(nombre, apellido, telefono, correo);
		system("cls");
	}
}

//funcion para imprimir los contactos
void ImprimirContactos() {
	while(true) {
		printf("Contactos");
		contactos::listar();

		printf("\nX para volver al menú principal\n");

		char ch;
		while(true) {
			ch = getch();

			if(ch == "x" || ch == "X") {
				return;
			}
		}
	}
}


////funcion para actualizar los datos del contacto
void EditarContactos() {
	while(true) {
		printf("Editar Contactos\n");

		printf("\n¿desea editar un contacto?\nS para proceder N para cancelar... ");
		char ch = getch();

		if(ch == "n" || ch == "N") {
			return;
		}

		printf("Editar Contactos\n");
		
		string correo;
		printf("\ncorreo: ");
		cin>> correo;
		system("cls");

		Contacto contacto;
		bool existencia = base_de_datos::verificarExistencia(correo);

		if(existencia) {
			contacto = base_de_datos::obtener(correo);

			printf("Editar Contactos\n");
			contacto.imprimir();

			string nombre, apellido, telefono, correo;
			printf("\nNombre: "); cin>> nombre;
			printf("Apellido: "); cin>> apellido;
			printf("Teléfono: "); cin>> telefono;
			printf("Correo: "); cin>> correo;

			contacto.actualizar(nombre, apellido, telefono, correo);
			printf("el contacto se actualizo... ");
			getch();

		} else {
			printf("Editar Contactos\n");
			printf("\nno pudimos encontrar el correo \"%s\" dentro de tus contactos... ", correo)
		}

		system("cls");
	}
}
