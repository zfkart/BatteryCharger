/** MAS VOCEEEEE, VOCEEEEEE,,, VOCE QUE SOOOOOOOOFRE de prisaum de ventre...
que passa HORAS tentando... e quando viaja o intestino fica logo preso?????
LACTOPURGA resolve........ LACTOPURGA, deixa até sua PELE mais bonita! **/

// Controlador de Carga de Bateria com Arduino Uno / Nano
// TODO: Fazer o Readme.txt
// TODO: Desenhar pinout e postar


#include <LiquidCrystal.h> 
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
int batPin = A1;
int adc_key_val[5] ={30, 150, 360, 535, 760 }; 
int blPin = 10;
int pwmPin = 3;
int ledPin = 2;
int pwm = 0;
int i,data,bat,pwmout,b,tmp;
float vo,cutoff,on,dch;
long interval = 1000;
long blinkTime;
long blinkWait; 

void setup ()

void chargeControl(){
  vo=analogRead(batPin);
  vo=vo*.0197; // Magic Number for Voltage Divider with "GND-33K-A1-100K-Bat"

  if(vo>cutoff){
    pwm=0;}
  else{
    if(vo<on)pwm=100;
    else{
      if(vo>on){
        pwm=2160-(150*vo);
      }
    }
  }
  if(pwm<0)pwm=0;
  if(pwm>100)pwm=100;
  pwmout=(pwm*2.55);
  analogWrite(pwmPin,pwmout);
}

void dchBlink() {
  
  pinMode(ledPin, OUTPUT);
  static unsigned long previousMillis = 0;
  static bool ledState = false;
  unsigned long currentMillis = millis();
  cutoff=14.4;
  on=13.5;
  dch=12; //Lower than 12v = blink

  if (vo < dch) {
    int onTime = map(vo, 5, dch, 50, 2); 
    onTime = constrain(onTime, 5, 100);

    int totalCycle = map(vo, 8, dch, 300, 10000); 
    totalCycle = constrain(totalCycle, 100, 10000);
    int offTime = totalCycle - onTime;

    if (ledState && (currentMillis - previousMillis >= onTime)) {
      ledState = false;
      previousMillis = currentMillis;
      digitalWrite(ledPin, LOW);

    } 
    else if (!ledState && (currentMillis - previousMillis >= offTime)) {
      ledState = true;
      previousMillis = currentMillis;
      digitalWrite(ledPin, HIGH);
    }

  } else {
    digitalWrite(ledPin, LOW);
    ledState = false;
    previousMillis = currentMillis;
  }
}

void lcdInfo(){

  lcd.begin(16, 2);           
  lcd.clear();                     
  pinMode(blPin, OUTPUT);            
  analogWrite(blPin, 125);    
  lcd.print("Charging: "); 
  lcd.setCursor(0,1);
  lcd.print("VBat: ");

  if(pwm<10){
    lcd.setCursor(9, 0);                 
    lcd.print("NO     ");
  }
  if(pwm>10){
    lcd.setCursor(9, 0);
    if(pwm>99){
      lcd.print("YES,");
      lcd.print(pwm);
    }
    else{
      lcd.print("YES, ");
      lcd.print(pwm);
    }
  }  
  lcd.setCursor(6, 1);                 
  lcd.print(vo);
  lcd.print("V   ");
}


void loop(){

chargeControl();
// lcdInfo();  // If you are using the LCD Keypad Shield (or any other 16x2 LCD) and want the visual feedback, uncomment this line.
dchBlink();
delay(250);

}
