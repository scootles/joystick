#define UP A0
#define DOWN A3
#define LEFT A2
#define RIGHT A1
#define BUTT1 A4
#define BUTT2 A5

#define PAN 3
#define TILT 9

#include <Servo.h>

Servo pan;
Servo tilt;

int pan_val = 90;
int tilt_val = 90;

void setup()
{
	//joystick stuff
	Serial.begin(9600);
	Serial.println("started");
	pinMode(UP,INPUT);
	pinMode(DOWN,INPUT);
	pinMode(LEFT,INPUT);
	pinMode(RIGHT,INPUT);
	pinMode(BUTT1,INPUT);
	pinMode(BUTT2,INPUT);
	digitalWrite(UP,HIGH);
	digitalWrite(DOWN,HIGH);
	digitalWrite(LEFT,HIGH);
	digitalWrite(RIGHT,HIGH);
	digitalWrite(BUTT1,HIGH);
	digitalWrite(BUTT2,HIGH);

	//servos
	pan.attach(PAN);
	tilt.attach(TILT);

	pan.write(pan_val);
	tilt.write(tilt_val);
}

void loop()
{
	//buttons
	if(digitalRead(BUTT1)==LOW)
		Serial.println("butt1");
	if(digitalRead(BUTT2)==LOW)
		Serial.println("butt2");

	//joystick
	if(digitalRead(UP)==HIGH)
		tilt_val += 1;
	if(digitalRead(DOWN)==HIGH)
		tilt_val -= 1;
	if(digitalRead(LEFT)==HIGH)
		pan_val += 1;
	if(digitalRead(RIGHT)==HIGH)
		pan_val -= 1;

	//limits
	if(tilt_val>180)
		tilt_val = 180;
	if(tilt_val<0)
		tilt_val = 0;
	if(pan_val>180)
		pan_val = 180;
	if(pan_val<0)
		pan_val = 0;

	//write the values to the servos
	pan.write(pan_val);
	tilt.write(tilt_val);

	//debug
	/*
	Serial.print("pan:");
	Serial.println(pan_val);
	Serial.print("tilt:");
	Serial.println(tilt_val);
	*/

	//wait a bit to stop things happening too fast
	delay(10);
}
