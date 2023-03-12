class Pente:
    def __init__(self):
        # Initialize board with empty cells
        self.board = [['.' for _ in range(19)] for _ in range(19)]
        
        # Initialize player X as the starting player
        self.current_player = 'X'
        
        # Initialize scores for both players
        self.scores = {'X': 0, 'O': 0}
        
        # Initialize capture count for current player
        self.capture_count = 0
        
        # Initialize game status
        self.game_over = False
        self.winner = None
        
    def play(self):
        while not self.game_over:
            # Print current board state
            self.print_board()
            
            # Prompt current player for move
            row, col = map(int, input(f"Player {self.current_player}, enter your move (row, col): ").split())
            
            # Check if chosen cell is occupied
            if self.board[row][col] != '.':
                print("That cell is already occupied. Choose another.")
                continue
            
            # Place player's stone in chosen cell
            self.board[row][col] = self.current_player
            
            # Check for win condition
            if self.check_win():
                self.game_over = True
                self.winner = self.current_player
                break
            
            # Check for capture condition
            self.capture_count = self.check_capture(row, col)
            if self.capture_count > 0:
                self.scores[self.current_player] += self.capture_count
                self.remove_captured_stones()
            
            # Switch players
            if self.current_player == 'X':
                self.current_player = 'O'
            else:
                self.current_player = 'X'
            
            # Check for tie condition
            if all('.' not in row for row in self.board):
                print("Tie game!")
                self.game_over = True
                break
        
        # Print final board state and winner (if any)
        self.print_board()
        if self.winner:
            print(f"Player {self.winner} wins!")
        else:
            print("Game over.")
    
    def print_board(self):
        # Print column labels
        print('  ', end='')
        for i in range(19):
            print(chr(i+65), end=' ')
        print()
        
        # Print row labels and cells
        for i, row in enumerate(self.board):
            print(i, end=' ')
            for cell in row:
                print(cell, end=' ')
            print()
    
    def check_win(self):
        # Check for horizontal win
        for row in self.board:
            if self.current_player * 5 in ''.join(row):
                return True
        
        # Check for vertical win
        for col in range(19):
            if self.current_player * 5 in ''.join(row[col] for row in self.board):
                return True
        
        # Check for diagonal win (top-left to bottom-right)
        for i in range(15):
            for j in range(15):
                if self.current_player * 5 in ''.join(self.board[i+k][j+k] for k in range(5)):
                    return True
        
        # Check for diagonal win (bottom-left to top-right)
        for i in range(4, 19):
            for j in range(15):
                if self.current_player * 5 in ''.join(self.board[i-k][j+k] for k in range(5)):
                    return True
        
        return False
    
    def check_capture(self, row, col):
        count = 0
        
        # Check up direction
        if row > 1 and self.board[row-1][col] != '.' and self.board[row-2][col] == self.board[row-1][col] == self.current_player:
            count += 2
        if row > 0 and row < 17 and self.board[row-1][col] != '.' and self.board[row+1][col] == self.board[row-1][col] == self.current_player:
            count += 2
        if row < 16 and self.board[row+1][col] != '.' and self.board[row+2][col] == self.board[row+1][col] == self.current_player:
            count += 2
        
        # Check left direction
        if col > 1 and self.board[row][col-1] != '.' and self.board[row][col-2] == self.board[row][col-1] == self.current_player:
            count += 2
        if col > 0 and col < 17 and self.board[row][col-1] != '.' and self.board[row][col+1] == self.board[row][col-1] == self.current_player:
            count += 2
        if col < 16 and self.board[row][col+1] != '.' and self.board[row][col+2] == self.board[row][col+1] == self.current_player:
            count += 2
        
        # Check up-left direction
        if row > 1 and col > 1 and self.board[row-1][col-1] != '.' and self.board[row-2][col-2] == self.board[row-1][col-1] == self.current_player:
            count += 2
        if row > 0 and row < 17 and col > 0 and col < 17 and self.board[row-1][col-1] != '.' and self.board[row+1][col+1] == self.board[row-1][col-1] == self.current_player:
            count += 2
        if row < 16 and col < 16 and self.board[row+1][col+1] != '.' and self.board[row+2][col+2] == self.board[row+1][col+1] == self.current_player:
            count += 2
        
        # Check up-right direction
        if row > 1 and col < 16 and self.board[row-1][col+1] != '.' and self.board[row-2][col+2] == self.board[row-1][col+1] == self.current_player:
            count += 2
        if row > 0 and row < 17 and col > 0 and col < 17 and self.board[row-1][col+1] != '.' and self.board[row+1][col-1] == self.board[row-1][col+1] == self.current_player:
            count += 2
        if row < 16 and col > 1 and self.board[row+1][col-1] != '.' and self.board[row+2][col-2] == self.board[row+1][col-1] == self.current_player:
            count += 2
        
        return count

    def remove_captured_stones(self):
        for i in range(19):
            for j in range(19):
                if self.board[i][j] != self.current_player and self.check_capture(i, j) > 0:
                    self.board[i][j] = '.'
def main():
  game = Pente()
  game.play()
if __name__ == '__main__':
  main()