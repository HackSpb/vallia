#include <Servo.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(9, 10); // trig echo

Servo myservo;


void up() {
digitalWrite (3, HIGH);
digitalWrite (4, LOW); // левый вперед 

digitalWrite (6, HIGH);
digitalWrite (5, LOW); // правый вперед 
}

void down(){
  
digitalWrite (3, LOW);  // левый назад 
digitalWrite (4, HIGH) ;

digitalWrite (6, LOW);  // правый назад 
digitalWrite (5, HIGH) ;
}

void left(){
  digitalWrite (3, LOW);  // левый назад 
  digitalWrite (4, HIGH) ;

  digitalWrite (6, HIGH);
 digitalWrite (5, LOW); // правый вперед 
}

void right() {
digitalWrite (6, LOW);  // правый назад 
digitalWrite (5, HIGH) ;

digitalWrite (3, HIGH);
digitalWrite (4, LOW); // левый вперед 

}

void stopm() {

  digitalWrite (6, LOW);  
digitalWrite (5, LOW) ;

digitalWrite (3, LOW);
digitalWrite (4, LOW);  
}



 int servo_points[5] = {0, 45, 90, 135,180};

void setup() 
{
 Serial.begin(9600);
  myservo.attach(8);
 // input1 pin 3
 // input 2 pin 4
 //  input 3 pin 5
 // input 4 pin 6
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);

  

}


void loop() 

// 550 - 90 градусов
{
int rast [5];
int rast_max = 0;
int pos ;
for ( int i = 0; i < 6 ; i++ )
{
   myservo.write(servo_points[i]);
   delay(400);
   rast[i] = ultrasonic.Ranging(CM);
   
   Serial.println(rast[i]);

 }

 for ( int i = 0; i < 6 ; i++ )
   {
    if (rast[i] > rast_max )
    {
       rast_max = rast[i];
       pos = servo_points[i];
    }
   }
  Serial.print("rast_max");
  Serial.println(rast_max);
  Serial.print("pos");
  Serial.println(pos);

if (pos = 0) 
{
  left();
  delay(650);
  stopm();
    Serial.println("go left 90");
}
if (pos = 45) 
{
  left();
  delay(325);
  stopm();
   Serial.println("go left 45");
}

if (pos = 135) 
{
  right();
  delay(325);
  stopm();
   Serial.println("go right 45");
}
if (pos = 180) 
{
  right();
  delay(650);
  stopm();
   Serial.println("go right 90");
}


myservo.write(90);
delay(1000);



}
