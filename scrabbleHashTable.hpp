#ifndef scrabbleHashTable_HPP
#define scrabbleHashTable_HPP
#include <string>
using namespace std;

struct node {

  node* next=NULL;
  string word;
};

class hashTable {
  private:
    node** array;
    long int size;
    unsigned int getHash(string);
  public:
    hashTable(long int);
    ~hashTable();
    bool searchWord(int,string);
    void addWord(int score,string word);
    node* searchTiles(int score, string tiles);
    node* searchTilesWord(int score, string tiles, string word);
    void print();
};

#endif
