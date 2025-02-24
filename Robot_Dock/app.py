#Dylan Hart, Griffin Vriens, Tyler Evans u1313811
#User interfacing app for SLAM, MQTT, MATPLOTLIB, and
#libs
from tkinter import *
from tkinter import ttk
from PIL import Image, ImageTk
from tkinter import PhotoImage
#define the window object above
window = Tk()



def start():
    """start will init all of the window setup for tkinter and will be"""
    window.title('Robot tool')
    window.geometry('1000x1000')
    img  = Image.open('Image/IconLink.png')
    img = ImageTk.PhotoImage(img)
    window.iconphoto(True,img)

def main():
    "mainloop where threading will occur"
    print("Success!")
    start()
    window.mainloop()

#where the code is being exe.
main()
