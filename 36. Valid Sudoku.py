class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
    
        n: int = len(board) # fixed height
        m: int = len(board[0]) # fixed width

        flag: bool = True

        #creating a list of sets
        mp_rows: List[set[str]] = [set() for _ in range(n)]
        box_set: List[set[str]] = [set() for _ in range(9)]

        for i in range(n):
            col_set: set[str] = set()
            for j in range(m):
                if "." == board[i][j]:
                    continue

                if board[i][j] in col_set or board[i][j] in mp_rows[j]:
                    return False

                col_set.add(board[i][j])
                mp_rows[j].add(board[i][j])

                #calculating the box # for this element
                ind: int = 3*(i//3) + (j // 3)
                if board[i][j] in box_set[ind%9]:
                    return False
                
                box_set[ind].add(board[i][j])
        
        return True
