#include "tree.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  cout << "Hi welcome to scrabble helper." << endl;
  bool flag = false;
  bool flag2 = false;
  string userAnswer;
  string upperCaseTile;
  while(flag == false){
    cout << "Please enter the 7 letters that you have" << endl;
    cin >> userAnswer;
    //upperCaseTile = LowerCaseName(userAnswer);
    cout << "You inputed: " << userAnswer << endl;
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

