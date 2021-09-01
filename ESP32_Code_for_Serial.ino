#define Rx 16
#define Tx 17

void setup()
{    Serial.begin(115200);   
     Serial2.begin(9600, SERIAL_8N1, Rx, Tx);     
}

void loop()
{    Serial2.write('F');  //Forward
     delay(2000); 
     Serial2.write('R');  //Reverse
     delay(50);
     Serial2.write('L');  //Left turn
     delay(2000); 
     Serial2.write('r');  //Right turn
     delay(50);
     Serial2.write('S');  //Stop SIMBOT
     delay(2000);



     
     //Serial.println(  char(Serial2.read()  ) );  
          
}
