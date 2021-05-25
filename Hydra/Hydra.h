#ifndef Hydra_h
#define Hydra_h

#include "Arduino.h" //give access to arduino types and constants

class Hydra
{
public:
	Hydra(int IN1, int IN2, int IN3, int IN4, int ENA, int ENB);
	int drive_forward_timed(int power, unsigned long t);
	int drive_forward(int power);
	int turn_left(int power, unsigned long t);
	void stop_motors();
private:
	int _IN1;
	int _IN2;
	int _IN3;
	int _IN4;
	int _ENA;
	int _ENB;
};
#endif