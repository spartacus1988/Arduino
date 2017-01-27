char incomingByte;       // переменная для хранения входящих данных
int  LED1 = 13;           // LED подключен к 13 выводу (используем встроенный светодиод)
bool LED1on = false;
int  LED2 = 12;         
bool LED2on = false;
int  LED3 = 11;         
bool LED3on = false;
int  LED4 = 10;         
bool LED4on = false;
int  LED5 = 9; 
int  LED6 = 8; 
int  LED7 = 7; 
int  LED8 = 6; 

int analogPin0 = 0;
int analogPin1 = 1;
int analogPin2 = 2;
int analogPin3 = 3;
int analogPin4 = 4;
int analogPin5 = 5;
int analogPin6 = 6;
int analogPin7 = 7;

int val0 = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
int val6 = 0;
int val7 = 0;

void setup() {
  Serial.begin(9600);    // инициализация порта на скорость 9600 бод для связи с Bluetooth-модулем
  pinMode(LED1, OUTPUT);  // вывод LED настраиваем как выход
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
}

void loop() 
{
  
  if (Serial.available() > 0)
        {      // если пришли данные
          incomingByte = Serial.read();   
          if(incomingByte == '1')  { if (LED1on) {digitalWrite(LED1, LOW); digitalWrite(LED5, LOW); LED1on = false;}  else {digitalWrite(LED1, HIGH); digitalWrite(LED5, HIGH); LED1on = true;} }  
          if(incomingByte == '2')  { if (LED2on) {digitalWrite(LED2, LOW); digitalWrite(LED6, LOW); LED2on = false;}  else {digitalWrite(LED2, HIGH); digitalWrite(LED6, HIGH); LED2on = true;} }  
          if(incomingByte == '4')  { if (LED3on) {digitalWrite(LED3, LOW); digitalWrite(LED7, LOW); LED3on = false;}  else {digitalWrite(LED3, HIGH); digitalWrite(LED7, HIGH); LED3on = true;} }   
          if(incomingByte == '8')  { if (LED4on) {digitalWrite(LED4, LOW); digitalWrite(LED8, LOW); LED4on = false;}  else {digitalWrite(LED4, HIGH); digitalWrite(LED8, HIGH); LED4on = true;} }          
        }

        val0 = analogRead(analogPin0);
        val1 = analogRead(analogPin1);
        val2 = analogRead(analogPin2);
        val3 = analogRead(analogPin3);
        val4 = analogRead(analogPin4);
        val5 = analogRead(analogPin5);
        val6 = analogRead(analogPin6);
        val7 = analogRead(analogPin7);

   if ((val0 > 950) &&(LED1on==false)) digitalWrite(LED1, HIGH);
   if ((val0 < 950) &&(LED1on==false)) digitalWrite(LED1, LOW);

   if ((val1 > 950) &&(LED1on==false)) digitalWrite(LED5, HIGH);
   if ((val1 < 950) &&(LED1on==false)) digitalWrite(LED5, LOW);

   if ((val2 > 950) &&(LED2on==false)) digitalWrite(LED2, HIGH);
   if ((val2 < 950) &&(LED2on==false)) digitalWrite(LED2, LOW);

   if ((val3 > 950) &&(LED2on==false)) digitalWrite(LED6, HIGH);
   if ((val3 < 950) &&(LED2on==false)) digitalWrite(LED6, LOW);

   if ((val4 > 950) &&(LED3on==false)) digitalWrite(LED3, HIGH);
   if ((val4 < 950) &&(LED3on==false)) digitalWrite(LED3, LOW);

   if ((val5 > 950) &&(LED3on==false)) digitalWrite(LED7, HIGH);
   if ((val5 < 950) &&(LED3on==false)) digitalWrite(LED7, LOW);

   if ((val6 > 950) &&(LED4on==false)) digitalWrite(LED4, HIGH);
   if ((val6 < 950) &&(LED4on==false)) digitalWrite(LED4, LOW);

   if ((val7 > 950) &&(LED4on==false)) digitalWrite(LED8, HIGH);
   if ((val7 < 950) &&(LED4on==false)) digitalWrite(LED8, LOW);

        
}

