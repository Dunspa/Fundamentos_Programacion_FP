//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Inter�s bancario versi�n 1

#include <iostream>
using namespace std;

int main (){
	double capital, interes, total;
	
	cout << "Introduzca el valor del capital depositado durante un a�o a plazo fijo, en euros: ";
	cin >> capital;
	cout << "Ahora introduzca el valor del inter�s que se le aplicar�: ";
	cin >> interes;									
	
	total = capital + ((capital*interes)/100);
	
	cout << "Al cabo de un a�o, aplicado el inter�s, se tendr�n " << total << " euros.";
	
	/* Ventajas de usar la variable capital en vez de total: Te ahorras
	un espacio de memoria que ocupar�a esa variable. Inconvenientes: la																										
	variable capital no se guarda, el dato se sobreescribir� */
	
}
