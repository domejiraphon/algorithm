/*
1105. Filling Bookcase Shelves
You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.
*/
class Solution {
  int n;
  int width;
  vector<vector<int>> b;
  int memo[1001][1001];
public:
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    n = books.size();
    width = shelfWidth;
    b = books;
    memset(memo, -1, sizeof(memo));
    return helper(0, 0, 0);
  }
private:
  int nextHeight(int i, int h, int w) {
    if (i == n)
      return h;
    if (memo[i][w] != -1)
      return memo[i][w];
    int cur = h + nextHeight(i + 1, b[i][1], b[i][0]);
    if (b[i][0] <= width - w){
      cur = min(cur, nextHeight(i + 1, max(h, b[i][1]), w + b[i][0]));
    }
    //return cur;
    return memo[i][w] = cur;
  }
};