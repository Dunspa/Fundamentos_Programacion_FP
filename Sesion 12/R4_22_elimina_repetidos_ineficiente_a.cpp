//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Elimina repetidos ineficiente (versión a)

#include <iostream>
using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 2e6; 
                                 
   char vector_privado[TAMANIO];
   int total_utilizados;
public:
   SecuenciaCaracteres()
      :total_utilizados(0) {
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   void Aniade(char nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados - 1;

         for (int j = posicion ; j < tope ; j++)
            vector_privado[j] = vector_privado[j+1];

         total_utilizados--;
      }
	}
   
	char Elemento(int indice){
      return vector_privado[indice];
   }
   
   void EliminaRepetidos (){
   	char sin_repetidos[TAMANIO] = {0};
   	bool componente_es_igual;
   	int util_repetidos = 0;
   	
   	for (int i = 0 ; i < total_utilizados ; i++){
   		componente_es_igual = true;
			for (int j = 0 ; j < util_repetidos && !componente_es_igual ; j++){
				if (vector_privado[i] != sin_repetidos[j] && j == util_repetidos - 1){
					sin_repetidos[util_repetidos] = vector_privado[i];
					util_repetidos++;
				}
				else{
					componente_es_igual = true;
				}
			}
		}
		
		for (int i = 0 ; i < total_utilizados ; i++){
			vector_privado[i] = sin_repetidos[i];
		}
		
	}
};

int main (){
	SecuenciaCaracteres secuencia1;
	char caracter;
	const char TERMINADOR = '#';
	
	cout << "\nIntroduzca una secuencia de caracteres: ";
	
	caracter = cin.get ();
	while (caracter != TERMINADOR){
		secuencia1.Aniade (caracter);
		caracter = cin.get ();
	}
	
	secuencia1.EliminaRepetidos ();
	
	for (int i = 0 ; i < secuencia1.TotalUtilizados() ; i++){
		cout << secuencia1.Elemento (i);
	}
}
