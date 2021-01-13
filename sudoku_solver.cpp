#include<iostream>
#define n 9
#define Notused 0
using namespace std;

bool unusedloc(int box[n][n], int& r, int& c);
bool checknum(int box[n][n],int r, int c, int num);

bool sudokusolver(int box[n][n]){
    int row, col;
    if(!unusedloc(box,row,col))
        return true;
    for(int i=1;i<=9;i++)
    {
        if(checknum(box,row,col,i))
        {
            box[row][col] = i;
            if(sudokusolver(box))
                return true;
            box[row][col] = Notused;
        }
    }
    return false;
}

bool unusedloc(int box[n][n], int& r, int& c){
    for(r=0;r<n;r++)
        for(c=0;c<n;c++)
            if(box[r][c] == Notused)
                return true;
    return false;
}

bool checkinrow(int box[n][n], int r, int num){
    for(int i=0;i<n;i++)
        if(box[r][i] == num)
            return true;
    return false;
}

bool checkincol(int box[n][n], int c, int num){
    for(int i=0;i<n;i++)
        if(box[i][c] == num)
            return true;
    return false;
}

bool checkinbox(int box[n][n],int r, int c, int num){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(box[i+r][j+c] == num)
                return true;
    return false;
}

bool checknum(int box[n][n], int r, int c, int num){
    return !checkinrow(box,r,num)
            &&!checkincol(box,c,num)
            &&checkinbox(box,r - r%3,c - c%3,num)
            && box[r][c] == Notused;
}

void printSudoku(int box[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<box[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    int box[n][n] = {0};
    int i,j;
    char ch;
    cout<<"\nInput the SUDOKU\nInstructions:\nEnter numbers separated by whitespaces\nEnter '0' for empty places"<<endl;
        for(i=0;i<n;i++){
            cout<<"Fill row"<<i+1<<": ";
            for(j=0;j<n;j++)
                cin>>box[i][j];
        }
        cout<<"Entered SUDOKU: "<<endl;
        printSudoku(box);
            if(sudokusolver(box) == true)
                printSudoku(box);
            else    
                cout<<"No solution Found";
    return 0;
}