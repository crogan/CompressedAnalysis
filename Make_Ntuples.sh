mkdir -p NTUPLES
./MakeCompressedNtuple.x -ofile=./NTUPLES/Top.root -ifold=/Users/crogan/Dropbox/SAMPLES/SussexNt/Top/
./MakeCompressedNtuple.x -ofile=./NTUPLES/Wjets.root -ifold=/Users/crogan/Dropbox/SAMPLES/SussexNt/Wjets/
./MakeCompressedNtuple.x -ofile=./NTUPLES/Zjets.root -ifold=/Users/crogan/Dropbox/SAMPLES/SussexNt/Zjets/
./MakeCompressedNtuple.x -ofile=./NTUPLES/TT_500_327.root -ifile=/Users/crogan/Dropbox/SAMPLES/SussexNt/Signal/stopdiagonal_500.root
./MakeCompressedNtuple.x -ofile=./NTUPLES/TT_350_177.root -ifile=/Users/crogan/Dropbox/SAMPLES/SussexNt/Signal/stopdiagonal_350.root
./MakeCompressedNtuple.x -ofile=./NTUPLES/TT_300_127.root -ifile=/Users/crogan/Dropbox/SAMPLES/SussexNt/Signal/stopdiagonal_300.root
