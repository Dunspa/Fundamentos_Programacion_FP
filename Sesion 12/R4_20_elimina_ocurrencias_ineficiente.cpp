//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Elimina ocurrencias ineficiente

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
	
	void EliminaOcurrencias (char a_borrar){
		int i = 0;
		
		while (i < total_utilizados){
			if (vector_privado[i] == a_borrar)
				Elimina (i);
			else
				i++;
		}
	}
   
	char Elemento(int indice){
      return vector_privado[indice];
   }
};

int main (){
	SecuenciaCaracteres secuencia1;
	char caracter;
	char a_borrar;
	const char TERMINADOR = '#';
	
	cout << "\nIntroduzca una secuencia de caracteres: ";
	
	caracter = cin.get ();
	while (caracter != TERMINADOR){
		secuencia1.Aniade (caracter);
		caracter = cin.get ();
	}
	
	cout << "\nIntroduzca el caracter que quiera borrar: ";
	a_borrar = cin.get ();
	
	secuencia1.EliminaOcurrencias (a_borrar);
	cout << "\n";
	for (int i = 0 ; i < secuencia1.TotalUtilizados() ; i++){
		cout << secuencia1.Elemento (i);
	}
}
