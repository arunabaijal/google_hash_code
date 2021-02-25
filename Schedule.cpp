#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Schedule {
    public: 
        std::list<std::pair<int, std::list<std::pair<string, int>>>> allIntersection;
        int simulationTime = 20;

        void createListForIntersection(int id) {
            std::list<std::pair<string, int>> intersectionSchedule;
            std::list<string> perSecondSchedule;
            for (int i = 0; i < simulationTime ; i++) {
                perSecondSchedule.push_back(findLongestQueue(id));
            }
            int secCount = 1;
            string previousTrafficLight = perSecondSchedule.front();
            perSecondSchedule.pop_front();
            for (int i = 0; i < simulationTime - 1 ; i++) {
                if (perSecondSchedule.front().compare(previousTrafficLight) == 0) {
                    secCount++;
                } else {
                    intersectionSchedule.push_back(std::make_pair(previousTrafficLight, secCount));
                    secCount = 1;
                }
                previousTrafficLight = perSecondSchedule.front();
                perSecondSchedule.pop_front();
            }
            allIntersection.push_back(std::make_pair(id, intersectionSchedule));
        }

        string findLongestQueue(int id) {
            std::list<string> streets = getStreets(id);
            int max_queue = 0;
            string changeToGreen;
            for (const string st : streets) {
                if (getTrafficLight(st).currQueue.size() > max_queue) {
                    max_queue = getTrafficLight(st).currQueue.size();
                    changeToGreen = st;
                }
            }
            return changeToGreen;
        }

};

class TrafficLight {
    public:
        std::queue<int> currQueue;
};

TrafficLight getTrafficLight(string streetName) {
    return TrafficLight();
}
std::list<string> getStreets(int id) {
    return std::list<string> {'test'};
}
int main() {
	// your code goes here
	return 0;
}