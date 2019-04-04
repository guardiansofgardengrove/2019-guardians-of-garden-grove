#include <kipr/botball.h>

//List of functions:


int main()
{
    printf("This is our double elimination code\n");
    
	//List of integers:
    //Ports:
    	//Motors:
			int lm; //Left Motor = port 2
			lm = 2;
    		int rm; //Right Motor = port 3
			rm = 3;
    		int bm; //Bucket Motor = port 0
			bm = 0;
    	//Servos:
    		int claw; //CLAW servo = port 2
			claw = 2;
    		int arm; //ARM servo = port 3
			arm = 3;
    	//Sensors:
    			//Analogs:
    				int light; //LIGHT sensor (preliminary) = port 0
    				light = 0;
    				int front_ref; //FRONT REFlectance = port 1
            		front_ref = 1;
    			//Touch:
    		//more coming...
    
    //Preliminary code:
    shut_down_in(119); //code shuts down in 120 seconds (2 minutes)
    //wait_for_light(light); //calibration code
    
    //Start of real code:
    
    //testing line following code
   double start_time=seconds();
        while(seconds()<start_time+18) //15
        {
        	if (analog(front_ref)>1150) //when it sees dark ///550 //1550 @ competitoion
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
    //go forward until senses black
    //go forward until senses white
    //go forward until sense black
    return 0;
}

//Definitions of functions:
