#include <iostream>
#include <cmath>
using namespace std;

int main (){
	double longitud_del_segmento_plano, longitud_del_segmento_real;
	double altura1, altura2, grados_lon1, grados_lat1, grados_lon2, grados_lat2;
	double radianes_lat1, radianes_lat2, radianes_lon1, radianes_lon2;
	double incremento_longitud, incremento_latitud, magnitud_a, potencia_longitud, 
	potencia_latitud, magnitud_c, minimo;
	const double PI = (6.0 * asin (0.5)), GRADOS_A_RADIANES = PI/180.0, 
	RADIO_TERRESTRE = 6372797.560856, CONSTANTE_ARCOSENO_C = 2.0;
	
	cout << "Coordenadas geográficas (distancia). \nIntroduzca el valor de latitud en el punto 1 en grados: ";
	cin >> grados_lat1;
	cout << "Introduzca el valor de la longitud en el punto 1 en grados: ";
	cin >> grados_lon1;
	cout << "Introduzca el valor de la altura en el punto 1: ";
	cin >> altura1;
	cout << "Introduzca el valor de latitud del punto 2 en grados: ";
	cin >> grados_lat2;
	cout << "Introduzca el valor de longitud en el punto 2 en grados: ";
	cin >> grados_lon2;
	cout << "Introduzca el valor de la altura en el punto 2: ";
	cin >> altura2;
	
	incremento_longitud = (grados_lon2 - grados_lon1)*GRADOS_A_RADIANES;															
	incremento_latitud = (grados_lat2 - grados_lat1)*GRADOS_A_RADIANES;
	potencia_longitud = pow(sin(0.5*incremento_longitud) , 2);
	potencia_latitud = pow(sin(0.5*incremento_latitud) , 2);
	
	magnitud_a = potencia_latitud + cos(grados_lat1 * GRADOS_A_RADIANES) * 
				 cos(grados_lat2 * GRADOS_A_RADIANES) * potencia_longitud;  					
				 
	minimo = 1.0;																								
	if (sqrt(magnitud_a) < 1.0)
		minimo = sqrt(magnitud_a);
		
	magnitud_c = CONSTANTE_ARCOSENO_C * asin(minimo);																
	
	longitud_del_segmento_plano = RADIO_TERRESTRE * magnitud_c;	
	
	longitud_del_segmento_real = sqrt(pow(longitud_del_segmento_plano , 2) + pow((altura2 - altura1) , 2));													
	
	cout << fixed << "La distancia sobre el plano entre los dos puntos es: " << longitud_del_segmento_plano;
	cout << fixed << "La distancia real entre los dos puntos es: " << longitud_del_segmento_real;
	
}
