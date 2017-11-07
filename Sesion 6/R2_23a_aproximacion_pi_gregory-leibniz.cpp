//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Aproximaci�n de PI por Gregory-Leibniz (Versi�n a usando la funci�n pow)

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout.precision(15);
    int tope, incremento;
    double pi, serie, acumulador;
    
	// Entradas
	do{
		cout << "Introduzca el n�mero de series para calcular una aproximaci�n de PI."
        << " Debe ser un valor entre 1 y cien mil: ";
    	cin >> tope;
 	}while (tope <= 0 || tope >= 100000);
	
	// C�mputos
	// El acumulador va almacenando todas las series de cada vuelta
	// Sale del bucle cuando se haya dado vueltas un n�mero "tope" de veces
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
