#source
SRC=$(wildcard *.cpp)

#intermediate
OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

#output
OUTDIR=../out
LIB=$(addprefix $(OUTDIR)/,$(LIBFILE))
OUT=$(addprefix $(OUTDIR)/,$(OUTFILE))

INCLUDES += -I../core

#targets
none:
	$(error Please select a platform to build for)

windows: $(OBJ)
	$(GCC) -o $(OUT) $^ $(addprefix -D, $(DEFINES)) $(LIB)

linux: $(OBJ)
	$(error linux is not yet supported!)

switch: $(OBJ)
	$(error switch is not yet supported!)

$(OBJ): | $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(GCC) -c -o $@ $< $(INCLUDES) $(addprefix -D, $(DEFINES))

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
