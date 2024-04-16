# fursuit Fan Controller
A fursuit fan controller, that can be manually triggered or when a set temperature is hit. 
I made this because i have a fan, which is quite powerful but i do not hear anything when its running.
I havent had much time to test and tune in the temps, this also depends from fursuit to fursuit, though i recommend to keep the warning temp and overheat temp within 10° from eachother.
The config is in °C, though the display can be adjusted to display °F <br>
Features:
- Manual fan control using a reed switch (i attached a magnet to my paw to trigger it)
- Temperature monitoring: current temp, min temp, max temp, and average temp (of the last 20 measurements)
- Hi temp warning: if the temp reaches above a certain number (i used 50 for testing, customisable), a warning will start to flash.
- Automatic cooling: if the temp reaches above 60 (again customisable), the fan will kick in and stop when a temperature lower than 50 (the warning threshold) is reached.
- A 'Last water' timestamp, which is basically just the time since the system was powered up, so you need to restart / reset to reset this timer.

The configuration can be found in the conf.h file

Note that this is just a project i made. I do not have much experience with c so i this entire project is made with a 'if it works, dont touch it' mindset and might not look the greatest
<br> For this project, you will need:

- An arduino nano
- A USB, or any other 5v powered fan
- A BC547 NPN transistor, with a 1k gate resistor
- 2 USB cables, and a powerbank with 2 usb outputs (or 2 powerbanks) and preferably a low power mode, since the arduino doesnt consume that much current some powerbanks might not detect this and shut off. Some have a low power mode where the output will be always on. I used an Iniu B42 (the one with the paw on it). You can use one USB connection but i chose to separate the control circuit from the fan itself
- 1 DS18B20 temperature sensor (3 wire version). If there is no board, you also will need a 4k7 resistor.
- A reed switch and magnet (there are prebuilt reed switch shields)
- (optional) An OLED screen with i2c control (SDA / SCL pins), i used https://www.otronic.nl/nl/mini-oled-display-wit-096-inch-128x64-i2c.html
- Arduino editor downloaded on your pc
- Soldering skills and material
- Cables to connect everything
- A pcb to mount the components on. While you can just hardwire eveything, a pcb is easier, it also is easier to hide and less messy.
- Shrink tube / hotglue. Since the oled will be mounted inside of the head, where it can be humid, the display should be protected.

You dont really need to have any experience with c or just any programming language in general.
You do need some knowledge about how to upload code to the arduino but theres tons of tutorials on that.

You have to use a transistor to switch on the output fan since the nano can deliver a max of 20mA output, the fan i use is 200mA. <br>
The default i2c adress for the oled i used was 0x3c. These displays can also have 0x3d as address, you can find yours by looking at the back side of the panel.<br>
The wiring diagram can be found below<br>
Here the transistor is replaced by a LED, and the button is your reed switch. Some reed switches have 3 pins, make sure to use the NO (normally open) pin<br>
SDA is connected to pin A4, SCL to A5.<br>
The resistor has a value of 4k7<br>

To reset the nano, press the little reset switch. This will restart the program.
ALternatively, you can connect a switch to the RST pin to reset via there. Note that this switch needs to be connected to ground, not to 5v

![image](https://github.com/Wolvinny/Fursuit-fan-controller/assets/84203950/aabab62c-70be-47c7-bdce-003191842c2d)

Config. 
If you want the temps to be displayed and configured in °F, set USE_F to true. 
By default, the fan will turn on above the configured overheat threshold. This however can be overriden by using the switch. Do note this will not get rid of the message, and will only reset once the temp drops below the warning threshold. The fan will also automatically turn off once this is reached.

You will also need to install the following libraries: 
- Adafruit GFX Library
- Adafruit SSD1306
- OneWire
- DallasTemperature
- AverageValue






 
