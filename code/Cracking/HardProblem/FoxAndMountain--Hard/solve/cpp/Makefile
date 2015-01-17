OUTPUT_D=../../build/cpp
DATA_D=../../data
COMPILER=g++ -std=gnu++0x -I$$HOME/.gettc/include/cpp
RUNNER=sh ../../bin/runner.sh

run = $(RUNNER) $1 $(OUTPUT_D)/FoxAndMountainRunner $(DATA_D)/$2 $(OUTPUT_D)/$2

default : demo

setup :
	if [ ! -d $(OUTPUT_D) ]; then mkdir -p $(OUTPUT_D); fi

main : FoxAndMountainRunner.cpp FoxAndMountain.cpp setup
	$(COMPILER) -o $(OUTPUT_D)/FoxAndMountainRunner $<

test : FoxAndMountainTest.cpp FoxAndMountain.cpp setup
	$(COMPILER) -lboost_unit_test_framework -o $(OUTPUT_D)/FoxAndMountainTest $<
	$(OUTPUT_D)/FoxAndMountainTest

demo : main
	$(call run,verbose,demo) 

sys : main
	$(call run,quiet,sys)

sysv : main
	$(call run,verbose,sys)

clean :
	rm -rf $(OUTPUT_D)
