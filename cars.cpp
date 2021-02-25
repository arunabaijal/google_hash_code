#include <bits/stdc++.h> 
using namespace std; 
#include <fstream>
#include <string>
#include <cstdlib>


// class Car 
// { 
//     // Access specifier 
//     public: 


//     // Data Members 
//     int D;
//     int numCars;

  
//     // Member Functions() 
//     void ProcessInputFile() 
//     { 
       
//     } 
// }; 
  
int main() { 
    int D;
    int numCars;
    
    std::ifstream file("a.txt");
    std::string str; 

    std::getline(file, str);
    istringstream iss(str);
    int n;
    vector<int> v;
    while (iss >>n) {
        v.push_back(n);
    }
    // for (int i=0; i<v.size(); i++) {
    //     cout<< v[i]  << "\t";
    // }

    numCars = v[3];
    cout << "number of cars:"<< numCars << "\n";

    for (int i=0; i<v[2]; i++) {
        std::getline(file, str);
        // cout << str << "\n";
    }

    n = 0;
    
    unordered_map<int,vector<string>> car_paths;

    while (std::getline(file, str)) {
        istringstream iss(str);
        vector<string> paths;
        string word;
        for (auto x : str) { 
            if (x == ' ') 
            { 
                paths.push_back(word);
                word = ""; 
            } 
            else { 
                word = word + x; 
            } 
        paths.push_back(word);
        } 
        while (iss >>n) {
            car_paths[n] = paths;
        }
        paths = "";
    }
    for(auto x:car_paths) {
        cout << x.first << "\n";
        for(int i =0; i<x.second.size(); i++) {
            cout << x.second[i] << endl;
        }
    }
        

    

      
    // // Declare an object of class geeks 
    // Geeks obj1; 
  
    // // accessing data member 
    // obj1.geekname = "Abhi"; 
  
    // // accessing member function 
    // obj1.printname(); 
    return 0; 
} 