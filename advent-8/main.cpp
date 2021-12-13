#include <bits/stdc++.h>
#define TABLE 10
#define OUTPUT 4

using namespace std;



std::string::size_type match(string s1, string s2){
    sort(begin(s1), end(s1));
    sort(begin(s2),end(s2));
    string intersect;

    set_intersection(begin(s1), end(s1), begin(s2), end(s2), back_inserter(intersect));

    return intersect.size();
}

bool match_bool(string s1, string s2){
    sort(begin(s1), end(s1));
    sort(begin(s2),end(s2));
    string temp = s1;
    string intersect;

    set_intersection(begin(s1), end(s1), begin(s2), end(s2), back_inserter(intersect));
    if(intersect.size() == s1.size() && s1.size() == s2.size()){
        return true;
    }
    return false;
}

void initial_pass(vector<string> serial, string (&digit) [TABLE]){
    for(int i = 0; i < serial.size(); i++){
        int seg_c = serial[i].length();
        //cout << serial[i] << endl;
        switch(seg_c){
        case 2:
        digit[1] = serial[i];
        break;
        case 4:
        digit[4] = serial[i];
        break;
        case 3:
        digit[7] = serial[i];
        break;
        case 7:
        digit[8] = serial[i];
        break;

        }
    }
}

void map_pass(vector<string> serial, string (&digit) [TABLE], std::map<string,int> map){
    for(int i = 0; i < serial.size(); i++){
        int seg_c = serial[i].length();
        switch(seg_c){
        case 2:
        digit[1] = serial[i];
        map[serial[i]] = 1;
        break;
        case 4:
        digit[4] = serial[i];
        break;
        case 3:
        digit[7] = serial[i];
        break;
        case 7:
        digit[8] = serial[i];
        break;

        }
    }
}

void five_test(vector<string> serial, string (&digit) [TABLE]){
    vector<string> ef23;
    vector<string> six90;

    //cout << "Seven is: " << seven << endl;
   // cout << "One is: " << one << endl;


    for(int i = 0; i < serial.size(); i++){
        if(serial[i].length() == 5){
            ef23.push_back(serial[i]);
        } else if (serial[i].length() == 6){
            six90.push_back(serial[i]);
        }
    }

    for(int i = 0; i < ef23.size(); i++){
        //One shares two digits with 3
        if(match(digit[1],ef23[i]) == 2){
            digit[3] = ef23[i];
            vector<string>temp = ef23;
            temp.erase(temp.begin() + i);
            for(int j = 0; j < temp.size(); j++){
                if(match(digit[4],temp[j]) == 3){
                    digit[5] = temp[j];
                    temp.erase(temp.begin() + j);
                }
            }
            digit[2] = temp.front();
        }

    }

    for(int i = 0; i < six90.size(); i++){
        if(match(digit[7],six90[i]) == 2){
            digit[6] = six90[i];
            vector<string>temp = six90;
            temp.erase(temp.begin() + i);
            for(int j = 0; j < temp.size(); j++){
                if(match(digit[3],six90[j]) == 5){
                    digit[9] = six90[j];
                    //cout << six90[j] << " THAT" << endl;
                    temp.erase(temp.begin() + j);
                }
            }
            digit[0] = temp.front();
        }
    }


    //cout << digit[0] << endl;
/*
    for(int i = 0; i < ntemp.size(); i++){
        cout << ef23[i] << endl;
        if(match(digit[1],ef23[i]) == 1){         //Seven shares two digits with 2
                    digit[5] = ef23[i];
                    //cout << digit[5] << endl;
        }



    }
*/

//Something wrong with 5

}

void n_test(vector<string> serial, string (&digit) [TABLE]){
    vector<string> ef23;
    vector<string> six90;

    //cout << "Seven is: " << seven << endl;
   // cout << "One is: " << one << endl;


    for(int i = 0; i < serial.size(); i++){
        if(serial[i].length() == 5){
            ef23.push_back(serial[i]);
        } else if (serial[i].length() == 6){
            six90.push_back(serial[i]);
        }
    }

    for(int i = 0; i < ef23.size(); i++){
        //One shares two digits with 3
        if(match(digit[1],ef23[i]) == 2){
            digit[3] = ef23[i];
            vector<string>temp = ef23;
            temp.erase(temp.begin() + i);
            for(int j = 0; j < temp.size(); j++){
                if(match(digit[4],temp[j]) == 3){
                    digit[5] = temp[j];
                    temp.erase(temp.begin() + j);
                }
            }
            digit[2] = temp.front();
        }

    }

    for(int i = 0; i < six90.size(); i++){
        if(match(digit[7],six90[i]) == 2){
            digit[6] = six90[i];
            vector<string>temp = six90;
            temp.erase(temp.begin() + i);
            for(int j = 0; j < temp.size(); j++){
                if(match(digit[3],temp[j]) == 4){
                    digit[0] = temp[j];
                    //cout << temp[j] << " THAT" << endl;
                    temp.erase(temp.begin() + j);
                }
            }
            digit[9] = temp.front();
        }
    }


    //cout << digit[0] << endl;
/*
    for(int i = 0; i < ntemp.size(); i++){
        cout << ef23[i] << endl;
        if(match(digit[1],ef23[i]) == 1){         //Seven shares two digits with 2
                    digit[5] = ef23[i];
                    //cout << digit[5] << endl;
        }



    }
*/

//Something wrong with 5

}

struct Input {

    std::vector <string> table;
    std::vector <string> output;
};


int main()
{
    ifstream file ("input.txt");
    string line;
    vector<string> keys;
    vector<string> serial;
    vector<Input> raw;



    while(getline(file,line)){
        string delim = " | ";
        string temp2 = line;
        string temp1 = line;
        vector<string>perline;
        vector<string>exit;

        string before = temp2.substr(0, temp2.find(delim));
        temp2.erase(0, temp2.find(delim) + delim.length());
        string after = temp2;

        delim = " ";

       // cout << before << endl;

        size_t pos = 0;
        string token;
        before = before + delim;
        while((pos = before.find(delim)) != std::string::npos){
            token = before.substr(0, pos);
            perline.push_back(token);
            before.erase(0, pos + delim.length());
        }

        pos = 0;
        after = after + delim;
        while((pos = after.find(delim)) != std::string::npos){
            token = after.substr(0,pos);
            exit.push_back(token);
            after.erase(0, pos + delim.length());

        }

        raw.push_back({perline,exit});

/*
        string token;
        size_t pos = 0;
        string temp = actual + delim;
        string first = temp1.substr(0, temp1.find(delim));
        while((pos = first.find(delim)) != string::npos){
            token = first.substr(0,pos);
            serial.push_back(token);
            cout << token << endl;
            first.erase(0, pos + delim.length());
        }
        cout << first << endl;


        pos = 0;
        while((pos = temp.find(delim)) != string::npos){
            token = temp.substr(0,pos);
            //cout << token << endl;
            keys.push_back(token);
            temp.erase(0, pos + delim.length());
        }
*/

    }


    /*
    int count = 0;
    for(int i = 0; i < keys.size(); i++){
        int longth = keys[i].length();

        switch(longth){
        case 2:
        count++;
            break;
        case 4:
        count++;
            break;
        case 3:
        count++;
            break;
        case 7:
        count++;
            break;


        }
    }
    cout << count << endl;
    */



    int sum = 0;
    for(int i = 0; i < raw.size(); i++){
        string digit [10];

            initial_pass(raw[i].table, digit);
            n_test(raw[i].table,digit);



        string output;

        for(int k = 0; k < raw[i].output.size(); k++){
            for(int l = 0; l < 10; l++){

                    if(match_bool(raw[i].output[k],digit[l]) == true){
                        output += std::to_string(l);
                    }


            }
        }

        sum += std::stoi(output);
        //cout << output << " " << i << endl;


    }

    cout << sum << endl;

   // cout << raw[1].output[0] << endl;
   // cout << raw[1].output[1] << endl;
  //  cout << raw[1].output[2] << endl;
  //  cout << raw[1].output[3] << endl;
/*
    for(int i = 1; i < 2; i++){
        string digit [10];

            initial_pass(raw[i].table, digit);
            n_test(raw[i].table,digit);



        for(int j = 0; j < 10; j++){
            cout << digit[j] << " " << j << endl;
        }


    }
*/


/*
    for(int i = 0; i < raw.table.size(); i++){
        string digit [10];
        initial_pass(serial, digit);
        five_test(serial,digit);

        for(int j = 0; j < 4; j++){

        }


    }
*//*
    for(int i = 0; i < 10; i++){
        if(i >= 10){
            cout << "||" << endl;
        }
        cout << digit[i] << " " << i << endl;

    }


*/


    return 0;
}
