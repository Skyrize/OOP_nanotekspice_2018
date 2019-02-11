#!/bin/bash


./nanotekspice samples/5input_and.nts a=0 b=0 c=0 d=0 e=0
if [ $? != 0 ]; then
    echo -e "FAILED Test ./nanotekspice samples/5input_and.nts a=0 b=0 c=0 d=0 e=0\n"
else
    echo -e "SUCCESS Test ./nanotekspice samples/5input_and.nts a=0 b=0 c=0 d=0 e=0\n"
fi

./nanotekspice samples/5input_nand.nts a=0 b=0 c=0 d=0 e=0
if [ $? != 0 ]; then
    echo -e "FAILED Test ./nanotekspice samples/5input_nand.nts a=0 b=0 c=0 d=0 e=0\n"
else
    echo -e "SUCCESS Test ./nanotekspice samples/5input_nand.nts a=0 b=0 c=0 d=0 e=0\n"
fi

./nanotekspice samples/5input_nor.nts a=0 b=0 c=0 d=0 e=0
if [ $? != 0 ]; then
    echo -e "FAILED Test ./nanotekspice samples/5input_nor.nts a=0 b=0 c=0 d=0 e=0\n"
else
    echo -e "SUCCESS Test ./nanotekspice samples/5input_nor.nts a=0 b=0 c=0 d=0 e=0\n"
fi

./nanotekspice samples/5input_or.nts a=0 b=0 c=0 d=0 e=0
if [ $? != 0 ]; then
    echo -e "FAILED Test ./nanotekspice samples/5input_or.nts a=0 b=0 c=0 d=0 e=0\n"
else
    echo -e "SUCCESS Test ./nanotekspice samples/5input_or.nts a=0 b=0 c=0 d=0 e=0\n"
fi

./nanotekspice samples/adder.nts a0=0 a1=0 a2=0 a3=0 b0=0 b1=0 b2=0 b3=0 cin=0
if [ $? != 0 ]; then
    echo -e "FAILED Test ./nanotekspice samples/adder.nts a0=0 a1=0 a2=0 a3=0 b0=0 b1=0 b2=0 b3=0 cin=0\n"
else
    echo -e "SUCCESS Test ./nanotekspice samples/adder.nts a0=0 a1=0 a2=0 a3=0 b0=0 b1=0 b2=0 b3=0 cin=0\n"
fi