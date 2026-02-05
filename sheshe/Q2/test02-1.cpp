#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>
#include <cctype>

using namespace std;

void transMat(ifstream &file, vector<vector<int>> &matrix, vector<int> &currentRow);
void multiMat(ifstream &file, vector<vector<int>> &matrix1, vector<int> &currentRow);
void outputMatrix(vector<vector<int>> &matrix);


int main() {
    string fileName;
    cout << "enter the filename:";
    //string fileNames[] = {"input01.txt", "input02.txt", "input03.txt", "input04.txt", "input05.txt", /*"input06.txt"*/};
    cin >> fileName;

    cout << "----- Result for " << fileName << " -----" << endl;
    vector<vector<int>> matrix;
    vector<int> currentRow;
    string mode;

    ifstream file(fileName);
    if (file.is_open()) {
        file >> mode;

        if(mode == "Matrix_Transpose") {
            transMat(file, matrix, currentRow);
        }
        else if(mode == "Matrix_Multiplication") {
            multiMat(file, matrix, currentRow);
        }  
        else{
            cerr << "Could not open " << fileName << endl;
        }

        file.close();
            
        if(mode != "Matrix_Inverse"){
            outputMatrix(matrix); 
        }
        else{
            cout << "Error Error!" << endl;
        }
        } 
       
        cout << endl;
    
    return 0;
}

void transMat(ifstream &file, vector<vector<int>> &matrix, vector<int> &currentRow)
{   
    string word;
    vector<vector<int>> matrixTemp;
    while (file >> word){
        if (isdigit(word[0])){
            int num = stoi(word);
            currentRow.push_back(num);
        }
        else if (word == ";"){
            matrixTemp.push_back(currentRow);
            currentRow.clear();
        }
        
    }
    for (int i = 0; i < matrixTemp[0].size(); i++){
        vector<int> newRow;
        for (int j = 0; j < matrixTemp.size(); j++){
            newRow.push_back(matrixTemp[j][i]);
        }
        matrix.push_back(newRow);
    }
}

void multiMat(ifstream &file, vector<vector<int>> &matrix, vector<int> &currentRow)
{
    string word;
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    int matrixSection = 0;
    while (file >> word){
        
        if (isdigit(word[0])){
            int num = stoi(word);
            currentRow.push_back(num);
        }
        else if(word == "Name"){
            matrixSection++;
        }
        else if (word == ";" && matrixSection == 1){
            matrix1.push_back(currentRow);
            currentRow.clear();
        }
        else if(word == ";" && matrixSection == 2){
            matrix2.push_back(currentRow);
            currentRow.clear();
        }
        
    }

    for (int i = 0; i < matrix1.size(); i++) {
        vector<int> resultRow;
        for (int j = 0; j < matrix2[0].size(); j++) {
            int sum = 0;
            for (int k = 0; k < matrix1[0].size(); k++) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            resultRow.push_back(sum);
        }
        matrix.push_back(resultRow);
    }
}

void outputMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
