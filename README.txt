Readme file for the program: MashineSensorHoda in C++
-----------------------------------------------------
The “MashineSensor” program creates random data (instead of taking input from a sensor), 
then calibrate the data (sensor), and move the motor to a position that is the average of the data received, 
unless the door is open. For calibrating the data, it is checked whether the data is in this range or not. 
For this purpose, the Min and the Max is defined in the “CSensor::Calibrate(int data[])” function 
and the following formula is used for those data that are out of range:
X = X % 100 + 100;
In the next step, the average of the data is calculated in “CSensor::ReadData(int data[])”.
After that, the motor is moved to the average position by using “Cmotor1.MoveMotor(distance)”
The program stops working and the door becomes open when the average of the data becomes more than 160.
 

