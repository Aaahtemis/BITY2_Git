import serial
import time
from datetime import date, datetime

port = 'COM10'
baudrate = 9600

file = open(f"StoredValues/{date.today().day}.{date.today().month}.{date.today().year}_IRSerialValues_{datetime.now().hour}.{datetime.now().minute}.{datetime.now().second}.csv", 'w')
print(f"File \"{file.name}\" created.")
values = []

try :
    ser = serial.Serial(port,baudrate,timeout=1)
    time.sleep(2)
    print(f"connected to {port}")
    while True:
        if ser.in_waiting > 0 :
            line = ser.readline().decode('utf-8').rstrip()
            values.append(line+",")
            print(line)
        
except serial.SerialException as e :
    print(f"error: {e}")
except KeyboardInterrupt:
    print("\nExiting..")
finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print("Serial port closed.")

for line in values :
    print(line)
file.writelines(values)
file.close()
print("File closed.")