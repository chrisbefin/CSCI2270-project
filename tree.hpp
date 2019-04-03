#ifndef tree_HPP
#define tree_HPP
#include <string>

struct node {
  node *parent;
  node *leftChild;
  node *rightChild;
  string word;
  int score;
};

class tree {

}
