#include <fstream>
#include <iostream>
#include <string>
#include "wordArray.hpp"

using namespace std;
/*
Notes on the dictionary
longest word length - 15 letters
number of words by length
1 letter- 0
2 letters- 124
3 letters- 1341
4 letters- 5625
5 letters- 12917
6 letters- 22938
7 letters- 34167
8 letters- 41882
9 letters- 42290
10 letters- 36593
11 letters- 28617
12 letters- 20775
13 letters- 14185
14 letters- 9312
15 letters- 5877


  return 0;
max score - 47 points
*/
int calcScore(string word)
{
    int sum = 0;
    for(int i = 0; i < word.length(); i++)
    {
        if(word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'L' || word[i] == 'N' || word[i] == 'O' || word[i] == 'R' || word[i] == 'S' || word[i] == 'T' || word[i] == 'U')
            sum += 1;
        else if(word[i] == 'D' || word[i] == 'G')
            sum += 2;
        else if(word[i] == 'B' || word[i] == 'C' || word[i] == 'M' || word[i] == 'P')
            sum += 3;
        else if(word[i] == 'F' || word[i] == 'V' || word[i] == 'W' || word[i] == 'Y'|| word[i] == 'H')
            sum += 4;
        else if(word[i] == 'K')
            sum += 5;
        else if(word[i] == 'J' || word[i] == 'X')
            sum += 8;
        else if(word[i] == 'Q' || word[i] == 'Z')
            sum += 10;
    }
    return sum; 
}

int main(){
    ifstream myStream("ScrabbleDict.txt");
    wordArray words[15];//array of objects
    string word;
    int length;
    int score;
    while(getline(myStream, word))
    {
        length = word.length();
        score = calcScore(word);
        switch(length)
        {
            case 1:
            words[0].addWord(score, word);
            break;
            case 2:
            words[1].addWord(score, word);
            break;
            case 3:
            words[2].addWord(score, word);
            break;
            case 4:
            words[3].addWord(score, word);
            break;
            case 5:
            words[4].addWord(score, word);
            break;
            case 6:
            words[5].addWord(score, word);
            break;
            case 7:
            words[6].addWord(score, word);
            break;
            case 8:
            words[7].addWord(score, word);
            break;
            case 9:
            words[8].addWord(score, word);
            break;
            case 10:
            words[9].addWord(score, word);
            break;
            case 11:
            words[10].addWord(score, word);
            break;
            case 12:
            words[11].addWord(score, word);
            break;
            case 13:
            words[12].addWord(score, word);
            break;
            case 14:
            words[13].addWord(score, word);
            break;
            case 15:
            words[14].addWord(score, word);
            break;
        }
    }
//   cout << "Hi welcome to scrabble helper." << endl;
//   string userInput;
//   while(!false){
//     cout << "Please enter the 7 letters that you have" << endl;
//     cin >> userInput;
//     cout << "You inputed: " << userInput << endl;
//     cout << "Are this you tiles? Press Y for yes and N for no." << endl;
//     char choose;
//     cin >> choose;
//     while(!false){
//       if(choose == 'y' || choose == 'Y'){
//         break;
//       }else if(choose == 'n' || choose == 'N'){
//         break;
//       }else{
//         cout << "That is not a valid input. Please enter a valid input." << endl;
//         cin >> choose;
//       }
//     }
//     break;
//   }
  string tiles = "ZZZ";
  int resultScore = 30;
  node* temp;
  temp = words[2].searchTiles(resultScore, tiles);
  if(temp != nullptr)
  {
      cout << temp -> word << endl;
  }
  else {
      cout << "fail"<< endl;
  }
  //words[2].print();
  return 0;
  
}
