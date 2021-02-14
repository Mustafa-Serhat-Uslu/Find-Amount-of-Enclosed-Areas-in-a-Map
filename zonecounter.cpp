#include <iostream>
#include "zonecounter.hpp"

namespace MustafaSerhatUSLU {

void ZoneCounter::Init(MapInterface * map) {
    m_map = map;
}

int ZoneCounter::Solve() {

    //If map hasn't been initialized return 0
    if(!m_map) {
        return 0;
    }

    //Number of seperate areas
    int count = 0;

    int width, height;
    m_map->GetSize(width, height);

    //This array has as many elements as the map members and checks whether it has been visited or not
    bool visited[width * height];

    //Initialize every cell as unvisited
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            visited[j * width + i] = false;
        }
    }

    //Visit all cells
    for(int i = 0; i < width; ++i) {
        for(int j = 0; j < height; ++j) {
            // If the cell isn't a border, and it hasn't been visited yet, initialize the search
            if(!m_map->IsBorder(i, j) && !visited[j * width + i]) {
                Search(i, j, width, height, visited);
                count++;
            }
        }
    }

    return count;
}

//Checks if the cell is not visited yet && not a border && in the area then does the same for 4 the cells around it
void ZoneCounter::Search(int x, int y, int width, int height, bool visited[]) {
    if(!m_map->IsBorder(x, y) && !visited[y * width + x] && x >= 0 && y >= 0 && x < width && y < height) {
        //Label this point as visited
        visited[y * width + x] = true;
        Search(x - 1, y, width, height, visited);
        Search(x + 1, y, width, height, visited);
        Search(x, y - 1, width, height, visited);
        Search(x, y + 1, width, height, visited);
    }
}

}
