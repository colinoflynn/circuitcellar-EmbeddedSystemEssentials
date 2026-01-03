import serial

#Pico USB Serial - no baud needed, but need to set dtr
ser = serial.Serial("com5", timeout=2)
ser.dtr = True

for i in range(60, 200, 1):
    ser.write(b"\xff"*i + b"\n\r")
    data = ser.read(100)
    print("%4s :"%i + str(data))

