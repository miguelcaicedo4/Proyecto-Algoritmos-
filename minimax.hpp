#ifndef _MINIMAX_HPP
#define _MINIMAX_HPP

#include<vector>
#include<map>

class tictactoe{
private:
  std::vector<int> move;
  int player = 2;
  int opponent = 1;

void showall();


public:
  tictactoe();
  tictactoe(std::vector<int> pl);
  //~tictactoe();
  //funciones algoritmo minimax
  int Valueplay();
  int minimax(bool ismax);
  void findBestMove();
  //funciones visuales
  void display();
  void movePlayer();
  void Reset();


};

#include "minimax.cpp"
#endif
