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
#include <TList.h>

#include "CompressedHiggsinoNtuple.hh"

using namespace std;

int main(int argc, char* argv[]) {

  char inputFileName[400];
  char inputListName[400];
  char inputFolderName[400];
  char outputFileName[400];

  bool DO_FILE = false;
  bool DO_LIST = false;
  bool DO_FOLDER = false;

  if ( argc < 2 ){
    cout << "Error at Input: please specify an input file name, a list of input ROOT files and/or a folder path"; 
    cout << " and an output filename:" << endl; 
    cout << "  Example:      ./MakeCompressedHiggsinoNtuple.x -ifile=input.root -ofile=output.root"  << endl;
    cout << "  Example:      ./MakeCompressedHiggsinoNtuple.x -ilist=input.list -ofile=output.root"  << endl;
    cout << "  Example:      ./MakeCompressedHiggsinoNtuple.x -ifold=folder_path -ofile=output.root" << endl;
    
    return 1;
  }
  for (int i=0;i<argc;i++){
    if (strncmp(argv[i],"-ifile",6)==0){
      sscanf(argv[i],"-ifile=%s",  inputFileName);
      DO_FILE = true;
    }
    if (strncmp(argv[i],"-ilist",6)==0){
      sscanf(argv[i],"-ilist=%s",  inputListName);
      DO_LIST = true;
    }
    if (strncmp(argv[i],"-ifold",6)==0){
      sscanf(argv[i],"-ifold=%s",  inputFolderName);
      DO_FOLDER = true;
    }
    if (strncmp(argv[i],"-ofile",6)==0)  sscanf(argv[i],"-ofile=%s",  outputFileName);
  }

  gROOT->ProcessLine("#include <vector>");

  vector<string> filenames;

  char Buffer[500];
  char MyRootFile[2000];  

  if(DO_FOLDER){
    DIR *dpdf;
    struct dirent *epdf;
    dpdf = opendir(inputFolderName);
    if(dpdf == NULL){
      cout << "ERROR: " << inputFolderName << " is not a directory" << endl;
      return 1;
    }
    string dname(inputFolderName);
    while ((epdf = readdir(dpdf))){
      if(string(epdf->d_name).find(".root") == string::npos)
	continue;
      string name = dname+"/"+string(epdf->d_name);
      filenames.push_back(name);
    }
  }

  if(DO_LIST){
    ifstream *inputFile = new ifstream(inputListName);
    while( !(inputFile->eof()) ){
      inputFile->getline(Buffer,500);
      if (!strstr(Buffer,"#") && !(strspn(Buffer," ") == strlen(Buffer))){
	sscanf(Buffer,"%s",MyRootFile);
	filenames.push_back(MyRootFile);
      }
    }
    inputFile->close();
    delete inputFile;
  }

  if(DO_FILE){
    filenames.push_back(inputFileName);
  }
  int Nfile = filenames.size();
  for(int i = 0; i < Nfile; i++){
    std::cout << "Adding trees from file " << filenames[i] << " :" << endl;
    TFile* F = new TFile(filenames[i].c_str(),"READ");
    TObjLink* link = F->GetListOfKeys()->FirstLink();
    vector<string> treenames;
    while(link){
      string name = link->GetObject()->GetName();
      if(name == "outputTree"){
	int Nt = treenames.size();
	bool isnew = true;
	for(int i = 0; i < Nt; i++){
	  if(name == treenames[i]){
	    isnew = false;
	    break;
	  }
	}
	if(isnew){
	  treenames.push_back(name);
	  cout << name << endl;
	}
      }
      link = link->Next();
    }

    int Ntree = treenames.size();
    for(int j = 0; j < Ntree; j++){
      TChain* chain = new TChain(treenames[j].c_str());
      chain->Add(filenames[i].c_str());
      cout << "   Running tree " << treenames[j] << " " << chain->GetEntries() << endl;
      CompressedHiggsinoNtuple* ntuple = new CompressedHiggsinoNtuple(chain);
      ntuple->WriteNtuple(string(outputFileName));
      delete ntuple;
    }
  }
 
  return 0;
}
