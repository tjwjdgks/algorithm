def solution(numbers):
    answers = set();
    for i in range(len(numbers)):
        for j in range(len(numbers)):
            if i==j : continue
            answers.add(numbers[i]+numbers[j])
    answer = list(answers)
    answer.sort()
    return answer

if __name__ == "__main__" :
    b = [2,1,3,4,1]
    a = solution(b)