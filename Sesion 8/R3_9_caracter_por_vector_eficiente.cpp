//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Sustituir carácter por vector (versión eficiente)

#include <iostream>
using namespace std;

int main (){
	const int MAX_CARACTERES = 100;
	const char TERMINADOR = '#';
	char vector_principal[MAX_CARACTERES] = {0};
	char vector_nuevo[MAX_CARACTERES] = {0};
	char a_borrar, caracter;
	int principal_utilizados, nuevo_utilizados, total, ocurrencias_borrar;
	int lectura, escritura;

	total = 0;
	ocurrencias_borrar = 0;
	principal_utilizados = 0;
	nuevo_utilizados = 0;
	
	cin >> caracter;
	
	while (caracter != TERMINADOR){
		vector_principal[principal_utilizados] = caracter;
		principal_utilizados++;
		cin >> caracter;
	}
	
	
	cin >> caracter;
	
	while (caracter != TERMINADOR){
		vector_nuevo[nuevo_utilizados] = caracter;
		nuevo_utilizados++;
		cin >> caracter;
	}
	
	cin >> a_borrar;
	
	for (int i = 0 ; i < principal_utilizados ; i++){
		if (vector_principal[i] == a_borrar)
			ocurrencias_borrar++;
	}
	
	nuevo_utilizados = nuevo_utilizados - 1;
	lectura = principal_utilizados - 1;
	escritura = lectura + ocurrencias_borrar * (nuevo_utilizados);
	
	while (lectura >= 0){
		if (vector_principal[lectura] == a_borrar){
			for (int i = nuevo_utilizados ; i >= 0 ; i--){
				vector_principal[escritura] = vector_nuevo[i];
				escritura--;
				total++;
			}
			lectura--;
		}
		else{
			vector_principal[escritura] = vector_principal[lectura];
			escritura--;
			lectura--;
			total++;
		}
	}
	
	for (int i = 0 ; i < total ; i++){
		cout << vector_principal[i];
	}
}
