#include <iostream>
#include <vector>
#include <fstream>

// Function definations
void readMap(std::vector<char> &map, unsigned int &mapSizeX, unsigned int &mapSizeY);
unsigned int getArrayIndex(unsigned int column, unsigned int row, unsigned int numberOfColumn);

int main(){
    std::vector<char> map;
    unsigned int mapSizeX, mapSizeY;

    // Reading the map
    readMap(map, mapSizeX, mapSizeY);

    // Testing the final outout
    // std::cout<<"The x value of the map is "<<mapSizeX<<" and the y size of the map is "<<mapSizeY;
    for(int j=0; j<mapSizeY; j++){
        for(int i=0; i<mapSizeX; i++){
            std::cout<<map[getArrayIndex(i, j, mapSizeX)];
            // std::cout<<i<<" "<<j<<" "<< getArrayIndex(i, j, mapSizeX)<<"\n";
        }
        std::cout<<"\n";
    }

    return 0;
}

void readMap(std::vector<char> &map, unsigned int &mapSizeX, unsigned int &mapSizeY){
    std::ifstream file("map.txt");
    if(!file){
        std::cout<<"Unable to load the map.txt try reinstalling the program!";
    }

    char ch;
    mapSizeX = 0;
    mapSizeY = 1u;
    while(file.get(ch)){
        if(ch == '\r') continue; // This is for windows devices

        if(ch == '\n'){
            mapSizeX=0;
            mapSizeY++;
            continue;
        }

        map.push_back(ch);

        mapSizeX++;
    }

    file.close();
}

unsigned int getArrayIndex(unsigned int column, unsigned int row, unsigned int numberOfColumn){
    return row*numberOfColumn + column;
}