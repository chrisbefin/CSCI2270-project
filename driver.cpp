#include <fstream>
#include <iostream>
#include <string>
using namespace std;


void dispLayMenu(){
  cout << "======Main Menu======" << endl;
  cout << "1. Enter new tiles" << endl;
  cout << "2. Multiply score by 2" << endl;
  cout << "3. Multiply score by 3" << endl;
  cout << "4. Use a wildcard" << endl;
  cout << "5. Quit" << endl;
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

int main(){
  string userChoose;
  int score;
  string userTile;
  string read;
  string newUserTile;
  cout << "Hi welcome to Scrabble Helper" << endl;
  cout << "Please enter the 7 letters" << endl;
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
  cout << "You have entered this 7 letters: " << newUserTile << endl << endl;
  while(userChoose != "5"){
    dispLayMenu();
    getline(cin, userChoose);
    cout << endl;
    if(userChoose >= "1" && userChoose <= "9"){
      switch(stoi(userChoose)){
        case 1:
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
          cout << "You have entered this 7 letters: " << newUserTile << endl << endl;
          score = calcScore(newUserTile);;
          break;
        case 2:
          score *= 2;
          cout << "The new score is " << score << endl;
          break;
        case 3:
          score *= 3;
          cout << "The new score is " << score << endl;
          break;
        case 4:
          break;
        case 5:
          cout << "Goodbye! " << endl;
          break;
        default:
          cout << "That is not a valid input. Please enter a valid input." << endl;
          break;
        }
      }else{
        cout << "That is not a valid input. Please enter a valid input." << endl;
      }
    }
}
