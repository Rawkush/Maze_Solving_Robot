const int lMotFwd=9; 
const int rMotFwd=10;
const int lMotRev=11;
const int rMotRev=12; 

const int volt=8;
const int triggerL = 2; //Trigger pin of LEFT Sesnor
const int echoL = 3; //Echo pin of 1st Sesnor
const int triggerM = 4; //Trigger pin of MIDDLE Sesnor
const int echoM = 5;//Echo pin of 2nd Sesnor
const int triggerR = 6; //Trigger pin of RIGHT Sesnor
const int echoR = 7; //Echo pin of 1st Sesnor


const int criticalDistance = 100;  // distance that tell there is a wall
int leftDistance;
int rightDistance;
int forwardDistance;

void setup() {
Serial.begin(9600); 
pinMode(triggerL, OUTPUT); 
pinMode(echoL, INPUT); 
pinMode(volt,OUTPUT);
pinMode(triggerM, OUTPUT); 
pinMode(echoM, INPUT);
pinMode(triggerR, OUTPUT); 
pinMode(echoR, INPUT); 



  pinMode(lMotFwd,OUTPUT); 
  pinMode(rMotFwd,OUTPUT);
  pinMode(lMotRev,OUTPUT);  
  pinMode(rMotRev,OUTPUT); 


}


void moveForward()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,HIGH);
}

void turnLeft()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,HIGH);
}


void turnRight()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,LOW);
}

void turnCircle()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,LOW);
  digitalWrite(lMotRev,HIGH);
  digitalWrite(rMotFwd,HIGH);
}

void Stop()
{

digitalWrite(lMotFwd,LOW);
digitalWrite(rMotFwd,LOW);
digitalWrite(lMotRev,LOW);
digitalWrite(rMotRev,LOW);
  
}



/*###Function to calculate distance###*/ 
int calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
int time_taken = pulseIn(echo, HIGH);
int dist= time_taken*0.034/2;
return dist;
}

void loop() {
  
  // put your main code here, to run repeatedly:
  
  leftDistance=calculate_distance(triggerL,echoL);
  rightDistance=calculate_distance(triggerR,echoR);
  forwardDistance=calculate_distance(triggerM,echoM);
  Serial.print(leftDistance);
  Serial.print("\t"); 
  Serial.print(leftDistance); 
  Serial.print("\t");
  Serial.println(leftDistance); 

}
