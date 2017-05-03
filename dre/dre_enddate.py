import urllib
from bs4 import BeautifulSoup

NLDAS = "https://cmr.earthdata.nasa.gov/search/granules?short_name=NLDAS_NOAH0125_H&version=002&page_size=1&sort_key=-start_date"
NLDAS_forcing = "https://cmr.earthdata.nasa.gov/search/granules?short_name=NLDAS_FORA0125_H&version=002&page_size=1&sort_key=-start_date"
GLDAS = ""
TRMM = ""
GRACE = ""

# Find url2 from url1
def get_url2(url1):
	urlText1 = urllib.urlopen(url1)
	urlLines1 = urlText1.readlines()
	soup1 = BeautifulSoup(urlLines1[0],'html.parser')
	url2 = soup1.location.getText()
	return url2

# Find endtime from url1
def get_endtime(url2):
	urlText2 = urllib.urlopen(url2)
	urlLines2 = urlText2.readlines()
	soup2 = BeautifulSoup(urlLines2[0], 'html.parser')
	endtime = soup2.endingdatetime.getText()
	return str(endtime)

# Find bounding rectangle coordinates
def get_bounds(url2):
	urlText2 = urllib.urlopen(url2)
	urlLines2 = urlText2.readlines()
	soup2 = BeautifulSoup(urlLines2[0], 'html.parser')
	nbound = soup2.northboundingcoordinate.getText()
	ebound = soup2.eastboundingcoordinate.getText()
	sbound = soup2.southboundingcoordinate.getText()
	wbound = soup2.westboundingcoordinate.getText()
	bounds = "North Bound: %s\nEast Bound: %s\nSouth Bound: %s\nWest Bound: %s" % (nbound, ebound, sbound, wbound)
	return str(bounds)

# Convert endtime to mm/dd/yyyy
def convert_endtime(endtime):
	day = endtime[8:10]
	month = endtime[5:7]
	year = endtime[:4]
	hour = endtime[11:13]
	minute = endtime[14:16]
	second = endtime[17:19]
	return "%s/%s/%s %s:%s:%s" % (month, day, year, hour, minute, second)

# Get endtime for url
url2 = get_url2(NLDAS)
endtime = get_endtime(url2)
bounds = get_bounds(url2)

print convert_endtime(endtime)
print bounds