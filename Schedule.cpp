#include <iostream>
#include <list>
#include <queue>
using namespace std;

class TrafficLight {
    public:
        std::queue<int> currQueue;
        void add_car(int que) {
            currQueue.push(que);
        }
};

TrafficLight getTrafficLight(string streetName) {
    TrafficLight light1 = TrafficLight();
    light1.add_car(1);
    light1.add_car(2);
    light1.add_car(3);
    TrafficLight light2 = TrafficLight();
    light2.add_car(1);
    light2.add_car(2);
    if (streetName.compare("test1") == 0) {
        return light1;
    }
    return light2;
}
std::list<string> getStreets(int id) {
    std::list<string> streets {"test1", "test2"};
    return streets;
}
class Schedule {
    public: 
        std::list<std::pair<int, std::list<std::pair<string, int>>>> allIntersection;
        int simulationTime = 6;

        void createListForIntersection(int id) {
            std::cout << "STARTED";
            std::list<std::pair<string, int>> intersectionSchedule;
            std::list<string> perSecondSchedule;
            for (int i = 0; i < simulationTime ; i++) {
                perSecondSchedule.push_back(findLongestQueue(id));
            }
            int secCount = 1;
            string previousTrafficLight = perSecondSchedule.front();
            perSecondSchedule.pop_front();
            for (int i = 0; i < perSecondSchedule.size() - 1 ; i++) {
                if (perSecondSchedule.front().compare(previousTrafficLight) == 0) {
                    secCount++;
                    std::cout << "Repeated entry " << secCount << std::endl;
                } else {
                    intersectionSchedule.push_back(std::make_pair(previousTrafficLight, secCount));
                    secCount = 1;
                    std::cout << "New entry" << std::endl;
                }
                std::cout << " error1";
                previousTrafficLight = perSecondSchedule.front();
                std::cout << " error2";
                perSecondSchedule.pop_front();
                std::cout << " error3";
            }
            allIntersection.push_back(std::make_pair(id, intersectionSchedule));
            std::cout<<"HERE";
            for (int i = 0 ; i < allIntersection.size() ; i++) {
                std::cout << intersectionSchedule.front().first << intersectionSchedule.front().second << std::endl;
            }
        }

        string findLongestQueue(int id) {
            std::list<string> streets = getStreets(id);
            int max_queue = 0;
            string changeToGreen;
            for (const string st : streets) {
                std::cout << "In street " << st << getTrafficLight(st).currQueue.size() << std::endl;
                if (getTrafficLight(st).currQueue.size() > max_queue) {
                    max_queue = getTrafficLight(st).currQueue.size();
                    changeToGreen = st;
                }
            }
            std::cout << changeToGreen << max_queue << std::endl;
            return changeToGreen;
        }

};

int main() {
	// your code goes here
    Schedule sch = Schedule();
    sch.createListForIntersection(1);
	return 0;
}