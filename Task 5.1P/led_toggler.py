import tkinter as tk
import RPi.GPIO as GPIO
from gpiozero import LED


# setting up GPIO

GPIO.setmode(GPIO.BCM)
red = LED(17)
white = LED(27)
green = LED(22)

# functions
def select_led():
	choice = LED_name.get()
	if choice == "Red":
		red.on()
		white.off()
		green.off()
	elif choice == "White":
		red.off()
		white.on()
		green.off()
	elif choice == "Green":
		red.off()
		white.off()
		green.on()

def end():
	red.off()
	white.off()
	green.off()
	win.destroy() #closes the window

# GUI

win=tk.Tk()
win.title("LED Toggler")

# String variable to hold current selection
LED_name = tk.StringVar()
LED_name.set("Red")  # Default option

tk.Radiobutton(win, text= 'Red LED', variable = LED_name , value= "Red", command = select_led).grid(row=0, column=0)
tk.Radiobutton(win, text= 'White LED', variable =  LED_name , value= "White", command = select_led).grid(row=0, column=1)
tk.Radiobutton(win, text= 'Green LED', variable =  LED_name , value= "Green", command = select_led).grid(row=0, column=2)

exitButton = tk.Button(win, text= 'Exit', command = end, bg = 'red',height = 1, width = 10)
exitButton.grid(row=4,column=1)

select_led()
win.mainloop()
