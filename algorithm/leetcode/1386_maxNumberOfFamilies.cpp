/* 1386. Cinema Seat Allocation
 *A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, in that case, the aisle split a four-person group in the middle, which means to have two people on each side.
 * 
 */

class Solution {
public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, vector<int>> seats;
    int m=reservedSeats.size();
    for (int i=0; i<m; i++)
      seats[reservedSeats[i][0]-1].push_back(reservedSeats[i][1]-1);

    int free= (n-seats.size())*2;
    for (auto it=seats.begin(); it != seats.end(); it++){
      bool left=true, mid=true, right=true;
      check(it -> second, left, mid, right);
      if (left && right)
        free += 2;
      else
        free += (left || right || mid);
    }
    return free;
  }
private:
  void check(vector<int> seatInRow, bool& left, bool& mid, bool& right){
    int n=seatInRow.size();
    for (int i=0; i<n; i++){
      if (seatInRow[i] >= 1&& seatInRow[i] <= 4)
        left=false;
      if (seatInRow[i] >= 3&& seatInRow[i] <= 6)
        mid=false;
      if (seatInRow[i] >= 5&& seatInRow[i] <= 8)
        right=false;
    }
  }
};