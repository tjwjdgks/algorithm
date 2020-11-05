def solution(n):
    f,l = 0,1
    for i in range(n):
        f,l = l,f+l
    return f
if __name__ == "__main__" :
    b = [2,1,3,4,1]
    a = solution(b)