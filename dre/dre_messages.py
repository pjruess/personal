import urllib

output = "C:\\MyScripts\\dre_messages.csv"

url = "https://docs.google.com/spreadsheets/d/1B0t85OAofIS-Pv1prJBuN49ff5I2XyXtEWzedxUJCUU/edit#gid=0"



# write to csv
def write_url_to_csv(url, output): 
	urlfile = urllib.urlopen(url)
	urllines = urlfile.readlines()
	with open(output, "w") as file: 
		for line in urllines: 
			current = line.strip().split()
			index = current[0]
			value = current[1]
			file.write("%s, %s\n") % (index, value)

def read_from_online(url, messagenumber): 
	urlfile = urllib.urlopen(url)
	urllines = urlfile.readlines()
	message = ""
	with open(urlfile, "r") as file: 
		for line in urllines: 
			current = line.strip().split()
			if messagenumber == current[0].strip(): 
				message = current[1].strip()
	return message

def read_from_csv(csv, messagenumber): 
	csvfile = csv
	message = ""
	with open(csvfile, "r") as file: 
		csvlines = file.readlines()
		for line in csvlines: 
			current = line.strip().split()
			if messagenumber == current[0].strip(): 
				message = current[1].strip()
	return message 
 
# write_url_to_csv(url, output)

# urlfile = urllib.urlopen(url)
# urllines = urlfile.readlines()
# urllines = urllines[:20]
# for line in urllines: 
#     print urllines

# read_from_csv(output, "001")

with open(output, "r") as file: 
	lines = file.readlines()
	for line in lines: 
		current = line
		if current[0] + current[1] + current[2] == "001": 
			print [current]
