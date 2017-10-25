#include <iostream>
using namespace std;

int main (){
	char letra, letra_codificada, letra_descodificada, letras_que_se_pasa, sobrante;
	int clave, maximo = 90, minimo = 65, numero_de_letras = maximo - minimo + 1;
	
	cout << "Codificación de caracteres con algoritmo de rotación. \nIntroduzca la clave para codificar: ";
	cin >> clave;
	cout << "Introduzca la letra mayúscula que quiere codificar: ";
	cin >> letra;
	
	letra_codificada = letra + clave;
	letras_que_se_pasa = letra + clave - minimo;
	sobrante = letras_que_se_pasa - numero_de_letras;
	
	if (letra_codificada > maximo){
		letra_codificada = sobrante + minimo;
	}
	
	cout << "La letra codificada es: " << letra_codificada;
	
	letra_descodificada = letra_codificada - clave;

	if (letra_descodificada < minimo){
		letra_descodificada = letra_descodificada + numero_de_letras;
	}
	
	cout << "\nLa letra descodificada es: " << letra_descodificada;
	
}
