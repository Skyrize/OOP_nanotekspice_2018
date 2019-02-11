#!/bin/bash

echo "BUILDING .."

make

echo "BUILD DONE."

echo "TESTING PARSING :"

echo "" | ./nanotekspice samples/5input_and.nts a=0 b=0 c=0 d=0 e=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/5input_and.nts a=0 b=0 c=0 d=0 e=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/5input_nand.nts a=0 b=0 c=0 d=0 e=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/5input_nand.nts a=0 b=0 c=0 d=0 e=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/5input_nor.nts a=0 b=0 c=0 d=0 e=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/5input_nor.nts a=0 b=0 c=0 d=0 e=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/5input_or.nts a=0 b=0 c=0 d=0 e=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/5input_or.nts a=0 b=0 c=0 d=0 e=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/adder.nts a0=0 a1=0 a2=0 a3=0 b0=0 b1=0 b2=0 b3=0 cin=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/adder.nts a0=0 a1=0 a2=0 a3=0 b0=0 b1=0 b2=0 b3=0 cin=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/and.nts a=0 b=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/and.nts a=0 b=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/counter.nts reset=0 clock=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/counter.nts reset=0 clock=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/d_latch.nts clock=0 data=0 set=0 reset=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/d_latch.nts clock=0 data=0 set=0 reset=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/decoder.nts a0=0 a1=0 a2=0 a3=0 strobe=0 inhibit=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/decoder.nts a0=0 a1=0 a2=0 a3=0 strobe=0 inhibit=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/johnson.nts clockup=0 master_reset=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/johnson.nts clockup=0 master_reset=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/mandion.nts a=0 b=0 c=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/mandion.nts a=0 b=0 c=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/nand.nts a=0 b=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/nand.nts a=0 b=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/nor.nts a=0 b=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/nor.nts a=0 b=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/not.nts i0=0 i1=0 i2=0 i3=0 i4=0 i5=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/not.nts i0=0 i1=0 i2=0 i3=0 i4=0 i5=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/or.nts a=0 b=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/or.nts a=0 b=0\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/sample.nts
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/sample.nts\n"
else
    let "passed += 1"
fi

echo "" | ./nanotekspice samples/xor.nts a=0 b=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/xor.nts a=0 b=0\n"
else
    let "passed += 1"
fi

echo "TESTING PARSING DONE. RESULT : " $passed"/17 TESTS PASSED."
echo -e "\nTESTING BONUS :"

let "passed = 0"
echo "" | ./nanotekspice samples/romxor.nts dump=0 clock=0 reset=0
if [ $? != 0 ]; then
    echo -e  "FAILED Test ./nanotekspice samples/romxor.nts dump=0 clock=0 reset=0\n"
else
    let "passed += 1"
fi

echo "TESTING BONUS DONE. RESULT : " $passed"/1 TESTS PASSED."