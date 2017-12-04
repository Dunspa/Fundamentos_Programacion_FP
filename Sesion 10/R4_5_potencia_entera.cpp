//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Potencia entera

#include <iostream>
#include <cmath>
using namespace std;

double PotenciaEntera (double base, int exponente){
	double potencia;
	int exponente_positivo;
	
	if (base == 0 && exponente == 0)
		potencia = NAN;
	else{
		exponente_positivo = abs(exponente);
		potencia = 1;
		
		for (int i = 0 ; i < exponente ; i++){
			potencia = base * potencia;
		}
	}
	
	if (exponente < 0)
		potencia = 1 / potencia;
	
	return potencia;
}

int main (){
	double base_potencia, resultado;
	int exponente_potencia;
	
	cout << "Introduzca la base de la potencia: ";
	cin >> base_potencia;
	cout << "Introduzca el exponente de la potencia: ";
	cin >> exponente_potencia;
	
	resultado = PotenciaEntera (base_potencia, exponente_potencia);
	
	cout << "El valor de la potencia es: " << resultado;
}
