#!/bin/bash

g++ main.cpp functions.cpp movesImpl.cpp -o main.out
./main.out
rm main.out
exit 0
