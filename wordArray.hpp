#ifndef wordArray_HPP
#define wordArray_HPP
#include <string>
using namespace std;

struct node {
  node* next=NULL;
  string word;
};

class wordArray {
  private:
    node** array;
    int size;
  public:
    wordArray(int length);
    ~wordArray();
    void addWord(int score,string word);
    node* searchTiles(int score, string tiles);
    void print();
};
#endif
