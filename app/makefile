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
	$(GCC) -o $(OUT) $^ $(addprefix -D, $(DEFINES)) $(LIB)

switch: $(OBJ)
	$(error switch is not yet supported!)

$(OBJ): | $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(GCC) -c -o $@ $< $(INCLUDES) $(addprefix -D, $(DEFINES))

$(OBJDIR):
	mkdir $(OBJDIR)
