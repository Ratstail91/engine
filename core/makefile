#source
SRC=$(wildcard *.cpp)

#intermediate
OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

#output
OUTDIR=../out
LIB=$(addprefix $(OUTDIR)/,$(LIBFILE))
DLL=$(addprefix $(OUTDIR)/,$(DLLFILE))

#for exporting the dll
DEFINES+=BUILD_DLL

#targets
none:
	$(error Please select a platform to build for)

windows: $(OBJ)
	$(GCC) -shared -o $(DLL) $^ $(addprefix -D, $(DEFINES)) -Wl,--out-implib,$(LIB)

linux: $(OBJ)
	$(GCC) -shared -o $(addprefix $(OUTDIR)/lib,$(addsuffix .so,$(DLLFILE))) $^ $(addprefix -D, $(DEFINES)) -Wl,--out-implib,$(addprefix $(OUTDIR)/lib,$(addsuffix .a,$(LIBFILE)))

switch: $(OBJ)
	$(error switch is not yet supported!)

$(OBJ): | $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(GCC) -c -fpic -o $@ $< $(addprefix -D, $(DEFINES))

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
