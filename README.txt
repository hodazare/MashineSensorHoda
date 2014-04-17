Readme file for the program: MashineSensorHoda in C++
-----------------------------------------------------
Senario
-----------
The “MashineSensorHoda” program creates random data (instead of taking input from a sensor), 
then calibrate the data (sensor), and move the motor to a position that is the average of the received data, 
unless the door is open. For calibrating the data, it is checked whether the data is in this range or not. 
For this purpose, the Min and the Max is defined in the “CSensor::Calibrate(int data[])” function 
and the following formula is used for those data that are out of range:
X = X % 100 + 100;
In the next step, the average of the data is calculated in “CSensor::ReadData(int data[])”.
After that, the motor is moved to the average position by using “Cmotor.MoveMotor(distance)” function.
The program stops working and the door becomes open when the average of the data becomes more than 160.
 
Compiling
-----------
-----------
You should be able to use almost any C++ compiler to compile MashinSensorHoda.

Linux:

g++ MashinSensorHoda.cpp MashinSensorHoda.c
You can run executable file by typing MashineSensorHoda.

Windows:

From the VS Studio CMD Prompt:
Go to ~\MashineSensorHoda and type:
cl.exe MashineSensorHoda.cpp

Now, just run the executable file that is created: "MashineSensorHoda.exe"

# Prelude

> Role models are important. <br/>
> -- Officer Alex J. Murphy / RoboCop

One thing has always bothered me as a Ruby developer - Python developers
have a great programming style reference
([PEP-8](http://www.python.org/dev/peps/pep-0008/)) and we never got
an official guide, documenting Ruby coding style and best
practices. And I do believe that style matters. I also believe that a
great hacker community, such as Ruby has, should be quite capable of
producing this coveted document.


* Use `UTF-8` as the source file encoding.
* Use two **spaces** per indentation level (aka soft tabs). No hard tabs.

  ```Ruby
  # bad - four spaces
  def some_method
      do_something
  end

  # good
  def some_method
    do_something
  end
  ```
