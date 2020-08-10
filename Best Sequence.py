from itertools import permutations


def rearrange(words, broken_combs, counter):
    word = "".join(words)
    for i in broken_combs:
        try:
            counter["".join(i)] += word.count("".join(i))
        except KeyError:
            counter["".join(i)] = word.count("".join(i))
    return counter


paragraph = input().split()
brokenKeys = input().split()
brokenCombinations = permutations(brokenKeys)
a = rearrange(paragraph, brokenCombinations, {})
ans = []
temp = -1
for i in a.keys():
    temp = max(temp, a[i])
for i in a.keys():
    print(i, a[i])
    if a[i] == temp:
        ans.append(i)
for i in sorted(ans):
    print(i)
