import keyboard
import pyautogui
from pykeyboard import PyKeyboard
import time

k = PyKeyboard()

while(True):
    t1=time.time()
    keyboard.press('left')
    t2=time.time()
    keyboard.release('left')
    t3=time.time()
    pyautogui.keyDown('left') 
    t4=time.time()
    pyautogui.keyUp('left')
    t5=time.time()
    k.press_key('H')
    t6=time.time()
    k.release_key('H')
    t7=time.time()
    print("keyboard press:",t2-t1)
    print("keyboard release:",t3-t2)
    print("autogui keyDown:",t4-t3)
    print("autogui keyUp:",t5-t4)
    print("pykey keypress:",t6-t5)
    print("pykey keyrelease:",t7-t6)
