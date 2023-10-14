#include "BaseDeDatos.h"
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
	  	///funcionalidad del menu
	  	switch(opc){
  			case 1: //llamada a la funcion de agregar contactos
			agregarContactos();
			getch();
			system("cls");
			break;
		 
			case 2: //llamada a la funcion de listar contactos 
			listarContactos();
			getch();
			system("cls");
			break;
		
		  	case 3: //llamada a la funcion de buscar contactos
			buscarContactos();
			getch();
			system("cls");
			break;
			
			case 4: //llamada a la funcion de editar contactos
			editarContactos();
			getch();
			system("cls");
			break;
				
			
			case 5: //llamada a la funcion de eliminar contactos
			eliminarContactos();
			getch();
			system("cls");
			break;
		}
  } while (opc != 6);

  return 0;	
}

//funcion para registro de contactos
void registrarContactos(){
	char s; //variable para finalizar el ingreso de los contactos
	FILE *fp; ///variable que solo maneja archivos
	do{
		fp = fopen("Contactos.txt","a+b");
		system("cls");
		cout<<"\n\n\n\t\tRegistrar Contacto\n";
		cout<<"\n\tNombre del Contacto: ";
		cin.ignore();
		cin.getline();//ingresar funcion para contactos añadir nombres
		cout<<"\n\tCorreo electronico del contacto: ";
		cin.getline();//ingresar funcion para ñadir correos electronicos
		cout<<"\n\tNumero de telefono: ";
		cin>>;//funcion para guardar números de telefono
		fwrite(&//estructura de los contactos//, sizeof(//estructura de los contactos//),1,fp);
		fclose(fp);
		
		cout<<"\n\n\n\t\tIngrese un 1 para registrar otro contacto, 0 para salir ";
		cin>>s;
	}while(s != '0');
	
}

//funcion para imprimir los contactos
void imprimirContactos() {
    FILE *fp;
    fp = fopen("Contactos.txt", "r+b");
    system("cls");
    cout << "\n\n\n\t\tContactos registrados\n";

    // Leer un contacto del archivo
    while (fread(&//estructura de los contactos//, sizeof(//estructura de los contactos//), 1, fp) == 1) {
        cout << "\nNombre del contacto: " << //funcion de nombre de contacto//;
        cout << "\nCorreo electronico: " << //funcion de correo electronico//;
        cout << "\nNumero de telefono: " << //funcion de numero telefonico//;
        cout << "\n\n";
    }
    fclose(fp);
    cout << "Presione cualquier tecla para salir_ ";
}

////funcion para actualizar los datos del contacto
void actualizarDatos(){
	char buscarnombre[30];
	bool encontrado = false;
	FILE *fp;
	FILE *tempFile;
	
	system("cls");
	cout<<"\n\n\n\t\tActualiar Datos de un Contacto\n";
	cout<<"\n\tIngrese el nombre del contacto: ";
	cin.ignore();
	cin.getline(buscarnombre, sizeof(buscarnombre));
	
	fp = fopen("Contactos.txt","r+b");
	tempFile = fopen("tempContactos.txt","w+b");
	
	while(fread(&//estructura de los contactos//, sizeof(//estructura de los contactos//),1,fp)==1){
		if(strcmp(//funcion de nombre de contacto//,buscarnombre)==0){
			encontrado = true;
			cout<<"\n\tNuevo nombre: ";
			cin.getline(//funcion de nombre de contacto//, sizeof(//funcion de nombre de contacto//));
			cout<<"\n\tNuevo Correo Electronico: ";
			cin.getline(//funcion de correo electronico//, sizeof(//funcion de correo electronico//));
			cout<<"\n\tNuevo Numero: ";
			cin>>//funcion de numero de contacto//;
		}
		fwrite(&//estructura de los contactos//, sizeof(//estructura de los contactos//),1, tempFile);	
	}
	fclose(fp);
	fclose(tempFile);
	
	if(encontrado == true){
		remove("Contacto.txt");
		rename("tempContacto.txt","Contacto.txt");
		cout<<"\n\tDatos fueron actualizados...";
	}else{
		cout<<"\n\tDatos no fueron actualizados...";
	}
}

// funcion para agregar contactos
void agregarContactos() {

}

//funcion para eliminar ante comentarios
void eliminarContactos() {
    
}
