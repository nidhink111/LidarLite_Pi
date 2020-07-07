# LidarLite_Pi

## Introduction

- Interface Lidar Lite with Raspberry Pi

## Integration Details

- Download and Install WiringPi. Install WiringPi
- Connect the Hardware I2C pin of Raspberry Pi to LidarLite
- Enable Raspberry Pi I2C configuration in raspi_config tool then reboot system
- After reboot , enter the following command
	>ls /dev/*i2c*
- Pi should respond with  >/dev/i2c-1
- There is a set of command-line utility programs that can help get an 	I2c interface working. You can get them with the apt package manager.
	>sudo apt-get install -y i2c-tools
- The i2cdetect program will probe all the addresses on  a bus, and report whether 	any 	device are present
	>i2cdetect -y 1
- You will get peripheral address if I2C is working.
- Build your LidarLite code and link it to wiringPi using following command
	>gcc lidar_i2c.c -lwiringPi -o i2ctest
- Run i2ctest executable file,will get distance and velocity

## Supported sensor Interface

- Lidar Lite version
