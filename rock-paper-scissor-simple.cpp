#include<iostream>
#include<ctime>
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main(){
    char player;
    char computer;
    
    player = getUserChoice();
    std::cout<<"Your choice is:";
    showChoice(player);

    computer = getComputerChoice();
    std::cout<<"The computer's choice's is:";
    showChoice(computer);

    chooseWinner(player, computer);
}

char getUserChoice(){
    char player;
    do{
        std::cout<<"********* Rock Paper Scissor Game **********"
             <<"Choose your move: \n"
             <<"r for Rock \n"
             <<"p for Paper \n"
             <<"s for scissor";
        std::cin>>player;
    }while(player!= 'r' && player != 'p' && player!= 's');
   
    return player;
}
char getComputerChoice(){
    srand(time(0));
    int num = rand() % 3+1;
    switch (num)
    {
    case 1:
        return 'r';
        break;
    case 2:
        return 'p';
        break;
    case 3:
        return 's';
        break;
    default:
        return 0 ;
    }
}
void showChoice(char choice){
    switch (choice)
    {
    case 'r':
        std::cout<<"Rock \n";
        break;
    case 'p':
        std::cout<<"Paper \n";
        break;
    case 's':
        std::cout<<"scissor \n";
        break;
    default:
        std::cout<<"Invalid";
    }
}
void chooseWinner(char player, char computer){
    if(player == 'r'){
        if(computer == 'r'){
            std::cout<<"Tie! \n";
        }
        else if(computer == 'p'){
            std::cout<<"You Lose! \n";
        }
        else{
            std::cout<<"You Win! \n";
        }
    }
    else if(player == 'p'){
        if(computer == 'p'){
            std::cout<<"Tie! \n";
        }
        else if(computer == 's'){
            std::cout<<"You Lose! \n";
        }
        else{
            std::cout<<"You Win! \n";
        }
    }
    else if(player == 's'){
        if(computer == 's'){
            std::cout<<"Tie! \n";
        }
        else if(computer == 'p'){
            std::cout<<"You Lose! \n";
        }
        else{
            std::cout<<"You Win! \n";
        }
    }
    else {
        std::cout<<"SORRY! NOT ABLE TO PROCESS......";
    }
}
