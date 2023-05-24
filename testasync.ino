// #if defined(ESP8266)
// #include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
// #else
// #include <WiFi.h>
// #endif

#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include "index.h"

#include <ESPAsyncWebServer.h>
#include "ESPAsyncWiFiManager.h"         //https://github.com/tzapu/WiFiManager



const int red = 5;
const int green = 4;
const int blue = 0;

// String sliderValue = "255";
String redValue = "0";
String greenValue = "0";
String blueValue = "0";
String builtinValue = "255";
String rawInput = "";

const char* PARAM_INPUT = "value";


AsyncWebServer  server_esp(80);
DNSServer dns;

AsyncWiFiManager wifiManager(&server_esp,&dns);

WiFiServer server(80);

// Variable to store the HTTP request
String header;


// Current time
unsigned long currentTime = millis();

// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if (var == "SLIDERVALUE"){
    return builtinValue;
  }else if(var == "TIME"){
    currentTime = millis();
    return String(currentTime);
  }
  return String();
}
    
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  
  Serial.begin(9600);
  digitalWrite(LED_BUILTIN, HIGH);
  
  
  //first parameter is name of access point, second is the password
  wifiManager.autoConnect("esp_wifi");
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Route for root / web page
  // The Arrow(->) operator exists to access the members of the structure or the unions using pointers.
  server_esp.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Send a GET request to <ESP_IP>/red?value=<inputMessage>
  server_esp.on("/red", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/red?value=<inputMessage>
    // The Arrow(->) operator exists to access the members of the structure or the unions using pointers.
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      redValue = inputMessage;
      analogWrite(red, redValue.toInt());
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("red led = "+inputMessage);
    request->send(200, "text/plain", "OK");
  });
  

 
  // Send a GET request to <ESP_IP>/green?value=<inputMessage>
  server_esp.on("/green", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/green?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      greenValue = inputMessage;
      analogWrite(green, greenValue.toInt());
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("green led = "+inputMessage);
    request->send(200, "text/plain", "OK");
  });

  // Send a GET request to <ESP_IP>/blue?value=<inputMessage>
  server_esp.on("/blue", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/blue?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      blueValue = inputMessage;
      analogWrite(blue, blueValue.toInt());
      
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("blue led = "+inputMessage);
    request->send(200, "text/plain", "OK");
  });
  


  // Send a GET request to <ESP_IP>/builtin?value=<inputMessage>
  server_esp.on("/builtin", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/slider?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      builtinValue = inputMessage;
      analogWrite(LED_BUILTIN, builtinValue.toInt());
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("builtin led = "+inputMessage);
    request->send(200, "text/plain", "OK");
  });
  
    // Send a GET request to <ESP_IP>/raw?value=<inputMessage>
  server_esp.on("/raw", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/raw?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      rawInput = inputMessage;
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("raw input received = "+inputMessage);
    request->send(200, "text/plain", "OK");
  });

  
  server_esp.on("/time", HTTP_GET, [] (AsyncWebServerRequest *request) {
    
    currentTime = millis();
    char temp[10];

    sprintf(temp, "%d,%ds",currentTime/1000,currentTime%1000);
    // Serial.println(temp);

    request->send(200, "text/plain", temp);
    // request->send(200, "text/plain", String(currentTime%1000).c_str());
  });

  // Start server
  server_esp.begin();
  
}

void loop() {
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("trying to connect to wifi");
    for(int i =0; i<5;i++){
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN,LOW);
      delay(10);
    }
      wifiManager.autoConnect("esp_wifi");

    if(WiFi.status()== WL_CONNECTED){
      Serial.println("not trying to connect to the wifi any more");
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("");
      Serial.println("WiFi connected.");
      Serial.println("IP address: ");
      Serial.println(WiFi.localIP());

      server_esp.begin();                  //Start server
      Serial.println("HTTP server started");
    }
  }

  

}












// void setup() {
//     // put your setup code here, to run once:
//     Serial.begin(115200);

//     //WiFiManager
//     //Local intialization. Once its business is done, there is no need to keep it around
//     AsyncWiFiManager wifiManager(&server,&dns);
//     //reset saved settings
//     //wifiManager.resetSettings();
//     //set custom ip for portal
//     //wifiManager.setAPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
//     //fetches ssid and pass from eeprom and tries to connect
//     //if it does not connect it starts an access point with the specified name
//     //here  "AutoConnectAP"
//     //and goes into a blocking loop awaiting configuration
//     wifiManager.autoConnect("AutoConnectAP");
//     //or use this for auto generated name ESP + ChipID
//     //wifiManager.autoConnect();
//     //if you get here you have connected to the WiFi
//     Serial.println("connected...yeey :)");
// }

// void loop() {
//     // put your main code here, to run repeatedly:
// }

//TODO changin the LED_BUILTIN for ledbuilt in and rgb yw robot 






// void handleRoot() {
// //  String s = MAIN_page; //Read HTML contents From index.h
//  String s = index_html; //Read HTML contents From index.h

 
//  server_esp.send(200, "text/html", s); //Send web page
// }