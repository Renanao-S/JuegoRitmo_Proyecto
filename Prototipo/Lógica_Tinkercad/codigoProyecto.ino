
#include <LiquidCrystal.h>

// Pines del LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin donde conectamos el sensor FSR
const int sensorFSR = A0;

void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("Sensor de fuerza");

  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");

  delay(1500);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  // Leer la señal del sensor
  int lectura = analogRead(sensorFSR);
  String fuerza = "";
  
  //Comparar según nivel de fuerza
   if(lectura <= 400){
    fuerza = "Baja";
  }else if(lectura > 400 and lectura <= 700){
    fuerza = "Media";
   }else{
     fuerza = "Alta";
   };

  // Mostrar la lectura en el LCD
  lcd.setCursor(0, 0);
  lcd.print("FSR: ");
  lcd.print(lectura);
  lcd.print("     ");

  lcd.setCursor(0, 1);
  lcd.print("Nivel: ");
  lcd.print(fuerza);
  
   
  // Mostrar tambien los datos en el monitor serial
  Serial.print("Lectura FSR: ");
  Serial.print(lectura);
  Serial.print(fuerza);

  delay(150);
}
