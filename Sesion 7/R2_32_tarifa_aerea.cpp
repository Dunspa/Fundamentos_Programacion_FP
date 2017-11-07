//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Jose Luis Gallego Peña
//
//////////////////////////////////////////////////////////////////////////

// Tarifa aérea: múltiples billetes

#include <iostream>
using namespace std;

int main (){
	const int    LIMITE_KMS_TARIFICACION_ADICIONAL = 300;
   const double TARIFA_POR_KM_ADICIONAL = 0.1;
   const double MINIMO_KMS_DESCUENTO = 700.0;
   const int    MINIMO_PUNTOS_DESCUENTO_BAJO = 100;
   const int    MINIMO_PUNTOS_DESCUENTO_ALTO = 200;
   const double DESCUENTO_POR_KMS = 0.02;
   const double DESCUENTO_BAJO_POR_PUNTOS = 0.03;
   const double DESCUENTO_ALTO_POR_PUNTOS = 0.04;
	const double TARIFA_BASE = 150.0;
	const int    MAXIMO_NUM_PUNTOS = 400;
	
	double descuento_final;
   double   tarifa_final;
   int distancia_trayecto;
   int num_puntos_fidelizacion;
   char introduccion_datos;
   
   do{
   	cout << "Introduzca el carácter N cada vez que quiera introducir los datos de un billete: ";
   	cin >> introduccion_datos;
	}while(introduccion_datos != 'N');
   
   while (introduccion_datos != '#'){
   	do{
   		cout << "\nIntroduzca la distancia del recorrido del viaje (> 0): ";
      	cin >> distancia_trayecto;         
   	}while (distancia_trayecto <= 0);
   	
   	do{
   		cout << "\nIntroduzca el número de puntos de la tarjeta (entre 0 y "
   			  << MAXIMO_NUM_PUNTOS << "): ";
      	cin >> num_puntos_fidelizacion;   
   	}while (num_puntos_fidelizacion < 0 || num_puntos_fidelizacion > MAXIMO_NUM_PUNTOS);
   
   	tarifa_final = TARIFA_BASE;

   	if (distancia_trayecto > LIMITE_KMS_TARIFICACION_ADICIONAL)
      	tarifa_final = tarifa_final + TARIFA_POR_KM_ADICIONAL *
                       (distancia_trayecto - LIMITE_KMS_TARIFICACION_ADICIONAL);
         
   	if (distancia_trayecto > MINIMO_KMS_DESCUENTO)
      	descuento_final = DESCUENTO_POR_KMS;   
   	else
      	descuento_final = 0;   
         
   	if (num_puntos_fidelizacion > MINIMO_PUNTOS_DESCUENTO_ALTO)   
      	descuento_final = descuento_final + DESCUENTO_ALTO_POR_PUNTOS;
   	else if (num_puntos_fidelizacion > MINIMO_PUNTOS_DESCUENTO_BAJO)   
      	descuento_final = descuento_final + DESCUENTO_BAJO_POR_PUNTOS;
         
   	tarifa_final = tarifa_final * (1 - descuento_final);

   	cout << "\n\nTarifa final aplicando los descuentos: ";
   	cout << tarifa_final;
   	
   	do{
   		cout << "\nIntroduzca el carácter N cada vez que quiera introducir los datos de un billete: ";
   		cin >> introduccion_datos;
		}while(introduccion_datos != 'N' && introduccion_datos != '#');
	}
}
