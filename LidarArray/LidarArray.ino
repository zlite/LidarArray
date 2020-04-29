
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
#define Sensor6_newAddress 55
#define Sensor6_newAddress 57

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
 
  Serial.begin(9600);
 
  Wire.begin();
  Wire.setClock(100000);


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
  Sensor7.setAddress(Sensor6_newAddress);

  pinMode(XSHUT_pin8, INPUT);
     if (!Sensor8.init())
  {
    Serial.println("Failed to detect and initialize sensor8!");
    while (1);
  }
  delay(10);
  Sensor8.setAddress(Sensor6_newAddress);

 
  Sensor1.setTimeout(500);
  Sensor2.setTimeout(500);
  Sensor3.setTimeout(500);
  Sensor4.setTimeout(500);
  Sensor5.setTimeout(500);
  Sensor6.setTimeout(500);
  Sensor7.setTimeout(500);
  Sensor8.setTimeout(500);


 
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
{
   Sensor1.startContinuous(200);
   Sensor1.read();
   Sensor1.stopContinuous();
   long time1 = millis();
   Sensor2.startContinuous(200);
   Sensor2.read();
   Sensor2.stopContinuous();
   Sensor3.startContinuous(200);
   Sensor3.read();
   Sensor3.stopContinuous();
   Sensor4.startContinuous(200);
   Sensor4.read();
   Sensor4.stopContinuous();
   Sensor5.startContinuous(200);
   Sensor5.read();
   Sensor5.stopContinuous();
   Sensor6.startContinuous(200);
   Sensor6.read();
   Sensor6.stopContinuous();
   Sensor7.startContinuous(200);
   Sensor7.read();
   Sensor7.stopContinuous();
   Sensor8.startContinuous(200);
   Sensor8.read();
   Sensor8.stopContinuous();

   long time2 = millis();
   
   
  Serial.print("Sensor 1 Range: ");
  Serial.print(Sensor1.ranging_data.range_mm);
  Serial.println(" ");
  Serial.print("Sensor 2 Range: ");
  Serial.print(Sensor2.ranging_data.range_mm);
  Serial.println(" ");
  Serial.print("Sensor 3 Range: ");
  Serial.print(Sensor3.ranging_data.range_mm);
  Serial.println(" ");
  Serial.print("Sensor 4 Range: ");
  Serial.print(Sensor4.ranging_data.range_mm);
  Serial.println(" ");
  Serial.print("Sensor 5 Range: ");
  Serial.print(Sensor5.ranging_data.range_mm);
  Serial.println(" ");
  Serial.print("Sensor 6 Range: ");
  Serial.print(Sensor6.ranging_data.range_mm);
  Serial.println(" ");
  Serial.print("Sensor 7 Range: ");
  Serial.print(Sensor7.ranging_data.range_mm);
  Serial.println(" ");
  Serial.print("Sensor 8 Range: ");
  Serial.print(Sensor8.ranging_data.range_mm);
  Serial.println(" ");
  Serial.println();
}
