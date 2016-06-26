mkdir -p HIGGSINONTUPLES
./MakeCompressedHiggsinoNtuple.x -ofile=./HIGGSINONTUPLES/ttbar.root -ifile=/Users/sezata/atlas/CompressedJigsaw/BackgroundSamples/ttbar_MET_gt_100.root
./MakeCompressedHiggsinoNtuple.x -ofile=./HIGGSINONTUPLES/Diboson.root -ifile=/Users/sezata/atlas/CompressedJigsaw/BackgroundSamples/VV_MET_gt_100.root
./MakeCompressedHiggsinoNtuple.x -ofile=./HIGGSINONTUPLES/Ztautau.root -ifile=/Users/sezata/atlas/CompressedJigsaw/BackgroundSamples/Ztautau_MET_gt_100.root
