//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Top K (versi�n eficiente)

#include <iostream>
using namespace std;

int main (){
	const int TERMINADOR = -1;
   int dato;
   const int TAMANIO = 1e+6;
   int vector[TAMANIO], topk[TAMANIO];
   int utilizados_vector, maximo, posicion_maximo, guardar, izda, i, k;
	
   cout << "Topk.\n\n"
        << "Introduzca enteros con terminador "
        << TERMINADOR << "\n"
        << "Luego introduzca el valor de k.\n\n";
        
   utilizados_vector = 0;
   cin >> dato;

   while (dato != TERMINADOR && utilizados_vector < TAMANIO){
      vector[utilizados_vector] = dato;
      utilizados_vector++;
      cin >> dato;
   }
   
   cin >> k;

   for (i = 0; i < utilizados_vector; i++)
      topk[i] = vector[i];
   
   for (izda = 0 ; izda < k ; izda++){
      maximo = topk[izda];
      for (i = izda + 1 ; i < utilizados_vector ; i++){
         if (topk[i] > maximo){
            maximo = topk[i];
            posicion_maximo = i;
         }
      }
      
      guardar = topk[izda];
      topk[izda] = maximo;
      topk[posicion_maximo] = guardar;
   }
   
   for (int i = 0; i < k; i++){
      cout << topk[i] << " ";
   }
}
