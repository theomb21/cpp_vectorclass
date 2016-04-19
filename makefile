

############### DEFINE OS #######################
RMV = rm

############### DEFINE FLAGS ####################
DEF_FLAGS = 
#DEF_FLAGS +=   #add flag here

############### GIT VERSION? ####################
# Adds git version to DEF_FLAGS
IS_GIT_REPOSITORY := $(shell ((git status >/dev/null 2>&1) && echo yes) || (echo no))
ifeq ($(IS_GIT_REPOSITORY), yes)
    VERSION_STRING:=$(shell git rev-parse --short HEAD | tr -d '\n'; (git status --short | grep -v -q -e '^?') && echo '-mod')
    DEF_FLAGS += -DVERSION_STRING='"$(VERSION_STRING)"'
endif 

################# COMPILER ######################
CXX = g++

CXX_FLAGS =
CXX_FLAGS += -std=gnu++11
#CXX_FLAGS += -O2 
#CXX_FLAGS += -g
#CXX_FLAGS += -Wall 
#CXX_FLAGS += -fmessage-length=0

#################### INCLUDES ###################
INC  = -I./include 

################### SOURCES #####################
SRC_DIR = src
SRC_EXT = cpp

SRC   := $(shell find $(SRC_DIR) -type f -name \*.$(SRC_EXT))
vpath = $(SRC)

############## BUILD DIRECTORY ##################
BUILD_DIR = build

############## BINARY DIRECTORY #################
EXEC_DIR = bin

################### OBJECTS #####################
OBJ   := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRC:.$(SRC_EXT)=.o))

################### LINKER ######################
LIB  =


################### TARGETS #####################
status :
	@echo Version Git-repository : $(VERSION_STRING)
	@echo $(OBJ)
	@echo $(SRC)

bin/main : $(OBJ)
	rm -f bin/main
	$(CXX) $(CXX_FLAGS) $(DEF_FLAGS) $(INC) $(OBJ) -o ./bin/main $(LIB)

# Objekt-Dateien erzeugen
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(EXEC_DIR)
	$(CXX) $(CXX_FLAGS) $(DEF_FLAGS) $(INC) -c -o $@ $< $(LIB)

run/% : bin/%
	konsole --noclose -e ./$<

.PHONY : clean
clean :
	$(RMV) -r -f $(BUILD_DIR)/*

