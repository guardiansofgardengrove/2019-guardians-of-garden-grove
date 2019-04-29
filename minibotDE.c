#include <kipr/botball.h>

//List of functions:
void grab_blue_poms_and_move();

//List of integers:
    //Motors:
		int lm = 2; //Left Motor = port 2
		int rm = 3; //Right Motor = port 3
		int bm = 0; //Bucket Motor = port 0
    //Servos:
		int claw = 3; //CLAW servo = port 3	
		int arm = 2; //ARM servo = port 2
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
    
    printf("This is our double elimination code\n");
   
    //Preliminary code:
    shut_down_in(119); //code shuts down in 120 seconds (2 minutes)
    //wait_for_light(light); //calibration code
    
    //Start of real code:
    //move forward just enough to clear the black tape from front reflectance
    cmpc(rm);
    while (gmpc(rm) < 3900)
    {
        motor(lm,78);
        motor(rm,70);
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
    
    //go straight to the blue line
    cmpc(rm);
    while (gmpc(rm) < 5833)
    {
        motor(lm,78);
        motor(rm,70);
        
    }
    ao();
    
    msleep(500);
    
    //turn 90 degrees to face the long blue tape
    motor(rm,-70);
    motor(lm,70);
    msleep(550);
    ao();
    
    msleep(500);
    
    //go back a little to get into position to grab the first category of blue poms
    cmpc(rm);
    while (gmpc(rm) > -583)
    {
        motor(lm,-78);
        motor(rm,-70);
        
    }
    ao();
    
    //first blue pom collection and move
    grab_blue_poms_and_move();
        
    return 0;
}

//Definitions of functions:
void grab_blue_poms_and_move()
{
    //Pick up the poms and place them in the basket:
    //put claw down 45 degrees
    
    set_servo_position(arm,1024);
    enable_servo(arm);
    msleep(500);
    //open claw completely
    set_servo_position(claw,533);
    enable_servo(claw);
    msleep(500);
    //lower claw completely
    set_servo_position(arm,359);
    msleep(500);
    //close claw
    set_servo_position(claw,1218);
    msleep(500);
    //lift all the way back
    set_servo_position(arm,1775);
    msleep(500);
    //open claw as far as possible;ie 15 Degree
    set_servo_position(claw,818);
    msleep(500);
    
}
