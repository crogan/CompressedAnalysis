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

all: MakeCompressedNtuple.x DoStopOptimization.x

MakeCompressedNtuple.x:  $(SRCDIR)MakeCompressedNtuple.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o MakeCompressedNtuple.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch MakeCompressedNtuple.x

DoStopOptimization.x:  $(SRCDIR)DoStopOptimization.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o DoStopOptimization.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch DoStopOptimization.x

$(OUTOBJ)%.o: src/%.cc include/%.hh
	mkdir -p obj/
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OUTOBJ)*.o 
	rm -f *.x
	rm -rf *.dSYM
