class Solution:
    def solveNQueens(self, n):
        result = []

        board = []
        for i in range(n):
            board.append(["."] * n)

        columns = set()
        diagonal1 = set()
        diagonal2 = set()

        def backtrack(row):
            # All queens have been placed
            if row == n:
                solution = []

                for r in board:
                    solution.append("".join(r))

                result.append(solution)
                return

            # Try every column in this row
            for col in range(n):

                # Check column
                if col in columns:
                    continue

                # Check diagonal \
                if row - col in diagonal1:
                    continue

                # Check diagonal /
                if row + col in diagonal2:
                    continue

                # Place queen
                board[row][col] = "Q"
                columns.add(col)
                diagonal1.add(row - col)
                diagonal2.add(row + col)

                # Move to next row
                backtrack(row + 1)

                # Remove queen / undo
                board[row][col] = "."
                columns.remove(col)
                diagonal1.remove(row - col)
                diagonal2.remove(row + col)

        backtrack(0)

        return result