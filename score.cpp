#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
// #include "cars.h" 
using namespace std;

// F - socre for successful completion of each car
// D - total simulation time

int score(int cars, int F, int D){
    int final_score = 0;
    
    for(int i=0; i<cars.size(); i++) {
        if (car[i].reached_destination()) {
            final_score = final_score + F + (D-cars[i].time_taken());
        }

        // int curr_location = cars[i].get_curent_location();
        // // if (!at_ebd()){
        // //     continue;
        // // }
        // int curr_street = cars[i].get_curent_street();
        // string destination = cars[i].get_destination();

        // if (curr_street == destination) {
        //     final_score = final_score + F
        // }
    }

    return final_score;

}