def group_word_checker(num: int) -> int:
    cnt: int = 0
    for _ in range(num):
        status: bool = True
        word: str = input()
        exist: set = set()
        for idx, char in enumerate(word):
            if (char in exist) and (word[idx - 1] != char):
                status = False
                break
            exist.add(char)
        if status:
            cnt += 1
    return cnt

num: int = int(input())
print(group_word_checker(num))
