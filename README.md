# esphome_ArlecSmartGlobe
Custom Light Component for the Arlec Smart LED Globe (GLD112HA) sold in Australia by Bunnings.

These globes can be converted to ESPHome using tuya-convert (https://github.com/ct-Open-Source/tuya-convert). A great guide for this is https://everythingsmarthome.co.uk/howto/tuya-convert-guide-ota-flashing-of-smart-bulbs-and-plugs/.

The regular ESPHome "CWWW" component does not work correctly with these globes as they are based on a BP5926 chip. Rather than the more traditional way of wiring one colour channel to each GPIO, this design uses one PWM GPIO to control brightness and another PWM GPIO to control the colour temp which ESPHome as far as I can tell can't work with.

GPIO Assignment:

GPIO5: Colour Temperature 0 = Warm, 255 = Cold

GPIO13: Brightness 0 = Off, 255 = Full brightness

To make this work in ESP home I used a custom light component. 

I have provided the ESPHome YAML config file for the globe, and the custom light component code (esphome_arlec_light_component.h) file that will need to go in the root of your ESPHome's config directory.

You will need to change your Wifi SSID details and ESPHome node names.


THIS IS PROVIDED AS IS WITH NO WARRANTY. USE THIS AT YOUR OWN RISK. It is provided incase anyone runs in to the same trouble that I did when converting one of these globes to ESPHome.
