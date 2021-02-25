#include <iostream>
#include <string>
#include <cstdlib>
#include <queue> 
#include "TrafficLight.h"
// #include car.h
using namespace std;

int main() {
    // your code goes here
    
    TrafficLight t("1");
    cout << t.get_num_of_waiting_cars() << endl;
    t.update_queue(1);
    cout << t.get_num_of_waiting_cars() << endl;
    cout << t.get_current_state() << endl;
    t.update_state(true);
    cout << t.get_current_state() << endl;
    
    return 0;
}