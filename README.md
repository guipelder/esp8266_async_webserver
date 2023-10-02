# RGB LED controller 
esp8266 webserver with wifimanager Async using https://github.com/alanswx/ESPAsyncWiFiManager repository
## Board pin connections
here is the schematics of the board that i used

![NodeMCU-ESP8266-Pinout](https://github.com/guipelder/testasync/assets/79325164/12429f0f-6834-4c53-8404-a78274bbf767)
##
i used D4(GPIO2) , D3(GPIO0) , D2(GPIO4) 
1. D4 -> red 
2. D3 -> green
3. D2 -> blue

![IMG_20231112_031204](https://github.com/guipelder/testasync/assets/79325164/e280ea7f-5882-4b7d-8b65-401574849a4f)

## Bugs
turning the builtin LED would turn on the the **Red** LED on RGB module  
