//librerias
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

//variables de la libreria
LiquidCrystal_I2C lcd(0x3F, 20, 4); //direccion,No. de caracteres, No. lineas
SoftwareSerial BT_JULIO(10, 11); // RX | TX
//variables globales
int timer = 3000;

void setup() {
  // put your setup code here, to run once:
  lcd.init();        //inicializar el I2C-lcd
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("esperando data...");

  Serial.begin(9600);//inicializar el serial
  BT_JULIO.begin(9600);  // HC-05 iniciando

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    int dato = Serial.read();
    switch (dato) {
      case'a':                      //HACIA ADELANTE RUEDA IZQUIERDA
        lcd.clear();
        lcd.setCursor(4,2);
        lcd.print("DERECHA");
        digitalWrite(5, HIGH);
        Serial.println("MOTOR ON");
        delay(timer);

        digitalWrite(5, LOW);
        Serial.println("MOTOR OFF");
        delay(timer);
        break;
      case'b':                    //HACIA ATRAS RUEDA IZQUIERDA
        lcd.clear();
        lcd.setCursor(4,2);
        lcd.print("IZQUIERDA");
        digitalWrite(4, HIGH);
        Serial.println("MOTOR ON");
        delay(timer);

        digitalWrite(4, LOW);
        Serial.println("MOTOR OFF");
        delay(timer);
        break;

      case'c':                    //HACIA ADELANTE RUEDA DERECHA
        lcd.clear();
        lcd.setCursor(4,2);
        lcd.print("IZQUIERDA");
        digitalWrite(8, HIGH);
        Serial.println("MOTOR ON");
        delay(timer);

        digitalWrite(8, LOW);
        Serial.println("MOTOR OFF");
        delay(timer);
        break;
      case'd':                    //HACIA ATRAS RUEDA IZQUIERDA
        lcd.clear();
        lcd.setCursor(4,2);
        lcd.print("DERECHA");
        digitalWrite(9, HIGH);
        Serial.println("MOTOR ON");
        delay(timer);

        digitalWrite(9, LOW);
        Serial.println("MOTOR OFF");
        delay(timer);
        break;
      case'e':                    //HACIA ADELANTE 2 RUEDAS
        lcd.clear();
        lcd.setCursor(4,2);
        lcd.print("ADELANTE");
        digitalWrite(5, HIGH);
        digitalWrite(8, HIGH);
        Serial.println("MOTOR ON");
        delay(timer);

        digitalWrite(5, LOW);
        digitalWrite(8, LOW);
        Serial.println("MOTOR OFF");
        delay(timer);
        break;
      case'f':                    //HACIA ATRAZ 2 RUEDAS
        lcd.clear();
        lcd.setCursor(3,2);
        lcd.print("ATRAS");
        digitalWrite(4, HIGH);
        digitalWrite(9, HIGH);
        Serial.println("MOTOR ON");
        delay(timer);

        digitalWrite(4, LOW);
        digitalWrite(9, LOW);
        Serial.println("MOTOR OFF");
        delay(timer);
        break;
    }
  }
}
