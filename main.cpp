//Mustafa Serhat USLU

#include <iostream>
#include <ctime>
#include <cmath>
#include "zonecounter.hpp"
#include "map.hpp"

void CreateRandomMap(MapInterface* map);

int main() {
    MapInterface* map = new MustafaSerhatUSLU::Map();
    ZoneCounterInterface* zone = new MustafaSerhatUSLU::ZoneCounter();

    CreateRandomMap(map);

    zone->Init(map);

    std::cout << "AREAS: " << zone->Solve()<< std::endl;

    map->Show();

    return 0;
}

void CreateRandomMap(MapInterface* map){

    srand((unsigned) time(0));

    int randomWidth = (rand() % 45) + 5;
    int randomHeight = (rand() % 15) + 5;
    int randomAmountOfBorders = (rand() % 8) + 3;

    //INSIDE_AREA->(x,y) but FRAME_SIZE->(x+2,y+2)
    map->SetSize(randomWidth, randomHeight);

    //Draw random lines inside the initialized area
    for(int n = 0; n<= randomAmountOfBorders; n++){

        //Find random border points to draw lines from
        int x_randomBorderPoint, y_randomBorderPoint;
        do{
            x_randomBorderPoint = (rand() % (randomWidth + 1));
            y_randomBorderPoint = (rand() % (randomHeight + 1));
        }
        while(!(map->IsBorder(x_randomBorderPoint, y_randomBorderPoint)));

        //Figure out the random border style
        int borderDirectionHorizontal = rand() % 100;
        int borderDirectionVertical = rand() % 100;
        int borderDirectionDiagonal = rand() % 100;

        //random horizontal direction
        if(borderDirectionHorizontal % 2 == 0){
            borderDirectionHorizontal = 1;
        }
        else{
            borderDirectionHorizontal = -1;
        }

        //random vertical direction
        if(borderDirectionVertical % 2 == 0){
            borderDirectionVertical = 1;
        }
        else{
            borderDirectionVertical = -1;
        }

        //random tilt or not
        if(borderDirectionDiagonal % 2 == 0){
            borderDirectionDiagonal = 1;
        }
        else{
            borderDirectionDiagonal = -1;
        }

        //hypotenus is needed as a limit for the inside border length as it is the longest possible border inside
        int hypotenus = sqrt(pow(randomWidth,2) + pow(randomHeight,2));

        if(borderDirectionDiagonal == 1){          //Draw diagonal border
           for(int m = 0; m <= hypotenus; m++) {
                map->SetBorder(x_randomBorderPoint + m*borderDirectionHorizontal, y_randomBorderPoint + m*borderDirectionVertical);
            }
        }
        else if(n % 2 == 0){                       //Draw vertical border
           for(int m = 0; m <= hypotenus; m++) {
                map->SetBorder(x_randomBorderPoint, y_randomBorderPoint + m*borderDirectionVertical);
           }
        }
        else{
           for(int m = 0; m <= hypotenus; m++) {   //Draw horizontal border
                map->SetBorder(x_randomBorderPoint + m*borderDirectionHorizontal , y_randomBorderPoint);
           }
        }
    }
    std::cout << std::endl << "Frame Width,Height: " << randomWidth << "," << randomHeight << std::endl;
}
