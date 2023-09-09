#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> 

class illegal_exception{

};

void output(int &turn, std::vector<std::string> position){
    int index = 0;
    for(int i = 1; i <= 9; i++){
        if(i == 2 || i == 5 || i == 8){
            std::cout << "        " << position[i-2] << "        |        " <<  position[i-1] << "        |        " << position[i]<< std::endl;
        }
        else if(i == 3 || i == 6){
            std::cout << "_________________|_________________|_________________" << std::endl;
        }
        else{
            std::cout << "                 " << "|" << "                 " << "|" << "                 " << std::endl;
        }
    }

    if(turn % 2 == 1){  //player 1's turn
        std::cout << "Player - 1 [X] turn : " << std::endl;
    }
    else{               //player 2's turn
        std::cout << "Player - 2 [O] turn : " << std::endl;
    }
    turn++;
    return;
}
void input(int turn, int userInput, std::vector<std::string> &position){
    if(turn % 2 == 1){         //use "O" because new output displays in the next turn
        position[userInput-1] = "O";
    }
    else{
        position[userInput-1] = "X";
    }
    return;
}
bool check(std::vector<std::string> position){
    //horizontal winning condition
    if((position[0] == "O" && position[1] == "O" && position[2] == "O") ||
    (position[3] == "O" && position[4] == "O" && position[5] == "O") ||
    (position[6] == "O" && position[7] == "O" && position[8] == "O") || 
    (position[0] == "O" && position[3] == "O" && position[6] == "O") ||
    (position[1] == "O" && position[4] == "O" && position[7] == "O") || 
    (position[2] == "O" && position[5] == "O" && position[8] == "O") ||
    (position[0] == "O" && position[4] == "O" && position[8] == "O") ||
    (position[2] == "O" && position[4] == "O" && position[6] == "O")){
        std::cout << "Player 2 has won!" << std::endl;
        return true;
    }
    else if((position[0] == "X" && position[1] == "X" && position[2] == "X")
    || (position[3] == "X" && position[4] == "X" && position[5] == "X")
    || (position[6] == "X" && position[7] == "X" && position[8] == "X")
    || (position[0] == "X" && position[3] == "X" && position[6] == "X")
    || (position[1] == "X" && position[4] == "X" && position[7] == "X")
    || (position[2] == "X" && position[5] == "X" && position[8] == "X")
    || (position[0] == "X" && position[4] == "X" && position[8] == "X")
    || (position[2] == "X" && position[4] == "X" && position[6] == "X")){
        std::cout << "Player 1 has won!" << std::endl;
        return true;
    }
    else{   //check if game is tied or not
        int fill = 0;
        for(int i = 0; i < position.size(); i++){
            if(position[i] == "X" || position[i] == "O"){
                fill++;
                if(fill == 9){
                    std::cout << "The game is tied! Good job for both sides!" << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int gameOver = 0;
    int turn = 1;
    int userInput;
    std::vector<std::string> position;
    position.resize(9);

    std::cout << "                 " << "TICK--TAC--TOE--GAME" << std::endl;
    std::cout << "                    " << "FOR 2 PLAYERS" << std::endl;
    std::cout << "            " << "PLAYER - 1 [X]    PLAYER - 2 [0]" << std::endl;

    for(int i = 0; i <= 8; i++){
        position[i] = std::to_string(i+1);
        //std::cout << position[i] << std::endl;
    }
    output(turn, position);
    while(gameOver == 0){
        try{
            std::cin >> userInput;
            if(position[userInput-1] == "O" || position[userInput-1] == "X" || (int)userInput > 9 || (int)userInput < 1){
                throw illegal_exception();
            }
            else{
                input(turn, userInput, position);
                output(turn, position);
                if(check(position) == true){
                    gameOver = 1;
                }
            }
        }
        catch(illegal_exception e1){
            std::cout << "Invalid Move!" << std::endl;
            gameOver = 1;
        }
    }
    return 0;
}