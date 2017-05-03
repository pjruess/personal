import urllib
from bs4 import BeautifulSoup
import os.path

# url = "http://neddimitrov.org/teaching/201404CO.html"
url = "http://neddimitrov.org/teaching/201604CO.html"

# output_location = r"C:\Users\Paul\Documents\My Stuff\UT Austin\Semester 3\ORI397_ComputationalOptimization" "\\"
# output_location = r"/media/paul/3EDEC65CDEC60BD9/Users/Paul/Documents/My Stuff/UT Austin/Semester 3/ORI397_ComputationalOptimization"
output_location = "/home/paul/myscripts/courses/fall2016/comp_opt/old_files/"

extensions = [".ipynb"]

def linkslist(url):
	urlfile = urllib.urlopen(url)
	urllines = urlfile.readlines()
	links = []
	for i in range(len(urllines)): 
		soup = BeautifulSoup(urllines[i], 'html.parser')
		for link in soup.find_all('a'): 
			current = link.get('href')
			links.append(current)
	return links

def download_links(linkslist, extensions): 
	dlfiles = []
	for ext in extensions: 
		negext = -len(ext)
		for i in range(len(linkslist)): 
			current = linkslist[i]
			if ext == str(current)[negext:]:
				dlfiles.append(linkslist[i])
	return dlfiles

def filenames(dlfiles):
	filenames = []
	for x in range(len(dlfiles)):
		for y in range(len(dlfiles[x])):
			current = dlfiles[x]
			if str(current)[-y] == "/":
				filenames.append(str(current)[(-y+1):])
				break
	return filenames

linkslist = linkslist(url)
dlfiles = []
dlfiles = download_links(linkslist, extensions)
filenames = filenames(dlfiles)
urlsnip = linkslist[0]

# def download_files(linkslist, dlfiles, filenames)

for item in range(len(dlfiles)): 
	thisitem = dlfiles[item]
	currenturl = urlsnip + "/" + thisitem
	print currenturl
	urltowrite = urllib.urlopen(currenturl).read()
	dllink = urllib.urlopen(currenturl)
	output = os.path.normcase(output_location + "%s" % filenames[item])
	with open(output,"wb") as endfile: 
		endfile.write(urltowrite)
		# for line in urltowrite:  
		# 	endfile.write("%s\n" % (line))

print "Downloaded files to %s" % os.path.normcase(output_location)