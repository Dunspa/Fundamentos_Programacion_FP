//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Elimina repetidos eficiente

#include <iostream>
#include <cmath>
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
   	int pos_escritura, pos_lectura;
		
		pos_escritura = 0;
		pos_lectura = 0;
		
		for (int i = pos_escritura ; i < pow(total_utilizados, 2) ; i++){
			for (int j = pos_escritura + 1 ; j < total_utilizados ; j++){
				if (vector_privado[pos_lectura] == vector_privado[pos_escritura])
					Elimina (pos_lectura);
			}
			
			if (i % 10 == 0)
				pos_escritura++;
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
