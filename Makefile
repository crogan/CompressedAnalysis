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

all: MakeCompressedNtuple.x DoStop0LOptimization.x DoStop1LOptimization.x

MakeCompressedNtuple.x:  $(SRCDIR)MakeCompressedNtuple.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o MakeCompressedNtuple.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch MakeCompressedNtuple.x

DoStop0LOptimization.x:  $(SRCDIR)DoStop0LOptimization.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o DoStop0LOptimization.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch DoStop0LOptimization.x

DoStop1LOptimization.x:  $(SRCDIR)DoStop1LOptimization.C $(OBJ_FILES) $(HH_FILES)
	$(CXX) $(CXXFLAGS) -o DoStop1LOptimization.x $(OUTOBJ)/*.o $(GLIBS) $ $<
	touch DoStop1LOptimization.x

$(OUTOBJ)%.o: src/%.cc include/%.hh
	mkdir -p obj/
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OUTOBJ)*.o 
	rm -f *.x
	rm -rf *.dSYM
