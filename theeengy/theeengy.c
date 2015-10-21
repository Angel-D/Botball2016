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
	
	while (1){
		camera_update(); //declare variables to be coordinates
		int prevx = get_object_center(0,0).x;
		int prevy = get_object_center(0,0).y;
		printf("x value is %d y value is %d\n", prevx, prevy);
		if (get_object_count(0) > 0) {
			create_drive_direct(140+prevx,300-prevx);
			/*if (prevy <= 80) {
				servo = servo + 30;
				printf("Up\n");
			}
			else {
				servo = servo - 30;
				printf ("down");
			}*/
		}
		
		if (get_object_count(0) == 0) {
			for (int s = 550; s < 1000; s+=20) {
				set_servo_position(0,s);
				msleep(100);
				if (get_object_count(0) > 0) {
					break;
				}
			}
		}
			
		if (get_object_count(0) == 0) {
			for (int se = 550; se > 550; se-=20) {
				set_servo_position(0,se);
				msleep(100);
					
				if (get_object_count(0) > 0) {
					break;
				}
			}
		}
		
		prevy = 80 - prevy;
		if (prevy <= -12 || prevy >= 12)
			servo = servo + prevy;
		if (servo > 1000)
			servo = 1000;
		if (servo < 550)
			servo = 550;
		set_servo_position(0, servo);
		msleep(5);
	}
	return 0;
}
