#include <mysql.h>
#include <iostream>
#include<string.h>
#include<string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;
class Empleados : Persona {
private: string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, puesto, fecha_inicio_labores, fechaingreso;
	   int telefono = 0;
	   // constructor
public:
	Empleados() {
	}
	Empleados(string nom, string ape, string dir, int tel, string dpi, string gen, string fechan, string pues, string fechainilab, string fechaingre) : Persona (nom, ape, dir, tel, dpi, gen, fechan, pues,fechainilab,fechaingre) {
		}
	// METODOS
	//set (modificar)
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setDPI(string dpi) { DPI = dpi; }
	void setgenero(string gen) { genero = gen; }
	void setFecha_Nacimiento(int fechan) { fecha_nacimiento = fechan; }
	void setPuesto(string pues) { puesto = pues; }
	void setFecha_inicio_labores(int fechainilab) { fecha_inicio_labores = fechainilab; }
	void setFechaingreso(int fechaingre) { fechaingreso = fechaingre; }

	//get (mostrar)
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getDPI() { return DPI; }
	string setgenero() { return genero; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	string getPuesto() { return puesto; }
	string getFecha_inicio_labores() { return fecha_inicio_labores; }
	string getFechaingreso() { return fechaingreso; }

	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
			string fechaingreso = "now()";
			string  nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, puesto, fecha_inicio_labores;
			int telefono;
			cout << "Ingrese Nombres:";
			getline(cin, nombres);
			cout << "Ingrese Apellidos:";
			getline(cin, apellidos);
			cout << "Ingrese Direccion:";
			getline(cin, direccion);
			cout << "Ingrese Telefono:";
			cin >> telefono;
			cin.ignore();
			cout << "Ingrese DPI:";
			getline(cin, DPI);
			cout << "Ingrese genero:";
			getline(cin, genero);
			cout << "Fecha Nacimiento:";
			cin >> fecha_nacimiento;
			cin.ignore();
			cout << "Ingrese puesto:";
			getline(cin, puesto);
			cout << "Fecha inicio labores:";
			cin >> fecha_inicio_labores;
			cin.ignore();
			cout << "Fecha ingreso:";
			cin >> fechaingreso;
			cin.ignore();
			string  insertar = "INSERT INTO empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento,puesto, fecha_inicio_labores, fechaingreso) VALUES ('" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + DPI + "','" + genero + "','" + fecha_nacimiento + "','" + puesto + "','" + fecha_inicio_labores + "','" + fechaingreso + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {

			cout << "------------ Datos de Clientes ------------" << endl;
			string consulta = "select * from empleados";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << "," << fila[9] << "," << fila[10] << endl;
				}

			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idempleado, nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, puesto, fecha_inicio_labores, fechaingreso;
			char s;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idempleado;
			string consulta = "select * from empleados where idempleado=" + idempleado + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {

					cout << "Id empleado: " << fila[0] << endl;
					cout << ("nombres: ") << fila[1] << endl;
					cout << ("apellidos: ") << fila[2] << endl;
					cout << ("direccion: ") << fila[3] << endl;
					cout << ("telefono: ") << fila[4] << endl;
					cout << ("DPI: ") << fila[5] << endl;
					cout << ("genero: ") << fila[6] << endl;
					cout << ("fecha nacimiento: ") << fila[7] << endl;
					cout << ("puesto: ") << fila[8] << endl;
					cout << ("fecha inicio labores: ") << fila[9] << endl;
					cout << ("fecha ingreso: ") << fila[10] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\nnuevo nombres del empleado: ";
						cin >> nombres;
						cout << "\nnuevo apellidos del empleado: ";
						cin >> apellidos;
						cout << "\nnueva direccion del empleado: ";
						cin >> direccion;
						cout << "\nnuevo telefono del empleado: ";
						cin >> telefono;
						cout << "\nnuevo DPI del empleado: ";
						cin >> DPI;
						cout << "\nnuevo genero del empleado: ";
						cin >> genero;
						cout << "\nnueva fecha nacimiento del empleado: ";
						cin >> fecha_nacimiento;
						cout << "\nnuevo puesto del empleado: ";
						cin >> puesto;
						cout << "\nnueva fecha inicio labores del empleado: ";
						cin >> fecha_inicio_labores;
						cout << "\nnueva fecha ingreso del empleado: ";
						cin >> fechaingreso;
						string modificar = "update empleados set nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento,puesto, fecha_inicio_labores, fechaingreso = '" + nombres + "','" + apellidos + "','" + direccion + "'," + telefono + ",'" + DPI + "','" + genero + "','" + fecha_nacimiento + "','" + puesto + "','" + fecha_inicio_labores + "','" + fechaingreso + "'   where idempleado =" + idempleado + "";
						const char* m = modificar.c_str();
						q_estado = mysql_query(cn.getConectar(), i);
					}
					else {
						cout << ("Modificacion exitosa") << endl;
					}
				}
			}
			else {
				cout << "Error al modificar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}

	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idempelado;
			cout << "------------------------------------------------" << endl;
			cout << "Ingrese el id del registro que desea eliminar\n";
			cin >> idempelado;

			string eliminar = "delete from empleados where idempleado = (" + idempelado + ")";
			const char* i = eliminar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al eliminar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};