#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

//estructura para control de libros
struct libro{
	char nombre[30];
	char autor[30];
	int edicion;
}libros;

///funciones
void iLibro(); //funcion para registrar los libros
void sLibro(); //funcion para ver los registros
void uLibro(); //funcion actualizar los datos 
void dLibro(); //funcion para eliminar los libros

int main(){
	
	cout<<"\n\n\n\t\tBienvenidos";
	cout<<"\n\n\n\t\tENTER para ingresar ";
	getch();
	system("cls");
	
	int op; //para almacenar la opcion del usuario
	
	///estructura del menu
	do{
	
		cout<<"\n\n\t\tBiblioteca San Juan";
		cout<<"\n\n\t1. Registrar Libros";
		cout<<"\n\n\t2. Registro de Libros";
		cout<<"\n\n\t3. Actualizar Datos";
		cout<<"\n\n\t4. Eliminar Libro";
		cout<<"\n\n\t5. Salir";
		cout<<"\n\n\tElija una opcion: ";
		cin>>op;
		///funcionalidad del menu
		switch(op){
			case 1:{
				iLibro(); //llamada a la funcion
				getch();
				system("cls");
				break;
			}
			case 2:{
				sLibro(); //llamando a la funcion 
				getch();
				system("cls");
				break;
			}
			case 3:{
				uLibro();
				getch();
				system("cls");
				break;
			}
			case 4:{
				dLibro();
				getch();
				system("cls");
				break;
				
			}
		}
	}while(op != 5);
	return 0;
}


////funcionalidad de la funcion Registro de libros
void iLibro(){
	char s; //variable para finalizar el ingreso de los libros
	FILE *fp; ///variable que solo maneja archivos
	do{
		fp = fopen("Biblioteca.txt","a+b");
		system("cls");
		cout<<"\n\n\n\t\tRegistrar Libro\n";
		cout<<"\n\tNombre del Libro: ";
		cin.ignore();
		cin.getline(libros.nombre, sizeof(libros.nombre));
		cout<<"\n\tNombre del Autor: ";
		cin.getline(libros.autor, sizeof(libros.autor));
		cout<<"\n\tAño de Edicion: ";
		cin>>libros.edicion;
		fwrite(&libros, sizeof(libros),1,fp);
		fclose(fp);
		
		cout<<"\n\n\n\t\tIngrese un 1 para registrar otro libro, 0 para salir ";
		cin>>s;
				
		
	}while(s != '0');
	
}

//funcion para imprimir los registros
void sLibro() {
    FILE *fp;
    fp = fopen("Biblioteca.txt", "r+b");
    system("cls");
    cout << "\n\n\n\t\tLibros Registrados\n";

    // Leer un registro del archivo
    while (fread(&libros, sizeof(libros), 1, fp) == 1) {
        cout << "\nNombre del libro: " << libros.nombre;
        cout << "\nNombre del autor: " << libros.autor;
        cout << "\nAño de Edicion: " << libros.edicion;
        cout << "\n\n";
    }
    fclose(fp);
    cout << "Presione cualquier tecla para salir_ ";
}
	
////funcion para actualizar los datos del libro
void uLibro(){
	char buscarnombre[30];
	bool encontrado = false;
	FILE *fp;
	FILE *tempFile;
	
	system("cls");
	cout<<"\n\n\n\t\tActualiar Datos de un Libro\n";
	cout<<"\n\tIngrese el nombre del libro a actualizar: ";
	cin.ignore();
	cin.getline(buscarnombre, sizeof(buscarnombre));
	
	fp = fopen("Biblioteca.txt","r+b");
	tempFile = fopen("tempBiblioteca.txt","w+b");
	
	while(fread(&libros, sizeof(libros),1,fp)==1){
		if(strcmp(libros.nombre,buscarnombre)==0){
			encontrado = true;
			cout<<"\n\tNuevo nombre: ";
			cin.getline(libros.nombre, sizeof(libros.nombre));
			cout<<"\n\tNuevo Autor: ";
			cin.getline(libros.autor, sizeof(libros.autor));
			cout<<"\n\tAño de Edicion: ";
			cin>>libros.edicion;
		}
		fwrite(&libros, sizeof(libros),1, tempFile);	
	}
	fclose(fp);
	fclose(tempFile);
	
	if(encontrado == true){
		remove("Biblioteca.txt");
		rename("tempBiblioteca.txt","Biblioteca.txt");
		cout<<"\n\tDatos fueron actualizados...";
	}else{
		cout<<"\n\tDatos no fueron actualizados...";
	}
}


//funcion para eliminar ante comentarios
void dLibro(){
    char buscarnombre[30];
    bool encontrado = false;
    FILE *fp;
    FILE *tempFile;
    
    system("cls");
    cout<<"\n\n\n\t\tEliminar un libro\n";
    cout<<"\n\tIngrese el nombre del libro a eliminar: ";
    cin.ignore();
    cin.getline(buscarnombre,sizeof(buscarnombre));
    
    fp = fopen("Biblioteca.txt","r+b");
    tempFile = fopen("tempBiblioteca.txt","w+b");
    
    while (fread(&libros,sizeof(libros),1,fp)==1) {
        if(strcmp(libros.nombre,buscarnombre)==0) {
            encontrado=true;
            cout<<"\n\tLibro Eliminado";
        } else {
            fwrite(&libros,sizeof(libros),1,tempFile);
        }
    }
    
    fclose(fp);
    fclose(tempFile);
    
    if(encontrado==true) {
        remove("Biblioteca.txt");
        rename("tempBiblioteca.txt", "Biblioteca.txt");
        cout<<"\n\tDatos fueron eliminados....";
    }else {
        cout<<"\n\tDatos no fueron eliminados :o ....";
    }
}
