#define led1 5
#define led2 6
#define button1 7
#define button2 8
#define red 9
#define blue 10
#define green 11
int num1;
int num2;
int randomNum;
int incr;
int goal;
bool state1;
bool state2;
const long interval = 1000;
unsigned long pMillis1;
unsigned long pMillis2;

void setup() {
  randomSeed(analogRead(0));
  pinMode(button1, INPUT);        //buttons are inputs
  pinMode(button2, INPUT);
  pinMode(led1, OUTPUT);          //led outputs
  pinMode(led2, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  num1 = 0;                   //counter for player 1
  num2 = 0;                   //counter for player 2
  randomNum = random(15, 30); //generate num 15-30
  incr = 255/randomNum;
  goal = randomNum*incr;
  
  pMillis1 = 0;
  pMillis2 = 0;
  Serial.begin(9600);
}

void loop() {
  
  //Check for button presses
  
  state1 = digitalRead(button1);
  state2 = digitalRead(button2);  

  
  if(state1 == HIGH && state2 == HIGH) {
    num1 = num1 + incr;
    num2 = num2 + incr;
    if (num1 >= 255)
   {
    num1 = 0; 
    delay(200); 
   }
   if(num2 >= 255)
   {
    num2 = 0;
    delay(200);
   }
    if(num1 == goal){
      pMillis1 = millis();
    }
    if(num2 == goal){
      pMillis2 = millis();
    }
    delay(200);
  }
  else if(state1 == HIGH && state2 == LOW) {
   num1 = num1 + incr;
   if (num1 >= 255)
   {
    num1 = 0; 
    delay(200); 
   }
   if(num1 == goal){
     pMillis1 = millis();
   }
   delay(200);
   
  }
  else if(state1 == LOW && state2 == HIGH) {
   num2 = num2 + incr;
   if(num2 >= 255)
   {
    num2 = 0;
    delay(200);
   }
   if(num2 == goal){
     pMillis2 = millis();
   }
   delay(200);
  }
  //else {continue;}//if(state1 == LOW && state2 == LOW) 


   
  // lights LED based on num1 & num2
  analogWrite(led1, num1);
  analogWrite(led2, num2);
  
  
  
  //cMillis = millis(); //check time again, if difference is 1sec +, light it
  if(num1 == goal){
    if(millis() - pMillis1 >= interval)
    {
      digitalWrite(red, HIGH);
      delay(10000);
    }
    
  }
  if(num2 == goal){
    if(millis() - pMillis2 >= interval)
    {
      digitalWrite(blue, HIGH);
      delay(10000);
    }
  }

}
