//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Bits to char

#include <iostream>
#include <cmath>
using namespace std;

int main (){
	char letra;
	const char MINIMO_LETRA = 'A', MAXIMO_LETRA = 'z';
	const char MINIMO_OTROS = ' ', MAXIMO_OTROS = '@';
	int i, bit, acumulador;
	double contador_letras, contador_otros, total_caracteres, porcentaje_letras, porcentaje_otros;
	bool bit_positivo;
	
	contador_letras = 0;
	contador_otros = 0;
	bit_positivo = true;
	acumulador = 0;
	while(bit_positivo){
		for (i = 7 ; i >= 0 && bit_positivo ; i--){
			do{
				cin >> bit;
			}while (bit > 1);
			
			if (bit < 0){
				bit_positivo = false;
			}	
			
			else{
				bit = bit * pow (2 , i);
				acumulador = acumulador + bit;
			}
			
			if (i == 0){
				letra = acumulador;
				acumulador = 0;
				if (letra >= MINIMO_LETRA && letra <= MAXIMO_LETRA){
					contador_letras++;
				}
				else if (letra >= MINIMO_OTROS && letra <= MAXIMO_OTROS){
					contador_otros++;
				}
				cout << letra;
			}		
		}
	}
	total_caracteres = contador_letras + contador_otros;
	porcentaje_letras = contador_letras / total_caracteres * 100.0;
	porcentaje_otros = contador_otros / total_caracteres * 100.0;
	
	cout << "\nLetras: " << porcentaje_letras << "%\nOtros: " 
	     << porcentaje_otros << "%";
}
