//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Aproximación de PI por Madhava sin usar pow ni if

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	cout.precision(15);
	int tope, incremento, incremento_potencia1, incremento_potencia2;
	double serie, acumulador, potencia1, potencia2, exponente, pi;
	
	do{
		cout << "Introduzca el número de series para calcular una aproximación de PI."
        	 << " Debe ser un valor entre 1 y cien mil: ";
    	cin >> tope;
 	}while (tope <= 0 || tope > 100000);
 	
 	acumulador = 0;
	incremento = 0;
	incremento_potencia1 = 0;
	incremento_potencia2 = 0;
	potencia1 = 1;
	potencia2 = -1;
	exponente = 1;
 	while (incremento < tope){
 		do{	
			potencia2 *= -1;
			incremento_potencia2++;
		}while (incremento_potencia2 < incremento);
		
		while (incremento_potencia1 < (2 * incremento + 1)){
 			potencia1 *= (1 / sqrt(3));
			incremento_potencia1++;
		}
		
 		serie = (potencia1 * potencia2) / (2 * incremento + 1);
 		
 		acumulador = serie + acumulador;	
 		exponente = 2 * incremento + 1;
 		incremento++;
	}
	
	pi = 6.0 * acumulador;
	
	cout << "El valor aproximado de PI según Wallis es: " << pi;
}
