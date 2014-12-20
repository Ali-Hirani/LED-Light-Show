int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;

void setup()
{    
  //initialize the led pins as an outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop()
{
  blinkAll(led1, led2, led3, led4);
  delay(100);
  blinkAll(led4, led3, led2, led1);
  delay(100);
  
  allOn(led1, led2, led3, led4);
  delay(100);
  allOff(led1, led2, led3, led4);
  delay(100);
  allOn(led1, led2, led3, led4);
  delay(100);
  allOff(led1, led2, led3, led4);
  delay(100);

  fadeInAll(led2, led4, led1, led3);
  fadeOutAll(led4, led1, led3, led2);

  blinkAll(led1, led2, led3, led4);
  delay(100);
  blinkAll(led4, led3, led2, led1);
  delay(100);
}

void blink(int led)
{
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led, LOW);
}

void blinkAll(int led1, int led2, int led3, int led4)
{
  blink(led1);
  blink(led2);
  blink(led3);
  blink(led4);
}

void allOn(int led1, int led2, int led3, int led4)
{
  digitalWrite(led1, HIGH); 
  digitalWrite(led2, HIGH); 
  digitalWrite(led3, HIGH); 
  digitalWrite(led4, HIGH); 
}

void allOff(int led1, int led2, int led3, int led4)
{
  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW); 
  digitalWrite(led3, LOW); 
  digitalWrite(led4, LOW); 
}

void fadeIn(int led)
{
  int brightness = 0;
  int fadeAmount = 5;

  while(brightness != 255)
  {
    // set the brightness of pin 9:
    analogWrite(led, brightness);    

    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;

    // wait for 10 milliseconds    
    delay(10);                            
  }
}

void fadeOut(int led)
{
  int brightness = 255;
  int fadeAmount = 5;

  while(brightness != 0)
  {
    analogWrite(led, brightness);

    brightness = brightness - fadeAmount;

    delay(10);
  }
}

void fadeInAll(int led1, int led2, int led3, int led4)
{
  fadeIn(led1);
  fadeIn(led2);
  fadeIn(led3);
  fadeIn(led4);
}

void fadeOutAll(int led1, int led2, int led3, int led4)
{
  fadeOut(led1);
  digitalWrite(led1, LOW);
  fadeOut(led2);
  digitalWrite(led2, LOW);
  fadeOut(led3);
  digitalWrite(led3, LOW);
  fadeOut(led4);
  digitalWrite(led4, LOW);
}