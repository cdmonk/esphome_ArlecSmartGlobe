This is no longer needed as ESPhome now has a platform that works for these globes. Thanka to @Ando023 for posting it.

ESP Home has a colour_temperature platform natively which can be used as below.


output:
  - platform: esp8266_pwm
    id: dimmer
    pin: GPIO5
  - platform: esp8266_pwm
    id: color_temp
    pin: GPIO13
    inverted: true

light:
- platform: color_temperature
  name: "Office Light Bulb"
  color_temperature: color_temp
  brightness: dimmer
  cold_white_color_temperature: 5700 K
  warm_white_color_temperature: 3000 K



# esphome_ArlecSmartGlobe
Custom Light Component for the Arlec Smart LED Globe (GLD112HA) sold in Australia by Bunnings.

These globes can be converted to ESPHome using tuya-convert (https://github.com/ct-Open-Source/tuya-convert). A great guide for this is https://everythingsmarthome.co.uk/howto/tuya-convert-guide-ota-flashing-of-smart-bulbs-and-plugs/.

The regular ESPHome "CWWW" component does not work correctly with these globes as they are based on a BP5926 chip. Rather than the more traditional way of wiring one colour channel to each GPIO, this design uses one PWM GPIO to control brightness and another PWM GPIO to control the colour temp which ESPHome as far as I can tell can't work with.

GPIO Assignment:

GPIO | Function | Notes
------------ | ------------- | -------------
**GPIO5** | Colour Temperature | Temperature 0 = Warm, 255 = Cold
**GPIO13** | Brightness | 0 = Off, 255 = Full brightness

To make this work in ESP home I used a custom light component. 

I have provided the ESPHome YAML config file for the globe, and the custom light component code (esphome_arlec_light_component.h) file that will need to go in the root of your ESPHome's config directory.

You will need to change your Wifi SSID details and ESPHome node names.


**THIS IS PROVIDED AS IS WITH NO WARRANTY. USE THIS AT YOUR OWN RISK.**

It is provided incase anyone runs in to the same trouble that I did when converting one of these globes to ESPHome.

Thanks to this project for helping me get my head around writing a custom light component for ESPHome (https://github.com/madjam002)

https://gist.github.com/madjam002/31cc88640efa370630fed6914fa4eb7f
