#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
bool hasCharacter(string word, char c)
{
  for(int i = 0; i < word.length(); i++)
  {
    if(word[i] == c)
      return true;
  }
  return false;
}
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

void dispLayMenu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Enter new tiles" << endl;
  cout << "2. Get best word" << endl;
  cout << "3. Check if word is valid" << endl;
  cout << "4. Play off of other tiles(perpendicular)" << endl;
  cout << "5. Play off of another word(parallel)" << endl;
  cout << "6. Quit" << endl;
}

string UpperCaseName(string name){
    int letter;
    char n;
    string UpperCaseWord;
    for(int i = 0; i<name.length(); i++){
        if(name[i] >= 'a' && name[i] <= 'z'){
            n = int(name[i]);
            letter = n - 32;
            UpperCaseWord = UpperCaseWord + char(letter);
        }else if(name[i] != ' ' && name[i] >= 'A' && name[i] <= 'Z'){
            n = int(name[i]);
            letter = n;
            UpperCaseWord = UpperCaseWord + char(letter);
        }
    }
    return UpperCaseWord;
}


int checkString(string word){
  int counter = 0;
  for(int i = 0; i < word.length(); i++){
    if(word[i] >= 'A' && word[i] <= 'Z'){
      counter++;
    }
  }
  return counter;
}

template <typename Iterator>
bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Mark Nelson http://marknelson.us */
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator i1 = first;
   Iterator i2 = last;
   ++i1;
   if (last == i1)
      return false;
   i1 = last;
   --i1;
   i1 = k;
   --i2;
   while (first != i1)
   {
      if (*--i1 < *i2)
      {
         Iterator j = k;
         while (!(*i1 < *j)) ++j;
         std::iter_swap(i1,j);
         ++i1;
         ++j;
         i2 = k;
         std::rotate(i1,j,last);
         while (last != j)
         {
            ++j;
            ++i2;
         }
         std::rotate(k,i2,last);
         return true;
      }
   }
   std::rotate(first,k,last);
   return false;
}

int main(){
    ifstream introStream("intro.txt");
    string introline;
    while(getline(introStream, introline))
      cout << introline << endl;
  cout << endl;
    ifstream myStream("ScrabbleDict.txt");
    vector<wordArray> words;
    long int sizes[] = {124,1341,5625,12917,22938,34167,41882,42290,36593,28617,20775,14185,9312,5877};
    //                   2 ,  3 ,  4 ,  5  ,  6  ,  7  ,  8  ,  9  , 10  , 11  , 12  , 13  , 14 , 15
    for (int i=0;i<14;i++) {
      wordArray n(sizes[i]*1.3);
      words.push_back(n);
    }
    string word;
    int length;
    int score;
    while(getline(myStream, word))
    {
        length = word.length()-1;
        score = calcScore(word);
        word = word.substr(0,length);
        switch(length)
        {
            case 2:
            words[0].addWord(score, word);
            break;
            case 3:
            words[1].addWord(score, word);
            break;
            case 4:
            words[2].addWord(score, word);
            break;
            case 5:
            words[3].addWord(score, word);
            break;
            case 6:
            words[4].addWord(score, word);
            break;
            case 7:
            words[5].addWord(score, word);
            break;
            case 8:
            words[6].addWord(score, word);
            break;
            case 9:
            words[7].addWord(score, word);
            break;
            case 10:
            words[8].addWord(score, word);
            break;
            case 11:
            words[9].addWord(score, word);
            break;
            case 12:
            words[10].addWord(score, word);
            break;
            case 13:
            words[11].addWord(score, word);
            break;
            case 14:
            words[12].addWord(score, word);
            break;
            case 15:
            words[13].addWord(score, word);
            break;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////
  string userChoose;
  string userTile;
  string read;
  string newUserTile;
  cout << "Hi! Welcome to Scrabble Helper" << endl;
  cout << "Please enter your 7 tiles" << endl;
  getline(cin, userTile);
  newUserTile = UpperCaseName(userTile);
  if(checkString(newUserTile) != 7){
    while(!false){
      cout << "This input is not valid. Please enter the tiles correctly" << endl;
      getline(cin, userTile);
      newUserTile = UpperCaseName(userTile);
      if(checkString(newUserTile) == 7){
        break;
      }
    }
  }
  score = calcScore(newUserTile);
  cout << "You have entered these 7 letters: " << newUserTile << endl << endl;
  while(userChoose != "6"){
    dispLayMenu();
    getline(cin, userChoose);
    cout << endl;
    if(userChoose >= "1" && userChoose <= "9"){
      switch(stoi(userChoose)){
        case 1: {
          cout << "Please enter the new letters" << endl;
          getline(cin, userTile);
          newUserTile = UpperCaseName(userTile);
          if(checkString(newUserTile) != 7){
            while(!false){
              cout << "This input is not valid. Please enter the tiles correctly" << endl;
              getline(cin, userTile);
              newUserTile = UpperCaseName(userTile);
              if(checkString(newUserTile) == 7){
                break;
              }
            }
          }
        }
          cout << "You have entered these 7 letters: " << newUserTile << endl << endl;
          score = calcScore(newUserTile);
          break;
        case 2: {
          node *pres = words[5].searchTiles(score,newUserTile);
          node *max = NULL;
          int length = newUserTile.length();
          char letters[length];
          if (pres == NULL) {
            string search;
            for (int i=2; i<newUserTile.length();i++) {
              do
              {
                  search = std::string(newUserTile.begin(), newUserTile.begin() + i);
                  pres = words[search.length()-2].searchTiles(calcScore(search),search);
                  if (max == NULL && pres!=NULL) {
                    max = pres;
                  }
                  if (pres!=NULL&&calcScore(search)>calcScore(max->word)) {
                    max = pres;
                  }

              } while (next_combination(newUserTile.begin(), newUserTile.begin() + i, newUserTile.end()));
            }
            if (max == NULL) {
              cout << "There are no possible combimations" << endl << endl;
            }
            else {
              cout << max->word << " is the best word you can play" << endl << endl;
            }
          }
          else {
            cout<< pres->word << " is the best word you can play" << endl << endl;
          }
          break;
        }
        case 3: {
          string input;
          cout << "Enter the word you would like to check:" << endl;
          getline(cin, input);
          input = UpperCaseName(input);
          cout << input;
          if (words[input.length()-2].searchWord(calcScore(input),input)) {
            cout <<" is a valid word" << endl;
          }
          else {
            cout << " is not a valid word" << endl;
          }
          cout << endl;
          break;
        }
        case 4: {
            string playTiles;
            string totalTiles;
            string substring;
            node* temp;
            cout << "Enter all tiles that you can play off of as a single string of characters:" << endl;
            getline(cin, playTiles);
            playTiles = UpperCaseName(playTiles);
            for(int x = 0; x < playTiles.length(); x++)
            {
              cout << "Playing off of the letter " << playTiles[x] << ":" << endl;
              totalTiles = playTiles[x] + newUserTile;
              score = calcScore(totalTiles);
              node *pres = NULL;
              node *max = NULL;
              int length = totalTiles.length();
              char letters[length];
              if (pres == NULL) {
                string search;
                for (int i=2; i<totalTiles.length();i++) {
                  do
                  {
                      search = std::string(newUserTile.begin(), newUserTile.begin() + i);
                      totalTiles = playTiles[x] + search;
                      //cout << totalTiles << endl;
                      substring = totalTiles.substr(0,1);
                      pres = words[totalTiles.length() - 2].searchTilesWord(score,totalTiles, substring);
                      if (max == NULL && pres!=NULL) {
                        max = pres;
                      }
                      if (pres!=NULL&&calcScore(search)>calcScore(max->word)) {
                          max = pres;
                      }
    
                  } while (next_combination(newUserTile.begin(), newUserTile.begin() + i, newUserTile.end()));
                }
                
                if (max == NULL) {
                  cout << "There is no word to play with this letter." << endl << endl;
                }
                else {
                  cout << max->word << " is the best word to play." << endl << endl;
                }
              }
              else {
                cout<< pres->word << " is the best word to play." << endl << endl;
              }
                }
            break;
        }
        case 5: {
            cout << "Enter the word you would like to play off of: " << endl;
            string playWord;
            string allTiles;
            node *pres= NULL;
            node *max=NULL;
            string search;
            getline(cin, playWord);
            playWord = UpperCaseName(playWord);
            allTiles = playWord + newUserTile;
            for (int i=1; i<newUserTile.length();i++) {
              do
              {
                  search = std::string(newUserTile.begin(), newUserTile.begin() + i);
                  allTiles = playWord + search;
                  pres = words[allTiles.length()-2].searchTilesWord(calcScore(allTiles),allTiles,playWord);
                  if (max == NULL && pres!=NULL) {
                    max = pres;
                  }
                  if (pres!=NULL&&calcScore(allTiles)>calcScore(max->word)) {
                    max = pres;
                  }

              } while (next_combination(newUserTile.begin(), newUserTile.begin() + i, newUserTile.end()));
            }
            if (max == NULL) {
              cout << "There are no possible combimations" << endl << endl;
            }
            else {
              cout << max->word << " is the best word you can play" << endl << endl;
            }
            break;
        }
        case 6:
          cout << "Goodbye! " << endl << endl;
          return 0;
          break;
        default:
          cout << "That is not a valid input. Please enter a valid input." << endl;
          break;
        }
      }
    }
  return 0;

}
