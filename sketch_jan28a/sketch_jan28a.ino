#include <U8x8lib.h>

#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/
U8X8_PIN_NONE);

DHT dht(3, DHT11);


void setup() {
  pinMode(4, OUTPUT);

  dht.begin();

  u8x8.begin();
  u8x8.setFlipMode(1);
  u8x8.clear();

}

void loop() {
  double temperature = (dht.readTemperature() * 9/5) + 32;
  double humidity = dht.readHumidity();
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.setCursor(0, 0);

  String sign = " F";
  String printTemp = temperature + sign;
  String precent = " %";
  String printHumidity = humidity + precent;
  
  u8x8.print("Temperature: ");
  u8x8.println();
  u8x8.println(printTemp);

  u8x8.print("Humidity: ");
  u8x8.println();
  u8x8.println(printHumidity);

  if (humidity > 70.00) {
    tone(5, 1000);
    digitalWrite(4, HIGH);
    delay(1000);
    digitalWrite(4, LOW);
    delay(1000);
  }
  else
    noTone(5);

}
