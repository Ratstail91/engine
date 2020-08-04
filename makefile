#RM fix
ifeq ($(OS),Windows_NT)
#Windows 7:
#RM=del /y

#Windows 8.1 and up:
export RM=del /S
endif

#for this build sustem
export GCC=g++

export OUTDIR=out

#targets
none:
	$(error Please select a platform to build for)

windows-debug: export DEFINES += DEBUG_LOG
windows-debug: windows

windows: export DEFINES += PLATFORM_WINDOWS
windows: export LIBFILE = libengine.a
windows: export DLLFILE = engine.dll
windows: export OUTFILE = app.exe
windows: $(OUTDIR)
	$(MAKE) -C core windows
	$(MAKE) -C app windows

linux: $(OUTDIR)
	$(error linux is not yet supported!)

switch: $(OUTDIR)
	$(error switch is not yet supported!)

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
