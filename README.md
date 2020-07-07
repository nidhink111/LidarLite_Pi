# LidarLite_Pi

## Introduction

- Interface Lidar Lite with Raspberry Pi

## Installation

### Clone repository
	git clone https://github.com/nidhink111/LidarLite_Pi.git
### Install WiringPi
	sudo apt-get install wiringpi
### Install command-line utility programs that can help get an I2c interface working
	sudo apt-get install -y i2c-tools
	
## Integration Details

- Connect the Hardware I2C pin of Raspberry Pi to LidarLite
- Enable Raspberry Pi I2C configuration in raspi_config tool then reboot system
- After reboot , enter the following command
	>ls /dev/*i2c*
- Pi should respond with  >/dev/i2c-1
- The i2cdetect program will probe all the addresses on  a bus, and report whether 	any 	device are present
	>i2cdetect -y 1
- You will get peripheral address if I2C is working.
- Build your LidarLite code and link it to wiringPi using following command
	>gcc lidar_i2c.c -lwiringPi -o i2ctest
- Run i2ctest executable file,will get distance and velocity

## Supported sensor Interface

- Lidar Lite version
