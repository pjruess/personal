# import pygame
# import sys
from Tkinter import *
import pygame

# Piano: C:\ProgramData\Ableton\Live 9 Suite\Resources\Core Library\Samples\Grand Piano

# Copied to: C:\MyScripts\GrandPiano

Letters = ["C","D","E","F","G","A","B"]
keys = ["C1","D1","E1","F1", "G1", "A1","B1"]

class keyboard:

	def __init__(self,master):
		self.master = master
		frame = Frame(master)
		frame.pack()

		keys = []

		letters = ["C","D","E","F","G","A","B"]
		numbers = range(9)
		

		for key in keys:
			self.button = Button(frame,text=key,command=lambda key=key: self.play_note(key))
			self.button.pack(side=LEFT)

	def play_note(self,key):
		pygame.init()
		print "You played ", key
		parentfolder = "C:\MyScripts\GrandPiano"
		file = parentfolder + "\GrandPiano-%s-f.aif" % key
		print "file: ", file
		sound = pygame.mixer.Sound(file)
		sound.play()

if __name__ == "__main__": 
	root = Tk()
	app = keyboard(root)
	root.mainloop()