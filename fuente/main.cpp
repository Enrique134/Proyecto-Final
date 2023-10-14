#include "contactos.h"
#include <iostream>
#include<conio.h>

using namespace std;

int main()
{
	int opc;

	cout<<"\n\n\n\t\tBienvenido";
	cout<<"\n\n\n\t\tENTER para ingresar ";
	getch();
	system("cls");
  
  	do{
    	cout<<"\n\n\t\tContactos";
  		cout<<"\n\n\t1. Agregar nuevos contactos";
		cout<<"\n\n\t3. Lista de contactos";
	    cout<<"\n\n\t2. Buscar contactos";
		cout<<"\n\n\t4. Editar contactos";
	  	cout<<"\n\n\t5. Eliminar contactos";
		cout<<"\n\n\t6. Salir";
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
		}

		getch();
		system("cls");
  } while (opc != 6);

  return 0;	
}

void BuscarContactos() {
	int opc;
	cout<<"\n\n\t\tContactos";
  		cout<<"\n\n\t1. Agregar nuevos contactos";
		cout<<"\n\n\t3. Lista de contactos";
	    cout<<"\n\n\t2. Buscar contactos";
		cout<<"\n\n\t4. Editar contactos";
	  	cout<<"\n\n\t5. Eliminar contactos";
		cout<<"\n\n\t6. Salir";
	 	cout<<"\n\n\tElija una opcion: ";
	 	cin>>opc;
}

//funcion para registro de contactos
void RegistrarContactos() {
	
}

//funcion para imprimir los contactos
void ImprimirContactos() {

}


////funcion para actualizar los datos del contacto
void EditarContactos() {
	
}
