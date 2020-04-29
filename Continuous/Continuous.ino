/*
This example shows how to take simple range measurements with the VL53L1X. The
range readings are in units of mm.
*/

#include <Wire.h>
#include <VL53L1X.h>

VL53L1X sensor;
VL53L1X sensor2;

void setup()
{
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(2, LOW);  
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(1000);
  
  digitalWrite(3,HIGH);
  delay(150);
  sensor2.init(true);
  Serial.println("Setting address for Sensor 2");
  delay(100);
  sensor2.setAddress(0x31);
  Serial.println("Set address for Sensor 2");
  delay(100);

  Serial.begin(115200);
  Wire.begin();
  Wire.beginTransmission(0x31);
  Wire.setClock(400000); // use 400 kHz I2C

  sensor2.setTimeout(1000);
  if (!sensor2.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1);
  }
  
  // Use long distance mode and allow up to 50000 us (50 ms) for a measurement.
  // You can change these settings to adjust the performance of the sensor, but
  // the minimum timing budget is 20 ms for short distance mode and 33 ms for
  // medium and long distance modes. See the VL53L1X datasheet for more
  // information on range and timing limits.
  sensor2.setDistanceMode(VL53L1X::Long);
  sensor2.setMeasurementTimingBudget(50000);

  // Start continuous readings at a rate of one measurement every 50 ms (the
  // inter-measurement period). This period should be at least as long as the
  // timing budget.
  sensor2.startContinuous(50);
}

void loop()
{
  Serial.print(sensor.read());
  if (sensor2.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
}
