//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Elimina caracteres finales

#include <iostream>
#include <string>
using namespace std;

string EliminaUltimos (string cadena, char a_borrar){
	int i;
	
	i = cadena.size () - 1;
	while (cadena[i] == a_borrar){
		cadena.pop_back ();
		i--;
	}
	
	return cadena;
}

int main (){
	string cadena;
	char caracter, a_borrar;
	const char TERMINADOR = '#';

	cout << "Introduzca la cadena de caracteres: ";
	caracter = cin.get ();
	
	while (caracter != TERMINADOR){
		cadena.push_back (caracter);
		caracter = cin.get ();
	}
	
	cout << "Introduzca el caracter que quiere borrar: ";
	cin >> a_borrar;
	
	cadena = EliminaUltimos (cadena, a_borrar);
	
	cout << "La cadena resultante: " << cadena;
}
