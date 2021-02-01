//Arduino Mega Micrcontroller
//1/26/20201
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
//Out to relay
#define ENABLE 5

//Seconds for take-up to sleep no matter the slack
#define MIN_SLEEP_SECONDS 8
//Limit on total seconds to run regardless of the slack
#define MAX_RUNNING_SECONDS 5
//slack distance from sensor in centimeters
#define SLACK_DISTANCE_THRESHOLD 110


SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long slackDistance;
long sleepSeconds;
long runningSeconds;


void setup() {
   pinMode(ENABLE,OUTPUT);
   Serial.begin(9600);
   delay(1000);
}

void loop() {
  
   slackDistance = sr04.Distance();

   //information to terminal
   Serial.print(slackDistance);
   Serial.println("cm");
   
   if ( slackDistance < SLACK_DISTANCE_THRESHOLD && runningSeconds < MAX_RUNNING_SECONDS){
    runningSeconds = runningSeconds + 1;
    //take-up slack
    Serial.println("Take-up RUNNING");
    digitalWrite(ENABLE,HIGH); // trigger relay to turn on voltage to halt circuit
   }else{
    sleepSeconds = sleepSeconds + 1;
    if(sleepSeconds < MIN_SLEEP_SECONDS){
      //stop slack take-up
      Serial.println("Take-up STOPPED");
      digitalWrite(ENABLE,LOW); // trigger relay to turn off voltage to halt circuit
    }else{
      Serial.println("Take-up counters reset");
      sleepSeconds = 0;
      runningSeconds = 0;
    }
   }
   //read every second
   delay(1000);
   Serial.println("      ");

}
