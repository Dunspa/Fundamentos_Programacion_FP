//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Descuento tarifa aérea mezclando tipos 

#include <iostream>
using namespace std;

int main (){
	double precio_billete, precio_final1, precio_final2;
	int descuento1, descuento2;
	
	cout << "Introduzca el precio de su billete en euros: ";
	cin >> precio_billete;
	cout << "Primer descuento que desea aplicar del 1 al 100: ";
	cin >> descuento1;
	cout << "Segundo descuento que desea aplicar del 1 al 100: ";
	cin >> descuento2;
	
	precio_final1 = precio_billete - precio_billete * descuento1/100;
	precio_final2 = precio_billete - precio_billete * descuento2/100;
	
	cout << "Con el primer descuento el precio es " << precio_final1 << " y con el segundo descuento es " << precio_final2;
	
}
