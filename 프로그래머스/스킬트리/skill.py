def solution(skill, skill_trees):
    answer = 0
    for s in skill_trees :
        check = True
        index =0
        for i in range(len(skill)):
            tempindex = s.find(skill[i])
            if  tempindex != -1 and index != -1 :
                if index > tempindex :
                    check = False
                    break
            elif tempindex != -1 and index == -1 :
                check = False
                break
            index = tempindex
        if check == True:
            answer +=1
    return answer
if __name__ == "__main__" :
    s = "CBD"
    st = ["BACDE", "CBADF", "AECB", "BDA"]
    a = solution(s,st)