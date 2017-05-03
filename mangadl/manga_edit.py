from PIL import Image
from pytesseract import *

""" 
Info......
http://csdgn.org/inform/manga-editing
"""


image_file = "/home/paul/Downloads/menu_test.jpg"
image = Image.open(image_file)
text = image_to_string(image)

print text