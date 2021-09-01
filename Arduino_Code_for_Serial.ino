//Software serial
#include <SoftwareSerial.h>
#define Rx 7
#define Tx 8
int incomingbyte = 0;
SoftwareSerial my_serial = SoftwareSerial(Rx, Tx);







//movement
int R_PWM = 10;
int L_PWM = 9;

//  Motor Direction Pins
int R_direction = 5;
int L_direction = 6;

#define Forward 1
#define Reverse 0

// Left Speed
int CCW_R = 180;        // Forward (max 0 - min 255)
int CCW_L = 40;         // Reverse (max 255 - min 0)
// Left Speed
int CW_R = 40;          // Forward (max 0 - min 255)
int CW_L = 180;         // Reverse (max 255 - min 0)
//wheel speeds (Forward/Reverse)
int right_speed = 40;
int left_speed  = 40;





void setup()
{  Serial.begin(115200);
   my_serial.begin(9600);
   pinMode(Rx, INPUT );  
   pinMode(Tx, OUTPUT);   
}

void loop ()
{ if (my_serial.available()) 
  {
   int incoming_value = my_serial.read();  //incoming_values are always are in ASCII
   Serial.println(incoming_value); 

   if (incoming_value == 70)        //70=F=Forward
        {   forward();   } 
   else if (incoming_value == 82)   //82=R=Reverse
        {   reverse();   }
   else if (incoming_value == 76  ) //76=L=Left
        {   turn_left()   }
   else if (incoming_value == 114)  //114=r=Right
        {   turn_right()   }
   else if (incoming_value == 83)   //83=S=Stop
        {   stop_SIMBOT()   }
        
  }
}



void forward() 
{
        analogWrite(R_PWM, right_speed);
        digitalWrite(R_direction, Forward); 
        
        analogWrite(L_PWM, left_speed);
        digitalWrite(L_direction, Forward);     
}

void reverse() 
{
        analogWrite(R_PWM, right_speed);
        digitalWrite(R_direction, Reverse);
        
        analogWrite(L_PWM, left_speed);
        digitalWrite(L_direction, Reverse);     
}

void stop_SIMBOT() 
{
        analogWrite(R_PWM, 0);
        digitalWrite(R_direction, Reverse);
        
        analogWrite(L_PWM, 0);
        digitalWrite(L_direction, Reverse);     
}

void turn_right() 
{
        analogWrite(R_PWM, right_speed);
        digitalWrite(R_direction, Reverse);
        
        analogWrite(L_PWM, left_speed);
        digitalWrite(L_direction, Forward); 
}

void turn_left() 
{   
        analogWrite(R_PWM, right_speed);
        digitalWrite(R_direction, Forward);
        
        analogWrite(L_PWM, left_speed);
        digitalWrite(L_direction, Reverse);
}
