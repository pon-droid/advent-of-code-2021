#include <iostream>
#include <bits/stdc++.h>



int main()
{

    std::vector<int> vec;

    std::ifstream file_in("values.txt");

    std::string line;
    while(std::getline(file_in,line)){
        std::istringstream ss(line);
        int x;
        while(ss >> x){
            vec.push_back(x);
        }
    }


    int num [] = {199,
                      200,
                      208,
                      210,
                      200,
                      207,
                      240,
                      269,
                      260,
                      263,0,0,0,0,0,0,0,0,0};




    vec.push_back(0);
    vec.push_back(0);
    vec.push_back(0);
    int count = -1;
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    int sum = 0;
    int n_sum = 0;
    int last_i = 1;

    for(int i = 0; i < vec.size(); i++){

        t1 = vec[last_i-1];
        t2 = vec[last_i];
        t3 = vec[last_i+1];
        n_sum = (t1+t2+t3);
        if(n_sum > sum){
            count++;
            std::cout << sum << std::endl;

        }
        sum = n_sum;
        last_i = i + 1;



    }
    std::cout << count << " || " << sum << std::endl;
    /*
    int temp = 0;
    int count = 0;
    for(int i = 0; i < 10; i++){
        if(numbers[i] > temp){

            count++;
        }
        temp = numbers[i];
    }
    std::cout << count << std::endl;
    */
    return 0;
}
