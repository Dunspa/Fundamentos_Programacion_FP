//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Pasar de may�scula a min�scula 

#include <iostream>
using namespace std;

int main (){
	char caracter_mayuscula, caracter_minuscula;
	
	cout << "Pasar de may�scula a min�scula. \nIntroduzca una letra may�scula: ";
	cin >> caracter_mayuscula;
	
	caracter_minuscula = caracter_mayuscula + 32;
	
	cout << "La letra " << caracter_mayuscula << " en min�scula es " << caracter_minuscula;
	
}
