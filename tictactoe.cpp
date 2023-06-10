#include<iostream>

char square[10]={'0','1','2','3','4','5','6','7','8','9'};
int choice;

//function to return game status

int checkwin(){
    
    if(square[1]==square[2]&&square[2]==square[3])
        return 1;
    else if(square[4]==square[5]&&square[5]==square[6])
        return 1;
    else if(square[7]==square[8]&&square[8]==square[9])
        return 1;
    else if(square[1]==square[4]&&square[4]==square[7])
        return 1;
    else if(square[2]==square[5]&&square[5]==square[8])
        return 1;
    else if(square[3]==square[6]&&square[6]==square[9])
        return 1;
    else if(square[1]==square[5]&&square[5]==square[9])
        return 1;
    else if(square[3]==square[5]&&square[5]==square[7])
        return 1;
    else if(square[1]!='1'&&square[2]!='2'&&square[3]!='3'&&square[4]!='4'&&square[5]!='5'&&square[6]!='6'&&square[7]!='7'
    &&square[8]!='8'&&square[9]!='9')
        return 0;
    else 
        return -1;
    
}

//board with marks

void board(){
    system("clear");    //clears the screen
    std::cout<<"\n\n  Tic Tac Toe Game \n\n"<<std::endl;

    std::cout<<"Player 1(X) - Player 2(O)\n"<<std::endl;
    std::cout<<std::endl;

    //board

    std::cout<<"     |     |     "<<std::endl;
    std::cout<<"  "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<std::endl;
    std::cout<<"_____|_____|_____"<<std::endl;
    std::cout<<"     |     |     "<<std::endl;
    std::cout<<"  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<std::endl;
    std::cout<<"_____|_____|_____"<<std::endl;
    std::cout<<"     |     |     "<<std::endl;
    std::cout<<"  "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<std::endl;
    std::cout<<"     |     |     "<<std::endl;
}

int main(){
    
    int player = 1;
    int i,choice;

    char mark;
    
    do{
        board();
        player=(player%2)?1:2;

        std::cout<<"Player "<<player<<" enter the number: ";
        std::cin>>choice;

        mark=(player==1)?'X':'O';

        if(square[choice]!='X'&&square[choice]!='O'){
            square[choice]=mark;
        }
        else{
            std::cout<<"invalid move!"<<std::endl;
            player--;
            std::cin.ignore();
            std::cin.get();
        }

        i=checkwin();
        player++;

    }while(i==-1);
    board();
    if(i==1){
        std::cout<<"\nCongratulations! Player "<<--player<<" wins"<<std::endl;
    }
    else{
        std::cout<<"\nIts is Draw!"<<std::endl;
    }
    std::cin.ignore();
    std::cin.get();

    return 0;
}