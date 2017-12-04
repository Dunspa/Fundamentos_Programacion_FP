//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Parejas de caracteres

#include <iostream>
using namespace std;

int main (){
	char min_izda, max_izda, min_dcha, max_dcha;
	char letra_dcha, letra_izda;
	
	cin >> min_izda >> max_izda >> min_dcha >> max_dcha;

	for (letra_izda = min_izda; letra_izda <= max_izda; letra_izda++){
      	cout << "\n"; 
      for (letra_dcha = min_dcha; letra_dcha <= max_dcha; letra_dcha++)
         cout << letra_izda << letra_dcha << " ";
   }
}
