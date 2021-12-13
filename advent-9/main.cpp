#include <bits/stdc++.h>

using namespace std;


int low(std::vector<int>raw, int x, int y, const  int HEIGHT, const  int WIDTH){

    for(int length = -1; length <= 1; length++){
        int current_y = y + length;

        if (length == 0)
            continue;

        if(!(current_y < 0 || current_y >= HEIGHT) && raw[current_y*WIDTH+x] <= raw[y*WIDTH+x]){
           return -1;
        }



    }
    for(int side = -1; side <=1; side++){
        int current_x = x + side;

        if (side == 0)
            continue;

        if(!(current_x < 0 || current_x >= WIDTH) && raw[y*WIDTH+current_x] <= raw[y*WIDTH+x]){
            return -1;
        }


    }

    return raw[y*WIDTH+x];
}



int basin(std::vector<int>(&raw), int x, int y, const int HEIGHT, const int WIDTH, int &(sum)){

    for(int length = -1; length<=1; length++){
        int current_y = y + length;



        if(raw[current_y*WIDTH+x] == 9 || raw[current_y*WIDTH+x] == -1){
            continue;
        }

        if(!(current_y < 0 || current_y >= HEIGHT)){
            sum++;
            raw[current_y*WIDTH+x] = -1;
            basin(raw,x,current_y,HEIGHT,WIDTH, sum);
        }
    }
    for(int side = -1; side <= 1; side++){
        int current_x = x + side;

        if(raw[y*WIDTH+current_x] == 9 || raw[y*WIDTH+current_x] == -1){
            continue;
        }

        if(!(current_x < 0 || current_x >= WIDTH)){
            sum++;
            raw[y*WIDTH+current_x] = -1;
            basin(raw,current_x,y,HEIGHT,WIDTH, sum);
        }

    }
    return sum;
}

int main()
{
    ifstream file ("input.txt");
    ifstream file2 ("input.txt");

    std::vector<int> raw;
    string line;

    while(!file.eof()){
        char c;
        file >> c;
        raw.push_back(c - '0');
    }


   int temp_w = 0;
   int temp_h = 0;

    while(getline(file2,line)){
        temp_w = line.length();
        temp_h++;
    }

    const  int HEIGHT = temp_h;
    const int WIDTH = temp_w;
    std::vector<int>sizes;
    for(unsigned int y = 0; y < HEIGHT; y++){
        for(unsigned int x = 0; x < WIDTH; x++){
            int temp = low(raw,x,y,HEIGHT,WIDTH);

            if(temp != -1 && temp != 9){
                int sum = 0;
                basin(raw,x,y,HEIGHT,WIDTH, sum);

                sizes.push_back(sum);

            }



        }

    }



   sort(sizes.begin(),sizes.end(),greater<int>());

   int x = sizes[0];
   int y = sizes[1];
   int z = sizes[2];

   cout << x*y*z << endl;

           /*

     for(int y = 0; y < HEIGHT; y++){
         for(int x = 0; x < WIDTH; x++){
             cout << raw[y*WIDTH+x];
         }
         cout << endl;
     }

*/
    return 0;
}
