//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
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
	cout << "C�lculo de la funci�n Gaussiana. \nIntroduzca el par�metro mu (esperanza o media): ";
	cin >> esperanza;
	
	do{
		cout << "Introduzca el par�metro sigma (desviaci�n t�pica): ";
		cin >> desviacion_tipica;
	}while (desviacion_tipica < 0);
	
	cout << "Se aplicar� la funci�n a varios valores de abscisas."
			" Introduzca el m�nimo valor de abscisa que desea: ";	
	cin >> minimo;
	
	do{
		cout << "Introduzca el m�ximo valor de abscisa que desea: ";
		cin >> maximo;
	}while (maximo < minimo);
	
	cout << "Introduzca el valor de los saltos de incremento que se dar�n: ";
	cin >> incremento;

	valor_abscisa_x = minimo;
	do{
		division = 1 / (desviacion_tipica * sqrt(2 * PI));
		potencia_numero_e = exp(-0.5 * pow((valor_abscisa_x - esperanza) / desviacion_tipica , 2));
		valor_gaussiana = division * potencia_numero_e;
		cout << "\nEl valor que toma la funci�n en x es " << valor_gaussiana;
		valor_abscisa_x = minimo + incremento;
		incremento = 2 * incremento;
	}while (valor_abscisa_x <= maximo);
	
}
