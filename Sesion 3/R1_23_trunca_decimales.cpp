//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Trunca decimales 

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double numero_real;
	int truncar, real_a_entero;
	
	cout << "Trunca decimales. \nIntroduzca el n�mero real que desea truncar: ";
	cin >> numero_real;
	cout << "�A cuantas cifras decimales quiere truncarlo?: ";
	cin >> truncar;
	
	real_a_entero = numero_real * pow(10 , truncar);
	numero_real = real_a_entero / pow(10 , truncar);
	
	cout << "El n�mero truncado a " << truncar << " cifras decimales es: " << numero_real;
	
}
