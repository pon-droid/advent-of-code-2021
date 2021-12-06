#include <bits/stdc++.h>
#define B 5
#define M -1
#define R -2


struct Board {

  int grid[B][B];

};
/*
Board::Board(){
    //Initialize marked array with nothing
    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            mark[i][j] = false;
        }
    }
}*/

Board read(std::ifstream& file){
    Board board;
    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            file >> board.grid[i][j];
        }
    }
    return board;
}

void print_board(Board board){
    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            std::cout << board.grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

Board mark_board(Board board, std::vector<int> drawn){
    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            int val = board.grid[i][j];
            //std::vector<int>::iterator it;
           // it = std::find (drawn.begin(), drawn.end(), val);
            for(int k = 0; k < drawn.size(); k++){
                if(drawn[k] == val){
                    board.grid[i][j] = -1;

                }
            }
        }
    }
    return board;
}



//Draw ONE number
//Loop for every board
//Check for win

bool win(Board board){
    for(int i = 0; i < B; i++){
        int match = 0;
        //row
        for(int j = 0; j < B; j++){
            if(board.grid[i][j] == M){
                match++;
            }
        }
        if(match == 5){
            return true;
        }
        //Columns
        match = 0;
        for(int j = 0; j < B; j++){
            if(board.grid[j][i] == M){
                match++;
            }
        }
        if(match == 5){
            return true;
        }
    }
    return false;
}

int sum_v(Board board, int val){
    int result = 0;
    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            if(board.grid[i][j] != M){
                result += board.grid[i][j];
            }

        }
    }
    std::cout << val << std::endl;
    return result * val;
}

int b_mark(std::vector<Board>boxes, std::vector<int> drawn){
    for(int i = 0; i < drawn.size(); i++){
        //For every drawn value
        int val = drawn[i];
        for(int j = 0; j < boxes.size(); j++){
            //Check each grid in 'boxes'
            //If this results in a win, sum up all the unmarked values of that board and return it
          for(int k = 0; k < B; k++){
              for(int l = 0; l < B; l++){
                if(win(boxes[j]) == true ){

                   return sum_v(boxes[j],val);
                }
                if(boxes[j].grid[k][l] == val){
                    boxes[j].grid[k][l] = M;
                }
              }
          }
    }
  }
    return 0;

}

void clear(Board &board){
    for(int i = 0; i < B; i++){
        for(int j = 0; j < B; j++){
            board.grid[i][j] = R;
        }
    }
}


int return_winner(std::vector<Board>&boxes, std::vector<int> drawn){
    for(int i = 0; i < drawn.size(); i++){
        //For every drawn value
        int val = drawn[i];
        for(int j = 0; j < boxes.size(); j++){
            //Check each grid in 'boxes'
            //If this results in a win, sum up all the unmarked values of that board and return it
          for(int k = 0; k < B; k++){
              for(int l = 0; l < B; l++){
                if(win(boxes[j]) == true ){

                   return sum_v(boxes[j],val);
                }
                if(boxes[j].grid[k][l] == val){
                    boxes[j].grid[k][l] = M;
                }
              }
          }
    }
  }
    return 0;

}

//Save index of last winning board
//For every drawn value
//Drip feed it to the loop below
//Check each grid, if there is a win
//Retire the board with clear() if there is and save it's index

int p2(std::vector<Board>boxes, std::vector<int>drawn){
    int index = 0;
    int last_sum = 0;
    for(int i = 0; i < drawn.size(); i++){
        int val = drawn[i];
        for(int j = 0; j < boxes.size(); j++){
            for(int k = 0; k < B; k++){
                for(int l = 0; l < B; l++){
                    if(win(boxes[j])){
                        index = j;
                        last_sum = sum_v(boxes[j],val);
                        std::cout << last_sum << std::endl;
                        //Retire
                        clear(boxes[j]);
                    }
                    if(boxes[j].grid[k][l] == val){
                        boxes[j].grid[k][l] = M;
                    }
                }
            }
        }
    }
    std::cout << "Winning Box: " << index << std::endl;
    return last_sum;
}



int main()
{
    std::vector<int> drawn  {
        50,68,2,1,69,32,87,10,31,21,78,23,62,98,16,99,65,35,27,96,66,26,74,72,45,52,81,60,38,57,54,19,18,77,71,29,51,41,22,6,58,5,42,92,85,64,94,12,83,11,17,14,37,36,59,33,0,93,34,70,97,7,76,20,3,88,43,47,8,79,80,63,9,25,56,75,15,4,82,67,39,30,89,86,46,90,48,73,91,55,95,28,49,61,44,84,40,53,13,24
    };

    std::ifstream file("bingo.txt");

    std::vector<Board> boxes;



    while(!file.eof()){
        Board temp = read(file);
        boxes.push_back(temp);

    }
    //Mark every board in vector




    std::cout << p2(boxes,drawn) << std::endl;




    //for(int i = 0;)






    return 0;
}
