OUTPUT_D=../../build/haskell
DATA_D=../../data
COMPILER=ghc -i$$HOME/.gettc/include/haskell -outputdir $(OUTPUT_D)
RUNNER=sh ../../bin/runner.sh

run = $(RUNNER) $1 $(OUTPUT_D)/DengklekPaintingSquaresRunner $(DATA_D)/$2 $(OUTPUT_D)/$2

default : demo

setup :
	if [ ! -d $(OUTPUT_D) ]; then mkdir -p $(OUTPUT_D); fi

main : DengklekPaintingSquaresRunner.hs DengklekPaintingSquares.hs setup
	$(COMPILER) -o $(OUTPUT_D)/DengklekPaintingSquaresRunner $<

test : DengklekPaintingSquaresTest.hs DengklekPaintingSquares.hs setup
	$(COMPILER) -o $(OUTPUT_D)/DengklekPaintingSquaresTest $<
	$(OUTPUT_D)/DengklekPaintingSquaresTest

demo : main
	$(call run,verbose,demo) 

sys : main
	$(call run,quiet,sys)

sysv : main
	$(call run,verbose,sys)

clean :
	rm -rf $(OUTPUT_D)
