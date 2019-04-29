#include <kipr/botball.h>

//List of functions:
void turn_slightly_before_line_following();
void drive_straight_until_front_ref_sees_black();

//List of integers:
    //Motors:
		int lm = 2; //Left Motor = port 2
		int rm = 3; //Right Motor = port 3
		int bm = 0; //Bucket Motor = port 0
    //Servos:
		int claw = 2; //CLAW servo = port 2	
		int arm = 3; //ARM servo = port 3
    //Sensors:
    	//Analogs:
    		int light = 0; //LIGHT sensor (preliminary) = port 0
            int front_ref = 1; //FRONT REFlectance = port 1
    		int left_ref = 2; //LEFT REFlectance = port 2

//Notes:
    //circumfrence of wheel = 216.7 mm and there are 1800 ticks per revolution
    // = 1 tick = .12 mm

int main()
{
    /*/
    printf("This is our double elimination code\n");
   
    //Preliminary code:
    shut_down_in(119); //code shuts down in 120 seconds (2 minutes)
    //wait_for_light(light); //calibration code
    
    //Start of real code:
    //move forward just enough to clear the black tape from front reflectance
    cmpc(lm);
    while (gmpc(lm) < 3800) //4000
    {
        motor(lm,70);
        motor(rm,70);
    }
    ao();
    
    msleep(500);
    
    //make the left motor move 20 mm just to straighten up a bit
    cmpc(lm);
    while (gmpc(lm) < 250)
    {
        motor(lm,30);
    }
    ao();
    
    msleep(500);
    
    //turn 90 degrees to back up on the pipe
    motor(rm,-70);
    motor(lm,70);
    msleep(540);
    ao();
    
    msleep(500);
    
    //drive backwards into the pipe to straighten up the robot
    motor(rm,-70);
    motor(lm,-70);
    msleep(2000);
    ao();
    
    msleep(500);
    
    /*/
    //line follow along the first black portion
    double first_line=seconds();
        while(seconds()<first_line+30) //for 3.5 seconds approximately
        {
        	if (analog(left_ref)<1150) //if it sees white, turn more left
            {
            	motor(rm,70);
            	motor(lm,40);
            }
            if (analog(left_ref)<2200) //if it sees between white and black, go straight
            {
                motor(rm,50);
                motor(lm,50);
            }
        	else //if it sees black, turn more right
            {
            	motor(rm,40);
            	motor(lm,70);
            }
        }
    ao();
    
    /*/
    //turn slightly to the right to make up for possible turning
    turn_slightly_before_line_following();
    
    //drive forward until sees the grey line
    while (analog(front_ref)>1500)
    {
        motor(rm,70);
    	motor(lm,70);
    }
    msleep(500);
    ao();
    
    //turn slightly to the right to make up for possible turning
    turn_slightly_before_line_following();
    
    //drive forward 
    
    /*/
    return 0;
}

//Definitions of functions:
void turn_slightly_before_line_following()
{
	motor(rm,-30);
    msleep(250);
    ao();
}

void drive_straight_until_front_ref_sees_black()
{
    while (analog(front_ref)<2500) //while the front reflectance doesn't see black yet...
    {
        motor(lm,75); //drive forward as fast as possible
        motor(rm,75);
    }
}
