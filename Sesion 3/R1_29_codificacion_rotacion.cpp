//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Codificación de caracteres con algoritmo de rotación 

#include <iostream>
using namespace std;

int main (){
	int clave;
	const int intervalo_letras_maximo = 90, intervalo_letras_minimo = 65;
	char letra, letra_codificada, letra_descodificada;
	
	cout << "Cifrado César. \nIntroduzca la clave para realizar la codificación: ";
	cin >> clave;
	cout << "Introduzca la letra mayúscula que desea codificar: ";
	cin >> letra;
	
	letra_descodificada = letra;
	letra_codificada = ((letra + clave - intervalo_letras_minimo) % (intervalo_letras_maximo - intervalo_letras_minimo + 1)) + intervalo_letras_minimo;
	
	cout << "La letra codificada con clave " << clave << " es: " << letra_codificada << " y la letra descodificada es: " << letra_descodificada;
	
}
