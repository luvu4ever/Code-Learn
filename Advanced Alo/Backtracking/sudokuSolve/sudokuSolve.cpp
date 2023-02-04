#include<bits/stdc++.h>

using namespace std;

int MATRIXSIZE = 9;

void printMatrix(vector<string> matrix){
    for(int i=0; i<MATRIXSIZE; i++){
        cout<<matrix[i]<<" "<<endl;
    }
    cout<<endl;
}

int checkBox(int x, int y, vector<string> matrix, vector<string> checker){
    for(int i=0; i<MATRIXSIZE; i++){
        if(matrix[x][y] == matrix[x][i] && y!=i) return 0;
        if(matrix[x][y] == matrix[i][y] && x!=i) return 0;
    }
    int srow = x/3 *3;
    int scolumn = y/3 *3;
    // s stands for square
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
            if(matrix[x][y] == matrix[srow + i][scolumn + j] && (x != (srow + i)) && y != (scolumn + j))
                return 0;
    }
    return 1;
}

void BackTrack(int x, int y, vector<string> &matrix, vector<string> checker, vector<string> &ans){
    printMatrix(matrix);
    // if(checker[x][y] != '0'){
    //         if(x == MATRIXSIZE-1 && y == MATRIXSIZE -1){
    //                 for(int i=0; i<MATRIXSIZE; i++){
    //                     for(int j=0; j<MATRIXSIZE; j++)
    //                         ans[i][j] = matrix[i][j];
    //                 }
    //                 return;
    //         }
    //         else{
    //             if(x < MATRIXSIZE-1) BackTrack(x+1, y, matrix, checker, ans);
    //             else
    //                 BackTrack(x, y+1, matrix, checker, ans);
    //         }
    // }
    for(int val=0; val<MATRIXSIZE; val++){
        matrix[x][y] = ('0' + val);
        cout<<x<<" "<<y<<matrix[x][y]<<" "<<val<<endl;
        //if(checkBox(x,y, matrix, checker)){
            if(x == MATRIXSIZE-1 && y == MATRIXSIZE -1){
                
                for(int i=0; i<MATRIXSIZE; i++){
                    for(int j=0; j<MATRIXSIZE; j++)
                    ans[i][j] = matrix[i][j];
                }
                return;
            }
            else{
                if(x < MATRIXSIZE-1) BackTrack(x+1, y, matrix, checker, ans);
                else
                    BackTrack(x, y+1, matrix, checker, ans);
            }
        //}
    }
}

vector<string> sudokuSolve(vector<string> matrix)
{
    vector<string> checker, ans;
    for(int i=0; i<MATRIXSIZE; i++){
        checker.push_back(matrix[i]);
    }
    printMatrix(checker);
    BackTrack(0,0, matrix, checker, ans);
    return ans;
}

int main(){
    freopen("sudokuSolve.inp", "r", stdin);
    freopen("sudokuSolve.out", "w", stdout);
    vector<string> arr;
    for(int i=0; i<MATRIXSIZE; i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    vector<string> ans = sudokuSolve(arr);
    printMatrix(ans);
    return 0;
}