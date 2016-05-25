// C++ includes
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <dirent.h>

// ROOT includes
#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

#include "Stop0LOptimization.hh"

using namespace std;

/// Main function that runs the analysis algorithm on the
/// specified input files
int main(int argc, char* argv[]) {

  /// Gets the list of input files and chains
  /// them into a single TChain
  char sigFileName[400];
  char sigFolderName[400];
  char bkgFolderName[400];
  char outputFileName[400];

  bool GOT_SIG = false;
  bool GOT_SIG_FILE = false;
  bool GOT_SIG_FOLD = false;
  bool GOT_BKG = false;
  bool GOT_OUT = false;

  int NJOB = 1;
  int iJOB = 0;

  if ( argc < 3 ){
    cout << "Error at Input: please specify an signal file name/folder, a folder path for backgrounds"; 
    cout << " and an output filename" << endl; 
    cout << "Example:   ./DoStop0LOptimization.x -sfile=signal.root -bfold=bkg_folder -ofile=output.root -Njob=1 -ijob=0" << endl;
    cout << "Example:   ./DoStop0LOptimization.x -sfold=sig_folder -bfold=bkg_folder -ofile=output.root -Njob=1 -ijob=0" << endl;
    return 1;
  }

  for (int i=0;i<argc;i++){
    if (strncmp(argv[i],"-sfile",6)==0){
      sscanf(argv[i],"-sfile=%s",  sigFileName);
      GOT_SIG_FILE = true;
    }
    if (strncmp(argv[i],"-sfold",6)==0){
      sscanf(argv[i],"-sfold=%s",  sigFolderName);
      GOT_SIG_FOLD = true;
    }
    if (strncmp(argv[i],"-bfold",6)==0){
      sscanf(argv[i],"-bfold=%s",  bkgFolderName);
      GOT_BKG = true;
    }
    if (strncmp(argv[i],"-ofile",6)==0){
      sscanf(argv[i],"-ofile=%s",  outputFileName);
      GOT_OUT = true;
    }
    if (strncmp(argv[i],"-Njob",5)==0)
      sscanf(argv[i],"-Njob=%d",  &NJOB);
    if (strncmp(argv[i],"-ijob",5)==0)
      sscanf(argv[i],"-ijob=%d",  &iJOB);
  }

  if((!GOT_SIG_FOLD && !GOT_SIG_FILE) || !GOT_BKG || !GOT_OUT)
    return 1;

  gROOT->ProcessLine("#include <vector>");

  Stop0LOptimization Optimization;
  
  if(GOT_SIG_FILE){
    std::cout << "Chaining signal tree from input file: " << sigFileName << std::endl;
    if(string(sigFileName).find("eos") != std::string::npos)
      Optimization.AddSignal("root:/"+string(sigFileName));
    else 
      Optimization.AddSignal(string(sigFileName));
  }

  if(GOT_SIG_FOLD){
    DIR *dpdf;
    struct dirent *epdf;
    dpdf = opendir(sigFolderName);
    if(dpdf == NULL){
      cout << "ERROR: " << sigFolderName << " is not a directory" << endl;
      return 1;
    }
    string dname(sigFolderName);
    while ((epdf = readdir(dpdf))){
      if(string(epdf->d_name).find(".root") == string::npos)
	continue;
      string name = dname+"/"+string(epdf->d_name);
      Optimization.AddSignal(name);
      std::cout << "chaining " << name << std::endl;
    }
  }

  if(GOT_BKG){
    DIR *dpdf;
    struct dirent *epdf;
    dpdf = opendir(bkgFolderName);
    if(dpdf == NULL){
      cout << "ERROR: " << bkgFolderName << " is not a directory" << endl;
      return 1;
    }
    string dname(bkgFolderName);
    while ((epdf = readdir(dpdf))){
      if(string(epdf->d_name).find(".root") == string::npos)
	continue;
      string name = dname+"/"+string(epdf->d_name);
      Optimization.AddBackground(name);
      std::cout << "chaining " << name << std::endl;
    }
  }
 
  Optimization.Loop(NJOB,iJOB);
  Optimization.WriteOutputFile(string(outputFileName));
 
  return 0;
}
