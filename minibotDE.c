#include <kipr/botball.h>

//List of functions:
void line_follow_until_front_sees_white();
void line_follow_until_front_sees_black();

//List of integers:
    //Motors:
		int lm = 2; //Left Motor = port 2
		int rm = 3; //Right Motor = port 3
		int bm = 0; //Bucket Motor = port 0
    //Servos:
		int claw = 2; //CLAW servo = port 2
    		/*/its positions:
    			int open = _; //OPENing the claw = value of ____
                int close = _; //CLOSing the claw = value of ___ /*/	
		int arm = 3; //ARM servo = port 3
    		/*/its positions:
                int up_90 = __; //arm is UP at 90 degrees = value of ___
                int down_90 = __; //arm is DOWN at 90 degrees = value of ___ /*/
    //Sensors:
    	//Analogs:
    		int light = 0; //LIGHT sensor (preliminary) = port 0
            int front_ref = 1; //FRONT REFlectance = port 1
    		int left_ref = 2; //LEFT REFlectance = port 2
    	//Touch:
    		int touch_red = 0; //TOUCH sensor (RED lever) = port 0

int main()
{
    printf("This is our double elimination code\n");
   
    //Preliminary code:
    shut_down_in(119); //code shuts down in 120 seconds (2 minutes)
    //wait_for_light(light); //calibration code
    
    //Start of real code:
    line_follow_until_front_sees_black();
           
    //testing msleep time
    msleep(3000); //3 seconds time lapse
    
   line_follow_until_front_sees_white();
               
    //go straight (blindly) until front reflectance sees gray
    
    /*/ //testing line following code for blue tape values
    double start_time=seconds();
        while(seconds()<start_time+18) //testing for 18 seconds
        {
        	if (analog(front_ref)>1150)
            {
            motor(rm,20); //20
            motor(lm,70); //70
            }
        	else
            {
            motor(rm,70); //70
            motor(lm,20); //20
            }
        }
    ao();
    /*/
    
    return 0;
}

//Definitions of functions:
void line_follow_until_front_sees_white()
{
	//line follow with left relectance until front reflectance sees white
    while (analog(front_ref)>2000) //while the front reflectance sees black
    {
    	if (analog(left_ref)<1000) //if the left reflectance sees white
        {
            motor(rm,20); //turn more right
            motor(lm,70);
        }
        else //if the left relectance sees black
        {
            motor(rm,70);
            motor(lm,20); //turn more left
        }
    }
}

void line_follow_until_front_sees_black()
{
    //line follow with left relectance until front reflectance sees black
    while (analog(front_ref)<3000) //while the front reflectance sees white
    {
        if (analog(left_ref)<1000) //if the left reflectance sees white
        {
            motor(rm,20); //turn more right
            motor(lm,70);
        }
        else //if the left relectance sees black
        {
            motor(rm,70);
            motor(lm,20); //turn more left
        }
    }
}
