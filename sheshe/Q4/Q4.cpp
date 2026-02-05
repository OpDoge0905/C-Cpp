#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct NodeData {
    string label;
    int x;
    int y;
};

int main() {
    vector<NodeData> nodeList; 
    string currentLine, segment;

    ifstream inputFile("text1.txt");
    
    if (!inputFile.is_open()) {
        return 1;
    }   

    while (getline(inputFile, currentLine)) {
        stringstream ss(currentLine); 
        NodeData entry;
        getline(ss, segment, '(');
        entry.label = segment;
        cout << "label\n";
        getline(ss, segment, ',');
        entry.x = stoi(segment);
        cout << "x\n";
        getline(ss, segment, ')');
        entry.y = stoi(segment);
        cout << "y\n";
        nodeList.push_back(entry);        

    }
    
    inputFile.close();
    return 0;
}