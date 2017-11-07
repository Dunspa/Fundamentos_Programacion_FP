//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Coordenadas geográficas

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double grados_lon1, grados_lat1, grados_lon2, grados_lat2, radianes_lat1, radianes_lat2, radianes_lon1, radianes_lon2, potencia_latitud, potencia_longitud, valor_de_a;
	const double PI = (6 * asin (0.5)), GRADOS_A_RADIANES = PI/180;
	
	cout << "Coordenadas geográficas. Introduzca los valores de latitud y longitud del punto 1 en grados: ";
	cin >> grados_lat1 >> grados_lon1;
	cout << "Introduzca los valores de latitud y longitud del punto 2 en grados: ";
	cin >> grados_lat2 >> grados_lon2;
	
	radianes_lat1 = grados_lat1 * GRADOS_A_RADIANES;
	radianes_lat2 = grados_lat2 * GRADOS_A_RADIANES;
	radianes_lon1 = grados_lon1 * GRADOS_A_RADIANES;
	radianes_lon2 = grados_lon2 * GRADOS_A_RADIANES;
	
	potencia_longitud = pow(sin((radianes_lat2 - radianes_lat1) * 0.5) , 2.0);
	potencia_latitud = pow(sin((radianes_lon2 - radianes_lon1) * 0.5) , 2.0);
	
	valor_de_a = potencia_longitud + cos(radianes_lat1) * cos (radianes_lat2) * potencia_latitud;
	
	cout << "El valor de la variable a es: " << valor_de_a;
	
}
