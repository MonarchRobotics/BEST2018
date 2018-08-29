//which port on the robot we            Name of the motor. 
//plug it in. It is important           You can name this whatever 
//to put the driving motors             you want and it is used 
//on opposite sides to provide          later to control the motors
//enough power          ↓                   ↓                                               
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, reversed)
#pragma config(Motor,  port9,           leftMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           smallMotor,   tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           servo,        tmotorServoStandard, openLoop)

task main()
{
	int driveSpeed;
	driveSpeed=3;
	int direction;
	direction=1;
	while(true)
    //define all variables before the while loop, and put all things that can change at any time below (mostly button presses and motor control)
	{
		//Driving Speed, This is used for allowing us to change the speed of our robot.
		if(vexRT[Btn7U] == 1)
		{driveSpeed=1;}
		else if(vexRT[Btn7L] == 1)
		{driveSpeed=2;}
		else if(vexRT[Btn7R] == 1)
		{driveSpeed=3;}
		else if(vexRT[Btn7D] == 1)
		{driveSpeed=4;}


		//Driving Motor Control - Port 2/9, basic driving
		if (direction == 1){
		motor[leftMotor] = vexRT[Ch3] /driveSpeed;
		motor[rightMotor] = vexRT[Ch2] /driveSpeed;}
		else if (direction == 0){
		motor[leftMotor] = vexRT[Ch2] /driveSpeed*-1;
		motor[rightMotor] = vexRT[Ch3] /driveSpeed*-1;}

        //Driving Direction, lets us drive backwards
		if (vexRT[Btn8U]){direction=1;}
		if (vexRT[Btn8D]){direction=0;}

		//Grabber - Port 5, opens and closees gripper
		if (vexRT[Btn6U] == 1){
			motor[servo] = -127;
		}
		else if (vexRT[Btn6D] == 1){
			motor[servo] =50;
		}

		//Arm Movement - Port 6, moves gripper arm up and down.
		if (vexRT[Btn5D] == 1){
			motor[smallMotor] = -100;
		}
		else if (vexRT[Btn5U] == 1){
			motor[smallMotor] = 100;
		}
		else {motor[smallMotor] = 0;}


	}
}
