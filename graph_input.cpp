// 6 4 5 2 1000
// 2 0 rue-de-londres 1
// 0 1 rue-d-amsterdam 1
// 3 1 rue-d-athenes 1
// 2 3 rue-de-rome 2
// 1 2 rue-de-moscou 3
// 4 rue-de-londres rue-d-amsterdam rue-de-moscou rue-de-rome
// 3 rue-d-athenes rue-de-moscou rue-de-londres
#include<iostream>
#include<unordered_map>
#include <bits/stdc++.h> 
#include <fstream>
#include <string>
using namespace std;
#include <boost/algorithm/string.hpp>
using id = unsigned int; 
using weight = unsigned int;

// encodes child data: child id and associated edge weight 
// this is used only during initialization / graph formation 
struct child_data{
    weight edge_weight; 
    id child_id;
    child_data(id child_id, weight edge_weight){
        this->child_id = child_id; 
        this->edge_weight = edge_weight;
    }
    child_data() : child_id(0), edge_weight(0){}
};

// encodes the node id and the min distance value required to reach it
struct node_info{
    id node_id; 
    vector<string> incoming; 
    vector<string> outgoing;
    node_info(){}
    node_info(id node_id){
        this->node_id = node_id;
    }
};

class Graph{
public:
    Graph(){}
    using child_list = unordered_map<id, child_data>;
    void add_node(id start_id, id child_id, weight edge_weight);
    void add_node_info(id start_id, string street_name, bool incoming);
    void print();
    void print_node_info(); 
    child_list get_child_list(id start_id);
    unordered_map<id, node_info> node_info_graph; 
    // child_data get_child_data(id start_id, id child_id);
private: 
    unordered_map<id, child_list> graph; 
    
};
// Gives the children umap
Graph::child_list Graph::get_child_list(id start_id){
    if (graph.find(start_id) == graph.end())
        return {};
    return graph.at(start_id);
}

void Graph::print(){
    for (auto x : graph){
        cout << x.first << " -> ";
        for (auto y : x.second){
         cout << y.first << " ";
        }  
        cout << endl;
    }
    cout << endl;
}

void Graph::print_node_info(){
    for (auto x : node_info_graph){
        cout << x.first << endl;
        cout << "incoming ";
        for (auto y : x.second.incoming){
            cout << y << " ";
        }  
        cout << endl;
        cout << "outgoing ";
        for (auto y : x.second.outgoing){
            cout << y << " ";
        } 
        cout << endl;
    }
    cout << endl;
}

void Graph::add_node(id start_id, id child_id, weight edge_weight){
    if (graph.find(start_id) == graph.end())
        graph[start_id] = child_list();
    else{
        if (graph[start_id].find(child_id) != graph[start_id].end()){
            cerr << "Edge already exists from " << start_id << " to " << child_id << endl;
            return; 
        }
    }
    graph[start_id][child_id] = child_data(child_id, edge_weight);
}

void Graph::add_node_info(id start_id, string street_name, bool incoming){ 

    if (node_info_graph.find(start_id) == node_info_graph.end()){
        node_info temp(start_id);
        node_info_graph[start_id] = temp; 
    }
    if (incoming)
        node_info_graph[start_id].incoming.push_back(street_name);
    else 
        node_info_graph[start_id].outgoing.push_back(street_name);
}

int main(){
    std::ifstream file("/home/akanksha/Downloads/a.txt");
    std::string str; 
    std::getline(file, str);
    istringstream iss(str);
    int n;
    vector<int> v;
    while (iss >> n) {
        v.push_back(n);
    }

    int connections = v[2];
    // cout << connections << endl;
    Graph road_network;
    string file_input; 
    for (int i = 0; i < connections; ++i)
    {
        getline(file, file_input);
        // if (i == 0) continue;
        // cout << file_input << endl;
        std::vector<std::string> result; 
        std::istringstream iss(file_input); 
        for(std::string s; iss >> s; ) 
            result.push_back(s);
        id start_id = stoi(result[0]); 
        id end_id = stoi(result[1]); 
        string street_name = result[2];
        weight edge_wt = stoi(result[3]); 
        
        road_network.add_node(start_id, end_id, edge_wt); 
        road_network.add_node_info(start_id, street_name, 1); 
        road_network.add_node_info(end_id, street_name, 0); 
    }
    road_network.print();
    road_network.print_node_info(); 
    return 0; 
    // need 5!
    
}

