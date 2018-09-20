#pragma config(Motor,  port2,           moveMotor,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port9,           swivel,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           servo,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port6,		tilt1,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,		tilt2,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           clawArm1,        tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           clawArm2,        tmotorServoStandard, openLoop)

task main()
{
	int driveSpeed;
	driveSpeed=3;
	int direction;
	direction=1;
	int servoTilt = 0;
	
	while(true)
    //define all variables before the while loop, and put all things that can change at any time below (mostly button presses and motor control)
	{
		//Driving Speed, This is used for allowing us to change the speed of our robot.
		if(vexRT[Btn7U] == 1)
		{driveSpeed = 1;}
		else if(vexRT[Btn7L] == 1)
		{driveSpeed = 2;}
		else if(vexRT[Btn7R] == 1)
		{driveSpeed = 3;}
		else if(vexRT[Btn7D] == 1)
		{driveSpeed = 4;}

		//Scoop arm Movement
		motor[swivel] = vexRT[Ch4];
		motor[tilt1] = vexRT[Ch3];		
		motor[tilt2] = vexRT[Ch2];
		
		if(vexRT[Btn5D]){
			servoTilt += driveSpeed;
			motor[servo] = servoTilt;
		}
		else if(vexRT[Btn6D]){
			servoTilt -= driveSpeed;
			motor[servo] = servoTilt;
		}
        	else{motor[servo] = servoTilt;}
		
		//Close scoop arms
		if(vexRT[Btn8L]){
			motor[clawArm1] = 0;
			motor[clawArm2] = 0;
		}
		else if(vexRT[Btn8R]){
			motor[clawArm1] = 63;
			motor[clawArm2] = -63;
		}
  
		
        //put the new code to control robot on beam below, try to make it so that you can swap which buttons moves the robot one way (with variable direction)
	
        	if(vexRT[Btn5U]){motor[moveMotor] = direction * 128 / driveSpeed;}
        	else if(vexRT[Btn6U]){motor[moveMotor] = direction * -128 / driveSpeed;}
        	else{motor[moveMotor]=0;}


        //Driving Direction, lets us drive backwards
		if (vexRT[Btn8U]){direction = 1;}
		if (vexRT[Btn8D]){direction = -1;}


	}
}
