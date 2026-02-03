#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <ostream>

using namespace std;
//void transMat(ifstream &file, vector<vector<int>> &matrix, vector<int> &currentRow)
//transMat(file, matrix, currentRow)

struct Data{
    string name;
    int value;   
};


int partition(vector<Data> &arr, int start, int end)
{
    int pivot = arr[start].value;//設置第一位為pivot
    int count = 0;
    for (int i = start + 1; i <= end; i++){
        if (arr[i].value <= pivot)
            count++;
    }
    
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex){
 
        while (arr[i].value<= pivot) {
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
    // base case
    if (start >= end)
    {
        return;
    }
        
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);

}

// TODO 難!!
// vector<Data> nameSort(vector<Data> &arr){
//     if(!arr.empty()){
//         return arr;
//     }

//     int maxVal = 0;
//     for(auto& d: arr){
//         if(d.value > maxVal){
//             maxVal = d.value;
//         }
//     }

//     vector<vector<Data>> organizedArr();
//     for(int i=0; i<arr.size(); i++){
//         organizedArr[arr[i].value].push_back(arr[i]);
//     }
    
// }

vector<Data> binary_search(vector<Data> &arr, int key) {
    int low = 0;
    int high = arr.size()-1;
    while (low <= high) {
        int mid = int((low + high) / 2);
        if (key == arr[mid].value){
            vector<Data> sameValArr;
            sameValArr.push_back(arr[mid]);
            int L = mid-1; 
            while (L>=0 && arr[mid].value == arr[L].value){
                sameValArr.push_back(arr[L]);
                L--;
            }
            int R = mid+1; 
            while (R<arr.size() && arr[mid].value == arr[R].value){
                sameValArr.push_back(arr[R]);
                R++;
            }
            return sameValArr;
        }
            //return {arr[mid].name, arr[mid].value, mid};
        else if (key > arr[mid].value)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return {};
}

// vector<Data> searchSame(Data &targetArr, const vector<Data> &dataList){
//     vector<Data> sameValArr;
//     sameValArr.push_back(dataList[targetArr.index]);
//     int L = targetArr.index-1; 
//     while (L>=0 && dataList[targetArr.index].value == dataList[L].value){
//         sameValArr.push_back(dataList[L]);
//         L--;
//     }
//     int R = targetArr.index+1; 
//     while (R<dataList.size() && dataList[targetArr.index].value == dataList[R].value){
//         sameValArr.push_back(dataList[R]);
//         R++;
//     }
//     return sameValArr;
// }

int main() {
   
    string fileNames[] = {"Input1.txt", "Input2.txt", "Input3.txt", "Input4.txt"};
    string resultFiles[] = {"test1_result.txt", "test2_result.txt", "test3_result.txt", "test4_result.txt"};
    
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

        if (!dataList.empty()) {
            quickSort(dataList, 0, dataList.size() - 1);
            // TODO
            //nameSort(dataList);

            ofstream ofs;
            ofs.open(resultFiles[i]);

            if (!ofs.is_open()) {
                cout << "Failed to open file.\n";
                    return 1; // EXIT_FAILURE
            }

            int mid = 0;
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

        

        //for(int i = 0; i < dataList.size(); i++){
          //  cout << dataList[i].name << " " << dataList[i].value << " " ;
        //}

    }
    return 0;
}
