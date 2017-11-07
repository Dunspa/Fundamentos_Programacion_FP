//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Gaussiana versión 1

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double esperanza, desviacion_tipica, valor_gaussiana, valor_abscisa_x, division, potencia_numero_e;
	const double PI = (6 * asin (0.5));	
	
	cout << "Cálculo de la función Gaussiana. \nIntroduzca el parámetro mu (esperanza o media): ";
	cin >> esperanza;
	cout << "Introduzca el parámetro sigma (desviación típica): ";
	cin >> desviacion_tipica;
	cout << "Introduzca el valor de la abscisa x: ";
	cin >> valor_abscisa_x;
	
	division = 1 / (desviacion_tipica * sqrt(2 * PI));
	potencia_numero_e = exp(-0.5 * pow((valor_abscisa_x - esperanza) / desviacion_tipica , 2));
	valor_gaussiana = division * potencia_numero_e;
	
	cout << "El valor que toma la función en x es " << valor_gaussiana;
	
}
