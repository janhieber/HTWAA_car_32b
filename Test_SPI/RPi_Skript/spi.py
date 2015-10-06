#!/usr/bin/env python
# -*- coding: utf8 -*-

# import modules 
import spidev
import time

# open SPI device
SPI = spidev.SpiDev()
SPI.open(0, 0)
SPI.max_speed_hz = 500000

# main loop
while 1:
    SPI.writebytes([8])
    time.sleep(0.500)

    SPI.writebytes([12])
    time.sleep(0.500)
