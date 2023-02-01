/*
353. Design Snake Game
Design a Snake game that is played on a device with screen size height x width. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.

You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1.

Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.

When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies after moving (i.e. a snake of length 4 cannot run into itself).

Implement the SnakeGame class:

SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width and the positions of the food.
int move(String direction) Returns the score of the game after applying one direction move by the snake. If the game is over, return -1.
*/
class SnakeGame {
  deque<pair<int, int>> snakePos;
  queue<vector<int>> Food;
  int WIDTH;
  int HEIGHT;
public:
  SnakeGame(int width, int height, vector<vector<int>>& food) {
    snakePos.push_front({0, 0});
    WIDTH = width;
    HEIGHT = height;
    for (int i=0; i<food.size(); i++)
      Food.push(food[i]);
    
  }
  
  int move(string direction) {
    pair<int, int> head = snakePos.front();
    int i = head.first;
    int j = head.second;
    if (direction == "L")
      i--;
    else if (direction == "R")
      i++;
    else if (direction == "U")
      j--;
    else if (direction == "D")
      j++;
    
    
    if (i < 0 || i >= WIDTH || j < 0 ||j >= HEIGHT)
      return -1;

    if (Food.size() > 0 && Food.front()[0] == j && Food.front()[1] == i){
      Food.pop();
    }
    else {
      snakePos.pop_back();
    }
    

    for (auto it=snakePos.begin(); it != snakePos.end(); it++){
      pair<int, int> cur = *it;
      if (cur.first ==i && cur.second ==j)
        return -1;
    }
    
    snakePos.push_front({i, j});
    return snakePos.size() - 1;
  }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
