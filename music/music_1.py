import numpy as np
import wave
import pyaudio

output = '/home/paul/myscripts/courses/fall2016/comp_opt/music/'

class SoundFile:
   def  __init__(self,duration=1,nchannels=1,sampwidth=2,framerate=44100,comptype='NONE',compname='noncompressed'):
       self.file = wave.open(output+'test.wav', 'wb')
       self.file.setparams((nchannels,sampwidth,framerate,duration*framerate,comptype,compname))

   def write(self,signal):
       self.file.writeframes(signal)
       self.file.close()

duration = 1 # seconds

nchannels = 1
sampwidth = 2
framerate = 44100 # Hz
nframes = duration*framerate
comptype = 'NONE'
compname = 'noncompressed'

def make_wav(freq):
	period = framerate / float(freq) # in sample points
	omega = np.pi * 2 / period
	xaxis = np.arange(int(period),dtype=np.float)*omega
	ydata = 16384*np.sin(xaxis)
	signal = np.resize(ydata,(nframes,))
	ssignal = ''
	for i in range(len(signal)):
		ssignal += wave.struct.pack('h',signal[i]) #transform to binary
	return ssignal

A = make_wav(440)
C = make_wav(261.63)

# for i in [261.63,293.66,329.63,349.23,392.00,440.00,493.88,523.25]:
# 	print i

# f = SoundFile()
# f.write(A)
# f.write(C)

print 'file written'

###########################################################

#define stream chunk   
chunk = 1024  

#open a wav format music  
f = wave.open(output+'test.wav',"rb")
swidth = f.getsampwidth()
channels = f.getnchannels()
rate = f.getframerate()

# use a Blackman window
window = np.blackman(chunk)

#open stream
p = pyaudio.PyAudio()  
stream = p.open(format = p.get_format_from_width(swidth),  
                channels = channels,  
                rate = rate,  
                output = True)
#read data  
data = f.readframes(chunk)

# play stream and find the frequency of each chunk
while data != '':
    # write data out to the audio stream
    stream.write(data)

    # unpack the data and times by the hamming window
    indata = np.array(wave.struct.unpack("%dh"%(len(data)/swidth),\
                                         data))*window
    # Take the fft and square each value
    fftData=abs(np.fft.rfft(indata))**2
    # find the maximum
    which = fftData[1:].argmax() + 1
    # use quadratic interpolation around the max
    if which != len(fftData)-1:
        y0,y1,y2 = np.log(fftData[which-1:which+2:])
        x1 = (y2 - y0) * .5 / (2 * y1 - y2 - y0)
        # find the frequency and output it
        thefreq = (which+x1)*rate/chunk
        print "The freq is %f Hz." % (thefreq)
    else:
        thefreq = which*rate/chunk
        print "The freq is %f Hz." % (thefreq)
    
    # read some more data
    data = f.readframes(chunk)
if data:
    stream.write(data)
    
stream.close()
p.terminate()

"""
#play stream  
while len(data) == chunk*swidth:  
    stream.write(data)  
    data = f.readframes(chunk)  

#stop stream  
stream.stop_stream()  
stream.close()  

#close PyAudio  
p.terminate()
"""