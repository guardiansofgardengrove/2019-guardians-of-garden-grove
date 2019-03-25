#include <kipr/botball.h>

int main()
{
    printf("This is the create's code\n");
    
    //Intial functions (wait_for_light and shut_down_in)
    enable_servos();
    shut_down_in(119); //stop all code in 120 seconds
    create_connect(); //connect wallaby to create
    //List integers:
    int power = 3;
    int people = 0;
    int powerP = get_servo_position(power);
    int peopleP = get_servo_position(people);
    
    //Official start of code:
    //unfold the robot:
        while (get_servo_position(power) < 1550) {
        powerP = powerP+25;
        msleep(15);
        set_servo_position(power,powerP);
    }   
    //Quickly back up for alignment
    
    //Turn right to head towards the power lines
    
    //Drive straight until it senses the r

    create_disconnect();
    
    //function for people sweeping
    return 0;
}
