//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Intercambiar variables

#include <iostream>
using namespace std;

int main (){
	double caja_dcha, caja_izda, guardar;
	
	cout << "�Cu�nto dinero desea poner en la caja de la derecha? ";
	cin >> caja_dcha;
	cout << "�Y en la caja de la izquierda? ";
	cin >> caja_izda;
	
	guardar = caja_izda;																				//El valor de la izquierda se guarda
	caja_izda = caja_dcha;																				//El valor de la derecha ahora est� en la izquierda
	caja_dcha = guardar;																				//El valor de la izquierda que se guard� pasa a la derecha
	
	cout << "En la caja de la derecha hay " << caja_dcha << " euros";
	cout << " y en la de la izquierda hay " << caja_izda << " euros.";
	
}
