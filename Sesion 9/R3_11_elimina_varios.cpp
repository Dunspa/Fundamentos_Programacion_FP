//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Elimina Varios

#include <iostream>
using namespace std;

int main (){
	const int MAX_NUMEROS = 100;
	int v[MAX_NUMEROS], a_borrar[MAX_NUMEROS];
	int num_componentes, num_a_borrar, a_desplazar, i;
	int pos_escritura, pos_lectura, pos_lectura2, utilizados;
	   
	cout << "¿Cuantas componentes tendrá el vector v?: ";
	cin >> num_componentes;   
	cout << "Introduzca las componentes en el vector v: ";
	
	for (int i = 0 ; i < num_componentes ; i++){
		cin >> v[i];
	}
	
	cout << "¿Cuantas componentes tendrá el vector v?: ";
	cin >> num_a_borrar; 
	cout << "Introduzca las componentes en el vector a_borrar: ";
	
	for (int i = 0 ; i < num_a_borrar ; i ++){
		cin >> a_borrar[i];
	}
	
	utilizados = num_componentes - num_a_borrar;
	pos_escritura = 0;
	pos_lectura = 0;
	pos_lectura2 = 0;
	
	// Algoritmo de ordenación por inserción del vector a_borrar
	for (int izda = 1 ; izda < num_a_borrar ; izda++){
		a_desplazar = a_borrar[izda];
		for (i = izda ; i > 0 && a_desplazar < a_borrar[i-1] ; i--)
			a_borrar[i] = a_borrar[i-1];
		
		a_borrar[i] = a_desplazar;
	}
	
	for (int i = pos_escritura ; i < num_componentes ; i++){
		if (pos_lectura == a_borrar[pos_lectura2]){
			while (pos_lectura == a_borrar[pos_lectura2]){
				pos_lectura++;	
				pos_lectura2++;
				
			}

			v[pos_escritura] = v[pos_lectura];
			pos_escritura++;
			pos_lectura++;

		}
		else{
			pos_escritura++;
			pos_lectura++;
		}
	}
	
	for (int i = 0 ; i < utilizados; i++){
		cout << " " << v[i];
	}
}
