//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Sustituye carácter por secuencia (versión ineficiente sin secuencia auxiliar)

#include <iostream>
#include <string>
using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 100; 
   
   char vector_privado[TAMANIO];
   int total_utilizados;
   
   void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
      char intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:
   SecuenciaCaracteres()
      :total_utilizados(0) {
   }
   
   int TotalUtilizados(){
      return total_utilizados;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      total_utilizados = 0;
   }
   
   void Aniade(char nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }
   
   void Modifica(int posicion, char nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   char Elemento(int indice){
      return vector_privado[indice];
   }
   
   string ToString(){
      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++)
         cadena.push_back(vector_privado[i]);
         
      return cadena;
   }

   int PrimeraOcurrenciaEntre (int pos_izda, int pos_dcha, char buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }
   
   int PrimeraOcurrencia (char buscado){
      return PrimeraOcurrenciaEntre (0, total_utilizados - 1, buscado);
   }
   
   /////////////////////////////////////////////////////////////
   // Búsquedas
   
   int PosicionMinimoEntre(int izda, int dcha){
      int posicion_minimo = -1;
      char minimo;

      minimo = vector_privado[izda];
      posicion_minimo = izda;

      for (int i = izda+1 ; i <= dcha ; i++)
         if (vector_privado[i] < minimo){
            minimo = vector_privado[i];
            posicion_minimo = i;
         }

      return posicion_minimo;
   }
   
   int PosicionMinimo(){
      return PosicionMinimoEntre(0, total_utilizados - 1);
   }
   
   int BusquedaBinaria (char buscado){
      int izda, dcha, centro;
      bool encontrado = false;

      izda = 0;
      dcha = total_utilizados - 1;
      centro = (izda + dcha) / 2;

      while (izda <= dcha  &&  !encontrado){
         if (vector_privado[centro] == buscado)
            encontrado = true;
         else if (buscado < vector_privado[centro])
            dcha = centro - 1;
         else
            izda = centro + 1;

         centro = (izda + dcha) / 2;
      }

      if (encontrado)
         return centro;
      else
         return -1;
   }
   
   /////////////////////////////////////////////////////////////
   // Recorridos que modifican las componentes
   
   void Inserta(int pos_insercion, char valor_nuevo){
      if (total_utilizados < TAMANIO  &&  pos_insercion >= 0    
         &&  pos_insercion <= total_utilizados){

         for (int i = total_utilizados ; i > pos_insercion ; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[pos_insercion] = valor_nuevo;
         total_utilizados++;
      }
   }
   
   // Elimina una componente, dada por su posición
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
   }
   
   void InsertaSecuencia(int pos_insercion, SecuenciaCaracteres a_insertar){
      int longitud_a_insertar = a_insertar.TotalUtilizados();

      if (longitud_a_insertar + total_utilizados < TAMANIO){
         for (int i = 0; i < longitud_a_insertar; i++){
            Inserta(pos_insercion, a_insertar.Elemento(i));    
            pos_insercion++;
         }
      }
   }
   
   void SustituyeCaracterPorSecuencia (SecuenciaCaracteres secuencia, char a_borrar){		
	   for (int i = 0 ; i < total_utilizados ; i++){
	      if (vector_privado[i] == a_borrar){
		      Elimina (i);
			   InsertaSecuencia (i, secuencia);
		   }
	   }
	}
};

int main (){
	SecuenciaCaracteres secuencia_original, secuencia_nueva;
	char caracter, a_borrar;
	const char TERMINADOR = '#';
	
	cout << "Introduzca una secuencia de caracteres."
		  << "\nPara terminar introduzca '#': ";
	cin >> caracter;
	while (caracter != TERMINADOR){
		secuencia_original.Aniade (caracter);
		cin >> caracter;
	}
	
	cout << "\n\nIntroduzca la nueva secuencia de caracteres que quiere introducir."
		  << "\nPara terminar introduzca '#': ";
	cin >> caracter;
	while (caracter != TERMINADOR){
		secuencia_nueva.Aniade (caracter);
		cin >> caracter;
	}
	
	cout << "\n\nIntroduzca el caracter que quiere borrar en la secuencia original: ";
	cin >> a_borrar;
	
	secuencia_original.SustituyeCaracterPorSecuencia (secuencia_nueva, a_borrar);
	
	cout << "\n\nLa secuencia ahora es: " << secuencia_original.ToString ();
}
