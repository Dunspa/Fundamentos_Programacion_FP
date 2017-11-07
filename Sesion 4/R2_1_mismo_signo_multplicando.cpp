//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Mismo signo -multiplicando- 

#include <iostream>
using namespace std;

int main (){
	int entero1, entero2;
	
	cout << "Ver si dos números tienen el mismo signo. \nIntroduzca un primer número positivo o negativo: ";
	cin >> entero1;
	cout << "Introduzca un segundo número positivo o negativo: ";
	cin >> entero2;
	
	if ((entero1 * entero2) > 0)
		cout << "Los dos números tienen el mismo signo";
	else
		cout << "Los dos números no tienen el mismo signo";
		
}
