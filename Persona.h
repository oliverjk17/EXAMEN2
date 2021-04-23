#include <iostream>
using namespace std;
class Persona {
protected: string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, puesto, fecha_inicio_labores, fechaingreso;
		 int telefono = 0;
		 // constructor
protected:
	Persona() {
	}
	Persona(string nom, string ape, string dir, int tel, string dpi, string gen, string fechan, string pues, string fechainilab, string fechaingre) {
		{
			nombres = nom;
			apellidos = ape;
			direccion = dir;
			telefono = tel;
			DPI = dpi;
			genero = gen;
			fecha_nacimiento = fechan;
			puesto = pues;
			fecha_inicio_labores = fechainilab;
			fechaingreso = fechaingre;
		}
	}
};