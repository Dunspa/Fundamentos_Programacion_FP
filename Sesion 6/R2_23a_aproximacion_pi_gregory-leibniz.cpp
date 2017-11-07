//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Aproximación de PI por Gregory-Leibniz (Versión a usando la función pow)

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout.precision(15);
    int tope, incremento;
    double pi, serie, acumulador;
    
	// Entradas
	do{
		cout << "Introduzca el número de series para calcular una aproximación de PI."
        << " Debe ser un valor entre 1 y cien mil: ";
    	cin >> tope;
 	}while (tope <= 0 || tope >= 100000);
	
	// Cómputos
	// El acumulador va almacenando todas las series de cada vuelta
	// Sale del bucle cuando se haya dado vueltas un número "tope" de veces
    incremento = 0.0;
    acumulador = 0.0;
    while(incremento <= tope){
        serie = pow(-1.0 , incremento) / (2.0 * incremento + 1.0);
        acumulador = serie + acumulador;
        incremento++;
    }

    pi = 4.0 * acumulador;
	
	// Salidas
    cout << "El valor aproximado de PI es: " << pi;

}
