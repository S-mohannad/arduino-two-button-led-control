void setup() {
pinMode(7,INPUT_PULLUP);
pinMode(8,INPUT_PULLUP);
pinMode(2,OUTPUT);
digitalWrite(2,LOW);
}
void loop() {
if(digitalRead(7)==0&&digitalRead(8)==1)
{digitalWrite(2,HIGH);}
if(digitalRead(7)==1&&digitalRead(8)==0)
{digitalWrite(2,LOW);}
}
