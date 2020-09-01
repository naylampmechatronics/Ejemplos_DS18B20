/****************************************************************************************
 Simple Lectura
 
  Programa para realizar lecturas de un sensor DS18B20
  
 Conexiones:
  --------------------------
  DS18B20        -> Arduino
  --------------------------
  Pin1 (Negro)   -> GND  
  Pin2 (Amarillo)-> D2 + Res.Pull-Up 
  Pin3 (Rojo)    -> VCC 
  --------------------------
  *Puede cambiar la conexión a otro pin del arduino modificando la variable que define el pin.
 
 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir)
 
 Última modificación el 31/08/2020
 
 Más información en:
   -https://naylampmechatronics.com/blog/46_Tutorial-sensor-de-temperatura-DS18B20.html
   -https://github.com/naylampmechatronics/Ejemplos_DS18B20
**************************************************************************************************/
#include <OneWire.h>                
#include <DallasTemperature.h>

// definición de pines
int pinDS=2;

OneWire ourWire(pinDS);     //Se establece el pin 2  como bus OneWire
 
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor

void setup() {
delay(1000);
Serial.begin(9600);
sensors.begin();   //Se inicia el sensor
}
 
void loop() {
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC

Serial.print("Temperatura= ");
Serial.print(temp);
Serial.println(" C");
delay(100);                     
}
