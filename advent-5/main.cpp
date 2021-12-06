#include <bits/stdc++.h>
#define MS 1000
struct Point {
    int x;
    int y;
};

struct Map {
    int map[1000][1000];
};

void print_map(int map [MS][MS]){
    for(int i = 0; i < MS; i++){
        for(int j = 0; j < MS; j++){
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
//This uses bresenhaum's algoritihm, does not work with straight vertical
/*
void plot_lines(Point p1, Point p2, int map[MS][MS]){
    int n_grad = 2 * (p2.y - p1.y);
    int err_grad = n_grad - (p2.x - p1.x);
    for(int x = p1.x, y = p1.y; x <= p2.x; x++){
        map[x][y]-=2;

        err_grad += n_grad;

        if(err_grad >= 0){
            y++;
            err_grad -= 2 * (p2.x - p1.x);
        }

    }

}
*/

void plot_linesL(Point p1, Point p2, int (&map)[MS][MS]){
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    int yi = 1;
    if(dy < 0){
        yi = -1;
        dy = -dy;
    }
    int D = (2 * dy) - dx;
    int y = p1.y;

    for(int x = p1.x; x < p2.x; x++){
        map[x][y]++;
        if(D > 0){
            y = y + yi;
            D = D + (2 * (dy - dx));
        } else {
            D = D + 2*dy;
        }
    }
}

void plot_linesH(Point p1, Point p2, int (&map)[MS][MS]){
    int dx = p2.x - p1.x;
    int dy = p2.y - p2.y;
    int xi = 1;
    if(dx < 0){
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = p1.x;

    for(int y = p1.y; y < p2.y; y++){
        map[x][y]++;
        if(D > 0){
            x = x + xi;
            D = D + (2 * (dx-y));

        } else {
            D = D + 2 * dx;
        }
    }
}

void plot_lines(Point p1, Point p2, int (&map)[MS][MS]){
    if((p2.x - p1.x) < (p1.x - p2.x)){
        if(p1.x > p2.x){
            plot_linesL(p2,p1,map);
        } else {
            plot_linesL(p1,p2,map);
        }
    } else {
        if (p1.y > p2.y){
            plot_linesH(p2,p1,map);
        } else {
            plot_linesH(p1,p2,map);
        }
    }
}
//Add 1 to counter zero index counting
void tplot_lines(Point p1, Point p2, int (&map)[MS][MS]){
    //Vertical
    if(p1.x == p2.x){
        int max = std::max(p1.y,p2.y);
        int min = std::min(p1.y,p2.y);
        for(int i = min; i < max + 1; i++){
            map[i][p1.x]++;
        }
    }
    //horizontal
    else if(p1.y == p2.y){
        for(int i = std::min(p1.x,p2.x); i < std::max(p1.x,p2.x) + 1; i++){
            map[p2.y][i]++;
        }
    }
}

void plot_s_lines(Point p1, Point p2, int (&map)[MS][MS]){
    if(p1.x == p2.x){
        if(p1.y < p2.y){
            for(int i = p2.y; i > p1.y; i--){
                map[p1.x][i]++;
            }
        } else {
            for(int i = p1.y; i < p2.y; i++){
                map[p1.x][i]++;
            }
        }

    } else if (p2.y == p1.y) {
        if(p1.x < p2.x){
            for(int i = p2.x; i > p1.x; i--){
                map[i][p1.y]++;
            }
        } else {
            for(int i = p1.x; i < p2.x; i++){
                map[i][p1.y]++;
            }
        }


    }

}


int return_overlap(int map[MS][MS]){
    int overlap = 0;
    for(int i = 0; i < MS; i++){
        for(int j = 0; j < MS; j++){
            if(map[i][j] > 1){
                overlap++;
            }
        }
    }
    return overlap;
}
int main()
{
    std::ifstream file("coords.txt");

    std::string t;

   // std::vector<std::string>raw;<< std::endl
    std::vector<Point> starts;
    std::vector<Point> ends;
    int map[MS][MS];
    std::vector<int> grid;
    for(int i = 0; i < MS; i++){
        for(int j = 0; j < MS; j++){
            map[i][j] = 0;

        }
    }
/*
    std::string line;
    //Fix this for actual input later
    while(std::getline(file,line)){
        char x1 = line[0];
        char y1 = line[2];
        int xx1 = x1 - '0';
        int yy1 = y1 - '0';
        char x2 = line[7];
        int xx2 = x2 - '0';
        char y2 = line[9];
        int yy2 = y2 - '0';

        if(xx1 == xx2 || yy1 == yy2){

            starts.push_back({xx1,yy1});
            ends.push_back({xx2,yy2});
            std::cout << xx1 << " " << yy1 << std::endl;
            std::cout << xx2 << " " << yy2 << std::endl;
        }

    }
*/

    std::string line;

    int pos = 1;
    //Fix this for actual input later
    while(std::getline(file,line)){
        std::string delim = " -> ";
        std::string sp = line.substr(0, line.find(delim));
        line.erase(0,line.find(delim) + delim.length());
        std::string ep = line;

        delim = ",";
        std::string sx = sp.substr(0, sp.find(delim));
        std::string sy = sp.substr(sp.find(delim) + delim.length());
        std::string ex = ep.substr(0, ep.find(delim));
        std::string ey = ep.substr(ep.find(delim) + delim.length());

        std::cout << sx << " " << sy << std::endl;
        std::cout << ex << " " << ey << std::endl;

        int slx = std::stoi(sx);
        int sly = std::stoi(sy);
        int elx = std::stoi(ex);
        int ely = std::stoi(ey);

        if(slx == elx || sly == ely){
            starts.push_back({slx,sly});
            ends.push_back({elx,ely});
        }




    }



    if(ends.size() != starts.size()){
        std::cout << "Something terrible has happened" << std::endl;
    }

    //Mark point
    std::cout << "============" << std::endl;
    for(int i = 0; i < starts.size(); i++){

        tplot_lines(starts[i],ends[i],map);



    }


    print_map(map);

    std::cout << "Overlaps are: " << return_overlap(map) << std::endl;



    return 0;
}
