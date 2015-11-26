# this path may be different on your system. adjust it accordingly.
CAPSTONE_PATH=/usr/local/Cellar/capstone/3.0.4/include

all:
	make clean;
	make x86; make x64;

x64:
	cd tests; rm -rf x64; mkdir x64; cd x64;
	clang -m64 src/main.m src/ropnroll/ropnroll.c src/ropnroll/macho/rnr_macho.c src/ropnroll/glue.m test.s -framework Foundation -framework IOKit -I$(CAPSTONE_PATH) -Llib/ -lcapstone.3 -o tests/x64/test
	cd tests/x64/; ./test;

x86:
	cd tests; rm -rf x86; mkdir x86; cd x86;
	clang -m32 src/main.m src/ropnroll/ropnroll.c src/ropnroll/macho/rnr_macho.c src/ropnroll/glue.m test.s -framework Foundation -framework IOKit -I$(CAPSTONE_PATH) -Llib/ -lcapstone.3 -o tests/x86/test32
	cd tests/x86/; ./test32;

clean:
	rm -rf tests;
	mkdir tests;
