from typing import List

class Pente:
  def __init__(self):
    self.gridSize = 19
    self.contiguous = 5
    self.grid = [["." for _ in range(self.gridSize)] for _ in range(self.gridSize)]
    self.__spaceLeft = self.gridSize * self.gridSize
    self.captures = {"X": 0, "O": 0}
    self.player = "O"
    self.opponent = "X"
  
  def play(self, sequence: List[List[int]]) -> chr:
    """
    play the game and return the result of the game
    """
    for (row, col) in sequence:
      #place a stone
      if self.grid[row][col] != ".":
        print("Cannot place a stone. The space is not free. Choose a new position")
        continue
      self.grid[row][col] = self.player

      #reduce the space left
      self.__spaceLeft -= 1
      
      #check for 5 contiguous stones
      if self.__fiveInRow(self.player * self.contiguous, row, col):
        self.printBoard()
        return self.player
      
      #capture stones
      self.__capture(row, col)

      #found winner
      if (self.captures[self.player] >= 10):
        self.printBoard()
        return self.player

      #check if there is space left to place a stone
      if self.__spaceLeft == 0:
        self.printBoard()
        return "T"

      #take turn
      self.opponent, self.player = self.player, self.opponent
    #print table
    self.printBoard()
    return "T"
    
    
  def __fiveInRow(self, pattern: str, row: int, col: int) -> bool:
    """
    check 5 stones in a row (vertical, horizontal, diagonal, antidiagonal)
      return true if there exist 5 contiguous stones
    """
    #check row
    limitL = min(col, self.gridSize)
    limitR = min(self.gridSize - col, self.gridSize)
    if pattern in "".join([self.grid[row][col+i] for i in range(-limitL, limitR)]):
      return True
    
    #check column
    limitL = min(row, self.gridSize)
    limitR = min(self.gridSize - row, self.gridSize)
    if pattern in "".join([self.grid[row+i][col] for i in range(-limitL, limitR)]):
      return True 
    
    #check diagonal 
    limitL = min(row, col, self.contiguous)
    limitR = min(self.gridSize - row, self.gridSize - col, self.contiguous)
    if pattern in "".join([self.grid[row+i][col+i] 
                           for i in range(-limitL, limitR)]):
      return True
    
    #check antidiagonal
    limitL = min(row, self.gridSize - col - 1, self.contiguous - 1)
    limitR = min(self.gridSize - row, col + 1, self.contiguous)
    if pattern in "".join([self.grid[row+i][col-i] 
                           for i in range(-limitL, limitR)]):
      return True 
    return False

  def __capture(self, row: int, col: int) -> None:
    """
    capture the stones based on the rules
    """
    dirs = [[0, -3], [-3, -3], [-3, 0], [-3, 3], [0, 3], [3, 3], [3, 0], [3, -3]]
    #check every 8 direction where a player can capture
    for dir in dirs:
      flankRow = row + dir[0]
      flankCol = col + dir[1]

      #if the pair stone is still in the grid and is already placed by a winner
      #we check whether a player can capture
      if (flankRow >= 0 and flankRow < self.gridSize and 
        flankCol >= 0 and flankRow < self.gridSize and
        self.grid[flankRow][flankCol] == self.player):
        
        if (self.grid[row + int(dir[0]/3)][col + int(dir[1]/3)] == self.opponent and
            self.grid[row + int(2 * dir[0]/3)][col + int(2 * dir[1]/3)] == self.opponent):
          
          #change the grid back to free space
          self.grid[row + int(dir[0]/3)][col + int(dir[1]/3)] = "."
          self.grid[row + int(2 * dir[0]/3)][col + int(2 * dir[1]/3)] = "."
          self.captures[self.player] += 2

          #get 2 more spaces back
          self.__spaceLeft += 2
        
  def printBoard(self) -> None:
    """
    print the board
    """
    #print each position of the grid
    for row in self.grid:
      for pos in row:
        print(pos, end= " ")
      print("")

def main():
  game = Pente()
  seq = [[2, 4], [3, 5], [3, 6], [4, 5], [5, 5], 
         [4, 6], [5, 7], [6, 7], [3, 5], [5, 9],
         [4, 6], [6, 8], [1, 3]]
  outcome = game.play(seq)
  print(f"The winner of the game is {outcome}")

if __name__ == '__main__':
  main()