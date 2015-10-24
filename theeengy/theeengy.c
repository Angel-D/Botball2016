// Created on Fri October 2 2015
#include <stdio.h>

int main(){
	int fishface;
	int servo;
	enable_servos();
	set_servo_position(0, 750);
	create_connect();
	printf("Connectedified");
	camera_open();
	int location = 1;
	int createRight;
	int createLeft;
	
	while (1){
		camera_update(); //declare variables to be coordinates
		int prevx = get_object_center(0,0).x;
		int prevy = get_object_center(0,0).y;
		printf("x value is %d y value is %d\n", prevx, prevy);
		if (get_object_count(0) > 0) {
			createRight = 300-prevx;
			createLeft = 140 + prevx;
			create_drive_direct(140+prevx,300-prevx);
		}
			/*if (prevy <= 80) {
				servo = servo + 30;
				printf("Up\n");
			}
			else {
				servo = servo - 30;
				printf ("down");
			}*/
		
		if (get_object_count(0) == 0 && location == 1) {
			createRight = ((createRight*3)/4);
			createLeft = ((createLeft*3)/4);
			create_drive_direct(createLeft, createRight);
			for (int s = 500; s < 1000; s+=25) {
				set_servo_position(0,s);
				msleep(141);
				location = -1;
				if (get_object_count(0) > 0) {
					break;
				}
			}
		}
			
		if (get_object_count(0) == 0 && location == -1) {
			createRight = ((createRight*3)/4);
			createLeft = ((createLeft*3)/4);
			create_drive_direct(createLeft, createRight);
			for (int se = 1000; se > 500; se-=25) {
				set_servo_position(0,se);
				msleep(141);
				location = 1;
				if (get_object_count(0) > 0) {
					break;
				}
			}
		}
		if (get_object_count(0) > 0) {
			prevy = 80 - prevy;
			if (prevy > 0 )
				location = 1;
			else if (prevy < 0 )
				location = -1;
		}
		if (prevy <= -12 || prevy >= 12)
			servo = servo + prevy;
		if (servo > 1000)
			servo = 1000;
		if (servo < 500)
			servo = 500;
		set_servo_position(0, servo);
		msleep(5);
	}
	return 0;
}
