def solution(phone_book):
    answer = True
    phone_book.sort()
    for i in range(len(phone_book)):
        for j in range(i+1,len(phone_book)):
            if(phone_book[i] in phone_book[j]):
                return False
    return answer
if __name__ == "__main__":
    arr=["119", "97674223", "1195524421"]
    a = solution(arr)
    print(a)