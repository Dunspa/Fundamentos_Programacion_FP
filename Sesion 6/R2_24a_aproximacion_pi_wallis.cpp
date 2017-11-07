//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Aproximación de PI por Wallis versión a

#include <iostream>
using namespace std;

int main (){
	cout.precision(15);
	int tope, incremento;
	double serie, acumulador, numerador, denominador, pi; 
	
	do{
		cout << "Introduzca el número de series para calcular una aproximación de PI."
        	 << " Debe ser un valor entre 1 y cien mil: ";
    	cin >> tope;
 	}while (tope <= 0 || tope > 100000);
 	
 	serie = 1.0;
 	numerador = 0.0;
 	denominador = 1.0;
	incremento = 0.0;
	acumulador = 1.0;
	
	while (incremento < tope){
		if (incremento % 2 == 0){
			numerador = numerador + 2;
			serie = numerador / denominador;
		}
		
		else{
			denominador = denominador + 2;
			serie = numerador / denominador;	
		}
		
		acumulador = serie * acumulador;
 		incremento++;
 	}
 	
 	pi = 2 * acumulador;
 	
 	cout << "El valor aproximado de PI según Wallis es: " << pi;
 	
}
