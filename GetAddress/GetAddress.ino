/****************************************************************************************
 Get Address
 
  Programa para obtener las direcciones de los sensores conectados al bus OneWire
  
 Conexiones:
  --------------------------
  DS18B20        -> Arduino
  --------------------------
  Pin1 (Negro)   -> GND  
  Pin2 (Amarillo)-> D2 + Res.Pull-Up 
  Pin3 (Rojo)    -> VCC 
  --------------------------
  *Se pueden conectar uno o varios sensores al mismo pin del Arduino
  *Puede cambiar la conexión a otro pin modificando la variable que define el pin.
 
 Ejemplo desarrollado por Naylamp Mechatronics bajo licencia MIT (puede copiar, modificar, integrar o redistribuir)
 
 Última modificación el 31/08/2020
 
 Más información en:
   -https://naylampmechatronics.com/blog/46_Tutorial-sensor-de-temperatura-DS18B20.html
   -https://github.com/naylampmechatronics/Ejemplos_DS18B20
**************************************************************************************************/
#include <OneWire.h>

//definición de pines
const int pinBus=2;

OneWire ourWire(pinBus);  //Se establece el pin como bus OneWire

void setup(void) {
  Serial.begin(9600);
}

void loop(void) {
  byte addr[8];  
  Serial.println("Obteniendo direcciones:");
  while (ourWire.search(addr)) 
  {  
  Serial.print("Address = ");
  for( int i = 0; i < 8; i++) {
    Serial.print(" 0x");
    Serial.print(addr[i], HEX);
  }
  Serial.println();
}

Serial.println();
ourWire.reset_search();
delay(2000);
}
