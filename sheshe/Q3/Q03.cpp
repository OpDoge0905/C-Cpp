/*#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>
#include <algorithm> 
#include <sstream>
using namespace std;

/*1.int main裡面先讀檔，想辦法把string跟int分開
2.call function去找指定的數字，三個function都跑，如果找不到就去讀另外一個function
(思考點:要如何這個funtion找不到跳去下一個)
3.找到後在找到的function裡面排列出來
4.在main裡面call output function
5.在output裡面印出來


int main(){
    int inputnum;
    //cout << "Cin>>";
    //cin >> inputnum;

    string fileName[] = {"Input1.txt", "Input2.txt", "Input3.txt", "Input4.txt"};
    for(string filename : fileName){

    vector<int> currentRow;
    vector<string> names;
    vector<int> numbers;
    string mode, word, name;

    ifstream file(filename);

    if(!file.is_open()){
        cerr << "could not open the file" << filename << endl;
    }

    else if (file.is_open()) {
        file >> mode;
        string name;
        while (file >> name){
            cout << name << "\n";
            names.push_back(name);
        }
        file.close();
    }

    cout << endl;
   

}

return 0;
}
*/
/*#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void find_nums(ifstream &ifs, vector<string> &names, vector<int> &scores);
//void transMat(ifstream &file, vector<vector<int>> &matrix, vector<int> &currentRow);  上一題的
int main() {
    string fileNames[] = {"Input1.txt", "Input2.txt", "Input3.txt", "Input4.txt"};

    for (string fileName : fileNames) {

        vector<string> names;
        ifstream ifs("Input1.txt", std::ios::in);
        if (!ifs.is_open()) {
            cout << "Failed to open file.\n";
            return 1; 
        }
        else{
        string word;
        vector<vector<int>> matrix1;
        vector<int> currentrow;
        vector<string> currentrow2;
        while (ifs >> word) {
            if (isdigit(word[0])){
            int num = stoi(word);
            currentrow.push_back(num);
            currentrow.clear();
        }
            else if(!isdigit(word[0])){
                string word1 = word;
                currentrow2.push_back(word1);
                currentrow2.clear();
            }
        

           // string word;
            //ifs >> word;
            //cout << name <<  "\n";
            //names.push_back(name);

            
        }
    }
        ifs.close();
        cout << "End of:" << fileNames << endl;
        cout << endl;
    }

    return 0;
}

void find_nums(ifstream &ifs, vector<string> &names, vector<int> &scores){
    
}
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Data{
    string name;
    int value;    
};

void find_nums(ifstream &ifs, vector<string> &names);
//void transMat(ifstream &file, vector<vector<int>> &matrix, vector<int> &currentRow);  上一題的
int main() {
    string fileNames[] = {"Input1.txt"/*, "Input2.txt", "Input3.txt", "Input4.txt"*/};
    string inputnum;
    cout << "Cin >> ";
    cin >> inputnum;

    for (string fileName : fileNames) {
        vector<Data> names;
        //vector<int> scores;
        ifstream ifs("Input1.txt", std::ios::in);
        if (!ifs.is_open()) {
            cout << "Failed to open file.\n";
            return 1; 
        }

        string line;
        string name;

        while(getline(ifs,line)){
            stringstream ss(line);
            string n;
            int v;
            while(ss >> n >> v){
                struct Data data;
                data.name = n;
                data.value = v;
                names.push_back(data);
            }
            
        }    
        cout << "End of:" << fileNames << endl;
        cout << endl;
    }

    return 0;
}

