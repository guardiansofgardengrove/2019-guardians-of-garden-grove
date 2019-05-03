#include <kipr/botball.h>

//List of functions:
void grab_blue_poms();
void and_move();
void grab_blue_poms_and_move();

//List of integers:
    //Motors: 
		int lm = 2; //Left Motor = port 2
		int rm = 3; //Right Motor = port 3
		int bm = 0; //Bucket Motor = port 0
    //Servos:
		int bumper = 1; //BUMPER servo = port 1
			int bumper_up = 124; //the bumper is up and out of the way for clearance at 124
            int bumper_down = 1024; //the bumper is parallel to the ground for backing up at 1024
		int arm = 2; //ARM servo = port 2
			int up_to_drop = 1775; //the arm is up and behind to drop the poms into the holder
			int halfway = 1024; //the arm is halfway down (45 degrees) at 1024
			int down = 359; //the arm is all the way down on the ground (0 degrees) at 359
		int claw = 3; //CLAW servo = port 3	
			int open_all = 533; //the claw is open all the way at 533
			int open_to_drop = 818; //the claw is open enough to drop the poms into their container at 818
			int close_enough_to_pass_return = 1000; //the claw is closed enough to be brough back to the gound at 1000
			int close_all = 1218; //the claw is closed all the way at 1218
    //Sensors:
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
    //forever msleep(300000000);
    
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
    
    msleep(500);
    
    //Go along the whole blue line and collect the poms:
    //first blue pom collection
    grab_blue_poms();
    
    msleep(500);
    
    //put bumper down
    set_servo_position(bumper,bumper_down);
    enable_servo(bumper);
    msleep(1000);
    
    //move lm back to make it parallel to wall to back up
    cmpc(lm);
    while (gmpc(lm) > -170) 
    {
        motor(lm,-60);
    }
    ao();
    
    msleep(1000);
    
    //back up to run back into the two buildings
    cmpc(rm);
    while (gmpc(rm) > -2078)
    {
        motor(rm,-70);
        motor(lm,-78);
    }
    ao();
    
    msleep(1000);
    
    //go forward to the second pom gathering
    cmpc(rm);
    while (gmpc(rm) < 4200)
    {
        motor(rm,70);
        motor(lm,78);
    }
    ao();
    
    msleep(500);

    //2nd pom yeeeeet
    grab_blue_poms();
    
    msleep(500);
    
    //move to third pom
    //and_move();
    
    return 0;
}

//Definitions of functions:
void grab_blue_poms()
{
    //Pick up the poms and place them in the basket:
    //put claw down 45 degrees
    set_servo_position(arm,halfway);
    enable_servo(arm);
    msleep(500);
    //open claw completely
    set_servo_position(claw,open_all);
    enable_servo(claw);
    msleep(500);
    //lower claw completely
    set_servo_position(arm,down);
    msleep(500);
    //close claw
    set_servo_position(claw,close_all);
    msleep(500);
    //lift all the way back
    set_servo_position(arm,up_to_drop);
    msleep(1000);
    //open claw as far as possible to drop them into the bucket
    set_servo_position(claw,open_to_drop);
    msleep(500);
    //close claw to dislodge
    set_servo_position(claw,close_all);
    msleep(500);
    //open claw again, but not as much, to ensure clearance
    set_servo_position(claw,close_enough_to_pass_return);
    msleep(1000);  
}

void and_move()
{
 cmpc(rm);
    while (gmpc(rm) < 4200)
    {
        motor(rm,70);
        motor(lm,78);
    }
    ao();
}

void grab_blue_poms_and_move()
{
    grab_blue_poms();
    msleep(1000);
    and_move();
    msleep(1000);
}
