#include <iostream>
#include <string>
#include <mysql.h>
#include "ConexionBD.h"
#include "Persona.h"
#include "Empleados.h"
#include "Puesto.h"
using namespace std;
void menu();
void menu2();
void menu_principal();
void crear_Puesto();
void leer_Puesto();
void modificar_Puesto();
void eliminar_Puesto();
void crear();
void leer();
void modificar();
void eliminar();


int main()
{
	menu_principal();
}
void menu_principal() {
	int p;
	do {
		system("cls");
		cout << ("1. Tabla Puesto") << endl;
		cout << ("2. Tabla Empleados") << endl;
		cout << ("3. Salir") << endl;
		cout << ("Ingrese opcion: ");
		cin >> p;
		switch (p) {
		case 1:system("cls"); menu();
			break;
		case 2: system("cls"); menu2();
			break;
		}
	} while (p != 3);
}
void menu() {
	int a;
	do {
		system("cls");
		cout << ("1. Insertar Datos") << endl;
		cout << ("2. Mostrar Datos ") << endl;
		cout << ("3. Eliminar Datos") << endl;
		cout << ("4. Modificar Datos") << endl;
		cout << ("5. Salir") << endl;
		cout << ("Ingrese opcion: ");
		cin >> a;
		switch (a) {
		case 1:system("cls");
			crear_Puesto();
			break;
		case 2:system("cls");
			leer_Puesto();
			break;

		case 3:system("cls");
			eliminar_Puesto();
			break;

		case 4: system("cls");
			modificar_Puesto();
			break;
		}
	} while (a != 5);
}

void menu2() {
	int a;
	do {
		system("cls");
		cout << ("1. Insertar Datos") << endl;
		cout << ("2. Mostrar Datos ") << endl;
		cout << ("3. Eliminar datosa") << endl;
		cout << ("4. Modificar Datos") << endl;
		cout << ("5. Salir") << endl;
		cout << ("Ingrese opcion: ");
		cin >> a;
		switch (a) {
		case 1:system("cls");
			 crear();
			break;
		case 2:system("cls");
			 leer();
			break;

		case 3:system("cls");
			eliminar();
			break;

		case 4: system("cls");
			modificar(); 
			break;
		}
	} while (a != 5);
}

