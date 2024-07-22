#!/bin/bash

g++ main.cpp functions.cpp movesImpl.cpp -o main.out -std=c++17
./main.out
rm main.out
exit 0
