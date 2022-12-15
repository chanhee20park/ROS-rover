
#define pwm      12 // PWM output pin D9
#define dir      6 // Motor direction pin D3

int x = 0;
int xPos = 0;
int pwm_value = 0;

void setup(){
 
  
  // Define Pins
  TCCR2B = TCCR2B & B11111000 | B00000001; // for PWM frequency of 3921.16 Hz for pin 9 and 10
  pinMode(pwm,OUTPUT);
  pinMode(dir,OUTPUT); 
 
}

void loop(){

/*
maps value -255 to 255 for pwm usage
if positive then rotate right
*/


  x = analogRead(A0);
  xPos = map(x,0,1023,-255,255);
  delay(200);


  if(xPos>0){
    digitalWrite(dir,HIGH);
    
  }else{
    digitalWrite(dir,LOW);
  }
  delay(200);

  analogWrite(pwm,abs(pwm_value));

  Serial.print("X:");
  Serial.println(x); 

}