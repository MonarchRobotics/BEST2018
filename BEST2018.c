//which port on the robot we            Name of the motor.
//plug it in. It is important           You can name this whatever
//to put the driving motors             you want and it is used
//on opposite sides to provide          later to control the motors
//enough power          ↓                   ↓
#pragma config(Motor,  port2,           moveMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           swivel,     tmotorServoContinuousRotation, openLoop)
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
		/*if (direction == 1){
		motor[leftMotor] = vexRT[Btn] /driveSpeed;
        }*/
        
        //put the new code to control robot on beam below, try to make it so that you can swap which buttons moves the robot one way (with variable direction)
        //Driving Direction, lets us drive backwards
		if (vexRT[Btn8U]){direction=1;}
		if (vexRT[Btn8D]){direction=-1;}


	}
}
