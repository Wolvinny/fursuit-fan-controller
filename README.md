# fursuit fan controller [v1.0]
A fursuit fan controller, that can be manually triggered or when a set temperature is hit. 
I made this because i have a fan, which is quite powerful but i do not hear anything when its running. <br>
I havent had much time to test and tune in the temps, this also depends from fursuit to fursuit, though i recommend to keep the warning temp and overheat temp within 5-10° from eachother.<br>
The config is in °C, though this can can be adjusted to use °F
### The temps mentioned were the ones i used for testing. They need to be adjusted to your preferred temps as i doubt you'd want you and your suit to ever reach 60°C
Features:
- Manual fan control using a reed switch (i attached a magnet to my paw to trigger it)
- Optional reset switch (also via a reed switch)
- Temperature monitoring: current temp, min temp, max temp, and average temp (of the last 20 measurements)
- Hi temp warning: if the temp reaches above 50, a warning will start to flash.
- Automatic cooling: if the temp reaches above 60, the fan will kick in and stop when a temperature lower than 50 (the warning threshold) is reached.
- A 'Last water' timestamp, which is basically just the time since the system was powered up, so you need to restart / reset to restart this timer.

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
- Wires to connect everything
- A pcb to mount the components on. While you can just hardwire eveything, a pcb is easier, it also is easier to hide and less messy.
- Shrink tube / hotglue. Since the oled will be mounted inside of the head, where it can be humid, the display should be protected.

You dont really need to have any experience with c or just any programming language in general.
You do need some knowledge about how to upload code to the arduino but theres tons of tutorials on that.

You have to use a transistor to switch on the output fan since the nano can deliver a max of 20mA output, the fan i use is 200mA. <br>
The default i2c adress for the oled i used was 0x3c. These displays can also have 0x3d as address, you can find yours by looking at the back side of the panel.<br>
The display is really small (0.98in) and can either be mounted inside of your suit (if you have enough space) or somewhere outside.
The wiring diagram can be found below<br>
Here the transistor is replaced by a LED, and the button is your reed switch. Some reed switches have 3 pins, make sure to use the NO (normally open) pin<br>
SDA is connected to pin A4, SCL to A5.<br>
The resistor has a value of 4k7<br>
If your temperature sensor does not come with a board, it will also need a 4k7 resistor.

To reset the nano, press the little reset switch. This will restart the program.
ALternatively, you can connect a switch to the RST pin to reset via there. Note that this switch needs to be connected to ground, not to 5v

![image](https://github.com/Wolvinny/Fursuit-fan-controller/assets/84203950/aabab62c-70be-47c7-bdce-003191842c2d)

 
If you want the temps to be displayed and configured in °F, set USE_F to true. 
By default, the fan will turn on above the configured overheat threshold. This however can be overriden by using the switch. Do note this will not get rid of the message, and will only reset once the temp drops below the warning threshold. The fan will also automatically turn off once this is reached.

You will also need to install the following libraries: 
- Adafruit GFX Library
- Adafruit SSD1306
- OneWire
- DallasTemperature
- AverageValue

Once you downloaded the source code, import it in the arduino IDE (File > Open)
When that is done you should see all the files.
Next, go to the library tab ![library tab](https://bork.treble-is-fluffy.gay/flooff56c1746.png), and search and install the libraries i mentioned before.

Once thats done, head to the board manager (the tab above the library manager, and search for arduino nano (the package should be named Arduino AVR Boards).
Then, go to Tools > Board > Arduino AVR Boards and select Arduino Nano.

If all is configured well, you should be able to compile (press the checkmark button).

Then go to Tools > Port and select the port (it should say). Your arduino has to be plugged in.


For the hardware part, connect everything according to this schema. The led here is used as a replacement for the transistor, the only thing you need is the purple wire, which goes to the base of the transistor.
You can choose to use a reset switch or not, the reed switch i ordered came with 2 so i added one. 

The VCC and GND cables can come directly from the USB connection, they do not neccesarily need to be connected via the arduino, though both will work.


### If you end up using my project, it would mean a lot if you could star it and [support me](https://kofi.wolvinny.dev). I spent a lot of time making this and optimising it for other people to read and use, even the smallest amount helps ne out, and i plan on making more fursuit-related projects in the future 

If you have any questions or any problems, feel free to contact me at mail@wolvinny.dev

Special thanks to my friend on discord for helping me with some of this and testing it for me!





 
