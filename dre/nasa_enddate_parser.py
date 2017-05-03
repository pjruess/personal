import urllib 
from HTMLParser import HTMLParser
from bs4 import BeautifulSoup

url1 = "https://cmr.earthdata.nasa.gov/search/granules?short_name=NLDAS_NOAH0125_H&version=002&page_size=1&sort_key=-start_date"

urltext1 = urllib.urlopen(url1)

urllines1 = urltext1.readlines()

class myhtmlparser(HTMLParser):
	def __init__(self):
		self.reset()
		self.NEWTAGS = []
		self.NEWATTRS = []
		self.HTMLDATA = []
	def handle_starttag(self, tag, attrs): 
		self.NEWTAGS.append(tag)
		self.NEWATTRS.append(attrs)
	def handle_data(self, data):
		self.HTMLDATA.append(data)
	def clean(self):
		self.NEWTAGS = []
		self.NEWATTRS = []
		self.HTMLDATA = []

# Find url2 from url1

parser1 = myhtmlparser()
parser1.feed(urllines1[0])

data1 = parser1.HTMLDATA

parser1.clean()

url2 = data1[4]

# Find enddate from url2

urltext2 = urllib.urlopen(url2)

urllines2 = urltext2.readlines()

parser2 = myhtmlparser()
parser2.feed(urllines2[0])

tags2 = parser2.NEWTAGS
attrs2 = parser2.NEWATTRS
data2 = parser2.HTMLDATA

parser2.clean()

# print data2

soup = BeautifulSoup(urllines2[0], 'html.parser')

print soup.endingdatetime.getText()