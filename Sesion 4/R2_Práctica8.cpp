#include <iostream>
using namespace std;

int main (){
	int kilometros_al_destino, puntos_cliente;
	const int TARIFA_BASE = 150, LIMITE_KILOMETROS_PARA_TARIFA_BASE = 300, LIMITE_KILOMETROS_PARA_DESCUENTO = 700;
	double precio_final, primer_descuento, segundo_descuento;
	const double CENTIMO_POR_KILOMETRO = 0.10, DESCUENTO_KILOMETROS = 2.0/100.0, DESCUENTO_PUNTOS1 = 3.0/100.0, DESCUENTO_PUNTOS2 = 4.0/100.0;
	
	cout << "Tarifa aérea. \n¿A qué distancia en kilómetros está de su destino?: ";
	cin >> kilometros_al_destino;
	cout << "¿Cuántos puntos tiene en su tarjeta de fidelización?: ";
	cin >> puntos_cliente;
	
	if (kilometros_al_destino <= LIMITE_KILOMETROS_PARA_TARIFA_BASE){
		precio_final = TARIFA_BASE;
	}
	else{
		precio_final = TARIFA_BASE + CENTIMO_POR_KILOMETRO * (kilometros_al_destino - LIMITE_KILOMETROS_PARA_TARIFA_BASE);
	}
	
	if (kilometros_al_destino > LIMITE_KILOMETROS_PARA_DESCUENTO)
		primer_descuento = precio_final * DESCUENTO_KILOMETROS;
	
	if (puntos_cliente > 100){
		if(puntos_cliente > 200){
			segundo_descuento = precio_final * DESCUENTO_PUNTOS2;
		}
		else
			segundo_descuento = precio_final * DESCUENTO_PUNTOS1;
	}
	
	precio_final = precio_final - primer_descuento - segundo_descuento;
		
	cout << "El precio de su billete es de " << precio_final << " euros.";
}
