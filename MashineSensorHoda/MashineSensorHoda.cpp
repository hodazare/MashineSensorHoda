/*
This program will take input from a sensor, 
control a motor and read the value of a door latch. The state machine will need to first calibrate the sensor, 
read data, and move the motor to a position that is the average of the data received, unless the door is open.

*/
#include <iostream>
#include <ctime>
#include <stdlib.h>     /* srand, rand */

using namespace std;
const int length = 10;
int data[length]; 

class CSensor

{

public:

  bool Calibrate(); // calibrates the sensor
  bool Calibrate(int data[]); // calibrates the sensor

  void CreateData(); // We don't have sensor here. Therefore, this function creates the random data

  int ReadData(int data[]); // Reads the data from the sensor and return the average
  
  void waiting(); // To have a delay between the entrance of the data to the sensor

};


class CMotor

{

public:
  int MotorPosition;
  
  void ResetMotor(); // moves motor to the starting position

  void MoveMotor(int distance); // Moves motor to the measurement position

};
class CLatchDoor

{

public:
  bool IsOpen;

  void CloseDoor(); // close the door

  void OpenDoor(); // open the door

};

/* Functions of CSensor class */

bool CSensor::Calibrate() {

	bool currentState = true;
	return currentState;
}

bool CSensor::Calibrate(int data[]) {

	int Min = 100;
	int Max = 200;

/* It is checked whether the data is in the range (between Min and Max) or not. 
If not, the data will be set to be in this range.*/
	
	for ( int i = 0; i < length; ++i)
	{ 
		if (data[i] < Min || data[i] > Max)
			data[i] = data[i] % 100 + 100;
	}
	bool currentState = true;
	return currentState;
}

int CSensor::ReadData(int data[]) {
	
	int result = 0;
	
	for ( int i=0 ; i<length; i++ )
	{
		result += data[i];
	}
	
	return result/length;

}
void CSensor::CreateData() {
	/* set the seed */
  srand( (unsigned)time( NULL ) );

  for ( int i = 0; i < length; ++i)
  {
     data[i] = rand();
  }
}

/* A cross-platform wait a second */
void CSensor::waiting() {
    time_t time_current = time(NULL);
    while ( time(NULL) <= time_current+1 );
}

/* Functions of CMotor class */
void CMotor::ResetMotor() {
	MotorPosition = 0;
}
void CMotor::MoveMotor(int distance) {
	MotorPosition = distance;	
}

/* Functions of CLatchDoor */
void CLatchDoor::CloseDoor() {
	IsOpen = false;
}
void CLatchDoor::OpenDoor() {
	IsOpen = true;
}

int main () {
	
	int distance = 0;	
	CSensor Csensor1;
	CMotor Cmotor1;
	CLatchDoor CLatchDoor1;
	
	Cmotor1.ResetMotor();
	CLatchDoor1.CloseDoor();
	cout << "The door is closed until the average data of the sensor becomes more than 160..." << endl;
	cout << "The first position of the motor is:  " << Cmotor1.MotorPosition << endl;
		
	do 
	{
		Csensor1.CreateData();
		bool b = Csensor1.Calibrate(data);
		Csensor1.waiting();
		distance = Csensor1.ReadData(data);	
		if (distance <= 160)
			Cmotor1.MoveMotor(distance);
		else 
		{
			cout << "The average data of the sensor is:  " << distance << endl;
			CLatchDoor1.OpenDoor();
		}		
		
		cout << "The current position of the motor is:  " << Cmotor1.MotorPosition << endl;
	
	if (!CLatchDoor1.IsOpen)
		cout << "The door is closed " << endl;
	else
		cout << "The door is open " << endl;		
		
	} while (!CLatchDoor1.IsOpen);
	return 0;
}
