#include "wordArray.hpp"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool hasTiles(string tiles, string word) { //helper function that tells if the tiles can form the word // works
  bool letters[word.length()];
  for (int i=0;i<word.length();i++) {
    letters[i]=false;
  }
  for (int i=0; i < tiles.length();i++) {
    for (int j=0; j < word.length();j++) {
      if (tiles[i]==word[j] && letters[j] == false) {
        letters[j] = true;
        break;
      }
    }
  }
  for (int i=0;i<word.length();i++) {
    if (letters[i]!= true) {
      return false;
    }
  }
  return true;
}

wordArray::wordArray(long int usize) { //new
  size = usize;
  array= new node*[size];
  for (int i=0; i < size;i++) {
    array[i] = NULL;
  }
}

wordArray::~wordArray() {
  node *pres;
  node *next;
  for (int i=0;i<size;i++) {
    if (array[i]!= NULL) {
      pres = array[i];
      while (pres != NULL) {
        next = pres->next;
        delete pres;
        pres = next;
      }
      array[i]=NULL;
    }
  }
}

void wordArray::addWord(int score, string word) { //new way
  node *nn = new node;
  nn->word=word;
  sort(word.begin(),word.end());
  unsigned int index = getHash(word);
  if (array[index]==NULL) { //if there is no header to the linked list
    array[index] = nn;
  }
  else {
    node *pres;
    pres = array[index];
    while (pres->next != NULL) {
      pres = pres->next;
    }
    pres->next = nn;
  }
}

node* wordArray::searchTiles(int score, string tiles) {
  string word = tiles;
  sort(word.begin(),word.end());
  int index = getHash(word);
  node *pres = array[index];
  while (pres != NULL) {
    if (hasTiles(tiles, pres->word)) {
      return pres;
    }
    pres=pres->next;
  }
  return NULL;
}

void wordArray::print() {
  for (int i=0; i<size;i++) {
    cout << "bucket : " << i << endl;
    node* pres = array[i];
    while (pres!=NULL) {
      cout << pres-> word << endl;
      pres = pres->next;

    }
  }
}
bool wordArray::searchWord(int score, string word)
{
  string sorted = word;
  sort(sorted.begin(),sorted.end());
  unsigned int index = getHash(sorted);
  node* pres = array[index];
  while(pres != nullptr)
  {
    if(pres -> word == word)
      return true;
    pres = pres -> next;
  }
  return false;
}

unsigned int wordArray::getHash(std::string word) { //doesnt work for abiogenitacally
  unsigned int hashValue = 5381;
  int length = word.length();
  for (int i=0;i<length;i++)
    {
    hashValue=((hashValue<<5)+hashValue) + word[i];
    }
  hashValue %= size;
  return hashValue;
}
