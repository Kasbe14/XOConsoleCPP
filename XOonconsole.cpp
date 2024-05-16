#include <iostream>
#include <string>
#include <vector>
#define nl '\n';

enum class State {
    PLAYING,
    PLAYER_1_WIN,
    PLAYER_2_WIN,
    DRAW,
};

enum class Turn {
    P1,
    P2,
};

void instruction(){
    std::cout<<"Player 1 starts the game.\nPlayer 1 = X and Player 2 = O.\n";
}

void display_board(std::string& fr, std::string& sr, std::string& tr, State s){
    std::string p = "-------|-------|-------\n";
     if(s == State::PLAYING){
        std::cout<<fr;
        std::cout<<p;
        std::cout<<sr,
        std::cout<<p;
        std::cout<<tr;
     }else if ( s == State::PLAYER_1_WIN){
    std::cout<<'\n';
        std::cout<<p;
        std::cout<<"!!!!! PLAYER 1 WINS !!!!!\n";
        std::cout<<p;
     }else if (s == State::PLAYER_2_WIN){
    std::cout<<'\n';
        std::cout<<p;
        std::cout<<"!!!!! PLAYER 2 WINS !!!!!\n";
        std::cout<<p;
     }else if(s == State::DRAW) {
    std::cout<<'\n';
        std::cout<<p;
        std::cout<<"!!!!!! GAME IS DRAW !!!!!!\n";
        std::cout<<p;
     }
}
void frow_append(std::string &fr, int num,Turn turn){
    if(num == 1){
       (turn == Turn::P1 ? fr[3]= 'X' : fr[3]= 'O'); 
    }else if(num == 2){
        (turn == Turn::P1 ? fr[11] = 'X' : fr[11] = 'O');
    }else if(num == 3){
        (turn == Turn::P1 ? fr[19] = 'X' : fr[19] = 'O');
    }
}

void srow_append(std::string &sr, int num,Turn turn){
    if(num == 4){
       (turn == Turn::P1 ? sr[3]= 'X' : sr[3]= 'O'); 
    }else if(num == 5){
        (turn == Turn::P1 ? sr[11] = 'X' : sr[11] = 'O');
    }else if(num == 6){
        (turn == Turn::P1 ? sr[19] = 'X' : sr[19] = 'O');
    }
}

void trow_append(std::string &tr, int num, Turn turn){
    if(num == 7){
        (turn == Turn::P1 ? tr[3] = 'X' : tr[3] = 'O');
    }else if(num == 8){
        (turn == Turn::P1 ? tr[11] = 'X' : tr[11] = 'O');
    }else if(num == 9){
        (turn == Turn::P1 ? tr[19] = 'X' : tr[19] = 'O');
    }
}


void game_state(std::vector<std::vector<int>> &game,std::string &fr,std::string &sr, std::string &tr,State &state){
    int row1{0},row2{0},row3{0};
    int col1{0},col2{0},col3{0};
    int dig1{0},dig2{0};
    // change the if conditon if there is no x or o to keep value of cell 0;
    (fr[3] ==  'X' ? game[0][0] = 1 : fr[3] ==  'O' ? game[0][0] = -1 : game[0][0] = 0);
    (fr[11] == 'X' ? game[0][1] = 1 : fr[11] == 'O' ? game[0][1] = -1 : game[0][1] = 0);
    (fr[19] == 'X' ? game[0][2] = 1 : fr[19] == 'O' ? game[0][2] = -1 : game[0][2] = 0);
    (sr[3] ==  'X' ? game[1][0] = 1 : sr[3] ==  'O' ? game[1][0] = -1 : game[1][0] = 0);
    (sr[11] == 'X' ? game[1][1] = 1 : sr[11] == 'O' ? game[1][1] = -1 : game[1][1] = 0);
    (sr[19] == 'X' ? game[1][2] = 1 : sr[19] == 'O' ? game[1][2] = -1 : game[1][2] = 0);
    (tr[3] ==  'X' ? game[2][0] = 1 : tr[3] ==  'O' ? game[2][0] = -1 : game[2][0] = 0);
    (tr[11] == 'X' ? game[2][1] = 1 : tr[11] == 'O' ? game[2][1] = -1 : game[2][1] = 0);
    (tr[19] == 'X' ? game[2][2] = 1 : tr[19] == 'O' ? game[2][2] = -1 : game[2][2] = 0);
    // Updating the rows and colums state
    row1 = game[0][0] + game[0][1] + game[0][2];
    row2 = game[1][0] + game[1][1] + game[1][2];
    row3 = game[2][0] + game[2][1] + game[2][2];
    col1 = game[0][0] + game[1][0] + game[2][0];
    col2 = game[0][1] + game[1][1] + game[2][1];
    col3 = game[0][2] + game[1][2] + game[2][2];
    dig1 = game[0][0] + game[1][1] + game[2][2];
    dig2 = game[0][2] + game[1][1] + game[2][0];
// Updating the State
    if(row1 == -3) { state = State::PLAYER_2_WIN; return;}
    if(row1 == 3)  { state = State::PLAYER_1_WIN; return;}
    if(row2 == -3) { state = State::PLAYER_2_WIN; return;}
    if(row2 == 3)  { state = State::PLAYER_1_WIN; return;}
    if(row3 == -3) { state = State::PLAYER_2_WIN; return;}
    if(row3 == 3)  { state = State::PLAYER_1_WIN; return;}
    if(col1 == -3) { state = State::PLAYER_2_WIN; return;}
    if(col1 == 3)  { state = State::PLAYER_1_WIN; return;}
    if(col2 == -3) { state = State::PLAYER_2_WIN; return;}
    if(col2 == 3)  { state = State::PLAYER_1_WIN; return;}
    if(col3 == -3) { state = State::PLAYER_2_WIN; return;}
    if(col3 == 3)  { state = State::PLAYER_1_WIN; return;}
    if(dig1 == -3) { state = State::PLAYER_2_WIN; return;}
    if(dig1 == 3 ) { state = State::PLAYER_1_WIN; return;}
    if(dig2 == -3) { state = State::PLAYER_2_WIN; return;}
    if(dig2 == 3 ) { state = State::PLAYER_1_WIN; return;}

   
 }

int main(){
    instruction();
    State state = State::PLAYING; 
    Turn turn = Turn::P1;
    int move = 0;
    std::vector<std::vector<int>> game (3,std::vector<int> (3,0));
    std::string first_row ="   1   |   2   |   3   \n";
    std::string sec_row   ="   4   |   5   |   6   \n";
    std::string third_row ="   7   |   8   |   9   \n";
    display_board(first_row,sec_row,third_row, state);
    while(state == State::PLAYING){
        int box_num{};
        std::cout<<"Enter box number : \n";
        std::cin>>box_num;
        // std::cout<<"\n";
        if(box_num < 4){
            frow_append(first_row,box_num, turn);
        }
        if(box_num < 7){
            srow_append(sec_row,box_num, turn);
        }
        if(box_num < 10){
            trow_append(third_row,box_num, turn);
        }
        display_board(first_row,sec_row,third_row,state);
        game_state(game,first_row,sec_row,third_row,state);
        move++;
        if(move == 9 && state == State::PLAYING) {
                state = State::DRAW;
        }
        if(turn == Turn::P1){
            turn = Turn::P2;
        }else {
            turn = Turn::P1;
        }
        // std::cout<<move<<'\n';
    }
    display_board(first_row,sec_row,third_row,state);
    return 0;
}