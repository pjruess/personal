import urllib
from bs4 import BeautifulSoup

nldas_1 = "https://cmr.earthdata.nasa.gov/search/granules?short_name=NLDAS_NOAH0125_H&version=002&page_size=1&sort_key=-start_date"
nldas_1f = "https://cmr.earthdata.nasa.gov/search/granules?short_name=NLDAS_FORA0125_H&version=002&page_size=1&sort_key=-start_date"
gldas_1 = "https://cmr.earthdata.nasa.gov/search/granules?short_name=GLDAS_VIC10_3H&version=001&page_size=1&sort_key=-start_date"
gldas2_1 = ""
trmm_1 = "https://cmr.earthdata.nasa.gov/search/granules?short_name=TRMM_3B42&version=7&page_size=1&sort_key=-start_date"
grace_1 = ""

# Find url2 from url1
def get_url2(url1):
	urlText1 = urllib.urlopen(url1)
	urlLines1 = urlText1.readlines()
	url2 = ""
	for i in range(len(urlLines1)):
		soup1 = BeautifulSoup(urlLines1[i],'html.parser')
		if soup1.find("location") is not None: 
			url2 = soup1.location.getText()
	return url2

# # Find begintime from url1
# def get_begintime(url2):
# 	urlText2 = urllib.urlopen(url2)
# 	urlLines2 = urlText2.readlines()
# 	begintime = ""
# 	for j in range(len(urlLines2)): 
# 		soup2 = BeautifulSoup(urlLines2[j], 'html.parser')
# 		if soup2.find("beginningdatetime") is not None: 
# 			begintime = soup2.beginningdatetime.getText()
# 	return begintime

# Find endtime from url1
def get_endtime(url2):
	urlText2 = urllib.urlopen(url2)
	urlLines2 = urlText2.readlines()
	endtime = ""
	for j in range(len(urlLines2)): 
		soup2 = BeautifulSoup(urlLines2[j], 'html.parser')
		if soup2.find("endingdatetime") is not None: 
			endtime = soup2.endingdatetime.getText()
	return endtime

# Find bounding rectangle coordinates
def get_bounds(url2):
	urlText2 = urllib.urlopen(url2)
	urlLines2 = urlText2.readlines()
	bounds = ""
	for k in range(len(urlLines2)): 
		soup2 = BeautifulSoup(urlLines2[k], 'html.parser')
		if soup2.find("northboundingcoordinate") is not None: 
			nbound = soup2.northboundingcoordinate.getText()
			ebound = soup2.eastboundingcoordinate.getText()
			sbound = soup2.southboundingcoordinate.getText()
			wbound = soup2.westboundingcoordinate.getText()
			bounds = "North Bound is %s, East Bound is %s, South Bound is %s, West Bound is %s" % (nbound, ebound, sbound, wbound)
	return bounds

# Convert endtime to mm/dd/yyyy
def convert_endtime(endtime):
	day = endtime[8:10]
	month = endtime[5:7]
	year = endtime[:4]
	hour = endtime[11:13]
	minute = endtime[14:16]
	second = endtime[17:19]
	return "%s/%s/%s %s:%s:%s" % (month, day, year, hour, minute, second)

# Get all variables
# NLDAS
nldas_2 = get_url2(nldas_1)
# nldas_begintime = convert_begintime(get_begintime(nldas_2))
nldas_begintime = 
nldas_endtime = convert_endtime(get_endtime(nldas_2))
nldas_bounds = get_bounds(nldas_2)

# NLDAS Forcing
nldas_2f = get_url2(nldas_1f)
# nldasf_begintime = convert_begintime(get_begintime(nldas_2f))
nldasf_begintime = 
nldasf_endtime = convert_endtime(get_endtime(nldas_2f))
nldasf_bounds = get_bounds(nldas_2f)

# GLDAS
gldas_2 = get_url2(gldas_1)
# gldas_begintime = convert_begintime(get_begintime(gldas_2))
gldas_begintime = 
gldas_endtime = convert_endtime(get_endtime(gldas_2))
gldas_bounds = get_bounds(gldas_2)

# GLDAS 2
gldas2_2 = get_url2(gldas2_1)
# gldas2_begintime = convert_begintime(get_begintime(gldas2_2))
gldas2_begintime = 
gldas2_endtime = convert_endtime(get_endtime(gldas2_2))
gldas2_bounds = get_bounds(gldas2_2)

# TRMM
trmm_2 = get_url2(trmm_1)
# trmm_begintime = convert_begintime(get_begintime(trmm_2))
trmm_begintime = 
trmm_endtime = convert_endtime(get_endtime(trmm_2))
trmm_bounds = get_bounds(trmm_2)

# GRACE
grace_2 = get_url2(grace_1)
# grace_begintime = convert_begintime(get_begintime(grace_2))
grace_begintime = '01/06/2003 00:00:00'
grace_endtime = convert_endtime(get_endtime(grace_2))
grace_bounds = get_bounds(grace_2)

# Print results

print "Current begintimes...\nNLDAS: %s\nNLDAS(Forcing): %s\nGLDAS: %s\nGLDAS2: %s\nTRMM: %s\nGRACE: %s\n" \
	% (nldas_begintime, nldasf_begintime, gldas_begintime, gldas2_begintime, trmm_begintime, grace_begintime)

print "Current endtimes...\nNLDAS: %s\nNLDAS(Forcing): %s\nGLDAS: %s\nGLDAS2: %s\nTRMM: %s\nGRACE: %s\n" \
	% (nldas_endtime, nldasf_endtime, gldas_endtime, gldas2_endtime, trmm_endtime, grace_endtime)

print "Current bounds...\nNLDAS: %s\nNLDAS(Forcing): %s\nGLDAS: %s\nGLDAS2: %s\nTRMM: %s\nGRACE: %s\n" \
	% (nldas_bounds, nldasf_bounds, gldas_bounds, gldas2_bounds, trmm_bounds, grace_bounds)