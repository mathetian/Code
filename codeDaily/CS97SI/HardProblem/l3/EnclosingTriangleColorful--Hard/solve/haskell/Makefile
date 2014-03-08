OUTPUT_D=../../build/haskell
DATA_D=../../data
COMPILER=ghc -i$$HOME/.gettc/include/haskell -outputdir $(OUTPUT_D)
RUNNER=sh ../../bin/runner.sh

run = $(RUNNER) $1 $(OUTPUT_D)/EnclosingTriangleColorfulRunner $(DATA_D)/$2 $(OUTPUT_D)/$2

default : demo

setup :
	if [ ! -d $(OUTPUT_D) ]; then mkdir -p $(OUTPUT_D); fi

main : EnclosingTriangleColorfulRunner.hs EnclosingTriangleColorful.hs setup
	$(COMPILER) -o $(OUTPUT_D)/EnclosingTriangleColorfulRunner $<

test : EnclosingTriangleColorfulTest.hs EnclosingTriangleColorful.hs setup
	$(COMPILER) -o $(OUTPUT_D)/EnclosingTriangleColorfulTest $<
	$(OUTPUT_D)/EnclosingTriangleColorfulTest

demo : main
	$(call run,verbose,demo) 

sys : main
	$(call run,quiet,sys)

sysv : main
	$(call run,verbose,sys)

clean :
	rm -rf $(OUTPUT_D)
