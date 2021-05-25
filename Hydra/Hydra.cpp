/*
Hydra.cpp Library for Hydra rover drive code
Zachary Sahnger, 5/18/21
*/

#include "Arduino.h"
#include "Hydra.h"

Hydra::Hydra(int IN1, int IN2, int IN3, int IN4, int ENA, int ENB) {
	//constructor
	_IN1 = IN1;
	_IN2 = IN2;
	_IN3 = IN3;
	_IN4 = IN4;
	_ENA = ENA;
	_ENB = ENB;
}
int Hydra::drive_forward_timed(int power, unsigned long t) {
	//set power level
	analogWrite(_ENA, power);
	analogWrite(_ENB, power);

	//get initial time
	unsigned long functionStartMillis = millis();

	//run motors forward
	digitalWrite(_IN1, HIGH);
	digitalWrite(_IN2, LOW);
	digitalWrite(_IN3, HIGH);
	digitalWrite(_IN4, LOW);


	while (t > (millis() - functionStartMillis)) {
		Serial.println("driving forward");
	}
	stop_motors();
	return 0;
}
int Hydra::drive_forward(int power) {
	digitalWrite(_IN1, HIGH);
	digitalWrite(_IN2, LOW);
	digitalWrite(_IN3, HIGH);
	digitalWrite(_IN4, LOW);
}
int Hydra::turn_left(int power, unsigned long t) {
	analogWrite(_ENA, power);
	analogWrite(_ENB, power);
	unsigned long functionStartMillis = millis();

	//set left motor reverse
	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, HIGH);
	//set right motor forward
	digitalWrite(_IN3, HIGH);
	digitalWrite(_IN4, LOW);

	//wait for time to elapse
	while (t > (millis() - functionStartMillis)) {
		Serial.println("turning left");
	}
	stop_motors();
}

void Hydra::stop_motors() {
	digitalWrite(_IN1, LOW);
	digitalWrite(_IN2, LOW);
	digitalWrite(_IN3, LOW);
	digitalWrite(_IN4, LOW);
	Serial.println("stopping motors");
}