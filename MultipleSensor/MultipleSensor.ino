/****************************************************************************************
 Multiple Sensor
 
  Para realizar lecturas de varios sensores DS18B20 conectados a un mismo bus (Todos los sensor en un mismo pin)
  
 Conexiones:
  --------------------------
  DS18B20(1)     -> Arduino
  --------------------------
  Pin1 (Negro)   -> GND  
  Pin2 (Amarillo)-> D2 + Res.Pull-Up 
  Pin3 (Rojo)    -> VCC 
  --------------------------
  DS18B20(2)     -> Arduino
  --------------------------
  Pin1 (Negro)   -> GND  
  Pin2 (Amarillo)-> D2 
  Pin3 (Rojo)    -> VCC 
  --------------------------
  DS18B20(3)     -> Arduino
  --------------------------
  Pin1 (Negro)   -> GND  
  Pin2 (Amarillo)-> D2 
  Pin3 (Rojo)    -> VCC 
  --------------------------
  *Se pueden conectar uno o varios sensores al mismo pin del Arduino
  *Solo es necesario una resistencia Pull-Up presente en el bus
  *Puede cambiar la conexión a otro pin del arduino modificando la variable que define el pin.
 
 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir)
 
 Última modificación el 31/08/2020
 
 Más información en:
   -https://naylampmechatronics.com/blog/46_Tutorial-sensor-de-temperatura-DS18B20.html
   -https://github.com/naylampmechatronics/Ejemplos_DS18B20
**************************************************************************************************/
#include <OneWire.h>                
#include <DallasTemperature.h>

//definición de pines
const int pinBus=2;

OneWire ourWire(pinBus);   //Se establece el pin como bus OneWire
 
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro bus

DeviceAddress address1 = {0x28, 0xFF, 0xCA, 0x4A, 0x5, 0x16, 0x3, 0xBD};//dirección del sensor 1
DeviceAddress address2 = {0x28, 0xFF, 0x89, 0x3A, 0x1, 0x16, 0x4, 0xAF};//dirección del sensor 2
DeviceAddress address3 = {0x28, 0xFF, 0x23, 0x19, 0x1, 0x16, 0x4, 0xD9};//dirección del sensor 3

void setup() {
delay(1000);
Serial.begin(9600);
sensors.begin();   //Se inicia el sensor
}
 
void loop() {
  
sensors.requestTemperatures();   //envía el comando para obtener las temperaturas
float temp1= sensors.getTempC(address1);//Se obtiene la temperatura en °C del sensor 1
float temp2= sensors.getTempC(address2);//Se obtiene la temperatura en °C del sensor 2
float temp3= sensors.getTempC(address3);//Se obtiene la temperatura en °C del sensor 3

Serial.print("Temperatura 1 = ");
Serial.print(temp1);
Serial.print(" C");
Serial.print("   Temperatura 2 = ");
Serial.print(temp2);
Serial.print(" C");
Serial.print("   Temperatura 3 = ");
Serial.print(temp3);
Serial.println(" C");
delay(100);                     
}
