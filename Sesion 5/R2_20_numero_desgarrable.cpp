//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Número desgarrable 

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	bool no_es_desgarrable = true;
	int numero, parte_izda, parte_dcha, numdigitos, divisor;

	cout << "Nï¿½mero desgarrable. \nIntroduzca un entero: ";
	cin >> numero;

	numdigitos = 0;
	while (no_es_desgarrable && parte_izda > 0){
		numdigitos++;
		divisor = pow(10 , numdigitos);
		parte_izda = numero / divisor;
		parte_dcha = numero % divisor;
		if ((pow(parte_izda + parte_dcha , 2) == numero)){
			no_es_desgarrable = false;
		}
	}

	if (no_es_desgarrable)
		cout << "El entero no es desgarrable";
	else
		cout << "Es desgarrable";
}
