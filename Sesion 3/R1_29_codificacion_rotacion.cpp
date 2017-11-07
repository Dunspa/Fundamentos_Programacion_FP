//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Pe�a
//
//////////////////////////////////////////////////////////////////////////

// Codificaci�n de caracteres con algoritmo de rotaci�n 

#include <iostream>
using namespace std;

int main (){
	int clave;
	const int intervalo_letras_maximo = 90, intervalo_letras_minimo = 65;
	char letra, letra_codificada, letra_descodificada;
	
	cout << "Cifrado C�sar. \nIntroduzca la clave para realizar la codificaci�n: ";
	cin >> clave;
	cout << "Introduzca la letra may�scula que desea codificar: ";
	cin >> letra;
	
	letra_descodificada = letra;
	letra_codificada = ((letra + clave - intervalo_letras_minimo) % (intervalo_letras_maximo - intervalo_letras_minimo + 1)) + intervalo_letras_minimo;
	
	cout << "La letra codificada con clave " << clave << " es: " << letra_codificada << " y la letra descodificada es: " << letra_descodificada;
	
}
