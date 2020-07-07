#include <stdio.h>
#include <stdint.h>
#include "wiringPi.h"
#include "wiringPiI2C.h"

#define    LIDARLite_ADDRESS   0x62          // Default I2C Address of LIDAR-Lite.
#define    RegisterMeasure     0x00          // Register to write to initiate ranging.
#define    MeasureValue        0x04          // Value to initiate ranging.
#define    RegisterHighLowB    0x8f          // Register to get both High and Low bytes in 1 call.


int main (void){
	
	unsigned int fd , result;
	float floatVelocity=0;
	//if(wiringPiSetup () == -1)
	//	return 1;
//	printf("\nStart I2C\n");	
	
	fd = wiringPiI2CSetup(LIDARLite_ADDRESS);
	//pinMode(0,OUTPUT);
	
	result = wiringPiI2CReadReg8(fd,0x02);

	wiringPiI2CWriteReg8 (fd, RegisterMeasure, MeasureValue) ;
	wiringPiI2CWriteReg8 (fd, 0x04, 0x80) ;
	wiringPiI2CWriteReg8 (fd, 0x68, 0xC8) ;

	while(1){
		
		uint8_t nackack =100;
		
		while(nackack != 0){
			nackack = wiringPiI2CWriteReg8 (fd, RegisterMeasure, MeasureValue) ;
			delay(20);
		}
		
		uint8_t distance_array[2];
		
//		distance_array[0] = wiringPiI2CReadReg8 (fd, 0x0f) ;
//		distance_array[1] = wiringPiI2CReadReg8 (fd, 0x10) ;
		//result = (distance_array[0] << 8) +distance_array[1] ; 
		
		result = wiringPiI2CReadReg16 (fd, 0x8f) ;
		/* Swaping 16bit Distance data [wiringPiI2CReadReg16 has a bug ] */
		result = result >> 8 | ((result << 8) & 0xffff);
				
		printf("Distance= %d \t\t\t",result);
		delay(80);
		
		int8_t velocity;

			
		velocity = wiringPiI2CReadReg8 (fd, 0x09) ;
		velocity = velocity * 0.1 ; 
		printf(" %d \n",velocity); /* Unit Velocity m/s. */
		
	}
}
