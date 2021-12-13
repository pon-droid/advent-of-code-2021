#include <bits/stdc++.h>

using namespace std;

struct Fish {
    std::vector<int> net;
};

void birth (std::vector<int64_t> &raw){

    for(int64_t i = 0; i < raw.size(); i++){
        if(raw[i] == 0){
            raw.push_back(9);

        }
    }

}

void check_cycles(std::vector<int> &raw){
    for(int i = 0; i < raw.size(); i++){
        if(raw[i] == 0){
            raw[i] = 6;
        }
    }
}

void merge(std::vector<int>&raw, std::vector<int>n_vector){
    for(int i = 0; i < n_vector.size(); i++){
        raw.push_back(n_vector[i]);
    }
}

void print_fish(std::vector<int> raw, int day){
    std::cout << "After " << day << " days: ";
    for(int i = 0; i < raw.size(); i++){
        std::cout << raw[i] << ",";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int>raw { 2,1,2,1,5,1,5,1,2,2,1,1,5,1,4,4,4,3,1,2,2,3,4,1,1,5,1,1,4,2,5,5,5,1,1,4,5,4,1,1,4,2,1,4,1,2,2,5,1,1,5,1,1,3,4,4,1,2,3,1,5,5,4,1,4,1,2,1,5,1,1,1,3,4,1,1,5,1,5,1,1,5,1,1,4,3,2,4,1,4,1,5,3,3,1,5,1,3,1,1,4,1,4,5,2,3,1,1,1,1,3,1,2,1,5,1,1,5,1,1,1,1,4,1,4,3,1,5,1,1,5,4,4,2,1,4,5,1,1,3,3,1,1,4,2,5,5,2,4,1,4,5,4,5,3,1,4,1,5,2,4,5,3,1,3,2,4,5,4,4,1,5,1,5,1,2,2,1,4,1,1,4,2,2,2,4,1,1,5,3,1,1,5,4,4,1,5,1,3,1,3,2,2,1,1,4,1,4,1,2,2,1,1,3,5,1,2,1,3,1,4,5,1,3,4,1,1,1,1,4,3,3,4,5,1,1,1,1,1,2,4,5,3,4,2,1,1,1,3,3,1,4,1,1,4,2,1,5,1,1,2,3,4,2,5,1,1,1,5,1,1,4,1,2,4,1,1,2,4,3,4,2,3,1,1,2,1,5,4,2,3,5,1,2,3,1,2,2,1,4 };

    uint64_t num [9] = {0,0,0,0,0,0,0,0,0};

    for(int i = 0; i < raw.size(); i++){
        num[raw[i]]++;
    }




    uint64_t sum = 0;
    for(int i = 0; i < 256; i++){

        uint64_t father = num[0];
        num[0] = num[1];
        num[1] = num[2];
        num[2] = num[3];
        num[3] = num[4];
        num[4] = num[5];
        num[5] = num[6];
        num[6] = num[7] + father;
        num[7] = num[8];
        num[8] = father;



    }
    for(int i = 0; i < 9; i++){
        sum += num[i];
    }
    std::cout << "Total: " << sum << std::endl;

    /*
                if(turn_z == true){
                    eight += zero;
                    zero -= zero;
                    turn_z = false;
                }

                //Drain cycle
                zero = one;
                one = two;
                two = three;
                three = four;
                four = five;
                five = six;
                six = seven;
                seven = eight;
                eight = zero;



            turn_z = true;

    */

    return 0;
}
