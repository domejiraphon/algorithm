/*
957. Prison Cells After N Days
There are 8 prison cells in a row and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.

You are given an integer array cells where cells[i] == 1 if the ith cell is occupied and cells[i] == 0 if the ith cell is vacant, and you are given an integer n.

Return the state of the prison after n days (i.e., n such changes described above).
*/
class Solution {
public:
  vector<int> prisonAfterNDays(vector<int>& cells, int n) {
    n %= 14;
    if (n == 0)
      n = 14;
   
    vector<int> cur = cells;
    vector<int> next = cells;
    next[0] = 0, next[7] = 0;
    for (int i=0; i<n; i++){
      int right = 1;
      
      while (right < 7){
        if (cur[right - 1] == cur[right + 1])
          next[right] = 1;
        else
          next[right] = 0;
        right++;
      }
      
      cur = next;
      
    }
    return cur;
  }
void print(vector<int>& cur){
  for (int i=0; i<8; i++){
    cout << cur[i]<<", ";
  }
  cout <<endl;
}
};
