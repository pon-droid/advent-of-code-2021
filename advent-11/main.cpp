#include <bits/stdc++.h>

using namespace std;

struct Index {
    int x;
    int y;

};

void update (vector<int>(&map), int x, int y, const int WIDTH, const int HEIGHT, vector<bool>(&flashed)){
    for(int col = -1; col <= 1; col++){
        for(int row = -1; row <= 1; row++){
            int current_x = x + row;
            int current_y = y + col;
            if(!(current_x < 0 || current_x >=WIDTH || current_y < 0 || current_y >=HEIGHT) && !(col == 0 && row == 0)){
                if(flashed[current_y*WIDTH+current_x]) continue;
                if(map[current_y*WIDTH+current_x] <= 9) continue;

                map[current_y*WIDTH+current_x] = 0;
                flashed[current_y*WIDTH+current_x] = true;
                update(map,current_x,current_y,WIDTH,HEIGHT,flashed);

            }
        }
    }
}

void n_update(vector<int>(&map), int x, int y, const int WIDTH, const int HEIGHT, vector<bool>(&flashed)){
    for(int col = -1; col <= 1; col++){
        for(int row = -1; row <= 1; row++){
            int current_x = x + row;
            int current_y = y + col;
            if(!(current_x < 0 || current_x >=WIDTH || current_y < 0 || current_y >=HEIGHT) && !(col == 0 && row == 0)){

                if(flashed[current_y*WIDTH+current_x]) continue;
                map[current_y*WIDTH+current_x]++;
                if(map[current_y*WIDTH+current_x] < 9){
                    flashed[current_y*WIDTH+current_x] = true;
                    n_update(map,current_x,current_y,WIDTH,HEIGHT,flashed);
                }


            }
        }
    }
}


int main()
{
    ifstream file("input.txt");
    ifstream file2("input.txt");
    vector<int>map;
    char temp;
    while(file >> temp){
        int actual = temp - '0';
        map.push_back(actual);

    }

    string line;
    int temp_w = 0;
    int temp_h = 0;

    while(getline(file2,line)){
        temp_w = line.length();
        temp_h++;
    }


    const int WIDTH = temp_w;
    const int HEIGHT = temp_h;
    int flash = 0;

    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            cout << map[y*WIDTH+x];
        }
        cout << endl;
    }



    std::stack<Index>buffer;
    for(int i = 0; i < 2; i++){
         cout << "=============" << endl;
         for(int k = 0; k < buffer.size(); k++){

            update(map,buffer[k].x,buffer[k].y,WIDTH,HEIGHT);

         }
         buffer.clear();
        for(int y = 0; y < HEIGHT; y++){
            for(int x = 0; x < WIDTH; x++){

                map[y*WIDTH+x]++;


                if(map[y*WIDTH+x] > 9){
                    map[y*WIDTH+x] = 0;
                    //update(map,x,y,WIDTH,HEIGHT);
                    //flash++;
                    buffer.push_back({x,y});
                }
            }
        }

        for(int y = 0; y < HEIGHT; y++){
            for(int x = 0; x < WIDTH; x++){
                cout << map[y*WIDTH+x];
            }
            cout << endl;
        }



    }


/*
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            cout << map[y*WIDTH+x];
        }
        cout << endl;
    }

    for(int i = 0; i < 2; i++){

        std::vector<bool>flashed;
        for(int i = 0; i < map.size(); i++){
            flashed.push_back(false);
        }
         cout << "=============" << endl;

        for(int y = 0; y < HEIGHT; y++){
            for(int x = 0; x < WIDTH; x++){

                map[y*WIDTH+x]++;




                if(map[y*WIDTH+x] > 9){
                    map[y*WIDTH+x] = 0;
                    //update(map,x,y,WIDTH,HEIGHT);
                    //flash++;
                    buffer.push({x,y});
                }
                */


/*
        for(int y = 0; y < HEIGHT; y++){
            for(int x = 0; x < WIDTH; x++){
                if(flashed[y*WIDTH+x]) continue;
                if(map[y*WIDTH+x] <= 9) continue;
                map[y*WIDTH+x] = 0;
                flashed[y*WIDTH+x] = true;
            }
           // cout << endl;
        }



        for(int y = 0; y < HEIGHT; y++){
            for(int x = 0; x < WIDTH; x++){
                if(flashed[y*WIDTH+x]){
                    update(map,x,y,WIDTH,HEIGHT,flashed);
                }
            }
           // cout << endl;
        }

        for(int y = 0; y < HEIGHT; y++){
            for(int x = 0; x < WIDTH; x++){
                cout << map[y*WIDTH+x];
            }
            cout << endl;
        }


    }
*/




    return 0;
}
