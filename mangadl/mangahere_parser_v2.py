from urllib2 import *
from urllib import *
from bs4 import BeautifulSoup
import requests

mangahere = "http://www.mangahere.co/mangalist/"

destination = "/home/paul/MyScripts/mangas/"

url = "http://www.mangahere.co/manga"

# list_names = []
# mangas = {}
# chapters = {}

# def get_names_urls(url):
# 	lines = urlopen(url).readlines()
# 	for i in range(len(lines)):
# 		if i >= 339 and i < 343:
# 			soup = BeautifulSoup(lines[i],'html.parser')
# 			for link in soup.find_all('a','manga_info'):
# 				current = str(link.get('href')[:-1])
# 				for y in range(len(current)):
# 					if current[-y] == "/":
# 						name = current[(-y+1):]
# 						mangas[name] = current
# 						list_names.append(name)
# 						break
# 	return list_names
# 	return mangas

# get_names_urls(mangahere)





# name = raw_input("Please enter manga title (ie. 'shokugeki_no_soma'): ")
# chapter = raw_input("Please enter chapter to download (ie. 'c001'): ")

name = 'shokugeki_no_soma'
chapter = 'c001'

chapter_url = url + '/' + name + '/' + chapter + '/'

for page in range(1,15):
	page_url = chapter_url + str(page) + '.html'
	data = requests.get(page_url)
	soup = BeautifulSoup(data.content, 'html.parser')
	for link in soup.find_all('img',id='image'):
		img_url = link.get('src')
		urlretrieve(img_url,destination + name + '_' + chapter + '_p' + str(page) + '.jpg')
		print "Retrieved", (name + '_' + chapter + '_p' + str(page) + '.jpg')