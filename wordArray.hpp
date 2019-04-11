#ifndef wordArray_HPP
#define wordArray_HPP
#include <string>
using namespace std;

struct node {
  node* next;
  string word;
};

class wordArray {
  private:
    node** array;
  public:
    wordArray(int length);
    void addWord(int score,string word);
    node* searchTiles(int score, string tiles);
};

#endif
