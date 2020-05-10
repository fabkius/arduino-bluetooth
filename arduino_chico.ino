#include <Servo.h>
//#include <NewPing.h>

//#define TRIGGER_PIN  13   // Arduino pin 13 tied to trigger pin on the ultrasonic sensor.
//#define ECHO_PIN     12   // Arduino pin 12 tied to echo pin on the ultrasonic sensor.
//#define MAX_DISTANCE 500 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm

Servo servoMotor;

char Incoming_value;      //Variable for storing Incoming_value

// Motor A
int ENA = 3;
int IN1 = 11;
int IN2 = 8;

// Motor B
int ENB = 5;
int IN3 = 7;
int IN4 = 6;

//int distance;

//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
 
 Serial.begin(9600);
        
 servoMotor.attach(9);
 
 pinMode (ENA, OUTPUT);
 pinMode (ENB, OUTPUT);
 pinMode (IN1, OUTPUT);
 pinMode (IN2, OUTPUT);
 pinMode (IN3, OUTPUT);
 pinMode (IN4, OUTPUT);
 
}
void loop(){
  /*//test servo
  ServoCenter();
  delay(1000);
  ServoLeft();
  delay(1000);
  ServoRight();
  delay(1000);
  */
  
/*if(getSonarDistance()<15){
  Stop();
  delay(5000);
}*/
  
 if(Serial.available() > 0){
    //distance = getSonarDistance();
    Incoming_value = Serial.read();      //Read the incoming data and store it into variable Incoming_value
    //Serial.print(Incoming_value);        //Print Value of Incoming_value in Serial monitor
    //Serial.print("\n");        //New line 
      
      if(Incoming_value == '1'){
        ServoCenter();
          Up();
      }

      if(Incoming_value == '2'){
        ServoCenter();
        Down();
      }

      if(Incoming_value == '4'){
        ServoRight();
        Right();
      }

       if(Incoming_value == '3'){
        ServoLeft();
        Left(); 
      }

      if(Incoming_value == '0'){
        Stop(); 
      }


      /*if(Incoming_value == 's'){
        Serial.write(getSonarDistance());
      }*/

      // ******* ini manual servo *******
      if(Incoming_value == 'l'){
        ServoLeft();
      }

      if(Incoming_value == 'c'){
        ServoCenter();
      }

      if(Incoming_value == 'r'){
        ServoRight();
      }
     // ******* fin manual servo *******
    
  }   
  
}


void ServoCenter(){
  servoMotor.write(90);
}

void ServoLeft(){
  servoMotor.write(0);
}

void ServoRight(){
  servoMotor.write(180);
}

void Up(){
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 255); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 255); //Velocidad motor B
}

void Down(){
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 255); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 255); //Velocidad motor B
}

void Right(){
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 200); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, 0); //Velocidad motor A
}

void Left(){
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, 0); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 200); //Velocidad motor A
}

void Stop(){
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, 0); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 0); //Velocidad motor A
}

/*int getSonarDistance(){
  int cm = sonar.ping_cm();
  Serial.print(cm);
  Serial.print("\n");
  return cm;
}*/
