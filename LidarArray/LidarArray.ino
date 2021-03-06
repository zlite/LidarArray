// Modified code by Chris Anderson
// Orginal found here: https://forum.arduino.cc/index.php?topic=594762.msg4042641#msg4042641


#include <Wire.h>
#include <VL53L1X.h>

#define XSHUT_pin1 2
#define XSHUT_pin2 3
#define XSHUT_pin3 4
#define XSHUT_pin4 5
#define XSHUT_pin5 6
#define XSHUT_pin6 7
#define XSHUT_pin7 8
#define XSHUT_pin8 9

//ADDRESS_DEFAULT 0b0101001 or 41
#define Sensor1_newAddress 43
#define Sensor2_newAddress 45
#define Sensor3_newAddress 47
#define Sensor4_newAddress 49
#define Sensor5_newAddress 51
#define Sensor6_newAddress 53
#define Sensor7_newAddress 55
#define Sensor8_newAddress 57

VL53L1X Sensor1;
VL53L1X Sensor2;
VL53L1X Sensor3;
VL53L1X Sensor4;
VL53L1X Sensor5;
VL53L1X Sensor6;
VL53L1X Sensor7;
VL53L1X Sensor8;


void setup()
{

  pinMode(XSHUT_pin1, OUTPUT);
  pinMode(XSHUT_pin2, OUTPUT);
  pinMode(XSHUT_pin3, OUTPUT);
  pinMode(XSHUT_pin4, OUTPUT);
  pinMode(XSHUT_pin5, OUTPUT);
  pinMode(XSHUT_pin6, OUTPUT);
  pinMode(XSHUT_pin7, OUTPUT);
  pinMode(XSHUT_pin8, OUTPUT);
 
  Serial.begin(115200);
 
  Wire.begin();
  Wire.setClock(400000);


  pinMode(XSHUT_pin1, INPUT);
     if (!Sensor1.init())
  {
    Serial.println("Failed to detect and initialize sensor1!");
    while (1);
  }
  delay(10);
  Sensor1.setAddress(Sensor1_newAddress);

 pinMode(XSHUT_pin2, INPUT);
     if (!Sensor2.init())
  {
    Serial.println("Failed to detect and initialize sensor2!");
    while (1);
  }
  delay(10);
  Sensor2.setAddress(Sensor2_newAddress);
 
  pinMode(XSHUT_pin3, INPUT);
     if (!Sensor3.init())
  {
    Serial.println("Failed to detect and initialize sensor3!");
    while (1);
  }
  delay(10);
  Sensor3.setAddress(Sensor3_newAddress);

   pinMode(XSHUT_pin4, INPUT);
     if (!Sensor4.init())
  {
    Serial.println("Failed to detect and initialize sensor4!");
    while (1);
  }
  delay(10);
  Sensor4.setAddress(Sensor4_newAddress);

  pinMode(XSHUT_pin5, INPUT);
     if (!Sensor5.init())
  {
    Serial.println("Failed to detect and initialize sensor5!");
    while (1);
  }
  delay(10);
  Sensor5.setAddress(Sensor5_newAddress);

  pinMode(XSHUT_pin6, INPUT);
     if (!Sensor6.init())
  {
    Serial.println("Failed to detect and initialize sensor6!");
    while (1);
  }
  delay(10);
  Sensor6.setAddress(Sensor6_newAddress);

  pinMode(XSHUT_pin7, INPUT);
     if (!Sensor7.init())
  {
    Serial.println("Failed to detect and initialize sensor7!");
    while (1);
  }
  delay(10);
  Sensor7.setAddress(Sensor7_newAddress);

  pinMode(XSHUT_pin8, INPUT);
     if (!Sensor8.init())
  {
    Serial.println("Failed to detect and initialize sensor8!");
    while (1);
  }
  delay(10);
  Sensor8.setAddress(Sensor8_newAddress);
 
  Sensor1.setTimeout(100);
  Sensor2.setTimeout(100);
  Sensor3.setTimeout(100);
  Sensor4.setTimeout(100);
  Sensor5.setTimeout(100);
  Sensor6.setTimeout(100);
  Sensor7.setTimeout(100);
  Sensor8.setTimeout(100);


 
  Sensor1.setDistanceMode(VL53L1X::Medium);
  Sensor1.setMeasurementTimingBudget(33000);
  Sensor2.setDistanceMode(VL53L1X::Medium);
  Sensor2.setMeasurementTimingBudget(33000);
  Sensor3.setDistanceMode(VL53L1X::Medium);
  Sensor3.setMeasurementTimingBudget(33000);
  Sensor4.setDistanceMode(VL53L1X::Medium);
  Sensor4.setMeasurementTimingBudget(33000);
  Sensor5.setDistanceMode(VL53L1X::Medium);
  Sensor5.setMeasurementTimingBudget(33000);
  Sensor6.setDistanceMode(VL53L1X::Medium);
  Sensor6.setMeasurementTimingBudget(33000);
  Sensor7.setDistanceMode(VL53L1X::Medium);
  Sensor7.setMeasurementTimingBudget(33000);
  Sensor8.setDistanceMode(VL53L1X::Medium);
  Sensor8.setMeasurementTimingBudget(33000);

}

void loop()
{    // This is an effort to group sensor pulsing and reads in ways that they don't interfere with each other. So this is two groups of three and one of two, all seperated by at least two sensors. 
     // I've tried doing the evens and the odds in two batches but it didn't work :-(
   long time1 = millis();
   Sensor1.startContinuous(100);
   Sensor8.startContinuous(100);
   Sensor4.startContinuous(100);
   Sensor1.read();
   Sensor8.read();
   Sensor4.read();
   Sensor1.stopContinuous();
   Sensor8.stopContinuous();
   Sensor4.stopContinuous();

   Sensor2.startContinuous(100);
   Sensor7.startContinuous(100);
   Sensor5.startContinuous(100);
   Sensor2.read();
   Sensor7.read();
   Sensor5.read();
   Sensor2.stopContinuous();
   Sensor7.stopContinuous();
   Sensor5.stopContinuous();


   Sensor3.startContinuous(100);
   Sensor6.startContinuous(100);
   Sensor3.read();
   Sensor6.read();
   Sensor3.stopContinuous();
   Sensor6.stopContinuous();
   long time2 = millis();


 if (Sensor1.ranging_data.range_mm > 1200) {Sensor1.ranging_data.range_mm = 0;} 
 if (Sensor2.ranging_data.range_mm > 1200) {Sensor2.ranging_data.range_mm = 0;} 
 if (Sensor3.ranging_data.range_mm > 1200) {Sensor3.ranging_data.range_mm = 0;} 
 if (Sensor4.ranging_data.range_mm > 1200) {Sensor4.ranging_data.range_mm = 0;} 
 if (Sensor5.ranging_data.range_mm > 1200) {Sensor5.ranging_data.range_mm = 0;} 
 if (Sensor6.ranging_data.range_mm > 1200) {Sensor6.ranging_data.range_mm = 0;} 
 if (Sensor7.ranging_data.range_mm > 1200) {Sensor7.ranging_data.range_mm = 0;} 
 if (Sensor8.ranging_data.range_mm > 1200) {Sensor8.ranging_data.range_mm = 0;} 
   
  Serial.print("Sensor1:");
  Serial.print(Sensor1.ranging_data.range_mm);
  Serial.print(",");
  Serial.print("Sensor2:");
  Serial.print(Sensor2.ranging_data.range_mm);
  Serial.print(",");
  Serial.print("Sensor3:");
  Serial.print(Sensor3.ranging_data.range_mm);
  Serial.print(",");
  Serial.print("Sensor4:");
  Serial.print(Sensor4.ranging_data.range_mm);
  Serial.print(",");
  Serial.print("Sensor5:");
  Serial.print(Sensor5.ranging_data.range_mm);
  Serial.print(",");
  Serial.print("Sensor6:");
  Serial.print(Sensor6.ranging_data.range_mm);
  Serial.print(",");
  Serial.print("Sensor7:");
  Serial.print(Sensor7.ranging_data.range_mm);
  Serial.print(",");
  Serial.print("Sensor8:");
  Serial.println(Sensor8.ranging_data.range_mm);
//  Serial.print("Time per scan: ");
//  Serial.println(time2-time1);
//  Serial.print(" ");  
//  Serial.println("uT");
  
}
