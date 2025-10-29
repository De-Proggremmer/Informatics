def diff_set(A, B):
    C = set()	    
    C = B - A
    for i in C:
        if i >= 0:
	   C.remove(i)

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