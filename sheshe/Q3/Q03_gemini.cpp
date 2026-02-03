#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Data {
    string name;
    int value;    
};

int main() {
    // 1. 這裡可以把註解拿掉，處理多個檔案
    string fileNames[] = {"Input1.txt", "Input2.txt", "Input3.txt", "Input4.txt"};
    
    int targetValue; // 改用 int，方便等等比大小
    cout << "Cin >> ";
    cin >> targetValue;

    for (string fileName : fileNames) {
        vector<Data> names; // 每個檔案存一份自己的 vector
        
        // BUG 修正：使用 fileName 變數而不是寫死 "Input1.txt"
        ifstream ifs(fileName); 
        
        if (!ifs.is_open()) {
            cout << "Failed to open file: " << fileName << endl;
            continue; // 跳過這個檔案，繼續下一個
        }

        string line;
        // 讀取檔案邏輯
        while (getline(ifs, line)) {
            stringstream ss(line);
            string n;
            int v;
            // 這裡會自動跳過空白，讀取一對 (名字 數值)
            while (ss >> n >> v) {
                Data temp;
                temp.name = n;
                temp.value = v;
                names.push_back(temp);
            }
        }
        ifs.close(); // 讀完關檔

        // --- 這裡之後要放排序 (Merge Sort) ---
        
        // --- 這裡之後要放搜尋 (Binary Search) ---

        // BUG 修正：把這行移到迴圈內，並修正變數名（去掉 s）
        cout << "End of: " << fileName << " (Total: " << names.size() << " records)" << endl;
        cout << "-----------------------------------" << endl;
        
    } // for 迴圈結束

    return 0;
}