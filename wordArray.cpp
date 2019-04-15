#include "wordArray.hpp"
#include <iostream>

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

wordArray::wordArray(int length) {
  size=length;
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
      array[i]=NULL
    }
  }
  delete[] array;
}

void wordArray::addWord(int score,string word) {
  node *nn = new node;
  nn->word=word;
  if (array[score-1]==NULL) { //if there is no header to the linked list
    array[score] = nn;
  }
  else {
    node *pres;
    pres = array[score-1];
    while (pres->next != NULL) {
      pres = pres->next;
    }
    pres->next = nn;
  }
}

node* wordArray::searchTiles(int score, string tiles) {
  node *pres = array[score-1];
  while (pres != NULL) {
    if (hasTiles(tiles, pres->word)) {
      return pres;
    }
    pres=pres->next;
  }
  return NULL;
}

void wordArray::print() {
  for (int i=0; i<size+1;i++) {
    node* pres = array[i];
    while (pres!=NULL) {
      cout << pres-> word << endl;
      pres = pres->next;
    }
  }
}
