//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Pasar de mayúscula a minúscula 

#include <iostream>
using namespace std;

int main (){
	char caracter_mayuscula, caracter_minuscula;
	
	cout << "Pasar de mayúscula a minúscula. \nIntroduzca una letra mayúscula: ";
	cin >> caracter_mayuscula;
	
	caracter_minuscula = caracter_mayuscula + 32;
	
	cout << "La letra " << caracter_mayuscula << " en minúscula es " << caracter_minuscula;
	
}
