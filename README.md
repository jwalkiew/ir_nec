# Introduction

This is a simple implementation of NEC protocol. You can find description of this protocol on: http://www.sbprojects.com/knowledge/ir/nec.php

## Simplified state diagram

![alt text](ir_nec_ds.png?raw=true "Simplified state diagram")

# Description

As remote controller is used device described on http://www.geeetech.com/wiki/index.php/Arduino_IR_Remote_Control. It turns LEDs on and off using commands:
* CH- [0xffa25d] - LED red on
* CH+ [0xffe21d] - LED red off
* PREV [0xff22dd] - LED yellow off
* NEXT [0xff02fd] - LED yellow on
* VOL- [0xffe01f] - LED blue off
* VOL+ [0xffa857] - LED blue on

# Directory layout
* eagle - contains circuit diagram designed in Eagle
* src - contains sources written in C language

# Circuit diagram

![alt text](ir_nec_dc.png?raw=true "Circuit diagram")

# Used electronic components

* Microcontrollers:
  * 1 x Atmega 8

* IR receiver:
  * 1 x TSOP31238

* Capacitors:
  * 1 x 100 nF (ceramic)
  * 1 x 22 µF (electrolytic)
  * 1 x 4.7 µF (electrolytic)

* Resistors:
  * 1 x 10 kΩ
  * 1 x 330 Ω
  * 3 x 270 Ω

* Diodes:
  * 1 x LED blue
  * 1 x LED yellow
  * 1 x LED red

# Summary

You can see how it works on YouTube: https://www.youtube.com/watch?v=soU_9yaAHPE [PL]
