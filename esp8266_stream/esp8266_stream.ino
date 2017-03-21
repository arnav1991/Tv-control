#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "tv-contorl.firebaseio.com"
#define WIFI_SSID "Batak"
#define WIFI_PASSWORD "quackquack"
String str1,str2,str3,str4,str5;
boolean chk = true;
boolean chk2 = true;
boolean chk3 = true;
boolean chk4 = true;
boolean chk5 = true;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST);
}

void loop() {
str1=Firebase.getString("tv_test/tv_power");//to read values from Firebase database
//Serial.println(str1);
//delay(9999);
str2=Firebase.getString("tv_test/tv_volume-");//to read values from Firebase database
//str1.trim();
//str2.trim();
str3=Firebase.getString("tv_test/tv_volume^");//to read values from Firebase database
str5=Firebase.getString("tv_test/tv_chanel^");//to read values from Firebase database
//str5.trim();
str4=Firebase.getString("tv_test/tv_chanel-");//to read values from Firebase database
//str4.trim();
str3.trim();
if(str1=="\"on\""&&chk==true)//compare previous value with new to check change of state
{
  Serial.println("pwr");//if yes Send "pwr" on serial port of arduino.
  chk=false;
}
if(str1 =="\"off\""&&chk==false)
{
  Serial.println("pwr");
  chk=true;
}
if(str2=="\"vl-0\""&&chk2==true)
{
  Serial.println("vl-");
  chk2=false;
}
if(str2 =="\"vl-1\""&&chk2==false)
{
  Serial.println("vl-");
  chk2=true;
}
if(str3=="\"vl+0\""&&chk3==true)
{
  Serial.println("vl+");
  chk3=false;
}
if(str3=="\"vl+1\""&&chk3==false)
{
  Serial.println("vl+");
  chk3=true;
}
if(str4=="\"ch-0\""&&chk4==true)
{
  Serial.println("ch-");
  chk4=false;
}
if(str4 =="\"ch-1\""&&chk4==false)
{
  Serial.println("ch-");
  chk4=true;
}
if(str5=="\"ch+0\""&&chk5==true)
{
  Serial.println("ch+");
  chk5=false;
}
if(str5 =="\"ch+1\""&&chk5==false)
{
  Serial.println("ch+");
  chk5=true;
}


}


