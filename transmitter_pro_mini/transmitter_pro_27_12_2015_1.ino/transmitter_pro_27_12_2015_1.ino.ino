// transmitter.pde
//
// Simple example of how to use VirtualWire to transmit messages
// Implements a simplex (one-way) transmitter with an TX-C1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2008 Mike McCauley
// $Id: transmitter.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>

const int led_pin = 13;
//const int power_pin = 2;
const int transmit_pin = 1;
//const int receive_pin = 2;
//const int transmit_en_pin = 4;

char msg[255]; 
//const char p_msg;

int voltage_A0; 
int voltage_A1; 
int voltage_A2; 
int voltage_A3; 

String  str_voltage_A0; 
String str_voltage_A1; 
String str_voltage_A2; 
String str_voltage_A3; 

String strMsg; 

void setup()
{
    // Initialise the IO and ISR
    vw_set_tx_pin(transmit_pin);
 //  vw_set_rx_pin(receive_pin);
    //vw_set_ptt_pin(transmit_en_pin);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);       // Bits per sec
    pinMode(led_pin, OUTPUT);
 //   pinMode(power_pin, OUTPUT);
  //  digitalWrite(power_pin, HIGH);
}

byte count = 1;

void loop()
{
  voltage_A0 = analogRead(A0);
  voltage_A1 = analogRead(A1);
  voltage_A2 = analogRead(A2);
  voltage_A3 = analogRead(A3);


  str_voltage_A0 = String(voltage_A0,DEC); 
  str_voltage_A1 = String(voltage_A1,DEC); 
  str_voltage_A2 = String(voltage_A2,DEC); 
  str_voltage_A3 = String(voltage_A3,DEC); 
    //String millisresult = String(millis());

strMsg = "";
strMsg+= str_voltage_A0;
strMsg+= str_voltage_A1;
strMsg+= str_voltage_A2;
strMsg+= str_voltage_A3;


strMsg.toCharArray(msg, 255);

//*msg = "255";
//p_msg = *msg;

  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);

  delay(1000);
  

}
