from urllib2 import urlopen
from bs4 import BeautifulSoup
import requests
from lxml import html

mangahere = "http://www.mangahere.co/mangalist/"

"""
</li><li><a class="manga_info" rel="Fuyu Hodoki"
 href="http://www.mangahere.co/manga/fuyu_hodoki/">
 <span></span>Fuyu Hodoki</a>
 """

"""
Resources --------------------------
https://github.com/jiaweihli/manga_downloader
https://github.com/deepbhattacharya/manga-downloader
https://github.com/techwizrd/MangaFox-Download-Script
https://github.com/prasanthlouis/Manga-downloader/blob/master/dmanga.py
"""

# class manga():
# 	def __init__(self):
# 		self.get_names_urls(url)

mangas = {}
chapters = {}

def get_names_urls(url):
	list_names = []
	list_urls = []
	lines = urlopen(url).readlines()
	for i in range(len(lines)):
		if i >= 339 and i < 343:
			soup = BeautifulSoup(lines[i],'html.parser')
			for link in soup.find_all('a','manga_info'):
				current = str(link.get('href')[:-1])
				# list_urls.append(current)
				for y in range(len(current)):
					if current[-y] == "/":
						name = current[(-y+1):]
						mangas[name] = current
						# list_names.append(name)
						break

	return mangas


	# for i in range(len(list_names)):
	# 	print "Name: ", list_names[i]
	# 	print "URL: ", list_urls[i]

def get_chapters(mangas,manga):
	url = mangas[manga]
	lines = urlopen(url).readlines()
	for i in range(len(lines)):
		if i >= 339: 
			soup = BeautifulSoup(lines[i],'html.parser')
			for link in soup.find_all('a'):
				current = link.get('href')[:-1]
				if url == current[:len(url)] and current[len(url):] != '/comment':
					for y in range(len(current)):
						if current[-y] == "/":
							chapter = current[(-y+1):]
							chapters[chapter] = current
							break

	return chapters

# def get_pages(chapters):
# 	url = chapters['aoi_hikaru_ga_chikyuu_ni_itakoro']
# 	print url 






get_names_urls(mangahere)
# print mangas

get_chapters(mangas,'aoi_hikaru_ga_chikyuu_ni_itakoro')
print chapters

# get_pages(chapters)
# print pages