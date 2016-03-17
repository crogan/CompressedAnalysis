# CompressedAnalysis
Analysis framework for LHC searches for new particles decaying to massive weakly interacting particle(s) in the "compressed" mass-spectra regime

## Installing and Setting Up RestFrames
This package depends on the external code package RestFrames.

To run this package, you first need to download and install RestFrames:

* Go to the directory where you want to install RestFrames and download the git repository

  `<cmdline> git clone https://github.com/crogan/RestFrames`

* Change directories to newly created RestFrames
  
  `<cmdline> cd RestFrames`

* Configure and build the package
  + configure step (`--prefix` flag indicates where package is installed)

     `<cmdline> ./configure --prefix=$PWD`
  + make step
  
     `<cmdline> make`
  + install step
  
     `<cmdline> make install`

In addition to installing RestFrames, you need to set your environment paths to be able to see the RestFrames header files, shared library, etc. If `--prefix` was set to a directory already in your PATH (ex. /usr/local, which is the default) you've likely accomplished this already. If not, the RestFrames install step above also creates files `setup_RestFrames.(c)sh` which can be used at the start of a terminal session to add the approprate directories to your environment paths

* `<cmdline> cd RestFrames`
* `<cmdline> source setup_RestFrames.sh`
