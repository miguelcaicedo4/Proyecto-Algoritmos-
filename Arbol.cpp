#include "tree.hpp"
#include <vector>
#include <string>

tree::tree(string game, bool turn){
  node *root = new node;
  root->key = game;
  root->player = turn;
  if(turn== true){
    turn = false;
  }
  if(turn == false) {
    turn = true;
  }
  childrenNode(childrenNames(*root, turn), *root);
}
// convencion x = 1, o = 2, nada = 0
// player == true -> player = x,
// player == false -> player = o
vector<string> tree::childrenNames(node &root, bool player){

  string game = (root.key);
  string re = game;
  vector<string> vecChildren;

  for(int i = 0; i< 10;i++){
      if(game[i]== '0'){
        if(player == true){
          re[i]= '1';
        }
        else
        {
          re[i]= '2';
        }
        vecChildren.push_back(re);
        re = game;
      }
    }
  return vecChildren;

}
//funcion creadora de nodos
void tree::childrenNode(vector<string> childrenName , node &root){

  bool playerNext ;
  if(childrenName.size()>0){
    if(childrenName.size()== 3 ){
      root.left = new node;
      root.right = new node;
      root.central = new node;
      root.left->key = childrenName[0];
      root.right->key = childrenName[1];
      root.central->key = childrenName[2];
    }
    if(childrenName.size()==2 ){
      root.left = new node;
      root.right = new node;
      root.left->key = childrenName[0];
      root.right->key = childrenName[1];
      root.central = nullptr;
    }
    if(childrenName.size()== 1 ){
      root.left = new node;
      root.left->key = childrenName[0];
      root.right = nullptr;
      root.central = nullptr;
    }

    if(root.player == true){
      playerNext = false;
    }
    if(root.player == false) {
      playerNext = true;
    }

  vector<string> nameLeft = childrenNames(*(root.left), playerNext);
  vector<string> nameRight = childrenNames(*(root.right), playerNext);
  vector<string> nameCentral = childrenNames(*(root.central), playerNext);

  childrenNode(nameLeft, *(root.left));
  childrenNode(nameRight, *(root.right));
  childrenNode(nameCentral,*(root.central));
  }
  else{
    root.left = nullptr;
    root.right = nullptr;
    root.central = nullptr;
  }


}//prueba
