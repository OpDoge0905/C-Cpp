#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> get_data(ifstream &file){

    vector<int> currentRow;
    string word;
    vector<vector<int> > matrix;

    while (file >> word) {
        if (word == ";"){
            	matrix.push_back(currentRow);
            	currentRow.clear();	
			}
        else if(word == "End_"){
            break;
        }
		else if(isdigit(word[0])){
				int num = stoi(word);
        		currentRow.push_back(num);  
			}

            
        }

}


void output_matrix(vector<vector<int> > &matrix){
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size() ; j++){
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }
}



int main() {
    
    
    // �}���ɮ�
    ifstream file("input01.txt");
    
    if (file.is_open()) {
        // �v��Ū���A�����ɮ׵���
        while (file >> word) {
            if (word == ";"){
            	matrix.push_back(currentRow);
            	currentRow.clear();
				
			}
			else if(isdigit(word[0])){
				int num = stoi(word);
        		currentRow.push_back(num);  
			}

            
        }
        
        
        file.close(); // �����ɮ�
    } else {
        cerr << "Can't open the file" << endl;
    }

    output_matrix(matrix);
	
    return 0;
}





/*#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// 1. 讀取一個矩陣的函數：只抓數字和分號
vector<vector<int>> get_matrix_data(ifstream &file) {
    vector<vector<int>> matrix;
    vector<int> currentRow;
    string word;

    while (file >> word) {
        // 看到分號：代表一列結束，把這列塞進大矩陣
        if (word == ";") {
            if (!currentRow.empty()) {
                matrix.push_back(currentRow);
                currentRow.clear();
            }
            // 關鍵：如果偷看下一個字是 'N' (代表 Name)，說明這個矩陣讀完了
            if (file.peek() == '\n' || file.peek() == ' ') {
                // 繼續讀，但下一圈會由 break 判斷
            }
        } 
        // 看到結束標籤：立刻跳出
        else if (word.find("End_") != string::npos) {
            break;
        }
        // 如果這個字的第一個字元是數字 (或者是負號)
        else if (isdigit(word[0]) || (word.size() > 1 && word[0] == '-')) {
            currentRow.push_back(stoi(word));
        }
        // 看到下一個矩陣的 Name：代表第一個矩陣結束了
        else if (word == "Name" && !matrix.empty()) {
            // 這裡要把 Name 吐回去，或者直接 break
            // 為了簡單，我們直接判斷如果矩陣已經有東西了，就代表該換下一個了
            break; 
        }
        // 其餘的文字 (如 Name, :, A1) 會直接被略過
    }
    return matrix;
}

// 2. 轉置運算
void matrix_transpose(vector<vector<int>> &A) {
    if (A.empty()) return;
    int rows = A.size();
    int cols = A[0].size();
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << A[i][j] << " ";
        }
        cout << ";" << endl;
    }
}

// 3. 相乘運算
void matrix_multiplication(vector<vector<int>> &A, vector<vector<int>> &B) {
    if (A.empty() || B.empty()) return;
    int r1 = A.size();
    int c1 = A[0].size();
    int c2 = B[0].size();
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < c1; k++) {
                sum += A[i][k] * B[k][j];
            }
            cout << sum << " ";
        }
        cout << ";" << endl;
    }
}

int main() {
    // 這裡請確保你的檔名跟資料夾裡的檔案一模一樣
    string fileName = "input01.txt"; 
    ifstream file(fileName);
    
    if (!file.is_open()) {
        cout << "Can't open file!" << endl;
        return 1;
    }

    string mode;
    file >> mode; // 讀取第一個單字 (關鍵字)

    if (mode == "Matrix_Transpose") {
        vector<vector<int>> A = get_matrix_data(file);
        cout << "Transpose Result:" << endl;
        matrix_transpose(A);
    } 
    else if (mode == "Matrix_Multiplication") {
        // 呼叫兩次，分別存入 A 和 B
        vector<vector<int>> A = get_matrix_data(file);
        vector<vector<int>> B = get_matrix_data(file);
        cout << "Multiplication Result:" << endl;
        matrix_multiplication(A, B);
    }

    file.close();
    return 0;
}
*/