# RGB LED controller 
esp8266 webserver with wifimanager Async using https://github.com/alanswx/ESPAsyncWiFiManager repository
## Board pin connections
here is the schematics of the board that i used


![NodeMCU-ESP8266-Pinout](https://github.com/guipelder/esp8266_async_webserver/assets/79325164/dcb2393a-9d84-4ad1-99f4-0c7470e941fa)

##
i used D4(GPIO2) , D3(GPIO0) , D2(GPIO4) and 3V pins for this module
1. D4 -> red 
2. D3 -> green
3. D2 -> blue

![IMG_20231112_031204](https://github.com/guipelder/esp8266_async_webserver/assets/79325164/33c35c2c-4cf9-4e7b-87a6-a726e39124d9)
## How to use
first time that you upload the code using Arduino IDE v2.x.x   
you get `esp_wifi` as AccessPoint(no password) then Enter `192.168.4.1`  
(be carefull not to use `https` instead of `http`).  
whenever you use disconnect button in the page you will get an AP named **esp_wifi**  again,   
then you can enter your new credentials, after that the board restarts and connects to new wifi.
note that your old credentials will be erased each time for the   
`WiFi.disconnect(true,true);` in `testasync.ino` file.
## Note
for finding the IP of board for the main webpage you can check your router or
alternativly you can use `ip neigh` command in linux or   
termux(android terminal emulator) 
for finding the IP.   
(be carefull not to use `https` instead of `http`).
## Optional
to prevent the board from erasing the the credentials change the  
`WiFi.disconnect(true,true);`
to  
`WiFi.disconnect(true,false);` in the `testasync.ino` file.


## Bugs
turning the builtin LED would turn on the the **Red** LED on RGB module  
