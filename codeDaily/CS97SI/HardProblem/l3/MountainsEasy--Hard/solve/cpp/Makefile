OUTPUT_D=../../build/cpp
DATA_D=../../data
COMPILER=g++ -std=gnu++0x -I$$HOME/.gettc/include/cpp
RUNNER=sh ../../bin/runner.sh

run = $(RUNNER) $1 $(OUTPUT_D)/MountainsEasyRunner $(DATA_D)/$2 $(OUTPUT_D)/$2

default : demo

setup :
	if [ ! -d $(OUTPUT_D) ]; then mkdir -p $(OUTPUT_D); fi

main : MountainsEasyRunner.cpp MountainsEasy.cpp setup
	$(COMPILER) -o $(OUTPUT_D)/MountainsEasyRunner $<

test : MountainsEasyTest.cpp MountainsEasy.cpp setup
	$(COMPILER) -lboost_unit_test_framework -o $(OUTPUT_D)/MountainsEasyTest $<
	$(OUTPUT_D)/MountainsEasyTest

demo : main
	$(call run,verbose,demo) 

sys : main
	$(call run,quiet,sys)

sysv : main
	$(call run,verbose,sys)

clean :
	rm -rf $(OUTPUT_D)
