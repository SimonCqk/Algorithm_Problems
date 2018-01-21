/*
地上有一个m行n列的方格。一个机器人从坐标(0,0)的格子开始移动，它可以每次向左，右，上，下
移动一格，但不能进入行坐标和列坐标的数位之和大于k的格子。
例如 k=18;
能够进入(35,37)但是不能进入(35,38)
*/

int GetDigitSum(int num){
    int sum = 0;
    while(num){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool  Check(const int& threshold,const int& rows,const int& cols,
            const int& row,const int& col,vector<vector<bool>>& visited){
    if(row>=0&&row<rows&&col>=0&&col<=cols&&GetDigitSum(row)+GetDigitSum(col)<=threshold&&!visited[row][col])
        return true;
    return false;
}

int MovingCountCore(const int& threshold,const int& rows,const int& cols,
            const int& row,const int& col,vector<vector<bool>>& visited){
    int count = 0;
    if(Check(threshold,rows,cols,row,col,visited)){
        visited[row][col] = true;
        count = 1 + MovingCountCore(threshold, rows, cols, row-1, col, visited) 
        + MovingCountCore(threshold, rows, cols, row, col-1, visited)
         + MovingCountCore(threshold, rows, cols, row+1, col, visited)
          + MovingCountCore(threshold, rows, cols, row, col+1, visited);
    }
    return count;
}

int MovingCount(const int& threshold,const int& rows,const int& cols){
    if(threshold<0||rows<0||cols<0)
        return 0;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int 
}