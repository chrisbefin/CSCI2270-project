# Scrabble-Helper

Scrabble Helper is a group final project written in C++ and created for CSCI 2270- Data Structures during Spring 2019. The program is designed to help you
get better at the popular board game Scrabble. You input the tiles available in your hand as well as the tiles already on the board and 
it spits out the best possible word for you to play. This program also provides a convenient score counter to help you easily keep
track of how many points each player has.
The underlying data structure for storing our dictionary is an array of hash tables, where each index of the array corresponds to the point
value of the words hashed into the hash table located there.

Files in this repository:

Project Report (1).pdf  - An overview of the project along with some example output
ScrabbleDict.txt        - The dictionary file that is read in to the program
intro.txt               - This file is printed at the beginning of program execution
driver.cpp              - Contains the program's main routine (reads in dict, gets player input, instantiates objects etc.)
scrabbleHashTable.hpp   - The header file for the hash table class
scrabbleHashTable.cpp   - the implementation for the hash table class
