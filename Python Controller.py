import serial
import pyautogui
import time
import re

from ctypes import cast, POINTER
from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(
    IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = cast(interface, POINTER(IAudioEndpointVolume))
#volume.GetMute()
#volume.GetMasterVolumeLevel()
print(volume.GetVolumeRange())
#volume.SetMasterVolumeLevel(-30, None)


ser = serial.Serial("COM8", 9600)
ser.write(bytes("Start", "utf-8"))

while True:
    data = str(ser.readline())
    print(str(data))

    if "Pause/Play" in data:
        pyautogui.press(['space'], interval = 0)

    if "Volume" in data:
        dataString = str(data)
        vol = re.findall("\d+|.\d+", dataString)
        #print(vol)
        vol = float(vol[0]+vol[1])
        #print(vol) 
        print(f'Setting volume to {(vol + 65.25) / 0.6525}')
        volume.SetMasterVolumeLevel(vol, None)
