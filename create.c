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
    int timer = 0;
    
    //startup prerun functions
    create_connect(); //connect wallaby to create
    msleep(100);
    printf("Create Batter Power Before run: %d",get_create_battery_charge());
    printf("/n");
    msleep(1000);
    enable_servo(power);
    msleep(1000);
    enable_servo(people);
    set_servo_position(people,2040);
    set_servo_position(power,600);
     
    msleep(500);//wait for light
    shut_down_in(119); //stop all code in 120 seconds
    printf("Create Batter Power at start: %d",get_create_battery_charge());
    printf("/n");
    
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
    msleep(950); //960
    create_drive_direct(200,200);
    msleep(1500); //1250 1500 ///watch this number
    create_spin_CW(200);
    msleep(870); //930 900 870(before mess up) 915
    
    //slowly approach the power lines
    while (get_create_rbump() == 0 || get_create_lbump() == 0) {
        create_drive_direct(200,200); //100
        timer = timer + 1;
        msleep(100);
        if (timer > 30) {
            break;
        }
    }
    create_stop();
    timer = 0;
    
    //position for right washer
    create_spin_CCW(200);
    msleep(980);//960 1000 960 920 950
    create_drive_direct(-100,-100);
    msleep(800); //750 1000 //1250 1150 //1075 1000
    //create_stop();
    //msleep(1000);
    set_servo_position(power, 1570); //1520 1620 1670
    create_stop();
    msleep(1000);
    
    //connect washer and push container
    create_drive_direct(-150,-150);
    msleep(1725); //1200 1500 1675 1725 1825
    create_stop();
    msleep(250);
    
    //unhook and turn for next washer
    set_servo_position(power, 1800); //1700
    create_spin_CCW(200);
    msleep(480);
    
    create_drive_direct(25,25); //50
    msleep(250);
    set_servo_position(power, 800);
    create_spin_CW(200);
    msleep(465); //480
    create_drive_direct(200,200);
    msleep(1950); //1750 1850
    //create_stop();
    //msleep(500);
    
    //connect next washer
    set_servo_position(power, 1625); //1575
    create_stop();
    msleep(1000); //added
    create_drive_direct(150,150);
    msleep(1800); //1350 1600 1700
    create_stop();
    msleep(250);
    
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
    
    //check the gray and black line is passed before turning
    while (analog(0) < 2500){
        create_drive_direct(-200,-200);
    }
    msleep(333);
    
    while (analog(1) > 2500){
        create_drive_direct(-200,-200);
    }
    create_stop();
    
    //turn to align with the gray and black line
    create_spin_CW(200);
    msleep(500);
    
    while (timer < 55){ //to change time, add a zero to however many seconds you want it to double line follow //80
        if (analog(0) > 2500 && analog(1) > 2500){
            create_drive_direct(-250,-250);
            msleep(100);
            timer = timer + 1;
        }
        else if (analog(0) > 2500 && analog(1) < 2500){
            create_drive_direct(0,-250);
            msleep(100);
            timer = timer + .5;
    	}
    	else if (analog(0) < 2500 && analog(1) > 2500) {
            create_drive_direct(-250,0);
            msleep(100);
            timer = timer + .5;
        }
        else{
			create_drive_direct(-250,-125);
            msleep(100);
            timer = timer + .5;
        }
    }
          create_stop();
    	  timer = 0;
   
    	camera_open_black();
    	msleep(1000);
    	while (timer < 100){
    		camera_update();
            msleep(5);
            timer = timer + 1;
        }
    	
        if (get_object_area(0,0) >=100) //turn if it sees an object
        {
           create_spin_CW(200);
           msleep(500);
           create_drive_direct(-200,-200);
           msleep(2500);
           create_drive_direct(200,200);
           msleep(2500);
           create_spin_CCW(200);
           msleep(500);
        }
    	else
        {
           create_drive_direct(-200,-200);
           msleep(1700);
           create_drive_direct(200,200);
           msleep(1700);
    	}
    camera_close();
    timer = 0;
    create_stop();
    
    
    //give minibot some time
    create_drive_direct(400,400);
    msleep(2500);
    create_spin_CCW(200);
    msleep(960);
    create_drive_direct(-200,-200);
    msleep(4000);
    create_stop();
    msleep(20000);
    
    //drive to people 1
    create_drive_direct(200,200);
    msleep(1000);
    create_spin_CCW(200);
    msleep(960);
    create_drive_direct(400,400);
    msleep(2500);
    create_spin_CW(200);
    msleep(960);
    create_drive_direct(-200,-200);
    msleep(1000);
    create_drive_direct(400,400);
    msleep(1750);
    
    
    
    printf("Create Batter Power after: %d",get_create_battery_charge());
        
    
      
    
    return 0;
}
