//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Valores de la Gaussiana 

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double esperanza, desviacion_tipica, valor_gaussiana, valor_abscisa_x;
	double division, potencia_numero_e;
	double minimo, maximo, incremento;
	const double PI = (6 * asin (0.5));	
	
	// Entradas con filtro de entrada
	cout << "Cálculo de la función Gaussiana. \nIntroduzca el parámetro mu (esperanza o media): ";
	cin >> esperanza;
	
	do{
		cout << "Introduzca el parámetro sigma (desviación típica): ";
		cin >> desviacion_tipica;
	}while (desviacion_tipica < 0);
	
	cout << "Se aplicará la función a varios valores de abscisas."
			" Introduzca el mínimo valor de abscisa que desea: ";	
	cin >> minimo;
	
	do{
		cout << "Introduzca el máximo valor de abscisa que desea: ";
		cin >> maximo;
	}while (maximo < minimo);
	
	cout << "Introduzca el valor de los saltos de incremento que se darán: ";
	cin >> incremento;

	valor_abscisa_x = minimo;
	do{
		division = 1 / (desviacion_tipica * sqrt(2 * PI));
		potencia_numero_e = exp(-0.5 * pow((valor_abscisa_x - esperanza) / desviacion_tipica , 2));
		valor_gaussiana = division * potencia_numero_e;
		cout << "\nEl valor que toma la función en x es " << valor_gaussiana;
		valor_abscisa_x = minimo + incremento;
		incremento = 2 * incremento;
	}while (valor_abscisa_x <= maximo);
	
}
