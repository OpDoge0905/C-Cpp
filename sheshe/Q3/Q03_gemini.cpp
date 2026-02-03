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

// --- 快速排序法函數實作開始 ---

// 交換兩個 Data 結構的函數
void swapData(Data &a, Data &b) {
    Data temp = a;
    a = b;
    b = temp;
}

// 分割函數：選取基準點並移動元素
int partition(vector<Data> &arr, int low, int high) {
    int pivot = arr[high].value; // 選最後一個元素的數值作為基準
    int i = (low - 1); // 小於基準點區域的索引

    for (int j = low; j <= high - 1; j++) {
        // 如果目前元素的數值小於基準點
        if (arr[j].value < pivot) {
            i++;
            swapData(arr[i], arr[j]);
        }
    }
    swapData(arr[i + 1], arr[high]);
    return (i + 1);
}

// 快速排序遞迴函數
void quickSort(vector<Data> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 找出基準點的位置

        // 遞迴排序左半邊與右半邊
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// --- 快速排序法函數實作結束 ---

int main() {
    string fileNames[] = {"Input1.txt", "Input2.txt", "Input3.txt", "Input4.txt"};
    
    int targetNum;
    cout << "Cin >> ";
    cin >> targetNum;

    for (int i = 0; i < 4; i++) {
        string currentFile = fileNames[i];
        vector<Data> dataList;
        
        ifstream ifs(currentFile);
        if (!ifs.is_open()) {
            cout << "無法開啟檔案: " << currentFile << endl;
            continue;
        }

        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string n;
            int v;
            while (ss >> n >> v) {
                Data temp;
                temp.name = n;
                temp.value = v;
                dataList.push_back(temp);
            }
        }
        ifs.close();

        // --- 在這裡呼叫快速排序 ---
        if (!dataList.empty()) {
            quickSort(dataList, 0, dataList.size() - 1);
            cout << currentFile << " 排序完成！" << endl;
        }

        // 接下來你可以在這裡寫 Part B 的二元搜尋邏輯
    }

    return 0;
}