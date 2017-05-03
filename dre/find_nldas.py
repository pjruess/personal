import urllib

varPotentials =         {"APCPsfc": 1,
                          "DLWRFsfc": 1,
                          "DSWRFsfc": 1,
                          "PEVAPsfc": 1,
                          "SPFH2m": 1,
                          "TMP2m": 1,
                          "UGRD10m": 1,
                          "VGRD10m": 1,
                          "EVPsfc": 1,
                          "GFLUXsfc": 1,
                          "LHTFLsfc": 1,
                          "SHTFLsfc": 1,
                          "SSRUNsfc": 1,
                          "BGRIUNdfc": 1,
                          "SOILM0-10cm": 1,
                          "SOILM0-100cm": 1,
                          "SOILM0-200cm": 1,
                          "SOILM10-40cm": 1,
                          "SOILM40-100cm": 1,
                          "SOILM100-200cm": 1,
                          "TSOIL0-10cm": 1
                        }

def find_nldas(lat=42.4375, lon=-117.1875, variable="SOILM0-100cm", startDate="2013-08-01T00", endDate="2013-12-31T23", output='nldas_data.csv'):
    
    if variable not in varPotentials:
        print "Please input valid variable."
        return
    # Parameters
    webpage = ("http://hydro1.sci.gsfc.nasa.gov/daac-bin/access/timeseries.cgi"
               "?variable=NLDAS:NLDAS_NOAH0125_H.002:{0}&type=asc2"
               "&location=GEOM:POINT({1},%20{2})&startDate={3}&endDate={4}")

    # Open webpage
    textFile = urllib.urlopen(webpage.format(variable, lon, lat, startDate, endDate))
    lines = textFile.readlines()
    lines = lines[40:]
    # Save values in csv
    with open(output,  "w") as fp:
        fp.write("TIME, VARIABLE\n")
        # print(lines)
        for line in lines:
            # print line
            thing = line.strip().split()
            if len(thing) <= 1:
              continue
            mTime = thing[0].strip() + thing[1].strip()
            mVar  = thing[2].strip()
            fp.write("%s, %s\n" % (mTime, mVar))

if __name__ == '__main__':
    find_nldas(lat=42.4375, lon=-117.1875,
             startDate="2013-08-01T00", endDate="2013-12-31T23")

    # find_nldas()
    print("Done")
