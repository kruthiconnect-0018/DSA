class Solution:
    def solveSudoku(self, board):

        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        # Store existing numbers
        for r in range(9):
            for c in range(9):

                if board[r][c] != '.':
                    num = board[r][c]
                    box = (r // 3) * 3 + (c // 3)

                    rows[r].add(num)
                    cols[c].add(num)
                    boxes[box].add(num)

        def solve():

            # Find the empty cell with the fewest choices
            best_row = -1
            best_col = -1
            best_options = None

            for r in range(9):
                for c in range(9):

                    if board[r][c] == '.':

                        box = (r // 3) * 3 + (c // 3)

                        options = []

                        for num in "123456789":

                            if (num not in rows[r] and
                                num not in cols[c] and
                                num not in boxes[box]):

                                options.append(num)

                        # No possible number
                        if len(options) == 0:
                            return False

                        # Choose the cell with minimum options
                        if (best_options is None or
                            len(options) < len(best_options)):

                            best_row = r
                            best_col = c
                            best_options = options

                            # Can't do better than one option
                            if len(options) == 1:
                                break

                if best_options is not None and len(best_options) == 1:
                    break

            # No empty cells
            if best_options is None:
                return True

            r = best_row
            c = best_col
            box = (r // 3) * 3 + (c // 3)

            # Try each possible number
            for num in best_options:

                board[r][c] = num

                rows[r].add(num)
                cols[c].add(num)
                boxes[box].add(num)

                if solve():
                    return True

                # Undo
                board[r][c] = '.'

                rows[r].remove(num)
                cols[c].remove(num)
                boxes[box].remove(num)

            return False

        solve()