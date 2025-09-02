import tkinter as tk
import RPi.GPIO as GPIO
from gpiozero import PWMLED
import time

# setting up GPIO

GPIO.setmode(GPIO.BCM)
red = PWMLED(17)
white = PWMLED(27)
green = PWMLED(22)

# functions
def change_red(value):
	brightness  = float(value)/100
	print(f"Red LED brightness: {brightness}")
	red.value=brightness

def change_white(value):
	brightness  = float(value)/100
	print(f"White LED brightness: {brightness}")
	white.value=brightness

def change_green(value):
	brightness  = float(value)/100
	print(f"Green LED brightness: {brightness}")
	green.value=brightness

def end():
	red.off()
	white.off()
	green.off()
	win.destroy() #closes the window

# GUI

win=tk.Tk()
win.title("LED Slider")

tk.Label(win, text="Red LED").pack()
tk.Scale(win, from_=0, to=100, orient="horizontal", command=change_red).pack()

tk.Label(win, text="White LED").pack()
tk.Scale(win, from_=0, to=100, orient="horizontal", command=change_white).pack()

tk.Label(win, text="Green LED").pack()
tk.Scale(win, from_=0, to=100, orient="horizontal", command=change_green).pack()

exitButton = tk.Button(win, text='Exit', command=end, bg='red', height=1, width=10)
exitButton.pack()

win.mainloop()
