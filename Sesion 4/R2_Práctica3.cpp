#include <iostream>
using namespace std;

int main (){
	int kilometros_al_destino;
	const int tarifa_base = 150, limite_kilometros = 300;
	double precio_final;
	const double centimo_por_kilometro = 0.10;
	
	cout << "Tarifa aérea. \n¿A qué distancia en kilómetros está de su destino?: ";
	cin >> kilometros_al_destino;
	
	if (kilometros_al_destino <= limite_kilometros){
		precio_final = tarifa_base;
		cout << "El precio de su billete es de " << precio_final << " euros.";
	}
	else{
		precio_final = tarifa_base + centimo_por_kilometro * (kilometros_al_destino - limite_kilometros);
		cout << "El precio de su billete es de " << precio_final << " euros.";
	}
	
}
