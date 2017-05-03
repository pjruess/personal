import urllib

# output = "C:/MyScripts/nldas_data.csv" # Desired output folder
output = "/home/paul/myscripts/courses/fall2016/comp_opt/dre_output/"

lat = 28.1507 

lon = -97.5785

variable = "TMP2m" # Variable must be in a form found in varPotentials dictionary below

startDate = "2007-07-01T00" # yyyy-mm-ddThh, where hh is a 24-hour variable between 0 and 23

endDate = "2007-08-01T00" # Same format as startDate

varPotentials = {"APCPsfc": "NLDAS_FORA0125_H.002",
                 "DLWRFsfc": "NLDAS_FORA0125_H.002",
                 "DSWRFsfc": "NLDAS_FORA0125_H.002",
                 "PEVAPsfc": "NLDAS_FORA0125_H.002",
                 "SPFH2m": "NLDAS_FORA0125_H.002",
                 "TMP2m": "NLDAS_FORA0125_H.002",
                 "UGRD10m": "NLDAS_FORA0125_H.002",
                 "VGRD10m": "NLDAS_FORA0125_H.002",
                 "EVPsfc": "NLDAS_NOAH0125_H.002",
                 "GFLUXsfc": "NLDAS_NOAH0125_H.002",
                 "LHTFLsfc": "NLDAS_NOAH0125_H.002",
                 "SHTFLsfc": "NLDAS_NOAH0125_H.002",
                 "SSRUNsfc": "NLDAS_NOAH0125_H.002",
                 "BGRIUNdfc": "NLDAS_NOAH0125_H.002",
                 "SOILM0-10cm": "NLDAS_NOAH0125_H.002",
                 "SOILM0-100cm": "NLDAS_NOAH0125_H.002",
                 "SOILM0-200cm": "NLDAS_NOAH0125_H.002",
                 "SOILM10-40cm": "NLDAS_NOAH0125_H.002",
                 "SOILM40-100cm": "NLDAS_NOAH0125_H.002",
                 "SOILM100-200cm": "NLDAS_NOAH0125_H.002",
                 "TSOIL0-10cm": "NLDAS_NOAH0125_H.002"
                }

output = output + "nldas_lat=" + str(lat) + "_lon=" + str(lon) + "_var=" + variable + "_start=" + startDate + "_end=" + endDate + ".csv"

def get_nldas(lat, lon, variable, startDate, endDate, output):
    
    if variable not in varPotentials:
        print "Variable not accepted. Please try again." 
        return

    # Parameters
    webpage = "http://hydro1.sci.gsfc.nasa.gov/daac-bin/access/timeseries.cgi" \
        "?variable=NLDAS:{5}:{0}&startDate={3}&endDate={4}" \
        "&location=GEOM:POINT%28{1},%20{2}7%29&type=asc2"

    # Open webpage
    textFile = urllib.urlopen(webpage.format(variable, lon, lat, startDate, endDate, varPotentials[variable]))
    lines = textFile.readlines()
    lines = lines[40:]
    # Save values in csv
    with open(output, "w+") as fp:
        fp.write("Time, " + variable + "\n")
        # print(lines)
        for line in lines:
            # print line
            thing = line.strip().split()
            if len(thing) <= 1:
              continue
            mTime = thing[0].strip() + thing[1].strip()
            mVar  = thing[2].strip()
            fp.write("%s, %s\n" % (mTime, mVar))
    print "Data for Lat = %f, Lon = %f, Var = %s, Start = %s, End = %s\nOutput at: %s." % (lat, lon, variable, startDate, endDate, output)

get_nldas(lat, lon, variable, startDate, endDate, output)