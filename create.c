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
    int quarter = 900;
    
    //Official start of code:
    //unfold the robot:
        //while (get_servo_position(power) < 1550) {
        //powerP = powerP+25;
        //msleep(15);
        //set_servo_position(power,powerP);
    //}   
    
    //Task: drive to the powerlines
    //quick backup check
    
    create_drive_direct(-100,-100);
    msleep(1250);
    create_stop();
    
    create_drive_direct(200,200);
    msleep(400);
    create_stop();
    
    //aproach diagonal turn
    create_drive_direct(200,-200);
    msleep(quarter);
    create_stop();
    
    create_drive_direct(200,200);
    msleep(3000);
    create_stop();
    
    create_drive_direct(-200,200);
    msleep(quarter);
    create_stop();
    
    create_drive_direct(-100,-100);
    msleep(2100);
    create_stop();
    
    //complet diagonal 3 part turn to get to power lines
    create_drive_direct(200,200);
    msleep(1500);
    create_stop();
    
    create_drive_direct(200,-200);
    msleep(quarter/2);
    create_stop();
    
    create_drive_direct(200,200);
    msleep(1500);
    create_stop();
    
    create_drive_direct(200,-200);
    msleep(quarter/2 +100);
    create_stop();
    //slowly approach the power lines
    while (get_create_rbump() == 0) {
        create_drive_direct(50,50);
    }
    create_stop();
    
    create_drive_direct(-100,-100);
    msleep(750);
    create_stop();
    
    create_drive_direct(-200,200);
    msleep(quarter);
    create_stop();
    
    create_drive_direct(-200,-200);
    msleep(1900);
    create_stop();
    
    create_drive_direct(200,200);
    msleep(500);
    
   	msleep(20); 
    create_disconnect();
    msleep(20);
    return 0;
}
