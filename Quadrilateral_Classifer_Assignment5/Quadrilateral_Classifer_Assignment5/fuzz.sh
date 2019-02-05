#!/bin/bash

#clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main
clang++ -std=c++14 -O1 -g -fsanitize=address -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main
LLVM_PROFILE_FILE="main.profraw" ./main < testFiles/square.txt > testFiles/squareOutput.txt
#./main < testFiles/square.txt > testFiles/squareOutput.txt
diff testFiles/squareOutput.txt testFiles/squareExpected.txt

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

#clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main1
clang++ -std=c++14 -O1 -g -fsanitize=address -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main1
LLVM_PROFILE_FILE="main1.profraw" ./main1 < testFiles/rectangle.txt > testFiles/rectangleOutput.txt
#./main < testFiles/rectangle.txt > testFiles/rectangleOutput.txt
diff testFiles/rectangleOutput.txt testFiles/rectangleExpected.txt

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


#clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main2
clang++ -std=c++14 -O1 -g -fsanitize=address -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main2
LLVM_PROFILE_FILE="main2.profraw" ./main2 < testFiles/rhombus.txt > testFiles/rhombusOutput.txt
#./main < testFiles/rhombus.txt > testFiles/rhombusOutput.txt
diff testFiles/rhombusOutput.txt testFiles/rhombusExpected.txt

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


#clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main3
clang++ -std=c++14 -O1 -g -fsanitize=address -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main3
LLVM_PROFILE_FILE="main3.profraw" ./main3 < testFiles/trapezoid.txt > testFiles/trapezoidOutput.txt
#./main < testFiles/trapezoid.txt > testFiles/trapezoidOutput.txt
diff testFiles/trapezoidOutput.txt testFiles/trapezoidExpected.txt

err4=$?
if [ $err4 -eq 0 ]
then
    echo "trapezoid tests passed!"
#    echo "OKAY, ALL TESTS PASSED!"
elif [ $err4 -eq 1 ]
then
    echo "trapezoid tests failed!"
else
    echo "trapezoid tests failed to run properly"
fi


#clang++ -std=c++14 -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main4
clang++ -std=c++14 -O1 -g -fsanitize=address -fprofile-instr-generate -fcoverage-mapping main.cpp functions.cpp -o main4
LLVM_PROFILE_FILE="main4.profraw" ./main4 < testFiles/parallelogram.txt > testFiles/parallelogramOutput.txt
diff testFiles/parallelogramOutput.txt testFiles/parallelogramExpected.txt

err5=$?
if [ $err5 -eq 0 ]
then
    echo "parallelogram tests passed!"
    echo "OKAY, ALL TESTS PASSED!"
elif [ $err5 -eq 1 ]
then
    echo "parallelogram tests failed!"

else
    echo "parallelogram tests failed to run properly"
fi

## running colinear points to an expected output key
## due to the difficulty I chose to pick the smallest co-linear points and scale them
## I found it hard to generate truly random points that were co-linear so the scalling technique worked much better
#./main < testFiles/colinear.txt > testFiles/colinearOutput.txt
#diff testFiles/colinearOutput.txt testFiles/colinearExpected.txt

#for i in `seq 1 97`;
#do
#    output="output"
#    expected="Expected"
#    ./main < "testFiles/colinear$i.txt" > "testFiles/colinear$outputput$i.txt"
#    diff "testFiles/colinear$outputput$i.txt" "testFiles/colinear$expected$i.txt"
#
#    lineErr=$?
#    if [ $lineErr -eq 0 ]
#    then
#        echo "colinear $icolinear.txt test passed!"
#        echo "OKAY, ALL SCALLING TESTS PASSED!"
#    elif [ $lineErr -eq 1 ]
#    then
#        echo "colinear $icolinear.txt test failed!"
#    else
#        echo "colinear $icolinear.txt tests didn't run properly!"
#    fi
#done


for i in `seq 1 1000`;
do
    output="output"
    expected="expected"
    ./main < "testFiles/$i.txt" > "testFiles/$output$i.txt"
    ./main1 < "testFiles/$i.txt" > "testFiles/$expected$i.txt"
    diff "testFiles/$output$i.txt" "testFiles/$expected$i.txt"

    randErr=$?
    if [ $randErr -eq 0 ]
    then
        echo "test $i.txt random passed!"
    elif [ $randErr -eq 1 ]
    then
        echo "test $i.txt random failed!"
    else
        echo "test $i.txt random didn't run properly"
    fi
done


#for testing to see the out put in the terminal comment loop out when finsished
#for i in `seq 1 1000`;
#do
#    LLVM_PROFILE_FILE="testFiles/$i.profraw" ./main < testFiles/$i.txt
#done

##for testing to see the out put in the terminal
#LLVM_PROFILE_FILE="main.profraw" ./main < testFiles/square.txt
#LLVM_PROFILE_FILE="main.profraw" ./main < testFiles/rectangle.txt
#LLVM_PROFILE_FILE="main.profraw" ./main < testFiles/trapezoid.txt
#LLVM_PROFILE_FILE="main.profraw" ./main < testFiles/rhombus.txt
#LLVM_PROFILE_FILE="main.profraw" ./main < testFiles/parallelogram.txt



# merging files then writing the coverage output to a text file called COVERAGE.txt
xcrun llvm-profdata merge -sparse main.profraw main1.profraw main2.profraw main3.profraw main4.profraw -o master.profdata
xcrun llvm-cov show ./main -instr-profile=master.profdata > COVERAGE.txt
#xcrun llvm-cov show ./main1 -instr-profile=master.profdata >> COVERAGE.txt
