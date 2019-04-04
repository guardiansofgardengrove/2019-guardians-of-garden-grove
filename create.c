#include <kipr/botball.h>

int main()
{
    printf("This is the create's code\n");

    //List integers:
    int power = 3;
    int people = 0;
    int powerP = get_servo_position(power);
    int peopleP = get_servo_position(people);
    int quarter = 950;    
    
    //startup prerun functions
    create_connect(); //connect wallaby to create
    enable_servo(power);
    set_servo_position(power,1550);
    msleep(1000);
    enable_servo(people);
    set_servo_position(people,2040);
    msleep(1000);
        while (get_servo_position(power) > 600) {
        powerP = powerP-25;
        msleep(15);
        set_servo_position(power,powerP);
    } 
     
    msleep(1000);//wait for light
    shut_down_in(119); //stop all code in 120 seconds
    
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
    
    create_drive_direct(400,400);
    msleep(750);
    create_stop();
    
    //testing 90 degree turn
    create_spin_CW(200);
    msleep(960);
    create_drive_direct(400,400);
    msleep(1750);
    create_stop();
    
    //adjust to push container
    create_spin_CCW(200);
    msleep(960);
    create_drive_direct(200,200);
    msleep(1250);
    create_spin_CW(200);
    msleep(960);
    
    //aproach diagonal turn
    /*create_drive_direct(200,-200);
    msleep(quarter);
    create_stop();
    
    create_drive_direct(200,200);
    msleep(3000);
    create_stop();
    
    create_drive_direct(-200,200);
    msleep(quarter);
    create_stop();
    
    create_drive_direct(-100,-100);
    msleep(3000);
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
    create_stop();*/
    //slowly approach the power lines
    while (get_create_rbump() == 0 || get_create_lbump() == 0) {
        create_drive_direct(100,100);
    }
    create_stop();
    
    /*create_drive_direct(-100,-100);
    msleep(250);
    create_stop();
    
    create_drive_direct(-200,200);
    msleep(quarter);//special case for slight allingment issue
    create_stop();
    
    create_drive_direct(-200,-200);
    msleep(1900);
    create_stop();
    
    create_drive_direct(200,200);
    msleep(500);
    create_stop();
    
    //unfold the robot: to get the first washer
        while (get_servo_position(power) < 1850) {
        powerP = powerP+25;
        msleep(25);
        set_servo_position(power,powerP);
    }
    
    //position itself for washer
    create_drive_direct(100,100);
    msleep(1500);
    create_stop();
    msleep(500);
    
       // while (get_servo_position(power) > 1550) {
        //powerP = powerP+25;
        //msleep(25);
        //set_servo_position(power,powerP);
    //}
    msleep(500);
    
    //score the first point
    create_drive_direct(100,100);
    msleep(3000);
    create_stop();
    
   	msleep(20); 
    create_disconnect();
    msleep(20);*/
    
    //position for right washer
    create_spin_CCW(200);
    msleep(960);
    create_drive_direct(-100,-100);
    msleep(750);
    set_servo_position(power, 1520);
    
    //connect washer and push container
    create_drive_direct(-200,-200);
    msleep(1200);
    create_stop();
    
    //unhook and turn for next washer
    set_servo_position(power, 1700);
    create_spin_CCW(200);
    msleep(480);
    
    create_drive_direct(50,50);
    msleep(250);
    set_servo_position(power, 800);
    create_spin_CW(200);
    msleep(480);
    create_drive_direct(200,200);
    msleep(1750);
    create_stop();
    msleep(500);
    
    //connect next washer
    set_servo_position(power, 1575);
    create_drive_direct(200,200);
    msleep(1350);
    
    //disconnect from washer
    set_servo_position(power, 1800);
    create_spin_CW(200);
    msleep(480);
    set_servo_position(power, 800);
    create_drive_direct(100,100);
    msleep(500);
    
    //back up and sweep EVERYTHING
    create_spin_CCW(200);
    msleep(480);
    create_drive_direct(-400,-400);
    msleep(1000);
    create_spin_CW(200);
    msleep(950);
    create_drive_direct(-400,-400);
    msleep(4000);
    create_stop();
    msleep(1000);
    
    return 0;
}
