//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Mayúscula a minúscula y viceversa usando un enumerado 

#include <iostream>
using namespace std;

enum class TipoCaracter
	{mayuscula, minuscula, no_alfabetico};
			
int main(){
	TipoCaracter tipo_caracter;
	char letra_original, letra_convertida;
	const int DISTANCIA_MAY_MIN = 'a'-'A';
	
	// Entradas
	cout << "Mayúscula a minúscula y viceversa usando un enumerado."
		 << "\nIntroduzca una letra: ";
    cin >> letra_original; 
    
    // Cómputos
    if ((letra_original >= 'A') && (letra_original <= 'Z')){
    	letra_convertida = letra_original + DISTANCIA_MAY_MIN;
    	tipo_caracter = TipoCaracter::mayuscula;
	}
    else if ((letra_original >= 'a') && (letra_original <= 'z')){
    	letra_convertida = letra_original - DISTANCIA_MAY_MIN;
    	tipo_caracter = TipoCaracter::minuscula;
	}
    else
    	tipo_caracter = TipoCaracter::no_alfabetico;
    	
    // Salidas
    if (tipo_caracter == TipoCaracter::mayuscula)
    	cout << "La letra era mayúscula. Una vez convertida es: " 
			 << letra_convertida;
    else if (tipo_caracter == TipoCaracter::minuscula)
    	cout << "La letra era minúscula. Una vez convertida es: " 
			 << letra_convertida;
    else
    	cout << "El carácter " << letra_original << " no era una letra";
    
}
