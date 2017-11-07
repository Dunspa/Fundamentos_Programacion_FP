//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Interés bancario versión 1

#include <iostream>
using namespace std;

int main (){
	double capital, interes, total;
	
	cout << "Introduzca el valor del capital depositado durante un año a plazo fijo, en euros: ";
	cin >> capital;
	cout << "Ahora introduzca el valor del interés que se le aplicará: ";
	cin >> interes;									
	
	total = capital + ((capital*interes)/100);
	
	cout << "Al cabo de un año, aplicado el interés, se tendrán " << total << " euros.";
	
	/* Ventajas de usar la variable capital en vez de total: Te ahorras
	un espacio de memoria que ocuparía esa variable. Inconvenientes: la																										
	variable capital no se guarda, el dato se sobreescribirá */
	
}
