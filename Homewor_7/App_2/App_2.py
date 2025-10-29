def diff_set(A, B):
    C = set()
    for i in B:
        flg = True
        for j in A:
            if (i == j) or (i >= 0):
                flg = False
        if flg: C.add(i)
    print(C)


A, B = set(), set()

N = int(input("Кол-во элементов A: "))
print("Элементы B: ")
for i in range(N):
    A.add(int(input()))

N = int(input("Кол-во элементов B: "))
print("Элементы B: ")
for i in range(N):
    B.add(int(input()))

diff_set(A, B)