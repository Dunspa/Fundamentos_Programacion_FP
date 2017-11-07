//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Uso de constantes: Reescribir pr�ctica 3 c�lculo de pi a partir del arco-seno

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	const double PI = (6 * asin (0.5));	
	
	cout << "El valor de pi se puede calcular a partir del arcoseno de 0.5 multiplicado por 6. Su valor es: " << PI;
}
