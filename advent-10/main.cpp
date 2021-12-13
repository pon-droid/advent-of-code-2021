#include <bits/stdc++.h>

using namespace std;

struct Pair {
    char open;
    char close;
};

int main()
{
    ifstream file("input.txt");
    string line;

    std::vector<string>syntax;
    while(getline(file,line)){
        syntax.push_back(line);
    }




    std::unordered_map<char, char> op_c;
    std::unordered_map<char, char> cl_o;
    op_c['('] = ')';
    op_c['['] = ']';
    op_c['{'] = '}';
    op_c['<'] = '>';


    cl_o[')'] = '(';
    cl_o[']'] = '[';
    cl_o['}'] = '{';
    cl_o['>'] = '<';


    std::unordered_map<char,char> scores;
/*
    scores[')'] = 3;
    scores[']'] = 57;
    scores['}'] = 1197;
    scores['>'] = 25137;
*/
    scores[')'] = 1;
    scores[']'] = 2;
    scores['}'] = 3;
    scores['>'] = 4;



//Part one
     /*

  for(int L = 0; L < syntax.size(); L++){
      bool corrupt = false;
      std::stack<char>begin;

      for(int i = 0; i < syntax[L].length(); i++){
          char ch = syntax[L][i];


          if(op_c.find(ch) != op_c.end()){
              begin.push(ch);
          } else  if (begin.size() == 0 || op_c.at(begin.top()) != ch){

              corrupt = true;

              sum += scores.at(ch);

          } else {
              begin.pop();
          }

          if(corrupt == true){
              break;
          }

      }

    }
    */
    std::vector<int64_t>answer;
     for(int L = 0; L < syntax.size(); L++){
         bool corrupt = false;
         std::stack<char>begin;
         for(int i = 0; i < syntax[L].length(); i++){
             char ch = syntax[L][i];

             if(op_c.find(ch) != op_c.end()){
                 begin.push(ch);
             } else if (begin.size() == 0 || op_c.at(begin.top()) != ch){
                 corrupt = true;

             } else {
               //  begin.pop();
             }
             if(corrupt){
                 continue;
             }
                int64_t score = 0;
             while(begin.size() != 0){
                 char close = op_c.at(begin.top());
                 score *= 5;
                    cout << score << endl;
                 int64_t autoscore = scores.at(close);
                 score += autoscore;
                 begin.pop();
             }
            // cout << score << endl;
             answer.push_back(score);
         }
     }

     sort(answer.begin(),answer.end());



  cout << answer[(answer.size() - 1)/2] << endl;
  return 0;
}
