#include <iostream>
using namespace std;

int main (){
	int kilometros_al_destino, puntos_cliente;
	const int TARIFA_BASE = 150, LIMITE_KILOMETROS_PARA_TARIFA_BASE = 300;
	const int LIMITE_KILOMETROS_PARA_DESCUENTO = 700;
	const int MINIMO_PUNTOS = 0, MAXIMO_PUNTOS = 400;
	const int PUNTOS_DCTO1 = 100, PUNTOS_DCTO2 = 200;
	double precio_final, primer_descuento, segundo_descuento;
	const double CENTIMO_POR_KILOMETRO = 0.10, DESCUENTO_KILOMETROS = 2.0/100.0;
	const double DESCUENTO_PUNTOS1 = 3.0/100.0, DESCUENTO_PUNTOS2 = 4.0/100.0;
	
	// Entradas con filtro de entrada
	cout << "Tarifa aérea.";
	do{
	cout << "\n¿A qué distancia en kilómetros está de su destino?: ";
	cin >> kilometros_al_destino;	
	}while (kilometros_al_destino < 0);
	
	do{
	cout << "¿Cuántos puntos tiene en su tarjeta de fidelización?: ";
	cin >> puntos_cliente;
	}while (puntos_cliente >= MAXIMO_PUNTOS || puntos_cliente < 0);
	
	// Cómputos
	if (kilometros_al_destino <= LIMITE_KILOMETROS_PARA_TARIFA_BASE){
		precio_final = TARIFA_BASE;
	}
	else{
		precio_final = TARIFA_BASE + CENTIMO_POR_KILOMETRO * 
				(kilometros_al_destino - LIMITE_KILOMETROS_PARA_TARIFA_BASE);
	}

	if (kilometros_al_destino > LIMITE_KILOMETROS_PARA_DESCUENTO)
		primer_descuento = precio_final * DESCUENTO_KILOMETROS;
	
	if (puntos_cliente > PUNTOS_DCTO1){
		if(puntos_cliente > PUNTOS_DCTO2){
			segundo_descuento = precio_final * DESCUENTO_PUNTOS2;
		}
		else
			segundo_descuento = precio_final * DESCUENTO_PUNTOS1;
	}
	
	precio_final = precio_final - primer_descuento - segundo_descuento;
	
	// Salidas
	cout << "El precio de su billete es de " << precio_final << " euros.";
}
