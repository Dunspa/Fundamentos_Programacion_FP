//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Generador aleatorio

#include <iostream>
#include <random>		// generación de números pseudoaleatorios
#include <chrono>		// para la semilla
using namespace std;

class GeneradorAleatorioEnteros{
private:
	mt19937 generador_mersenne; // Mersenne twister
	uniform_int_distribution<int> distribucion_uniforme;
	
	long long Nanosec(){
		return chrono::high_resolution_clock::now().time_since_epoch().count();
	}
public:
	GeneradorAleatorioEnteros()
		:GeneradorAleatorioEnteros(0, 1){
	}

	GeneradorAleatorioEnteros(int min, int max){
		const int A_DESCARTAR = 70000;
		// ACM TOMS Volume 32 Issue 1, March 2006

		auto semilla = Nanosec();
		generador_mersenne.seed(semilla);
		generador_mersenne.discard(A_DESCARTAR);
		distribucion_uniforme =	uniform_int_distribution<int> (min, max);
	}

	int Siguiente(){
		return distribucion_uniforme(generador_mersenne);
	}
};

int main (){
	const int MINIMO = 1, MAXIMO = 5, NUMERO_VECES = 100;
	GeneradorAleatorioEnteros num_0_1_a_generar (MINIMO, MAXIMO);
	GeneradorAleatorioEnteros generar_binario;
	
	for (int i = 0 ; i < NUMERO_VECES ; i++){
		cout << "\n";
		for (int j = 0 ; j < num_0_1_a_generar.Siguiente () ; j++){
			cout << generar_binario.Siguiente ();
		}
	}
}
