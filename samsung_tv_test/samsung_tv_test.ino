#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
#include <IRremote.h>
#include <SoftwareSerial.h>
SoftwareSerial m(6,5);
//unsigned int irSignal1[] = {2600 ,950 ,550 ,300 ,350 ,550 ,350 ,950 ,400 ,900 ,950 ,350 ,400 ,500 ,400 ,500 ,350 ,500 ,500 ,400 ,400 ,450 ,400 ,500 ,350 ,500 ,400 ,500 ,350 ,500 ,400 ,500 ,450 ,400 ,400 ,500 ,400 ,500 ,350 ,500 ,500 ,400 ,800 ,500 ,400 ,900 ,500 ,400 ,350}; 
//unsigned int irSignal5[] = {4600,4350, 650,1550, 650,1600, 650,1600, 600,500, 600,500, 600,550, 550,550, 600,550, 550,1650, 600,1650, 550,1700, 550,550, 550,550, 600,500, 600,550, 550,550, 600,500, 600,550, 550,550, 550,550, 600,1650, 600,500, 600,500, 600,550, 550,1650, 600,1650, 600,1650, 550,1650, 600,550, 550,1650, 600,1650, 600,1650, 550};  // SAMSUNG E0E008F7
//unsigned int irSignal4[] = {4650,4250, 700,1550, 650,1600, 650,1550, 650,500, 600,500, 600,500, 650,500, 600,500, 600,1650, 550,1650, 600,1650, 600,500, 600,500, 600,550, 550,550, 600,550, 550,550, 550,1650, 600,550, 600,500, 600,1650, 550,550, 600,500, 600,550, 550,1650, 600,550, 550,1650, 600,1650, 600,500, 600,1650, 600,1600, 600,1650, 600};  
unsigned int irSignal3[] = {4600,4300, 650,1600, 650,1550, 650,1600, 600,500, 600,550, 600,500, 600,550, 550,550, 550,1700, 550,1650, 600,1650, 550,550, 600,500, 600,550, 550,550, 600,500, 600,1650, 600,1650, 550,1650, 600,550, 550,550, 600,500, 600,550, 550,550, 600,500, 600,550, 550,550, 600,1600, 600,1650, 600,1650, 550,1650, 600,1650, 600};  
unsigned int irSignal2[] = {4650,4250,700,1550,650,1550,700,1550,650,450, 650,450, 650,450, 600,550, 550,550, 600,1650, 550,1650, 550,1650, 600,550, 550,550, 550,550, 600,500, 600,500, 600,1650, 600,1600, 600,500, 600,1650, 550,550, 600,500, 600,500, 600,550, 550,550, 600,500, 600,1650, 550,550, 550,1650, 600,1650, 550,1650, 600,1650, 550};
unsigned int irSignal1[] = {4550,4400,600,1650,550,1650,600,1650,550,550,600,500,600,550,550,550,600,500,600,1650,600,1600,600,1650,550,550,600,500,600,550,600,500,600,500,650,450,650,1600,600,500,650,450,650,500,600,500,600,500,600,550,600,1600,600,500,650,1600,650,1550,650,1600,650,1550,650,1600,650,1600,600}; 
unsigned int irSignal5[] = {2600,950,550,300,400,500,400,900,500,800,850,500,400,450,400,500,400,450,400,500,400,450,400,500,400,450,400,500,400,500,350,500,400,500,400,450,400,500,800,950,450,400,400,500,350,500,400,500,350};//tata ch up
unsigned int irSignal4[] ={2600 ,950 ,600 ,300 ,350 ,500 ,400 ,900 ,400 ,950 ,800 ,500 ,400 ,450 ,400 ,500 ,400 ,500 ,350 ,500 ,400 ,500 ,400 ,450 ,400 ,500 ,400 ,450 ,400 ,500 ,400 ,450 ,400 ,500 ,400 ,450 ,400 ,500 ,800 ,950 ,550 ,300 ,400 ,500 ,400 ,500 ,800};//tata ch down
int a = 0;
int khz = 38;
IRsend irsend;

void setup()
{
Serial.begin(9600);
m.begin(9600);
}

void loop() {

  if(m.available())
  {
   String str = m.readStringUntil('\n');
   str.trim();
   if(str=="pwr")// to check what string is recived 
   {
    Serial.println(str);//for debuging purpose 
  irsend.sendRaw(irSignal1, sizeof(irSignal1) / sizeof(irSignal1[0]), khz); // Sending Ir data to power on the TV
  }
  if(str == "vl-")
   {
   Serial.println(str);
  irsend.sendRaw(irSignal2, sizeof(irSignal2) / sizeof(irSignal2[0]), khz); 
  }
  if(str == "vl+")
   {
    Serial.println(str);
  irsend.sendRaw(irSignal3, sizeof(irSignal3) / sizeof(irSignal3[0]), khz); 
  }
  if(str == "ch-")
   {
    Serial.println(str);
  irsend.sendRaw(irSignal4, sizeof(irSignal4) / sizeof(irSignal4[0]), khz); 
  }
  if(str == "ch+")
   {
    Serial.println(str);
  irsend.sendRaw(irSignal5, sizeof(irSignal5) / sizeof(irSignal5[0]), khz); 
  }
}
}