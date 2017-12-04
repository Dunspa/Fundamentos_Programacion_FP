//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Sustituir carácter por vector (versión ineficiente)
// Ejecutando Quijote.txt
// El programa tardará unos 45 minutos (sobre un i7 con 16Gb de RAM) en ejecutarse.

#include <iostream>
using namespace std;

int main (){
	const int MAX_CARACTERES = 25e+5;
	const char TERMINADOR = '#';
	char vector_principal[MAX_CARACTERES] = {0};
	char vector_nuevo[MAX_CARACTERES] = {0};
	char a_borrar;
	int contador_principal, principal_utilizados, nuevo_utilizados;
	
	principal_utilizados = 0;
	nuevo_utilizados = 0;
	contador_principal = 0;
	
	while (vector_principal[principal_utilizados] != TERMINADOR){
		principal_utilizados++;
		vector_principal[principal_utilizados] = cin.get();
	}
	
	while (vector_nuevo[nuevo_utilizados] != TERMINADOR){
		nuevo_utilizados++;
		vector_nuevo[nuevo_utilizados] = cin.get();
	}
	
	cin >> a_borrar;
	
	while (contador_principal != principal_utilizados){
		if (vector_principal[contador_principal] == a_borrar){
			// Se elimina el "a_borrar" desplazando todo a la izquierda
			for (int i = contador_principal ; i < principal_utilizados ; i++){
				vector_principal[i] = vector_principal[i + 1];
			}
			
			principal_utilizados = principal_utilizados - 1;
			
			// Los valores se desplazan a la derecha dejando entre medias
			// los espacios suficientes para que entre el vector nuevo
			for (int i = principal_utilizados ; i >= contador_principal ; i--){
				vector_principal[i + nuevo_utilizados] = vector_principal[i];
			}
			
			// En los espacios se mete el vector nuevo
			for (int i = 0 ; i < nuevo_utilizados ; i++){
				vector_principal[contador_principal + i] = vector_nuevo[i];
			}
			
			principal_utilizados = principal_utilizados + nuevo_utilizados;
			contador_principal = contador_principal + nuevo_utilizados;
		}
		else{
			contador_principal++;
		}
	}
	
	for (int i = 0 ; i < principal_utilizados ; i++){
		cout << vector_principal[i];
	}
}
