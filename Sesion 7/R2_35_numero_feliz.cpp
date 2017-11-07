//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Número feliz

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	bool no_es_numero_feliz;
	int i, numero, grado1, grado2, digito, acumulador;
	
	cout << "Introduzca el número que quiere comprobar si es feliz: ";
	cin >> numero;
	cout << "¿Para qué grado?: ";
	cin >> grado1;
	
	no_es_numero_feliz = true;
	acumulador = 0;
	
	for (i = 1 ; i <= grado1 && no_es_numero_feliz ; i++){
		while (numero> 0){
			digito = numero % 10;
			numero = numero / 10;
			acumulador = acumulador + pow (digito , 2);
		}
	
		if (acumulador == 1 || i == grado1){
			grado2++;
			no_es_numero_feliz = false;
		}
		else{
			numero = acumulador;
			acumulador = 0;
			grado2++;
		}
	}
	
	if (acumulador == 1){
		cout << "Es feliz para cualquier grado >= " << grado2;
	}
	else{
		cout << "No es feliz para cualquier grado <= " << grado2;
	}

}
