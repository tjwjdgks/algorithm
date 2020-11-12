def solution(answers):
    answer = []
    numarr = [0,0,0]
    studuentarr = [[1,2,3,4,5],
                   [2,1,2,3,2,4,2,5],
                   [3,3,1,1,2,2,4,4,5,5]]
    for i in range(len(answers)):
        for j in range(3):
            rest = i%len(studuentarr[j])
            if answers[i] == studuentarr[j][rest] :
                numarr[j] +=1
    maxval = max(numarr)
    for i in range(3):
        if numarr[i] == maxval :
            answer.append(i+1)
    return answer
if __name__ == "__main__" :
    b = [2,1,3,4,1]
    a = solution(b)