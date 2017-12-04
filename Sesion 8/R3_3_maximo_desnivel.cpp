//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Máximo desnivel

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	const int MAXIMO_ALTURAS = 100;
	int numero_alturas, maximo_diferencia_alturas, suma_diferencias_alturas;
	int alturas[MAXIMO_ALTURAS], diferencias_alturas[MAXIMO_ALTURAS];
	
	cout << "Introduzca el número de valores de altura que se van a introducir "
		  << "(entre 1 y " << MAXIMO_ALTURAS << "): ";
		  
	do{
		cin >> numero_alturas;
	}while (numero_alturas <= 0 || numero_alturas > MAXIMO_ALTURAS);

	for (int i = 0 ; i < numero_alturas ; i++){
		cin >> alturas[i];
	}
	
	if (numero_alturas >= 2){
		for (int i = 0 ; i < numero_alturas - 1 ; i++){
			diferencias_alturas[i] = alturas[i + 1] - alturas [i];
		}
	
		maximo_diferencia_alturas = 0;
		suma_diferencias_alturas = 0;
	
		for (int i = 0 ; i < numero_alturas ; i++){
			if (abs(diferencias_alturas[i]) > maximo_diferencia_alturas){
				maximo_diferencia_alturas = abs(diferencias_alturas[i]);
			}
			if (diferencias_alturas[i] > 0){
				suma_diferencias_alturas = suma_diferencias_alturas + diferencias_alturas[i];
			}
		}
		
		cout << "El máximo desnivel es: " << maximo_diferencia_alturas
		     << " y el desnivel acumulado positivo es: " << suma_diferencias_alturas;
		     
	}
	
	else{
		cout << "No hay datos suficientes";
	}
}
