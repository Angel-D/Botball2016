// Created on Fri October 2 2015
#include <stdio.h>

int main(){
	create_connect();
	printf("Connectedified");
	camera_open();
	while (1){
		camera_update(); //declare variables to be coordinates
		int x = get_object_center(0,0).x;
		int y = get_object_center(0,0).y;
		printf("x value is %d y value is %d\n", x, y);
		if (get_object_count(0) > 0){
			/*if (x>40)
				create_drive_direct(300,100);
			else if (x>80)
				create_drive_direct(250,150);
			else if (x>120)
				create_drive_direct(150,250);
			else
				create_drive_direct(100,300);
			*/
			create_drive_direct(140+x,300-x);
		}
		msleep(50);
	}
	return 0;
}
