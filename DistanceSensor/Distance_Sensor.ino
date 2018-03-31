#define led1 5
#define led2 6
#define irr1 19
#define irr2 17
const int nSamples = 100;
long zero1;
long zero2;
int val1;
int val2;
int ir1;
int ir2;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(irr1, INPUT);//recievers are input
  pinMode(irr2, INPUT);
  for(int i=0; i<nSamples; i++)
  {
    zero1 += analogRead(irr1);
    zero2 += analogRead(irr2);
  }
  zero1 /= nSamples;
  zero2 /= nSamples;
  pinMode(led1, OUTPUT);//output light intensity based on irr
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ir1 = analogRead(irr1);
  if(ir1>zero1){ir1=zero1;}
  
  ir2 = analogRead(irr2);
  if(ir2>zero2){ir2=zero2;}
  
  val1 = map(ir1, 0, zero1, 255, 0);
  
  val2 = map(ir2, 0, zero2, 255, 0);

  analogWrite(led1, val1);
  analogWrite(led2, val2);
}
