#!/bin/bash


clang++ -std=c++14 main.cpp functions.cpp -o myMain
clang++ -std=c++14 mainNicole.cpp -o nicoleMain

./myMain < testFiles/rectangle.txt > testFiles/myRectOutput.txt
./nicoleMain < testFiles/rectangle.txt > testFiles/nicRectOutput.txt
diff testFiles/myRectOutput.txt testFiles/nicRectOutput.txt


errorCount=0
#err=$?
#if [ $err -eq 0 ]
#then
#    echo "square tests passed!"
#elif [ $err -eq 1 ]
#then
#    echo "sqare tests failed!"
#else
#    echo "square tests failed to run properly!"
#fi

#./myMain < testFiles/rectangle.txt > testFiles/myRectOutput.txt
#./nicoleMain < testFiles/rectangle.txt > testFiles/nicRectOutput.txt
for i in `seq 1 1000`;
do
    output="output"
    expected="expected"
    ./myMain < "testFiles/$i.txt" > testFiles/myOutput$i.txt
    ./nicoleMain < "testFiles/$i.txt" > testFiles/herOutput$i.txt
    diff testFiles/myOutput$i.txt testFiles/herOutput$i.txt

    randErr=$?
    if [ $randErr -eq 0 ]
    then
        echo "test $i.txt random passed!"
    elif [ $randErr -eq 1 ]
    then
        echo "test $i.txt random failed!"
        ((errorCount++))
    else
        echo "test $i.txt random didn't run properly"
    fi
done
echo $errorCount
