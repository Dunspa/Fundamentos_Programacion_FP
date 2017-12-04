//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Número narcisista

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	int i, numero, copia_numero, digito, numdigitos, acumulador;
	
	do{
		cin >> numero;
	}while (numero < 0);
	
	acumulador = 0;
	numdigitos = 0;
	copia_numero = numero;
	
	while (copia_numero > 0){
		copia_numero = copia_numero / 10;
		numdigitos++;
	}
	
	copia_numero = numero;
	
	for (i = 0 ; i < numdigitos ; i++){
		digito = copia_numero % 10;
		copia_numero = copia_numero / 10;
		acumulador = acumulador + pow (digito , numdigitos);
	}
	
	if (acumulador == numero){
		cout << "Es un número narcisista";
	}
	else{
		cout << "No es un número narcisista";
	}
	
}
