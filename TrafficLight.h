#include <iostream>
#include <string>
#include <cstdlib>
#include <queue> 
// #include car.h
using namespace std;

class TrafficLight {
	public: 
		string street;
		bool state; // red is false, green is true
		queue<int> cars_waiting;
	
		TrafficLight(string street_name) {
			state = false;
			street = street_name;
			cout << "Traffic light at the end of street " << street_name << " created." << endl;
		}
		
		void update_queue(int car_obj) {
			cars_waiting.push(car_obj);
		} 
		
		void update_state(bool new_state) {
			state = new_state;
		}
		
		int get_num_of_waiting_cars(){
			return cars_waiting.size();
		}
		
		bool get_current_state() {
			return state;
		}
};

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