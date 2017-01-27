

int val;
int LED = 13;

void setup()

{
Serial.begin(9600);
pinMode(LED, OUTPUT);

}
void loop()
{
if (Serial.available())
{
val = Serial.read();

// При символе "W" включаем светодиод
if (val == 'W')
{
digitalWrite(LED, HIGH);
}

// При символе "S" выключаем светодиод
if ( val == 'S')
{
digitalWrite(LED, LOW);
}

}
}

