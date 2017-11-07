//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Distancia Eucl�dea 

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double punto1_x, punto1_y, punto2_x, punto2_y, distancia, cuadrado_x, cuadrado_y;
	
	cout << "Distancia Eucl�dea entre dos puntos. \nIntroduzca los dos valores del primer punto: ";
	cin >> punto1_x >> punto1_y;
	cout << "Introduzca los dos valores del segundo punto: ";
	cin >> punto2_x >> punto2_y;
	
	cuadrado_x = (punto1_x - punto2_x) * (punto1_x - punto2_x);
	cuadrado_y = (punto1_y - punto2_y) * (punto1_y - punto2_y);
	distancia = sqrt(cuadrado_x + cuadrado_y);
	
	cout << "La distancia Eucl�dea entre los dos puntos es " << distancia;
	
}
