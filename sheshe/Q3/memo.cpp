// void quickSortName(vector<Data> &arr, int start, int end){
//     // base case
//     if (start >= end)
//     {
//         return;
//     }
        
//     // partitioning the array
//     int p = partition(arr, start, end);
 
//     // Sorting the left part
//     quickSortName(arr, start, p - 1);
 
//     // Sorting the right part
//     quickSortName(arr, p + 1, end);

// }


// if(dataList[targetArr.index].value == dataList[targetArr.index-1].value && targetArr.index-1 >= 0){
    //     Data frontVec = {dataList[targetArr.index-1].name, dataList[targetArr.index-1].value, targetArr.index-1};
    //     searchSame(frontVec, dataList);
    //     sameValArr.push_back(dataList[targetArr.index-1]);
    // }
    // else{
    //     return {"", 0, 0};
    // }
    // if(dataList[targetArr.index].value == dataList[targetArr.index+1].value && targetArr.index+1 < dataList.size()){
    //     Data backVec = {dataList[targetArr.index+1].name, dataList[targetArr.index+1].value, targetArr.index+1};
    //     searchSame(backVec, dataList);
    //     sameValArr.push_back(dataList[targetArr.index+1]);
    // }
    // else{
    //     return;
    // }
    // return sameValArr;

    int partition(vector<Data> &arr, int start, int end) {
    int pivotVal = arr[end].value; // 影片中是選最後一個當基準
    string pivotName = arr[end].name;
    
    int i = start; // 這是橘色旗子 (小於區域的邊界)

    // 巡邏員 j 從頭掃到尾 (不含基準點本身)
    for (int j = start; j < end; j++) {
        // 如果發現小的 (雙重排序邏輯)
        if (arr[j].value < pivotVal || (arr[j].value == pivotVal && arr[j].name < pivotName)) {
            // 交換 arr[i] 和 arr[j] (手動交換邏輯)
            Data temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; // 旗子往後移
        }
    }

    // 最後把基準點換到旗子的位置
    Data tempPivot = arr[i];
    arr[i] = arr[end];
    arr[end] = tempPivot;

    return i; // i 就是 pivotIndex
}