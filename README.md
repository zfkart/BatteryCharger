# BatteryCharger
An Arduino controlled 12V Pb or Li-ion Battery Charger

I made this to help me charge batteries on my EFI go-karts using a NEMA step motor as a generator. After rectification, the power goes to this module, which measures the battery charge and decides if some charging is needed.

I just uploaded the code. Now, I'm working on the hardware. As soon as I have the schematics, I'll update the readme.

For now, I can say you can test by plugging in your arduino:

. A1 - Analog Input of the Battery Voltage (using a Voltage Divider)

. D2 - Feedback LED output

. D3 - PWM (To 2N2222 which drives the MOSFET)

. D11 - Switch to select Pb 12v or Li-ion 11V batteries.





No warranties. No nothing. I'm sharing my work so you can save time building something similar. If you're one of those people who like to laugh at ugly code (my code), like "blablabla, you could use switches instead of all those ifs and elses", a disclaimer: Firsto, I'm not a coder, I'm a problem solver. Secondo: Here's something I learned a long time ago:
https://github.com/user-attachments/assets/c8230278-a752-43f9-84b4-db2c6a501f44


# The Prototype

You don't have to use all this LCD stuff. I made ONE like this to use as a tool. But, for production, I'm using only the 328P mcu soldered directly on the board. Or you can use a arduino NANO. 

![IMG_8815](https://github.com/user-attachments/assets/5a83d494-9375-4c41-a1ea-9a438554a047)

All the schematics and hardware photos will be here in a few days. Or weeks. Or years.
