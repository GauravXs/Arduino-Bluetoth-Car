//*************************************************************
//**********************BLUETOOTH CAR**************************
//*************************************************************
//Arduino Bluetooth Controlled Car MODIFIED by GAURAV SINGH originaly written by DIY BUILDER.
//This code is modified to work for this particular app inked below.
// The Bluetooth control Application is available on playstore kindly use the below link.
//Link https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller
//Note: This Code is Only Tested on this Application.
//Before uploading the code you have to install the necessary library
//Note - Disconnect the Bluetooth RX Cable before hiting the upload button otherwise you'll get compilation error message.
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install
//After downloading the library open Arduino IDE >> go to sketch >> Include Libray >> ADD. ZIP Libray >> Select the downloaded file
//Now You Can Upload the Code without any problem but make sure the bluetooth module isn't connected with Arduino while uploading code



#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
char command;

void setup()
{
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  Serial.println("Bluetooth Control Mode!");
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); //initialize with motors stopped
    //Change pin mode only if new command is different from previous.
    //Serial.println(command);
    switch (command) {
      case 'F':
        forward(); //to move car in forward direction
        break;
      case 'B': //to move car in backward direction
        back();
        break;
      case 'L': //to move car in left direction
        left();
        break;
      case 'R': //to move car in right direction
        right();
        break;
      case 'G': //to move car in forward left direction
        forward_left();
        break;
      case 'I': //to move car in forward right direction
        forward_right();
        break;
      case 'H': //to move car in back left direction
        back_left();
        break;
      case 'J': //to move car in back right direction
        back_right();
        break;
      case 'S':
        Stop();
        break;
    }
  }
}

void forward()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void back()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void left()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void Stop()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void forward_left()
{
  motor1.setSpeed(0);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void forward_right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(0);
  motor4.run(RELEASE);
}

void back_left()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(0);
  motor2.run(RELEASE);
  motor3.setSpeed(255);
  motor3.run(BACKWARD);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}

void back_right()
{
  motor1.setSpeed(255);
  motor1.run(BACKWARD);
  motor2.setSpeed(255);
  motor2.run(BACKWARD);
  motor3.setSpeed(0);
  motor3.run(RELEASE);
  motor4.setSpeed(255);
  motor4.run(BACKWARD);
}
