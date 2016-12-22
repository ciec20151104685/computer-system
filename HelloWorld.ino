//用Dht11m模块测出温度和湿度，然后显示到LCD1602的液晶屏幕上
#include <write.h>
#include<LiquidCrystal.h>
#include<dht11.h>

LiquidCrystal_SR lcd(8,7,TOW_WIRE);
dht11 DHT11;//声明对象
const byte dataPin=2;

void setup()//初始化lcd
{
lcd.begin(16，2)；//16行2列

lcd.setCursor(4,0);//设置点
lcd.print("temp");
lcd.setCursor(0,1);//设置点
lcd.print("humidity");
}

void loop()
{
  int chk=DHT11.read(dataPin);

  if(chk==0)
  {
    lcd.setCursor(9,0);//温度
    lcd.print((float)DHT11.temperature,2);
    lcd.print((char) 0xDF);
    lcd.print("C");

    lcd.setCursor(9,1);//温度
    lcd.print((float)DHT11.temperature,2);
    lcd.print("%");
    
  }
  delay(2000);
}



