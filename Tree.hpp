#ifndef _TREE_HPP
#define _TREE_HPP
#include <vector>
#include <string>

using namespace std;


class tree{
  struct node{
    string key;
    bool player;
    node *left, *right, *central, *parent;
  };

  public:
    tree(string game, bool turn);
    ~tree();

    vector<string> childrenNames(node &root, bool player);
    void childrenNode(vector<string> childrenName , node &root);

    /*
    void displayTree(std::ostream &out = std::cout)const;
    void insert(node &game);
    int max(int i , int p );
    int min(int i , int p);
    int Bestmove(node &game);
    void displayGame(node &game);
*/

};

#endif
