//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Cuadrado

#include <iostream>
using namespace std;

int main (){
	int i, j, valor_inicial, numero_filas;
	
	cout << "Introduzca el valor inicial: ";
	cin >> valor_inicial;
	cout << "Introduzca el n�mero de filas: ";
	cin >> numero_filas;
	
	for (i = valor_inicial ; i <= numero_filas ; i++){
		cout << "\n";
		for(j = i ; j < numero_filas + i ; j++)
			cout << " " << j;
	}
}
