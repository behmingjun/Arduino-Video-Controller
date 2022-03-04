import serial
import pyautogui
import time

ser = serial.Serial("COM6", 9600)
ser.write(bytes("Start", "utf-8"))

while True:
    data = str(ser.readline())
    print(str(data))

    if "Pause/Play" in data:
        pyautogui.press(['space'], interval = 0)

    if "Volume Up" in data:
        pyautogui.press(['volumeup'], interval = 0)

    if "Volume Down" in data:
        pyautogui.press(['volumedown'], interval = 0)
