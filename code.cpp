# c-
#include<iostream>
using namespace std;
const int n=9; // размер судоку (9x9)
bool row[n][n+1], col[n][n+1], square[n][n+1];

// проверка возможности поставить число на данную позицию
bool isValid(int r, int c, int val){
    int sq = (r/3)*3+c/3; // определение квадрата 3x3, в котором находится данная ячейка
    return !row[r][val] && !col[c][val] && !square[sq][val]; // возвращает true, если число можно поставить на данную позицию
}

// рекурсивный алгоритм для решения судоку
bool solve(int board[][n], int r, int c){
    if(r == n) return true; // если прошли все строки, значит судоку решено
    if(c == n) return solve(board, r+1, 0); // переходим на следующую строку
    if(board[r][c] != 0) return solve(board, r, c+1); // если ячейка уже заполнена, переходим к следующей

    for(int val=1; val<=9; val++){ // перебираем все возможные числа
        if(isValid(r,c,val)){
            board[r][c] = val;
            row[r][val] = col[c][val] = square[(r/3)*3+c/3][val] = true; // помечаем, что число уже использовалось
            if(solve(board, r, c+1)) return true; // если удалось решить судоку, возвращаем true
            board[r][c] = 0; // если не удалось решить, отменяем выбор числа
            row[r][val] = col[c][val] = square[(r/3)*3+c/3][val] = false; // помечаем, что число снова доступно
        }
    }

    return false; // если не удалось решить судоку
}

// функция для вывода судоку в консоль
void printSudoku(int board[][n]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int board[n][n] = {{0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
                       {0,0,0,0,0,0,0,0,0},
