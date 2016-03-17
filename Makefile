ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)

RFCFLAGS    = $(shell restframes-config --cxxflags)
RFGLIBS     = $(shell restframes-config --libs)

CXX            = g++

CXXFLAGS       = -fPIC -Wall -O3 -g
CXXFLAGS       += $(filter-out -stdlib=libc++ -pthread , $(ROOTCFLAGS))
CXXFLAGS       += $(filter-out -stdlib=libc++ -pthread , $(RFCFLAGS))

GLIBS          = $(filter-out -stdlib=libc++ -pthread , $(ROOTGLIBS))
GLIBS         += $(filter-out -stdlib=libc++ -pthread , $(RFGLIBS))


INCLUDEDIR       = ./include/
SRCDIR           = ./src/
CXX	         += -I$(INCLUDEDIR) -I.
OUTOBJ	         = ./obj/

CC_FILES := $(wildcard src/*.cc)
HH_FILES := $(wildcard include/*.hh)
OBJ_FILES := $(addprefix $(OUTOBJ),$(notdir $(CC_FILES:.cc=.o)))

all: MakeZeroLeptonTree.x MakeSystematicsTree.x MakeSunTree.x DavidSucks.x DoGluinoOptimization.x DoSquarkOptimization.x DoCompressedOptimization.x DoStopOptimization.x

MakeZeroLeptonTree.x:  $(SRCDIR)MakeZeroLeptonTree.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o MakeZeroLeptonTree.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch MakeZeroLeptonTree.x

MakeSystematicsTree.x:  $(SRCDIR)MakeSystematicsTree.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o MakeSystematicsTree.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch MakeSystematicsTree.x

MakeSunTree.x:  $(SRCDIR)MakeSunTree.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o MakeSunTree.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch MakeSunTree.x

DavidSucks.x:  $(SRCDIR)DavidSucks.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o DavidSucks.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch DavidSucks.x

DoGluinoOptimization.x:  $(SRCDIR)DoGluinoOptimization.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o DoGluinoOptimization.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch DoGluinoOptimization.x

DoSquarkOptimization.x:  $(SRCDIR)DoSquarkOptimization.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o DoSquarkOptimization.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch DoSquarkOptimization.x

DoCompressedOptimization.x:  $(SRCDIR)DoCompressedOptimization.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o DoCompressedOptimization.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch DoCompressedOptimization.x

DoStopOptimization.x:  $(SRCDIR)DoStopOptimization.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o DoStopOptimization.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch DoStopOptimization.x

$(OUTOBJ)%.o: src/%.cc include/%.hh
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OUTOBJ)*.o 
	rm -f *.x
