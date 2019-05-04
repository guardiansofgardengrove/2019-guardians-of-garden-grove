#include <kipr/botball.h>

//List of functions:
void grab_blue_poms();

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
			int open_all = 694; //the claw is open all the way at 533
			int open_to_drop = 836; //the claw is open enough to drop the poms into their container at 818
			int close_enough_to_pass_return = 1000; //the claw is closed enough to be brough back to the gound at 1000
			int close_all = 1212; //the claw is closed all the way at 1218
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
    //move forward
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
    motor(lm,-78);
    msleep(2000);
    ao();
    
    msleep(30000);
    
    //go straight to the blue line
    cmpc(rm);
    while (gmpc(rm) < 5800) //5833
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
    while (gmpc(lm) > -195)
    {
        motor(lm,-60);
    }
    ao();
    
    msleep(1000);
    
    //turn lm back
    motor(lm,-78);
    msleep(450);
    ao();
    //turn rm back
    motor(rm,-70);
    msleep(400);
    ao();
    
    msleep(1000);
    
    //back up to run back into the two buildings
    cmpc(rm);
    while (gmpc(rm) > -2000)
    {
        motor(rm,-70);
        motor(lm,-78);
    }
    ao();
    
    msleep(500);
    
    //go forward to the second pom gathering
    cmpc(lm);
    while (gmpc(lm) < 4450)
    {
        motor(rm,70);
        motor(lm,80); //78
    }
    ao();
    
    msleep(500);

    //2nd blue pom collection
    grab_blue_poms();
    
    msleep(500);
    
    //correction
    cmpc(rm);
    while (gmpc(rm) < 50) 
    {
        motor(rm,60);
    }
    ao();
    
    //move to third pom gathering
    cmpc(rm);
    while (gmpc(rm) < 2700)
    {
        motor(rm,70);
        motor(lm,78);
    }
    ao();
    msleep(500);
    
    //3rd blue pom collection
    grab_blue_poms();
    
    //correction
    cmpc(rm);
    while (gmpc(rm) < 50) 
    {
        motor(rm,60);
    }
    ao();
    
    //move to fourth pom gathering
    cmpc(rm);
    while (gmpc(rm) < 2550)
    {
        motor(rm,70);
        motor(lm,78);
    }
    ao();
    msleep(500);
    
    //4th blue pom collection
    grab_blue_poms();
    
    //correction
    cmpc(rm);
    while (gmpc(rm) < 50) 
    {
        motor(rm,60);
    }
    ao();
    
    //move to fifth pom gathering
    cmpc(rm);
    while (gmpc(rm) < 2300)
    {
        motor(rm,70);
        motor(lm,78);
    }
    ao();
    msleep(250);
    
    //5th blue pom collection
    grab_blue_poms();
    
    //correction
    cmpc(rm);
    while (gmpc(rm) < 50) 
    {
        motor(rm,60);
    }
    ao();
    
    //drive forward 
    cmpc(lm);
    while (gmpc(lm) < 1667)
    {
        motor(rm,70);
        motor(lm,78);
    }
    ao();
    
    msleep(250);
    
    //lift up the bumper to clear
    set_servo_position(bumper,bumper_up);
    msleep(500);
    
    //turn 90 degrees to face the long blue tape
    motor(rm,-70);
    motor(lm,70);
    msleep(550);
    ao();
    
    msleep(250);
    
    //drive backwards into the pipe to straighten up the robot
    motor(rm,-70);
    motor(lm,-78);
    msleep(2500);
    ao();
    
    msleep(250);
    
    //go forward into the zone
    cmpc(lm);
    while (gmpc(lm) < 5500)
    {
        motor(rm,88);
        motor(lm,98);
    }
    ao();
    
    msleep(250);
    
    //turn rm 45 degrees
    motor(rm,70);
    motor(lm,-70);
    msleep(230);
    ao();
    
    //drive forward a bit more
    cmpc(lm);
    while (gmpc(lm) < 1300)
    {
        motor(rm,88);
        motor(lm,98);
    }
    ao();
    
    msleep(250);
    
    //release motor
    motor(bm,-100);
    msleep(1000);
    ao();
    
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
