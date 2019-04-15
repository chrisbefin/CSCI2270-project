#include "tree.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  cout << "Hi welcome to scrabble helper." << endl;
  string userInput;
  string upperCaseTile;
  while(!false){
    cout << "Please enter the 7 letters that you have" << endl;
    cin >> userInput;
    cout << "You inputed: " << userInput << endl;
    cout << "Are this you tiles? Press Y for yes and N for no." << endl;
    char choose;
    cin >> choose;
    while(!false){
      if(choose == 'y' || choose == 'Y'){
        break;
      }else if(choose == 'n' || choose == 'N'){
        break;
      }else{
        cout << "That is not a valid input. Please enter a valid input." << endl;
        cin >> choose;
      }
    }
    break;
  }

  return 0;
}

