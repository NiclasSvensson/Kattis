import sys

fact_list = [1]

def factorial(n):
    try:
        return fact_list[n]
    except:
        while len(fact_list) < n + 1:
            fact_list.append(len(fact_list) * fact_list[-1])
        return fact_list[n]

def count_anagrams(word):
    dictonary = {}
    word = word.replace("\n", "")
    for char in word:
        if char not in dictonary:
            dictonary[char] = 1
        else:
            dictonary[char] += 1
    nominator = factorial(len(word))
    for char in dictonary:
        nominator = nominator // factorial(dictonary[char])
    return str(int(nominator))

def main():
    for word in sys.stdin:
        print(count_anagrams(word))

if __name__ == "__main__":
    main()