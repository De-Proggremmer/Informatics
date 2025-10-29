# import Geometry
#
# a, b, c = 1, 1, 1
#
# print(Geometry.get_perimetr(a, b, c))
# print(Geometry.get_square(a, b, c))

def count_under(A, B, t):
    cntA, cntB = 0, 0
    for i in A:
        if i < t: cntA += 1
    for i in B:
        if i < t:cntB += 1

    if cntA > cntB: print(A); print(B)
    else: print(B), print(A)


A, B, t = [0]*5, [0]*5, 0

print("Введите элементы A: ")
for i in range(5):
    A[i] = int(input())
print("Введите элементы B: ")
for i in range(5):
    B[i] = int(input())
print("Введите t: ")
t = int(input())

count_under(A, B, t)




