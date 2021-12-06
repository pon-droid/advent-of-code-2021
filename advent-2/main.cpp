#include <bits/stdc++.h>

struct data {
  std::string move;
  int dep;
};


int main()
{
    std::vector<data> vec;

    std::ifstream file("values.txt");

    std::string s;
    int num;

    while(file >> s >> num){
        vec.push_back({s,num});
    }

    int depth = 0;
    unsigned int position = 0;
  int aim = 0;

    std::vector<data> test;
    test.push_back({"forward",5});
    test.push_back({"down",5});
    test.push_back({"forward",8});
    test.push_back({"up",3});
    test.push_back({"down",8});
    test.push_back({"forward",2});

    /*

      for(int i = 0; i < vec.size(); i++){
      if(vec[i].move == "down"){
      increase depth/stuff
      }


      */

    for(int i = 0; i < vec.size(); i++){
        if(vec[i].move == "down"){
           //depth += test[i].dep;
           aim += vec[i].dep;
        }
        if(vec[i].move == "up"){
            //depth -= test[i].dep;
            aim -= vec[i].dep;
        }
        int d_add = (aim * vec[i].dep);
        //std::cout << "================" << std::endl;
        //std::cout << test[i].move << " " << test[i].dep << std::endl;
        //std::cout << d_add << " = " << aim << " * " << test[i].dep << std::endl;
        if(vec[i].move == "forward"){
            position += vec[i].dep;
            depth += d_add;
            //std::cout << d_add << " !!= " << aim << " * " << test[i].dep << std::endl;

        }

        //std::cout << "DEP: " << depth << std::endl;

    }

    std::cout << position << " && " << depth << std::endl;

    long sum = position * depth;

    std::cout << "ANS: " << sum << std::endl;


    return 0;
}
