#RM fix
ifeq ($(OS),Windows_NT)
#Windows 7:
#RM=del /y

#Windows 8.1 and up:
RM=del /S
endif

#config (top-level make only)
ifeq ($(MAKELEVEL), 0)
	ifeq ($(OS),Windows_NT)
		export DEFINES += PLATFORM_WINDOWS
		export OUTFILE = main.exe
	else ifeq ($(shell uname), Linux)
		export DEFINES += PLATFORM_LINUX
		export OUTFILE = main
	endif
endif

OUTDIR=out

#targets
all: $(OUTDIR)
	$(MAKE) -C core

ifeq ($(MAKELEVEL), 0)
debug: export DEFINES += DEBUG_LOG
endif
debug: rebuild

rebuild:
	$(MAKE) -i clean all

$(OUTDIR):
	mkdir $(OUTDIR)

.PHONY: clean

clean:
ifeq ($(OS),Windows_NT)
	$(RM) *.o *.a *.exe
	rmdir /S /Q $(OUTDIR)
else ifeq ($(shell uname), Linux)
	find . -type f -name '*.o' -exec rm -f -r -v {} \;
	find . -type f -name '*.a' -exec rm -f -r -v {} \;
	rm $(OUTDIR)/* -f
	find . -empty -type d -delete
endif
