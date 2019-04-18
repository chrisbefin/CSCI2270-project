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
    long int size;
    unsigned int getHash(string);
  public:
    wordArray(long int);
    ~wordArray();
    bool searchWord(int,string);
    void addWord(int score,string word);
    node* searchTiles(int score, string tiles);
    void print();
};

#endif
