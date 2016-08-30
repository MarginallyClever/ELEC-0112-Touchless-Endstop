// Touchless 3D printer endstop example code
// 2016-08-30 Lingkang Zhang <lingkangzhang@gmail.com>
// www.marginallyclever.com

// Connect sensor pin S pin to Arduino pin 9.
// Connect sensor pin V pin to Arduino pin 5v.
// Connect sensor pin G pin to Arduino pin GND.


int LED_PIN = 13;
int IR_PIN = 9;


void setup() {
  // start serial 
  Serial.begin(9600);
  // get ready to blink the light
  pinMode(LED_PIN, OUTPUT);
  // get ready to read the sensor
  pinMode(IR_PIN,INPUT);
}


void loop() {
  // read the sensor
  int sensorReading = digitalRead(IR_PIN);
  
  // print the sensor reading to the serial window
  Serial.println(sensorReading);

  // when sensorReading is zero there is nothing in the way.
  digitalWrite(LED_PIN, (sensorReading>0) ? HIGH : LOW);
}
