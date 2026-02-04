#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ostream>
#include <filesystem>

using namespace std;

struct Data{
    string name;
    int value;   
};

int partition(vector<Data> &arr, int start, int end)
{
    int pivot = arr[start].value;
    int count = 0;
    for (int i = start + 1; i <= end; i++){
        if (arr[i].value <= pivot)
            count++;
    }
    
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex){
 
        while (arr[i].value <= pivot) {
            i++;
        }
 
        while (arr[j].value > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

void quickSort(vector<Data> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
        
    int p = partition(arr, start, end);
 
    quickSort(arr, start, p - 1);
 
    quickSort(arr, p + 1, end);
}

vector<Data> binary_search(vector<Data> &arr, int key) {    
    int firstIdx = -1;
    int lastIdx = -1;
    vector<Data> sameValArr;

    //Find firstIdx
    int low = 0;
    int high = arr.size()-1;
    while (low <= high) {
        int mid = int((low + high) / 2);
        if (arr[mid].value>=key){
            if(arr[mid].value == key){
                firstIdx = mid;
            }
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    if(firstIdx == -1){
        return {};
    }

    //Find lastIdx
    low = 0;
    high = arr.size()-1;
    while (low <= high) {
        int mid = int((low + high) / 2);
        if(arr[mid].value<=key){
            if(arr[mid].value == key){
                lastIdx = mid;
            }
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    if(firstIdx == -1 && lastIdx == -1){
        return {};
    }

    for(int i = firstIdx; i<=lastIdx; i++){
        sameValArr.push_back(arr[i]);
    }
    return sameValArr;
}

int main() {
   
    string fileNames[] = {"Input1.txt", "Input2.txt", "Input3.txt", "Input4.txt"};
    string resultFiles[] = {"test1_result.txt", "test2_result.txt", "test3_result.txt", "test4_result.txt"};
    string folderPath;
    int targetNum;

    cout << "Destination Folder Location: ";
    
    getline(cin >> ws, folderPath);

    int targetNum;  
    cout << "Cin >> ";
    while(!(cin >> targetNum)){
        cout << "ERROR! Number Only! \n Cin >> ";
        cin.clear();
        cin.ignore('\n');
    }

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

        if (!dataList.empty()) {
            quickSort(dataList, 0, dataList.size() - 1);

            ofstream ofs;
            ofs.open(resultFiles[i]);

            if (!ofs.is_open()) {
                cout << "Failed to open file.\n";
                return 1;
            }

            vector<Data> sameTarget = binary_search(dataList, targetNum);
            if(sameTarget.empty()){
                ofs << "Cannoot Find " << targetNum << endl << endl;
                for(int i=0; i<dataList.size(); i++){
                    ofs << dataList[i].name << " " << dataList[i].value << endl;
                }
            }
            else{
                int sameQuantity = sameTarget.size();
                for(int i=0 ; i<sameQuantity; i++){
                    ofs << "Find " << sameTarget[i].name << " " << sameTarget[i].value << endl;
                }
                ofs << endl;

                for(int i=0; i<dataList.size(); i++){
                    ofs << dataList[i].name << " " << dataList[i].value << endl;
                }
            }
        }
    }
    return 0;
}