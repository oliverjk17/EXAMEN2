#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
using namespace std;
class Puesto : Persona {
	// METODOS
	//set (modificar)
	void setPuesto(string pue) { puesto = pue; }
	//get (mostrar)
	string getPuesto() { return puesto; }
	// metodo
void crear_Puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		if (cn.getConectar()) {
			string puesto;
			cout << "Ingrese Puesto:";
			cin >> puesto;
			string insertar = "insert into puestos(puesto) values('" + puesto + "')";
			const char* i = insertar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer_Puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			cout << "------------ Datos de Puestos ------------" << endl;
			string consulta = "select * from puestos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << endl;
				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void modificar_Puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idpuesto, puesto;
			char s;
			cout << ("------------------------- Modificar Datos ---------------------------") << endl;
			cout << "Ingrese el id del registro que desea modificar: ";
			cin >> idpuesto;
			string consulta = "select * from puestos where idpuesto=" + idpuesto + "";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {

				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << "Id puesto: " << fila[0] << endl;
					cout << ("puesto: ") << fila[1] << endl;
					cout << ("Desea modificarlo [s/n]: ");
					cin >> s;
					if ((s == 's') || (s == 'S')) {
						cout << "\ningrese el nuevo nombre del puesto: ";
						cin >> puesto;
						string modificar = "update puestos set puesto = '" + puesto + "' where idpuesto =" + idpuesto + "";
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

	void eliminar_Puesto() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getConectar()) {
			string idpuesto;
			cout << "Ingrese idpuesto:";
			cin >> idpuesto;
			string eliminar = "delete from puestos where idpuesto=(" + idpuesto + ")";
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
