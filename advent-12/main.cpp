#include <bits/stdc++.h>

#define TYPE_GRAPH std::unordered_map<std::string, std::vector<std::string>>
#define RECORD std::unordered_map<std::string, int>

std::unordered_map<std::string, std::vector<std::string>> init_graph(std::array<std::string,7> serial){
    std::unordered_map<std::string, std::vector<std::string>> list;

    for(int i = 0; i < serial.size(); i++){
        std::string ch = "-";

        std::string temp = serial[i];

        std::string first_cave = temp.substr(0, temp.find(ch));
        temp.erase(0, temp.find(ch) + ch.length());
        std::string second_cave = temp;

        std::vector<std::string>temp_vec = list[first_cave];
        temp_vec.push_back(second_cave);
        list[first_cave] = temp_vec;
        temp_vec.clear();
        temp_vec = list[second_cave];
        temp_vec.push_back(first_cave);
        list[second_cave] = temp_vec;

    }
    return list;
}

void print_graph(std::unordered_map<std::string, std::vector<std::string>>list){
    for(const auto& i : list){
        std::cout << "]]]]]]]]]]]]]]]" << std::endl;
        std::cout << i.first << std::endl;
        std::cout << "^^^^^^^^^^^^" << std::endl;
        std::cout << "Neighbours " << std::endl;
        std::cout << "===============" << std::endl;
        for(int j = 0; j < i.second.size(); j++){
            std::cout << i.second[j] << " ";
        }
        std::cout << std::endl;
    }
}

RECORD init_visited(TYPE_GRAPH graph){
    std::unordered_map<std::string, int>visit;

    for(const auto &i: graph){
        visit[i.first] = 0;
    }
    return visit;
}

int paths = 0;

void dfs(std::string node, TYPE_GRAPH list, RECORD &visited){
    if(node == "end") {paths++; return;};

    if (islower(node[0]) && node != "end" && node != "start"){
            int hit_small = 0;

            for(auto &cave: visited){

                if(cave.second > 1){
                    hit_small++;
                }

                if(cave.second > 1){
                    cave.second--;
                    return;
                }


            }

            if (hit_small > 1){
                visited[node]--;
                return;
            }
    }
    for(auto &cave: list){
        if (cave.first == "start"){
            continue;
        }
        dfs(cave.first,list,visited);
    }

    if (islower(node[0])){
        visited[node]--;
    }

}

int main()
{
    std::array<std::string,7> serial {
            "start-A",
            "start-b",
            "A-c",
            "A-b",
            "b-d",
            "A-end",
            "b-end"
    };


    TYPE_GRAPH graph = init_graph(serial);

    RECORD visit = init_visited(graph);

    dfs("start", graph, visit);

    std::cout << paths << std::endl;


    return 0;
}
