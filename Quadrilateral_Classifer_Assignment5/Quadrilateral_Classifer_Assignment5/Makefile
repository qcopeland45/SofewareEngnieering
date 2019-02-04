fuzzer: 
	mkdir testFiles                   #CREATING DIRECTORY TO STORE .TXT FILES
	#clang++ -std=c++14 main.cpp functions.cpp -o main
	chmod +x testGenerator.py
	python3 ./testGenerator.py        #python file creates the shapes 
	chmod +x fuzz.sh                  ##make into executable
	#./fuzz.sh                         ##run the bash script
	

clean:
	rm -f main.o functions.o QuadClassifier Expected_output.txt main main1 main2 main3 main4 fuzz
	rm -f main.profraw main1.profraw main2.profraw main3.profraw main4.profraw master.profdata
	rm -f COVERAGE.txt 
	rm -rf testFiles main.dSYM main1.dSYM main2.dSYM main3.dSYM main4.dSYM


 classifier:
	-LLVM_PROFILE_FILE="classifier.profraw" ./classifier < test.txt
	xcrun llvm-profdata merge -sparse classifier.profraw -o classifier.profdata
	xcrun llvm-cov show ./classifier -instr-profile=classifier.profdata

	
