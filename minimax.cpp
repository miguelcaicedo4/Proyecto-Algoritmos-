#ifdef _MINIMAX_HPP
#include<iostream>
using namespace std;

tictactoe::tictactoe(){
  move ={0,0,0,0,0,0,0,0,0};
}
tictactoe::tictactoe(vector<int> pl){
  this->move = pl;
}
int tictactoe::Valueplay(){
  int re = 0;
  bool diag = ((this->move[0]==this->move[4])&&(this->move[0]==this->move[8])) || ((this->move[2]==this->move[4])&&(this->move[4]==this->move[6]));
  if(diag && this->move[4]==opponent ){
    re = 10;
  }
  if(diag && this->move[4]==player){
    re =-10;
  }
  else{
    for(unsigned i=0;i<this->move.size();i+=3){
      if((this->move[i]==this->move[i+1])&&(this->move[i+1]==this->move[i+2]) && (this->move[i]==opponent)){
        re = 10;
        break;
      }
      else if((this->move[i]==this->move[i+1])&&(this->move[i+1]==this->move[i+2]) && (this->move[i]==player)){
        re = -10;
        break;
      }
    }
  //columnas
    for(unsigned j=0;j<3;j++){
      if((this->move[j]==this->move[j+3])&&(this->move[j+3]==this->move[j+6])&& (this->move[j]==opponent)){
        re = 10;
        break;
      }
      else if((this->move[j]==this->move[j+3])&&(this->move[j+3]==this->move[j+6])&& (this->move[j]==player)){
        re = -10;
        break;
      }
    }
  }

  if(re == 0){
    for(unsigned i = 0; i<9 ; i++){
      if(this->move[i]==0){
        re = 1;
        break;
      }
    }
  }

  return re;
}


int tictactoe::minimax(bool max){
  int value = (this->Valueplay());
  if(value!=1 ){
    return value ;
  }
  if(max){
    int maxValue = -1000;
    for(unsigned i = 0; i< 9;i++){
      if(this->move[i]==0) {
        this->move[i]=opponent;
        int bestValue= minimax(!max);
        if(bestValue>maxValue){
          maxValue = bestValue;
        }
        this->move[i]= 0;
      }

    }
    return maxValue;
  }
  else{
    int minValue = 1000;
    for(unsigned j = 0; j<9 ;j++){
      if(this->move[j]==0) {
        this->move[j]=player;
        int bestValue= minimax( !max);
        if(bestValue<minValue){
          minValue = bestValue;
        }
        this->move[j]= 0;
      }
    }
      return minValue;
    }
}




void tictactoe::findBestMove(){
  int bestVal = -1000;
  int index;
  for(unsigned i = 0; i < 9 ; i++)
  {
    if(this->move[i]==0){
      this->move[i]=opponent;
      int move = minimax(false);
      this->move[i]=0;
      if(move > bestVal){
        index = i;
        bestVal = move;
      }
    }
  }
  this->move[index]=opponent;
}

void tictactoe::display(){
    map<int,string> trans;
    trans[0] = " ";
    trans[1] = "X";
    trans[2] = "O";
    for(unsigned i=0;i<9;i++){
      if(move[i]==0){
        cout<< i + 1<<"|";
      }
      else{
        cout<< trans[this->move[i]] << "|";
      }
      if (i == 2 or i== 5){
        cout<<'\n'<<"------ "<<'\n';
      }
    }
    cout<<endl;
}

void tictactoe::movePlayer(){
  int box= -1;
  while(true){
    cout<<"ingrese el numero de la casilla que quiera jugar"<<endl;
    cin>>box;
    while(box > 9 || box <= 0){
      cout<<"Por favor ingrese un numero correto del 1-9"<<endl;
      cin>>box;
    }
    while(move[box - 1 ]==player || move[box - 1]==opponent){
      cout<<"la casilla ya ha sido seleccionada "<<endl;
      cout<<"ingrese otro numero de casilla no jugada"<<endl;
      cin>>box;
      while(box >= 9 || box < 1){
        cout<<"Por favor ingrese un numero correto del 1-9"<<endl;
        cin>>box;
      }
    }
    if((move[box - 1]==0)){
      break;
    }
  }

  this->move[box - 1]=player;
}

void tictactoe::Reset(){
  move ={0,0,0,0,0,0,0,0,0};
}

#endif 
