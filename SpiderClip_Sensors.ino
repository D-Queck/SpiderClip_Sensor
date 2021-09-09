
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <SparkFun_Bio_Sensor_Hub_Library.h>
#include <Wire.h>

// Reset pin, MFIO pin
int resPin = 4;
int mfioPin = 5;


SparkFun_Bio_Sensor_Hub bioHub(resPin, mfioPin); 

bioData body;  
Adafruit_MPU6050 mpu;
int steps=0;
void setup(){
mpu.begin();
  Serial1.begin(9600);

  Wire.begin();
  int result = bioHub.begin();
int error = bioHub.configBpm(MODE_TWO);
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  

  delay(100);
}

void loop(){
body = bioHub.readBpm();

sensors_event_t a, g, temp;
mpu.getEvent(&a, &g, &temp);
float totalacc = sqrt(((a.acceleration.x) * (a.acceleration.x)) + ((a.acceleration.y) * (a.acceleration.y)) + ((a.acceleration.z) * (a.acceleration.z)));
if (totalacc>10.4)
{
  steps++;
}
Serial1.print("{");

Serial1.print("\"b\":");
Serial1.print(body.heartRate);
Serial1.print(",");
Serial1.print("\"c\":");
Serial1.print(body.confidence);
Serial1.print(",");
Serial1.print("\"o\":");
Serial1.print(body.oxygen);
Serial1.print(",");
Serial1.print("\"steps\":");
Serial1.print(steps);
Serial1.print(",");

Serial1.print("\"ax\":");
Serial1.print(a.acceleration.x);
Serial1.print(",");

Serial1.print("\"ay\":");
Serial1.print(a.acceleration.y);
Serial1.print(",");

Serial1.print("\"az\":");
Serial1.print(a.acceleration.z);
Serial1.print(",");

Serial1.print("\"temp\":");
Serial1.print(temp.temperature);



Serial1.println("}");






    
    delay(250); 
}
