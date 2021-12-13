#include <bits/stdc++.h>

using namespace std;


struct Score {
  int fuel;
  int crab;
};

bool sort_score(const Score& x, const Score&y) {return x.fuel < y.fuel;};

int part_1(vector<int>crabs){
    int sum_fuel = 0;
    int crab_pos = -500;
    unsigned long long last_fuel = 99999999999999;


    for(int i = 0; i < crabs.size(); i++){
        sum_fuel = 0;
        for(int j = 0; j < crabs.size(); j++){
            int fuel = std::max(crabs[i],crabs[j]) - std::min(crabs[i],crabs[j]);

            sum_fuel += fuel;
            int crab = crabs[i];
        }
        if(sum_fuel < last_fuel){
            last_fuel = sum_fuel;
            crab_pos = crabs[i];
        }

    }
    return last_fuel;
}

int part_2(vector<int> crabs){
    int sum_fuel = 0;
    int crab_pos = -500;
    unsigned long long last_fuel = 99999999999999;


    for(int i = 0; i < crabs.size(); i++){
        sum_fuel = 0;
        for(int j = 0; j < crabs.size(); j++){
            int fuel = 0;
            int step = 1;
            for(int k = std::min(crabs[i],crabs[j]); k < std::max(crabs[i],crabs[j]); k+=step ){
                fuel = step;
                step++;
            }
            sum_fuel += fuel;
            int crab = crabs[i];
        }
        if(sum_fuel < last_fuel){
            last_fuel = sum_fuel;
            crab_pos = crabs[i];
        }

    }
    return last_fuel;
}

int main()
{
    vector<int> crabs {16,1,2,0,4,2,7,1,2,14};



    std::cout << part_1(crabs) << std::endl;
    std::cout << part_2(crabs) << std::endl;

/*
 *             int step = 1;
            for(int k = std::min(crabs[i],crabs[j]); k < std::max(crabs[i],crabs[j]); k+= step){
                step++;
            }
            */
    return 0;
}
