#!/bin/bash
fuzzer:
mkdir testFiles  #CREATING DIRECTORY TO STOR .TXT FILES
clang++ -std=c++14 main.cpp functions.cpp -o main
chmod +x testGenerator.py
python3 ./testGenerator.py
chmod +x fuzz.sh ##make into executable
./fuzz.sh



clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main
LLVM_PROFILE_FILE="main.profraw" ./main < testFiles/square.txt > testFiles/squareOutput.txt
xcrun llvm-profdata merge -sparse classifier.profraw -o classifier.profdata
xcrun llvm-cov show ./main -instr-profile=classifier.profdata
