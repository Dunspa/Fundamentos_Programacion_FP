//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Gaussiana versi�n 1

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double esperanza, desviacion_tipica, valor_gaussiana, valor_abscisa_x, division, potencia_numero_e;
	const double PI = (6 * asin (0.5));	
	
	cout << "C�lculo de la funci�n Gaussiana. \nIntroduzca el par�metro mu (esperanza o media): ";
	cin >> esperanza;
	cout << "Introduzca el par�metro sigma (desviaci�n t�pica): ";
	cin >> desviacion_tipica;
	cout << "Introduzca el valor de la abscisa x: ";
	cin >> valor_abscisa_x;
	
	division = 1 / (desviacion_tipica * sqrt(2 * PI));
	potencia_numero_e = exp(-0.5 * pow((valor_abscisa_x - esperanza) / desviacion_tipica , 2));
	valor_gaussiana = division * potencia_numero_e;
	
	cout << "El valor que toma la funci�n en x es " << valor_gaussiana;
	
}
