
#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
#include "index.h"

#include <ESPAsyncWebServer.h>
#include "ESPAsyncWiFiManager.h"         //https://github.com/tzapu/WiFiManager



const int red = 4;
const int green = 0;
const int blue = 2;

// String sliderValue = "255";
String redValue = "255";
String greenValue = "255";
String blueValue = "255";
String builtinValue = "255";
String rawInput = "";
String offValue = "on";

const char* PARAM_INPUT = "value";


AsyncWebServer  server_esp(80);
DNSServer dns;

AsyncWiFiManager wifiManager(&server_esp,&dns);


// Variable to store the HTTP request
String header;
String log_string ;


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
  server_esp.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  // Send a GET request to <ESP_IP>/red?value=<inputMessage>
  server_esp.on("/red", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/red?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      redValue = inputMessage;
      analogWrite(red, redValue.toInt());
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("red led = "+inputMessage);
    
    log_string = "red led = "+inputMessage;
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
    log_string = "green led = "+inputMessage;
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
    log_string = "blue led = "+inputMessage;
    request->send(200, "text/plain", "OK");
  });
  


  // Send a GET request to <ESP_IP>/builtin?value=<inputMessage>
  server_esp.on("/builtin", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input value on builtin led <ESP_IP>/builtin?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      builtinValue = inputMessage;
      analogWrite(LED_BUILTIN, builtinValue.toInt());
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("builtin led = "+inputMessage);
    log_string = "builtin led = "+inputMessage;
    request->send(200, "text/plain", "OK");
  });
  
    // Send a GET request to <ESP_IP>/raw?value=<inputMessage>
  server_esp.on("/raw", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input value on <ESP_IP>/raw?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      rawInput = inputMessage;
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println("raw input received = "+inputMessage);
    log_string = "raw input received = "+inputMessage;
    request->send(200, "text/plain", "OK");
  });

  
  server_esp.on("/time", HTTP_GET, [] (AsyncWebServerRequest *request) {
    
    currentTime = millis();
    char temp[10];

    sprintf(temp, "%d,%ds",currentTime/1000,currentTime%1000);
    // Serial.println(temp);

    
    request->send(200, "text/plain", log_string);
  });

      // Send a GET request to <ESP_IP>/off?value=<inputMessage>
  server_esp.on("/off", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/off?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      offValue = inputMessage;
    }
    else {
      inputMessage = "on";
    }
    if(inputMessage=="off"){
      // putting a flag for switching to another wifi
      offValue = "off";
      
              
   
    }

    Serial.println("offValue received = "+inputMessage);
    log_string = "offValue received = "+inputMessage;
    request->send(200, "text/plain", "OK");
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
      

    }
  
  }
    if(offValue=="off"){
        Serial.println("inside loop offValue 'if'");

        // WiFi.mode(WIFI_STA);

        WiFi.disconnect(true,true);

        server_esp.end();                  //Start server
        Serial.println("HTTP server stopped");
      
        wifiManager.autoConnect("esp_wifi");

        offValue="on";

        // ESP.eraseConfig();
        ESP.restart();
        
      }
      else{
        //Start server
        // Serial.println("HTTP server started");
        Serial.println(WiFi.localIP());
        delay(2000);
        Serial.println(WiFi.SSID());
        delay(2000);

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