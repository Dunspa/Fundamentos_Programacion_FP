//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Mismo signo -multiplicando- 

#include <iostream>
using namespace std;

int main (){
	int entero1, entero2;
	
	cout << "Ver si dos n�meros tienen el mismo signo. \nIntroduzca un primer n�mero positivo o negativo: ";
	cin >> entero1;
	cout << "Introduzca un segundo n�mero positivo o negativo: ";
	cin >> entero2;
	
	if ((entero1 * entero2) > 0)
		cout << "Los dos n�meros tienen el mismo signo";
	else
		cout << "Los dos n�meros no tienen el mismo signo";
		
}
