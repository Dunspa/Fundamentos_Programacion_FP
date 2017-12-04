//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Sustituir carácter por vector (con vector auxiliar)

#include <iostream>
using namespace std;

int main (){
	const int MAX_CARACTERES = 100;
	const char TERMINADOR = '#';
	int i, j, incremento;
	char cadena_principal[MAX_CARACTERES] = {0};
	char cadena_auxiliar[MAX_CARACTERES] = {0};
	char sustituido[MAX_CARACTERES] = {0};
	char a_borrar;
	
	i = 0;
	j = 0;
	incremento = 0;
	
	while (cadena_principal[i] != TERMINADOR){
		i++;
		cin >> cadena_principal[i];
	}
	
	
	while (cadena_auxiliar[j] != TERMINADOR){
		j++;
		cin >> cadena_auxiliar[j];
	}
	
	cin >> a_borrar;
	
	for (int k = 1 ; k < i ; k++){
		
		if (cadena_principal[k] == a_borrar){
			for (int m = 1 ; m < j ; m++){
				sustituido[incremento] = cadena_auxiliar[m];
				incremento++;
			}
		}
		else{
			sustituido[incremento] = cadena_principal[k];
			incremento++;
		}
	}
	
	for (i = 0 ; i < incremento ; i++){
		cout << " " << sustituido[i];
	}
}
