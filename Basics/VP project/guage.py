from tkinter import *

class GuageMeter:
    def __init__(self, root, _width, _height):
        self.canvas_width = _width
        self.canvas_height = _height
        self.cnvs = Canvas(root, width=self.canvas_width, height=self.canvas_height)
        self.cnvs.grid(row=2, column=1)
        coord = 10, 50, (self.canvas_width-20), (self.canvas_height-20), #define the size of the gauge
        self.low_r = 0 # chart low range
        self.hi_r = 100 # chart hi range
        
        # Create a background arc with a number of range lines
        numpies = 8
        for i in range(numpies):
            self.cnv.create_arc(coord, start=(i*(120/numpies) +30), extent=(120/numpies), fill="white",  width=1)    
        
        # # add hi/low bands
        self.cnv.create_arc(coord, start=75, extent=75, outline="green", style= "arc", width=20)
        self.cnv.create_arc(coord, start=50, extent=25, outline="yellow", style= "arc", width=20)
        self.cnv.create_arc(coord, start=30, extent=20, outline="red", style= "arc", width=20)
        # add needle/value pointer
        self.id_needle = self.cnv.create_arc(coord, start= 119, extent=1, width=6)
        
        # Add some labels
        # self.cnv.create_text(180,15,font="Times 20 italic bold", text="Oil Pressure Sensor")
        self.cnv.create_text(20,(self.canvas_height/2)-20,font="Times 12 bold", text=self.low_r)
        self.cnv.create_text((self.canvas_width-20),(self.canvas_height/2)-20,font="Times 12 bold", text=self.hi_r)
        self.id_text = self.cnv.create_text((self.canvas_width/2)+10,(self.canvas_height/2)+30,font="Times 15 bold")

    def update_gauge(self, newvalue = 0):
        self.cnvs.itemconfig(self.id_text,text = str(newvalue) + " %")
        # Rescale value to angle range (0%=120deg, 100%=30 deg)
        angle = 120 * (self.hi_r - newvalue)/(self.hi_r - self.low_r) + 30
        self.cnvs.itemconfig(self.id_needle,start = angle)
        # root.after(3000, update_gauge)