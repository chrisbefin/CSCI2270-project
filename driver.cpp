#include "tree.hpp"
#include <iostream>
#include <fstream>

using namespace std;

string LowerCaseName(string name){
    int letter;
    char n;
    string UpperCaseWord;
    for(int i = 0; i<name.length(); i++){
        if(name[i] >= 'a' && name[i] <= 'z'){//It checks if the letter at that index is a lowercaseletter
            n = int(name[i]);
            letter = n - 32;
            UpperCaseWord = UpperCaseWord + char(letter);  //This converts the letter into uppercase and add it into a new string.
        }else if(name[i] != ' ' && name[i] >= 'A' && name[i] <= 'Z'){ //if the letter ia already in a uppercase it already addeds to a string
            n = int(name[i]);
            letter = n;
            UpperCaseWord = UpperCaseWord + char(letter);
        }
    }
    return UpperCaseWord;
}

int main(){
  cout << "Hi welcome to scrabble helper." << endl;
  bool flag = false;
  bool flag2 = false;
  string userAnswer;
  string upperCaseTile;
  while(flag == false){
    cout << "Please enter the 7 letters that you have" << endl;
    cin >> userAnswer;
    upperCaseTile = LowerCaseName(userAnswer);
    cout << "You inputed: " << upperCaseTile << endl;
    cout << "Are this you tiles? Press Y for yes and N for no." << endl;
    char choose;
    cin >> choose;
    while(flag2 == false){
      if(choose == 'y' || choose == 'Y'){
        flag2 = true;
      }else if(choose == 'n' || choose == 'N'){
        flag2 = true;
      }else{
        cout << "That is not a valid input. Please enter a valid input." << endl;
        cin >> choose;
      }
    }
    flag = true;
  }

  return 0;
}

