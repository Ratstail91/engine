#RM fix
ifeq ($(OS),Windows_NT)
	#for github
	ifneq ($0,bash)
		#Windows 7:
		#RM=del /y

		#Windows 8.1 and up:
		export RM=del /S
	endif
endif

#for this build sustem
export GCC=g++

export OUTDIR=out

DEBUG=DEBUG_LOG

#targets
none:
	$(error Please select a platform to build for)

windows-debug: clean
windows-debug: export DEFINES += $(DEBUG)
windows-debug: windows

windows: export DEFINES += PLATFORM_WINDOWS
windows: export LIBFILE = libengine.a
windows: export DLLFILE = engine.dll
windows: export OUTFILE = app.exe
windows: $(OUTDIR)
	$(MAKE) -C core windows
	$(MAKE) -C app windows

linux-debug: clean
linux-debug: export DEFINES += $(DEBUG)
linux-debug: linux

linux: export DEFINES += PLATFORM_LINUX
linux: export LIBFILE = engine
linux: export DLLFILE = engine
linux: export OUTFILE = app
linux: $(OUTDIR)
	$(MAKE) -C core linux
	$(MAKE) -C app linux

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
