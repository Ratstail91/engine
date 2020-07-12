#source
SRC=$(wildcard *.cpp)

#config
ifeq ($(OS),Windows_NT)
GCC=g++
else
$(error Only windows is currently supported by the build system)
endif

#intermediate
OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

#output
OUTDIR=../out
OUT=$(addprefix $(OUTDIR)/,$(OUTFILE))

#targets
all: $(OBJ)
	$(GCC) -o $(OUT) $^ $(addprefix -D, $(DEFINES))

$(OBJDIR)/%.o: %.cpp
	$(GCC) -c -o $@ $< $(addprefix -D, $(DEFINES))

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

.PHONY: clean

clean:
ifeq ($(OS),Windows_NT)
	$(RM) *.o *.a *.exe
else ifeq ($(shell uname), Linux)
	find . -type f -name *.o -exec rm -f -r -v {} \;
	find . -type f -name *.a -exec rm -f -r -v {} \;
endif

rebuild: clean all
