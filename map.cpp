#include <iostream>
#include "map.hpp"

namespace MustafaSerhatUSLU {

//Sets the size of the map and initilizes all values as false
void Map::SetSize(const int width, const int height){
    m_mapPoint.clear();

    m_mapPoint.resize(width);

    for(int i = 0; i < width; ++i) {
        m_mapPoint[i].resize(height);
        for(int j = 0; j < height; ++j) {
            m_mapPoint[i][j] = false;
        }
    }
}

void Map::GetSize(int & width, int & height) const {
    width = m_mapPoint.size() > 0 ? m_mapPoint.size() : 0;
    height = m_mapPoint.size() > 0 ? m_mapPoint[0].size() : 0;
}

void Map::SetBorder(const int x, const int y) {
    //check if point to be drawn is in frame
    if(x >= 0 && y >= 0 && x < (int)m_mapPoint.size() && y < (int)m_mapPoint[0].size()) {
        m_mapPoint[x][y] = true;
    }
}

void Map::ClearBorder(const int x, const int y) {
    m_mapPoint[x][y] = false;
}

bool Map::IsBorder(const int x, const int y) const {
    //If it's within the bounds, return the value stored in the map, which will be true if it's a border or false otherwise.
    if(x < (int)m_mapPoint.size() && y < (int)m_mapPoint[0].size() && x >= 0 && y >= 0) {
        return m_mapPoint[x][y];
    }
    else{
        return true;
    }
}

void Map::Show() const {
    int width, height;
    GetSize(width, height);

    // Print the top border, width+2 to make actually inside of the area (width x height)
    for(int j = 0; j < width + 2; ++j) {
        std::cout << '*';
    }

    std::cout << std::endl;

    for(int i = 0; i < height; ++i){

        //Print the left border each time new line starts
        std::cout << '*';

        for(int j = 0; j < width; ++j) {
            // If it's a border or frame itself, print *, otherwise print a whitespace
            std::cout << (m_mapPoint[j][i] ? '*' : ' ');
        }

        //Print the right border each time at the end of line
        std::cout << '*' << std::endl;
    }

    // Print the bottom border
    for(int j = 0; j < width + 2; ++j) {
        std::cout << '*';
    }

    std::cout << std::endl;
}

}
