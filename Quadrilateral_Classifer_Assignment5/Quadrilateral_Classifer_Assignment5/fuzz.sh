#!/bin/bash


clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main
LLVM_PROFILE_FILE="main.profraw" ./main < testFiles/square.txt > testFiles/squareOutput.txt
#./main < testFiles/square.txt > testFiles/squareOutput.txt
#diff testFiles/squareOutput.txt testFiles/squareExpected.txt

err=$?
if [ $err -eq 0 ]
then
    echo "square tests passed!"
elif [ $err -eq 1 ]
then
    echo "sqare tests failed!"
else
    echo "square tests failed to run properly!"
fi


clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main1
LLVM_PROFILE_FILE="main1.profraw" ./main1 < testFiles/rectangle.txt > testFiles/rectangleOutput.txt
#./main < testFiles/rectangle.txt > testFiles/rectangleOutput.txt
#diff testFiles/rectangleOutput.txt testFiles/rectangleExpected.txt

err2=$?
if [ $err2 -eq 0 ]
then
    echo "rectangle tests passed!"
elif [ $err2 -eq 1 ]
then
    echo "rectangle tests failed!"
else
    echo "rectangle tests failed to run properly"
fi



clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main2
LLVM_PROFILE_FILE="main2.profraw" ./main2 < testFiles/rhombus.txt > testFiles/rhombusOutput.txt
#./main < testFiles/rhombus.txt > testFiles/rhombusOutput.txt
#diff testFiles/rhombusOutput.txt testFiles/rhombusExpected.txt

err3=$?
if [ $err3 -eq 0 ]
then
    echo "rhombus tests passed!"
elif [ $err3 -eq 1 ]
then
    echo "rhombus tests failed!"
else
    echo "rhombus tests failed to run properly"
fi



clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main3
LLVM_PROFILE_FILE="main3.profraw" ./main3 < testFiles/trapezoid.txt > testFiles/trapezoidOutput.txt
#./main < testFiles/trapezoid.txt > testFiles/trapezoidOutput.txt
#diff testFiles/trapezoidOutput.txt testFiles/trapezoidExpected.txt

err4=$?
if [ $err4 -eq 0 ]
then
    echo "trapezoid tests passed!"
    echo "OKAY, ALL TESTS PASSED!"
elif [ $err4 -eq 1 ]
then
    echo "trapezoid tests failed!"
else
    echo "trapezoid tests failed to run properly"
fi

xcrun llvm-profdata merge -sparse main.profraw main1.profraw main2.profraw main3.profraw -o master.profdata
xcrun llvm-cov show ./main -instr-profile=master.profdata
