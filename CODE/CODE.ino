const int lMotFwd=9; 
const int rMotFwd=10;
const int lMotRev=11;
const int rMotRev=12; 

const int voltL=0;
const int voltM=1;
const int voltR=2;

const int triggerL = 3; //Trigger pin of LEFT Sesnor
const int echoL = 4; //Echo pin of 1st Sesnor
const int triggerM = 5; //Trigger pin of MIDDLE Sesnor
const int echoM = 6;//Echo pin of 2nd Sesnor
const int triggerR = 7; //Trigger pin of RIGHT Sesnor
const int echoR = 8; //Echo pin of 1st Sesnor

const int criticalDistance = 100;  // distance that tell there is a wall
int leftDistance;
int rightDistance;
int forwardDistance;


void setup() {


  Serial.begin(9600);


  pinMode(voltL,OUTPUT);   
  pinMode(voltL,OUTPUT);   
  pinMode(voltrM,OUTPUT);   
  
  
  pinMode(triggerL,OUTPUT);   
  pinMode(echoL,OUTPUT);   
  pinMode(triggerM,OUTPUT);   
  pinMode(echoM,OUTPUT);   
  pinMode(triggerR,OUTPUT);   
  pinMode(echoR,OUTPUT); 

  pinMode(lMotFwd,OUTPUT); 
  pinMode(rMotFwd,OUTPUT);
  pinMode(lMotRev,OUTPUT);  
  pinMode(rMotRev,OUTPUT); 

  applyVoltageToSensors();
}

void  applyVoltageToSensors(){
  digitalWrite(voltL,HIGH);
  digitalWrite(voltR,HIGH);
  digitalWrite(voltM,HIGH);
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

//if (dist>50 && dist<60)
//dist = 50;

return dist;
}

void loop() {
  // put your main code here, to run repeatedly:
  leftDistance=calculate_distance(triggerL,echoL);
  rightDistance=calculate_distance(triggerR,echoR);
  forwardDistance=calculate_distance(triggerM,echoM);

  Stop();
  
  if(leftDistance>criticalDistance){
    turnLeft();
  }else{


      if(forwardDistance>criticalDistance){
        moveForward();
      }else{

        if(rightDistance>criticalDistnce){
          turnRight();
        }
       
      }
    
  }
  
  if(forwardDistance<criticalDistance && leftDistance<criticalDistance && rightDistance<criticalDistance){
    turnCircle();
  }

}
