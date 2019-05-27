Firestarter hardware definition
==========================

This board by [Hexastorm](https://www.hexastorm.com) enables one to combine the capibilities provided by [ldgraphy](https://github.com/hzeller/ldgraphy) and [beagleg](https://github.com/hzeller/beagleg).
The idea is a PCB prototype machine which can 
mill and expose PCBs. It uses a new kind of laser scanning technology, transparent polygon scanning. A white paper on the technology can be found on [RepRap](https://reprap.org/wiki/Transparent_Polygon_Scanning).
A blog on progress can be found on [Hackaday](https://hackaday.io/project/21933-open-hardware-transparent-polygon-scanner).
At the moment, a [Python fork](https://github.com/hstarmans/ldgraphy) of ldgraphy is used for laser direct imaging. Schematics and a bill of materials of the Firestarter can be found [here](https://github.com/hstarmans/firestarter).

![Firestarter V2 board][Firestarter-img]

## Overlay notes
Install the overlay, some info is [here](https://github.com/hstarmans/ldgraphy).
There is test code in the [scripts](https://github.com/hstarmans/ldgraphy/tree/master/scripts) folder to verify the cape is working. 


## Build notes

To support the Firestarter v2 cape, BeagleG must be built using the correct hardware target:

```
make BEAGLEG_HARDWARE_TARGET=Firestarter
```

## Motor configuration

The motors are controlled via TMC2130 stepper drivers and must be configured over SPI before use. A library for the Beaglebone is available [here](https://github.com/hstarmans/TMC2130Stepper).



## Machine control

The Firestarter cape can then control a machine with G-Code using the `machine-control`
binary. 
```
sudo ./machine-control -c firestarter.config [options] [<gcode-filename>]
```

### Default Motor mapping

The Firestarter cape supports three TMC2130 drivers. 

|Motors                |MOTOR_1  |MOTOR_2   |MOTOR_3  |
|---------------------:|:-------:|:--------:|:-------:|
|Mapped Axis           |**X**|**Y**|**Z**|
|**STEP** BBB Header   |P9-41|P8-12|P8-16|
|**DIR** BBB Header    |P9-42 |P8-15|P8-17|
|**ENABLE** BBB Header |P9-12|P8-11|P8-18|

### Default Output mapping

Two PWM outputs are used.

|Outputs         |AUX_1|AUX_2|
|---------------:|:-------:|:-------:|
|PWM output      |PWM_1|PWM_2|
|TIMER           |`?`|`?`|
|Mapped signal   |spindle|fan|
|**PWM** BBB Header|P8-19|P8-13|

### Default Input mapping

Three inputs are used for endstops.

|Inputs          |IN_1|IN_2|IN_3|
|---------------:|:-------:|:-------:|:-------:|
|Mapped signal   |min_x|min_y|min_z|
|**GPIO** input  |P9-15|P9-14|P9-16|

### Other
The laser and photodiode are not mapped. These are controlled via [ldgraphy](https://github.com/hstarmans/ldgraphy).

[Firestarter-img]: firestarterv2.jpg