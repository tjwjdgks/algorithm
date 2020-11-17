def solution(board, moves):
    answer =0
    arr = []
    for i in moves:
        x = i-1;
        for y in range(len(board)):
            if board[y][x] != 0:
                if not (not arr) and board[y][x] == arr[-1]:
                    arr.pop()
                    answer+=2
                else :
                    arr.append(board[y][x])
                board[y][x] = 0
                break
    return answer
if __name__ == "__main__" :
    b = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
    m = [1,5,3,5,1,2,1,4]
    a= solution(b,m)
