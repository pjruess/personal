import scikits.audiolab, scipy

output = '/home/paul/myscripts/courses/fall2016/comp_opt/music/'

x, fs, nbits = scikits.audiolab.wavread(output+'test.wav')
X = scipy.fft(x)