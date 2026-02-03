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
    vector<Data> leftPart, rightPart;
    // 將資料複製到暫存陣列
    for (int i = left; i <= mid; i++) leftPart.push_back(list[i]);
    for (int i = mid + 1; i <= right; i++) rightPart.push_back(list[i]);

    int i = 0, j = 0, k = left;

    // 比較並合併
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

    // 處理剩餘資料
    while (i < leftPart.size()) { list[k] = leftPart[i]; i++; k++; }
    while (j < rightPart.size()) { list[k] = rightPart[j]; j++; k++; }
}

void mergeSort(vector<Data>& list, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}

// === 第三部分：二元搜尋零件 (Binary Search) ===
int binarySearch(const vector<Data>& list, int target) {
    int low = 0;
    int high = list.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (list[mid].value == target) {
            return mid; // 找到目標，回傳索引
        } else if (list[mid].value < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // 沒找到回傳 -1
}

// === 第四部分：主程式 ===
int main() {
    string fileNames[] = {"Input1.txt", "Input2.txt", "Input3.txt", "Input4.txt"};

    // 作業要求：先輸入要找的數字
    int targetValue;
    cout << "Cin >> ";
    cin >> targetValue;

    for (string fileName : fileNames) {
        vector<Data> dataList;
        
        // 讀取檔案
        ifstream ifs(fileName); 
        if (!ifs.is_open()) {
            cout << "Failed to open file: " << fileName << endl;
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

        // 進行排序
        if (!dataList.empty()) {
            cout << "Sorting " << fileName << "..." << endl;
            mergeSort(dataList, 0, dataList.size() - 1);
        }

        // --- 處理輸出檔案 ---
        // 自動生成檔名，例如 Input1.txt -> Input1_result.txt
        string outName = fileName.substr(0, fileName.find(".")) + "_result.txt";
        ofstream ofs(outName);

        if (ofs.is_open()) {
            // 執行二元搜尋
            int foundIndex = binarySearch(dataList, targetValue);

            // 寫入搜尋結果（依照作業格式標記 AXXX）
            if (foundIndex != -1) {
                ofs << "Find " << dataList[foundIndex].name << " " << dataList[foundIndex].value << endl;
                cout << fileName << ": Find " << dataList[foundIndex].name << " " << dataList[foundIndex].value << endl;
            } else {
                ofs << "Cannot Find " << targetValue << endl;
                cout << fileName << ": Cannot Find " << targetValue << endl;
            }

            // 寫入排序後的完整清單 (Part A 要求)
            ofs << endl; 
            for (int i = 0; i < dataList.size(); i++) {
                ofs << dataList[i].name << " " << dataList[i].value << endl;
            }
            ofs.close();
        }

        cout << "End of: " << fileName << " (Records: " << dataList.size() << ")" << endl;
        cout << "-----------------------------------" << endl;
    }

    return 0;
}