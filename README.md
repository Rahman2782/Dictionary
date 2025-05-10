# Dictionary

Command-line based dictionary app that reads through csv files to show the definition of a desired word.
Reads from a .csv file and produces a formatted output with optional display settings

## Features 

- Searching for definitions of English words
- Displays the part of speech if available
- Optionally displays multiple definitions of the same word (if applicable)
- Modular OOP design with readable components

## Concepts/Skills Demonstrated

- Advanced C++ (dynamic memory w/ smart pointers, file I/O, OOP)
- Enums
- Stream manipulation with strings using std::ostringstream and std::istringstream
- Error handling

## Prerequisites

- C++ 17 compatible compiler
- Command line terminal

## To Build

g++ -std=c++17 -o dictionary main.cpp Dictionary.cpp
./dictionary data.csv
