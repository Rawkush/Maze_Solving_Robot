
const int triggerL = 2; //left
const int echoL = 3; // left
const int triggerM = 4; //middle
const int echoM = 5;// middle
const int triggerR = 6; //Right
const int echoR = 7;//  Right

const int volt=8; // for sensor 
int vo=13;
const int lMotFwd=9; 
const int rMotFwd=10;
const int lMotRev=11;
const int rMotRev=12; 

const int criticalDistance=10; //critical distance
const int touch=5;

long time_taken;
long distM,distL,distR;

 

void setup() {
Serial.begin(9600); 
pinMode(triggerL, OUTPUT); 
pinMode(echoL, INPUT); 
pinMode(volt,OUTPUT);
pinMode(vo,OUTPUT);
pinMode(triggerM, OUTPUT); 
pinMode(echoM, INPUT);
pinMode(triggerR, OUTPUT); 
pinMode(echoR, INPUT); 



  pinMode(lMotFwd,OUTPUT); 
  pinMode(rMotFwd,OUTPUT);
  pinMode(lMotRev,OUTPUT);  
  pinMode(rMotRev,OUTPUT); 


}

/*###Function to calculate distance###*/
int calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);
int dist= time_taken*0.034/2;
return dist;
}



void reverse()
{
  digitalWrite(lMotRev,HIGH);
  digitalWrite(rMotRev,HIGH);
  
}
void moveForward()
{
  digitalWrite(lMotFwd,HIGH);
  digitalWrite(rMotFwd,HIGH);
  
digitalWrite(lMotRev,LOW);
digitalWrite(rMotRev,LOW);
}

void turnLeft()
{
  digitalWrite(lMotFwd,LOW);
  digitalWrite(rMotFwd,HIGH);
  
digitalWrite(lMotRev,LOW);
digitalWrite(rMotRev,LOW);
}


void turnRight()
{
  digitalWrite(lMotFwd,HIGH);
digitalWrite(rMotFwd,LOW);
digitalWrite(lMotRev,LOW);
digitalWrite(rMotRev,LOW);}

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











void loop(){

digitalWrite(8,HIGH); // volatege to sensor
digitalWrite(vo,HIGH); // volatege to sensor


distL= calculate_distance(triggerL,echoL);
Serial.print(distL);
 
distM= calculate_distance(triggerM,echoM);
Serial.print("\t");
 Serial.print(distM);
distR= calculate_distance(triggerR,echoR);
Serial.print("\t");
 Serial.println(distR);


 if(distM>12){
  moveForward();
 }else{

  if(distM<12){

    if(distL>12){
      turnLeft();
    }else{
      if(distR>12){
        turnRight();
      }else{



        if(distL<12&&distR<12){
          turnCircle();
        }
      }

      
    }

      


    
  }

  
 }

 

}
