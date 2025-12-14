# gcc src/main.cpp -Wall -o test

EXE="pattern-game"

cmake .

make

./$EXE
