#include <WiFi.h>
#include <DHT.h>
#include <time.h>
#include <HTTPClient.h>

#define DHTPIN 4
#define DHTTYPE DHT22

const char* serverUrl = "http://192.168.1.6:3000/update";

const char* serverTime = "pool.ntp.org";
const bool gmtSeason = 0;
const long gmtViet = 3600 * 7;

const char* ssid = "Ong Thuong";
const char* pass = "123456789@";

DHT dht(DHTPIN, DHTTYPE);

String saveTime(){
  struct tm times;
  if(!getLocalTime(&times)){
    return "unknow";
  }
  char currentTime[10];
  strftime(currentTime, sizeof(currentTime), "%H:%M:%S", &times);
  return String(currentTime);
}

void setup(){
  Serial.begin(115200);
  Serial.print("Đang kết nối tới ");
  Serial.print(ssid);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("Kết nối thành công.");
  dht.begin();
  configTime(gmtViet, gmtSeason, serverTime);
  Serial.println("Đã cài đặt ntp");
}
void loop(){
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if(WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");
    String time = saveTime();
    // { "temp": --, "hum": --, "time": "-----" }
    String jsonData = "{\"temperature\": " + String(t) + ", \"humidity\": " + String(h) + ", \"time\": \"" + time + "\"}";
    
    Serial.println(http.POST(jsonData));
    Serial.println(time);
    http.end();
  }

  Serial.println(t);
  Serial.println(h);
  delay(1000);
}