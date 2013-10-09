Nikon Infrared Remote Control in Contact Lenses Case
----------------------------------------------------

Infrared Remote Control for Nikon cameras.
DIY project for beginners.
Very simple and compact design - attiny13 microcontroller, one transistor, two resistors, one capacitor, infrared LED, battery and a momentary switch.
PCB size is 


This repo contains:
nikon_rc_smd_isp.lay - printed circuit board design file for SprintLayout program.
toner_transfer.gif - a picture of pcb for toner transfer.
main.c - source code.
main.hex - compiled hex file.
Makefile

----------------------------------------------------
Electronic Components

In this project I'm using an npn transistor kt315 because it is the most widespread transistor in Ukraine. It can be substituted by any other npn transistor.

----------------------------------------------------
Programming the Microcontroller

After attiny13 is soldered into PCB, it can be programmed via the ISP header. You will need an ISP programmer, like USBTinyISP.
Assuming you use attiny13 and USBTinyISP programmer, the programming command should look like this:
avrdude -c usbtiny -p t13 -U flash:w:main.hex -U lfuse:w:0x75:m -U hfuse:w:0xff:m

---------------------------------------------------
This project is based on information from the following sources:
http://www.bigmike.it/ircontrol/
http://www.sbprojects.com/projects/nikon/index.php

---------------------------------------------------
Copyright - 2013 - Olexiy Logvinov

License: Creative Commons Attribution-NonCommercial-ShareAlike
http://creativecommons.org/licenses/by-nc-sa/3.0/
Applies to main.c and nikon_rc_smd_isp.lay


