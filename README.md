# BatteryCharger
An Arduino controlled 12V Pb or Li-ion Battery Charger

I just uploaded the code. Now, I'm working on the hardware. As soon as I have the schematics, I'll update the readme.

For now, I can say you can test by:

A1 - Analog Input of the Battery Voltage (using a Voltage Divider)
D2 - Feedback LED output
D3 - PWM (To 2N2222 which drives the MOSFET)

If you're one of those people who laugh at my code, like "blablabla, you could use switches instead of all those ifs and elses", a disclaimer: Firsto, I'm not a coder, I'm a problem solver. Secondo: Here's something I learned a long time ago:
https://github.com/user-attachments/assets/c8230278-a752-43f9-84b4-db2c6a501f44


# The Prototype

You don't have to use all this stuff. I made ONE like this to use as a tool. But, for production, I'm using only the 328P mcu soldered directly on the board. Or you can use a arduino NANO. 

![IMG_8815](https://github.com/user-attachments/assets/5a83d494-9375-4c41-a1ea-9a438554a047)

All the schematics and hardware photos will be here in a few days. Or weeks. Or years.
