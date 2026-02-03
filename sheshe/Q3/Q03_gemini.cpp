#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// === 第一部分：資料結構定義 ===
struct Data {
    string name;
    int value;    
};

// === 第二部分：手寫排序零件 (Merge Sort) ===

// 負責「合併」兩疊已經排好序的資料
void merge(vector<Data>& list, int left, int mid, int right) {
    // 建立暫存的左、右陣列
    vector<Data> leftPart, rightPart;
    for (int i = left; i <= mid; i++) leftPart.push_back(list[i]);
    for (int i = mid + 1; i <= right; i++) rightPart.push_back(list[i]);

    int i = 0; // 左邊的指標
    int j = 0; // 右邊的指標
    int k = left; // 原本 list 的填入位置

    while (i < leftPart.size() && j < rightPart.size()) {
        if (leftPart[i].value <= rightPart[j].value) {
            list[k] = leftPart[i];
            i++;
        } else {
            list[k] = rightPart[j];
            j++;
        }
        k++;
    }

    // 處理剩餘沒放完的資料
    while (i < leftPart.size()) { list[k] = leftPart[i]; i++; k++; }
    while (j < rightPart.size()) { list[k] = rightPart[j]; j++; k++; }
}

// 負責「切分」陣列的遞迴函數
void mergeSort(vector<Data>& list, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(list, left, mid);      // 處理左半邊
        mergeSort(list, mid + 1, right); // 處理右半邊
        merge(list, left, mid, right);   // 合併起來
    }
}

// === 第三部分：主程式 ===
int main() {
    // 設定要處理的檔案清單
    string fileNames[] = {"Input1.txt", "Input2.txt", "Input3.txt", "Input4.txt"};
    
    int targetValue;
    cout << "Cin >> ";
    cin >> targetValue;

    for (string fileName : fileNames) {
        vector<Data> names;
        
        // 修正 1：動態開啟目前迴圈指到的檔案
        ifstream ifs(fileName); 
        if (!ifs.is_open()) {
            cout << "Failed to open file: " << fileName << endl;
            continue;
        }

        // 讀檔邏輯
        string line;
        while (getline(ifs, line)) {
            stringstream ss(line);
            string n;
            int v;
            while (ss >> n >> v) {
                Data temp;
                temp.name = n;
                temp.value = v;
                names.push_back(temp);
            }
        }
        ifs.close();

        // 修正 2：在讀完檔後，立即進行排序
        if (!names.empty()) {
            cout << "Sorting " << fileName << "..." << endl;
            mergeSort(names, 0, names.size() - 1);
            cout << "Sort completed." << endl;
        }

        // --- 這裡接下來要放 Part B: 二元搜尋 (Binary Search) ---
        // 你可以先用迴圈印出前兩筆，檢查排序是否正確
        if(!names.empty()){
            cout << "Check First Data: " << names[0].name << " " << names[0].value << endl;
        }

        // 修正 3：正確顯示目前檔案處理結束訊息
        cout << "End of: " << fileName << " (Records: " << names.size() << ")" << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}