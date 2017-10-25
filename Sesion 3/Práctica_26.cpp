#include <iostream>
using namespace std;

int main (){
	char letra;
	int edad, adivine, bisiesto;
	bool bool_letra, bool_edad, bool_adivine, bool_bisiesto;
	
	cout << "Introduzca los siguientes valores: Letra (saber si es minúscula o no), Edad (verdadera si mayor que 18 y menor que 65), Adivine (si el número está entre 1 y 100) y Bisiesto (ver si el año es bisiesto): ";
	cin >> letra >> edad >> adivine >> bisiesto;
	
	bool_letra = letra >= 97 && letra <= 122;
	bool_edad = edad < 18 || edad > 65;
	bool_adivine = adivine >= 1 && adivine <= 100;
	bool_bisiesto = (bisiesto % 4 == 0 && !(bisiesto % 100 == 0)) || bisiesto % 400 == 0;
	
	cout << bool_letra << bool_edad << bool_adivine << bool_bisiesto;
	
}
