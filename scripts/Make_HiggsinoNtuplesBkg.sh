mkdir -p HIGGSINONTUPLEScluster
./MakeCompressedHiggsinoNtuple.x -ofile=./HIGGSINONTUPLEScluster/ttbar.root -ifile=/Users/sezata/atlas/CompressedJigsaw/BackgroundSamples/ttbar_MET_gt_100.root
./MakeCompressedHiggsinoNtuple.x -ofile=./HIGGSINONTUPLEScluster/Diboson.root -ifile=/Users/sezata/atlas/CompressedJigsaw/BackgroundSamples/VV_MET_gt_100.root
./MakeCompressedHiggsinoNtuple.x -ofile=./HIGGSINONTUPLEScluster/Ztautau.root -ifile=/Users/sezata/atlas/CompressedJigsaw/BackgroundSamples/Ztautau_MET_gt_100.root
