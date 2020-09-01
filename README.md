# Ejemplos_DS18B20
Códigos de ejemplos para sensores de temperatura DS18B20

![Sensor de Temperatura Digital DS18B20](https://naylampmechatronics.com/759-large_default/sensor-de-temperatura-digital-ds18b20.jpg)

Información detallada de los ejemplos en: [Tutorial DS18B20](https://naylampmechatronics.com/blog/46_Tutorial-sensor-de-temperatura-DS18B20.html)

## Contenido
* **SimpleLectura:** Programa para realizar lecturas de un sensor DS18B20.
* **MultipleBus:** Para realizar lecturas de varios sensores DS18B20 conectados cada uno en su propio bus (Cada sensor en un pin diferente).
* **GetAddress:** Programa para obtener las direcciones de los sensores conectados al bus OneWire.  
* **MultipleSensor:** Para realizar lecturas de varios sensores DS18B20 conectados a un mismo bus (Todos los sensor en un mismo pin)  
 
## Requerimientos
 **Software**
  * IDE Arduino
  * Librería  [OneWire](https://github.com/PaulStoffregen/OneWire)
  * Librería  [DallasTemperature](https://github.com/milesburton/Arduino-Temperature-Control-Library) 
  
 **Hardware**
  * [Arduino Uno](https://naylampmechatronics.com/arduino-tarjetas/8-arduino-uno-r3.html) (o cualquier modelo)
  * Sensor [DS18B20](https://naylampmechatronics.com/sensores-temperatura-y-humedad/16-sensor-de-temperatura-digital-ds18b20.html)
  
## Conexiones
### Ejemplo 1 o 3 : SimpleLectura o GetAddress
  DS18B20        | Arduino
  ---------------|-----------
  Pin1 (Cable Negro)   | GND  
  Pin2 (Cable Amarillo)| D2 + Res.Pull-Up 
  Pin3 (Cable Rojo)    | 5V 
  
  Puede cambiar la conexión a otro pin del arduino modificando la variable que define el pin.


### Ejemplo 2: MultipleBus
  DS18B20 (1)    | Arduino
  ---------------|-----------
  Pin1 (Cable Negro)   | GND  
  Pin2 (Cable Amarillo)| D2 + Res.Pull-Up 
  Pin3 (Cable Rojo)    | 5V 

  DS18B20 (2)    | Arduino
  ---------------|-----------
  Pin1 (Cable Negro)   | GND  
  Pin2 (Cable Amarillo)| D3 + Res.Pull-Up 
  Pin3 (Cable Rojo)    | 5V 

  Puede cambiar la conexión a otros pines del arduino modificando las variables que definen los pines.
  
### Ejemplo 3 o 4: GetAddress o MultipleSensor
  DS18B20(1)     | Arduino
  ---------------|-----------
  Pin1 (Cable Negro)   | GND  
  Pin2 (Cable Amarillo)| D2 + Res.Pull-Up 
  Pin3 (Cable Rojo)    | 5V 
 
  DS18B20(2)     | Arduino
  ---------------|-----------
  Pin1 (Cable Negro)   | GND  
  Pin2 (Cable Amarillo)| D2 
  Pin3 (Cable Rojo)    | 5V 
 
  DS18B20(3)     | Arduino
  ---------------|-----------
  Pin1 (Cable Negro)   | GND  
  Pin2 (Cable Amarillo)| D2 
  Pin3 (Cable Rojo)    | 5V 
 
  Se pueden conectar uno o varios sensores al mismo pin del Arduino
  
  Solo es necesario una resistencia Pull-Up presente en el bus
  
  Puede cambiar la conexión a otro pin del arduino modificando la variable que define el pin.
 

## Licencia
Los ejemplos son Open Source, creados por el equipo de Naylamp Mechatronics bajo [licencia MIT](LICENSE)
 
## Links 
 * [Tutorial sensor digital de temperatura DS18B20](https://naylampmechatronics.com/blog/46_Tutorial-sensor-de-temperatura-DS18B20.html)
 * [Sensor de Temperatura Digital DS18B20](https://naylampmechatronics.com/sensores-temperatura-y-humedad/16-sensor-de-temperatura-digital-ds18b20.html)
 * [Arduino Library for Maxim Temperature Integrated Circuits](https://github.com/milesburton/Arduino-Temperature-Control-Library) 
