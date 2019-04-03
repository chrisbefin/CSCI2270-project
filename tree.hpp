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
  public:
    tree();
    ~tree();
    void addNode(string word, int score);
    void deleteNode(string word);
    node* search(string tiles, int score)
    void rebalance();
  private:
    node* root;
}
