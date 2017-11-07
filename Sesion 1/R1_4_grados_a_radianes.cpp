//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Conversión de grados a radianes

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double grados1, grados2, radianes1, radianes2;
	const double PI = (6 * asin (0.5));
	
	cout << "Conversor de grados a radianes introduciendo dos datos distintos. Introduzca el primer dato: ";
	cin >> grados1;
	cout << "Introduzca el segundo: ";
	cin >> grados2;
	
	radianes1 = ((grados1*PI)/180);
	radianes2 = ((grados2*PI)/180);
	
	cout << "Las cantidades introducidas convertidas en radianes valen: " << radianes1 << " y " << radianes2;	
	
}

