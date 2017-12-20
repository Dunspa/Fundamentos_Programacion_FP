//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Sustituye carácter por secuencia (versión usando una secuencia auxiliar)

#include <iostream>
#include <cctype>
using namespace std;


struct FrecuenciaCaracter{
   char caracter;
   int  frecuencia;
};

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 100;
   char vector_privado[TAMANIO];
   int total_utilizados;

   void IntercambiaComponentesDirectamente(int pos_izda, int pos_dcha){
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
   
   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
	}

   void Inserta(int pos_insercion, char valor_nuevo){     
      if (total_utilizados < TAMANIO  &&  pos_insercion >= 0
         &&  pos_insercion <= total_utilizados){

         for (int i = total_utilizados ; i > pos_insercion ; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[pos_insercion] = valor_nuevo;
         total_utilizados++;
      }
   }
   
   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado){
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
      return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
   }

   void InsertaSecuencia(int pos_insercion, SecuenciaCaracteres a_insertar){
      int longitud_a_insertar = a_insertar.TotalUtilizados();

      if (longitud_a_insertar + total_utilizados < TAMANIO){
         for (int i = 0; i < longitud_a_insertar; i++){
            Inserta(pos_insercion, a_insertar.Elemento(i));    // Inserta aumenta automáticamente total_tulizados
            pos_insercion++;
         }
      }
   }
   
   void Replace(char a_eliminar, SecuenciaCaracteres sustituta){   
      SecuenciaCaracteres copia;
      int utilizados_sustituta = sustituta.TotalUtilizados();
      int utilizados_copia = 0;

      for (int i = 0; i < total_utilizados && copia.TotalUtilizados() < TAMANIO; i++){
         if (vector_privado[i] == a_eliminar){
            for (int j = 0 ;
                 j < utilizados_sustituta && copia.TotalUtilizados()< TAMANIO;
                 j++){
               copia.Aniade(sustituta.Elemento(j));
            }
         }
         else{
            copia.Aniade(vector_privado[i]);
         }
      }

      total_utilizados = copia.TotalUtilizados();

      for (int i = 0; i < total_utilizados; i++)
         vector_privado[i] = copia.Elemento(i);
   }
   
   
   int NumeroOcurrencias (char buscado, int izda, int dcha){
      int numero_ocurrencias = 0;

      for (int i = izda; i <= dcha; i++)
         if (vector_privado[i] == buscado)
            numero_ocurrencias++;

      return numero_ocurrencias;
   }
};

class LectorSecuenciaCaracteres{
private:
   char terminador;
public:
   LectorSecuenciaCaracteres(char caracter_terminador)
      :terminador(caracter_terminador)
   {
   }
   SecuenciaCaracteres Lee(){
      SecuenciaCaracteres a_leer;
      int total_introducidos; 
      int capacidad_secuencia;
      char caracter;

      total_introducidos = 0;
      capacidad_secuencia = a_leer.Capacidad();
      caracter = cin.get();

      while (caracter == '\n')
   		caracter = cin.get();

		while (caracter != terminador && total_introducidos < capacidad_secuencia){
			a_leer.Aniade(caracter);
			total_introducidos++;
			caracter = cin.get();
		}

		return a_leer;
	}
};

int main(){
   const char TERMINADOR = '#';
   SecuenciaCaracteres secuencia, a_insertar;
   LectorSecuenciaCaracteres lector_secuencias(TERMINADOR);
   char a_sustituir;
   int pos_insercion;

   secuencia  = lector_secuencias.Lee();
   a_insertar = lector_secuencias.Lee();
   
   a_sustituir = cin.get();
   secuencia.Replace(a_sustituir, a_insertar);
   
   cout << "\nSecuencia nueva: " << secuencia.ToString();
   cout << "\n";

   //Juan Cubero# Carlos#4
}

