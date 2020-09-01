
/****************************************************************************************
 Multiple Bus
 
  Para realizar lecturas de varios sensores DS18B20 conectados cada uno en su propio bus (Cada sensor en un pin diferente)
  
 Conexiones:
  --------------------------
  DS18B20 (1)    -> Arduino
  --------------------------
  Pin1 (Negro)   -> GND  
  Pin2 (Amarillo)-> D2 + Res.Pull-Up 
  Pin3 (Rojo)    -> VCC 
  --------------------------
  DS18B20 (2)    -> Arduino
  --------------------------
  Pin1 (Negro)   -> GND  
  Pin2 (Amarillo)-> D3 + Res.Pull-Up 
  Pin3 (Rojo)    -> VCC 
  --------------------------
  *Puede cambiar la conexión a otros pines del arduino modificando las variables que definen los pines.
 
 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir)
 
 Última modificación el 31/08/2020
 
 Más información en:
   -https://naylampmechatronics.com/blog/46_Tutorial-sensor-de-temperatura-DS18B20.html
   -https://github.com/naylampmechatronics/Ejemplos_DS18B20
**************************************************************************************************/
#include <OneWire.h>                
#include <DallasTemperature.h>

//definición de pines
int pinDS_1=2;
int pinDS_2=3;

OneWire ourWire1(pinDS_1);      //Se establece el pin pinDS_1  como bus OneWire
OneWire ourWire2(pinDS_2);      //Se establece el pin pinDS_2  como bus OneWire
 
DallasTemperature sensors1(&ourWire1); //Se declara una variable u objeto para nuestro sensor1
DallasTemperature sensors2(&ourWire2); //Se declara una variable u objeto para nuestro sensor2

void setup() {
delay(1000);
Serial.begin(9600);
sensors1.begin();   //Se inicia el sensor 1
sensors2.begin();   //Se inicia el sensor 2
}
 
void loop() {
sensors1.requestTemperatures();   //Se envía el comando para leer la temperatura
float temp1= sensors1.getTempCByIndex(0); //Se obtiene la temperatura en ºC del sensor 1

sensors2.requestTemperatures();   //Se envía el comando para leer la temperatura
float temp2= sensors2.getTempCByIndex(0); //Se obtiene la temperatura en ºC del sensor 2

Serial.print("Temperatura 1 = ");
Serial.print(temp1);
Serial.print(" C");
Serial.print("   Temperatura 2 = ");
Serial.print(temp2);
Serial.println(" C");
delay(100);                     
}
