// Created on Fri October 2 2015
#include <stdio.h>

int main(){
	int servo;
	enable_servos();
	set_servo_position(0, 750);
	create_connect();
	printf("Connectedified");
	camera_open();
	while (1){
		camera_update(); //declare variables to be coordinates
		int x = get_object_center(0,0).x;
		int y = get_object_center(0,0).y;
		printf("x value is %d y value is %d\n", x, y);
		if (get_object_count(0) > 0){
			create_drive_direct(140+x,300-x);
			if (y <= 80) {
				servo = servo + 30;
				printf("Up\n");
			}
			else {
				servo = servo - 30;
				printf ("down");
			}
		}
		if (servo > 1000)
			servo = 1000;
		if (servo < 550)
			servo = 550;
		set_servo_position( 0, servo);
		msleep(50);
	}
	return 0;
}
