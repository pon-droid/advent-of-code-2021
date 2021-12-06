#include <bits/stdc++.h>

std::string oxygen (std::vector<std::string>vector){
    int one;
    int zero;
    int max = vector.size();
    for(int i = 0; i < vector[0].size(); i++){
        one = 0;
        zero = 0;
        for(int j = 0; j < max; j++){
            char ch = vector[j][i];
            if(ch == '1'){
                one++;
            }
            if(ch == '0'){
                zero++;
            }
        }
        if(zero > one){
            for(int k = 0; k < vector.size(); k++){
                char ch = vector[k][i];
                if(ch == '1'){
                    vector.erase(vector.begin() + k);
                }
            }
        } else if (one >= zero) {
            for(int k = 0; k < vector.size(); k++){
                char ch = vector[k][i];
                if(ch == '0'){
                    vector.erase(vector.begin() + k);
                }
            }
        }
    }
    return vector[0];
}

struct bits {
    int one;
    int zero;
};

char f_common (std::vector<std::string>work, int position){
    int one = 0;
    int zero = 0;
    for(int i = 0; i < work.size(); i++)
    {
        if(work[i][position] == '1') one++;
        else zero++;
    }

    if(one > zero){
        return '1';
    } else {
        return '0';
    }
}

char n_common(std::vector<std::string> work, int position)
{
    int data = 0;
    for(int i = 0; i < work.size(); i++)
    {
        if(work[i][position] == '1') data++;
        else data--;
    }

    if(data >= 0)
        return '1';
    else
        return '0';
}

char common (std::vector<std::string>bits, int pos){
    int one = 0;
    int zero = 0;
    for(int i = 0; i < bits.size(); i++){
        if(bits[i][pos] == '1'){
            one++;
        } else {
            zero++;
        }
    }

    if(one > zero){
        return '1';
    } else if (zero >= one) {
        return '0';
    }
}

int main()
{
    std::string test = "0110101";
    std::string s;
    std::ifstream file ("binary.txt");
    std::vector<std::string> vec;
    while(file >> s){
        vec.push_back(s);
    }
    std::string gamma;
    int one = 0;
    int zero = 0;
    /*
    for(int i = 0; i < vec.size(); i++){

        for(int k = 0; k < 1; k++){
            for(int j = 0; j < vec[i].size(); j++){
                char ch = vec[i][j];
                if(ch == '1'){
                    one++;
                }
                if(ch == '0'){
                    zero++;
                }
            }
            if(one > zero){
                gamma += '1';
            } else {
                gamma += '0';
            }
        }



    }*/

    //Gamma and Epsilon
    for(int i = 0; i < vec[0].size(); i++){
        one = 0;
        zero = 0;
        for(int j = 0; j < vec.size(); j++){
            char ch = vec[j][i];
            if(ch == '1'){
                one++;
            }
            if(ch == '0'){
                zero++;
            }
        }
        if(one > zero){
            gamma += '1';
        } else {
            gamma += '0';
        }
    }
    std::string epsilon;
    for(int i = 0; i < gamma.size(); i++){
        if(gamma[i] == '1'){
            epsilon += '0';
        } else {
            epsilon += '1';
        }

    }
    unsigned int ep = std::bitset<32>(epsilon).to_ulong();
    unsigned int gam = std::bitset<32>(gamma).to_ulong();
    int sum = ep * gam;


    std::cout << gamma << " " << epsilon << " " << sum << std::endl;

    //Oxygen and CO2
/*
    std::vector<std::string>temp;
    char num = 1;
    for(int i = 0; i < vec.size(); i++){
        temp.push_back(vec[i]);
    }

    for(int i = 0; i < temp.size(); i++){
        if(vec[i][0] == num){
            temp.push_back(vec[i]);
            std::cout << temp.size() << std::endl;

        }
    }



    auto it = temp.begin();
    int i = 0;
    while(it != temp.end()){
        if(temp[i][0] == num){
            it = temp.erase(it);
        } else {
            it++;
        }
        i++;
    }
*/
    //Oxygen and CO2

    std::vector<std::string>oxygen;
    std::vector<std::string>carbon;
    std::vector<std::string> temp;



    std::string exam [] = {"00100",
                           "11110",
                           "10110",
                           "10111",
                           "10101",
                           "01111",
                           "00111",
                           "11100",
                           "10000",
                           "11001",
                           "00010",
                           "01010"};

    for(int i = 0; i < vec.size(); i++){
        oxygen.push_back(vec[i]);
        carbon.push_back(vec[i]);
    }

    for(int i = 0; oxygen.size() > 1; i++){
        char ch = common(oxygen,i);
        std::vector<std::string> t_oxy;
        for(int j = 0; j < oxygen.size(); j++){
            if(oxygen[j][i] == ch){
                t_oxy.push_back(oxygen[j]);
            }
        }
        oxygen = t_oxy;
    }

    for(int i = 0; carbon.size() > 1; i++)
    {
        char ch = common(carbon, i);
        std::vector<std::string> new_co2;
        for(int j = 0; j < carbon.size(); j++)
        {
            if(carbon[j][i] != ch)
                new_co2.push_back(carbon[j]);
        }
        carbon = new_co2;
    }


    std::cout << oxygen.front() << std::endl;
    std::cout << carbon.front() << std::endl;

    unsigned int oxy = std::bitset<32>(oxygen.front()).to_ulong();
    unsigned int carb = std::bitset<32>(carbon.front()).to_ulong();

    std::cout << oxy * carb << std::endl;


/*
    for(int i = 0; i < oxygen.size() > 1; i++){
        char ch = common(oxygen,i);
        std::vector<std::string> n_oxy;
        for(int j = 0; j < oxygen.size(); j++){
            if(oxygen[j][i] == ch){
                n_oxy.push_back(oxygen[i]);
            }
        }
        oxygen = n_oxy;

    }
    for(int i = 0; carbon.size() > 1; i++){
        char ch = common(carbon,i);
        std::vector<std::string> n_carb;
        for(int j = 0; j < carbon.size(); j++){
            if(carbon[j][i] != ch){
                n_carb.push_back(carbon[j]);
            }
            carbon = n_carb;
        }
    }

    std::cout << oxygen.front() << " || " << carbon.front() << std::endl;

    unsigned int p_oxy = std::bitset<32>(oxygen.front()).to_ulong();
    unsigned int p_carb = std::bitset<32>(carbon.front()).to_ulong();
*/
/*
    int max = 0;

    while(temp.size() > 1){
        //Max is a temporary search range
        max = temp.size();
        for(int i = 0; i < temp[0].size(); i++){
            one = 0;
            zero = 0;
            for(int j = 0; j < temp.size(); j++){
                char ch = temp[j][i];
                if(ch == '1'){
                    one++;
                }
                if(ch == '0'){
                    zero++;
                }
            }

            if(zero > one){
                for(int k = 0; k < temp.size(); k++){
                    char ch = temp[k][i];
                    if(ch == '1'){
                        temp.erase(temp.begin() + k);
                    }
                }
            } else if (one >= zero) {
                for(int k = 0; k < temp.size(); k++){
                    char ch = temp[k][i];
                    if(ch == '0'){
                        temp.erase(temp.begin() + k);
                    }
                }
            }
        }
    }
    std::cout << temp[0] << std::endl;

    std::string oxygen = temp[0];

    temp.clear();

    for(int i = 0; i < vec.size(); i++){
        temp.push_back(vec[i]);
    }
    */
/*
    max = 0;
    while(temp.size() > 1){

        //Max is a temporary search range
        max = temp.size();
        for(int i = 0; i < temp[0].size(); i++){
            one = 0;
            zero = 0;
            for(int j = 0; j < temp.size(); j++){
                char ch = temp[j][i];
                if(ch == '1'){
                    one++;
                }
                if(ch == '0'){
                    zero++;
                }
            }

            if(one < zero){
                for(int k = 0; k < temp.size(); k++){
                    char ch = temp[k][i];
                    if(ch == '0'){
                        temp.erase(temp.begin() + k);
                    }
                }
            } else if (one >= zero) {
                for(int k = 0; k < temp.size(); k++){
                    char ch = temp[k][i];
                    if(ch == '1'){
                        temp.erase(temp.begin() + k);
                    }
                }
            }

        }

    }
*/
    /*
    while(temp.size() > 1){
        //Current bit col
        for(int i = 0; i < temp[0].size(); i++){
            one = 0;
            zero = 0;
            //Every row
            for(int j = 0; j < temp.size(); j++){
                char ch = temp[j][i];
                if(ch == '1'){
                    one++;
                }
                if(ch == '0'){
                    zero++;
                }
            }
            if(one < zero){
                for(int k = 0; k < temp.size(); k++){
                    char ch = temp[k][i];
                    if(ch == '0'){
                        temp.erase(vec.begin() + k);
                    }
                }

            }
            if(zero <= one){
                for(int k = 0; k < temp.size(); k++){
                    char ch = temp[k][i];
                    if(ch == '1'){
                        temp.erase(vec.begin() + k);
                    }
                }
            }
        }
    }
*/




   // std::cout << "Oxygen: " << p_oxy << " Carbon: " << p_carb << std::endl;
    //std::cout << "SUM: " << p_oxy * p_carb << std::endl;



    std::cout << "===============" << std::endl;






    return 0;
}
