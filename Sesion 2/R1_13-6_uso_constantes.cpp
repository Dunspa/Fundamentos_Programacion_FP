//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Uso de constantes: Reescribir pr�ctica 6 Tarifa a�rea con descuento

#include <iostream>
using namespace std;

int main (){
	double precio;						
	double descuento1;					
	double descuento2;
	const double VALOR_DESCUENTO1 = 0.96, VALOR_DESCUENTO2 = 0.98;					
	
	cout << "Introduzca el precio de su billete de avi�n para que se le apliquen los dos tipos de descuento: ";
	cin >> precio;
	
	descuento1 = (precio * VALOR_DESCUENTO1);
	descuento2 = (precio * VALOR_DESCUENTO2);
	
	cout << "Con un descuento del 4% el precio de su billete es de " << descuento1 << " euros, y con el descuento del 2% el precio es de " << descuento2 << " euros. ";
	
}
