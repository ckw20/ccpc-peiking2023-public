import numpy as np
import random 
import os

random.seed(88733)
np.random.seed(88733)

MAXN = 100000
CUR_TEST_CASE_ID = 0

def coin_flip(prob):
    return random.random() < prob

def output(list: list):
    random.shuffle(list)
    global CUR_TEST_CASE_ID
    CUR_TEST_CASE_ID = CUR_TEST_CASE_ID + 1
    with open("%d.in" % CUR_TEST_CASE_ID, "w") as f:
        f.write("%d\n" % len(list))
        for (x,y) in list:
            f.write("%d %d\n" % (x, y))
    os.system("std.exe < %d.in > %d.ans" % (CUR_TEST_CASE_ID, CUR_TEST_CASE_ID))
    print(str(CUR_TEST_CASE_ID) + " Finished")

for _ in range(6):
    output([(random.randint(0, 1000000000),random.randint(0, 1000000000)) for _ in range(2)])
    
for _ in range(3):
    output([(random.randint(0, 1000000000),random.randint(0, 1000000000)) for _ in range(3)])

def randomVallist(n):
    vallist = list(np.random.randint(0, 1000000000 - 2 * n, 2 * n))
    vallist.sort()
    for i in range(len(vallist)):
        vallist[i] += i
    return vallist

def randomMatching(n):
    all = [i for i in range(2 * n)]
    random.shuffle(all)
    return [(all[i], all[i + n]) for i in range(n)]

def pairMatching(n):
    return [(2 * i , 2 * i + 1) for i in range(n)]

def mintmaxMatching(n):
    large = [i for i in range(n , 2 * n)]
    random.shuffle(large)
    res = [(i, large[i]) for i in range(n)]
    if coin_flip(0.5):
        res[-1] = (res[-1][1], res[-1][0])
    return res

def maxtminMatching(n):
    large = [i for i in range(n , 2 * n)]
    random.shuffle(large)
    res = [(large[i] , i) for i in range(n)]
    if coin_flip(0.5):
        res[-1] = (res[-1][1], res[-1][0])
    return res

def randomminmaxMatching(n):
    large = [i for i in range(n , 2 * n)]
    if coin_flip(0.5):
        large[0], large[-1] = large[-1], large[0]
        del large[-1]
        random.shuffle(large)
        large.append(n)
    else:
        random.shuffle(large)
    return [(large[i] , i) if coin_flip(0.5) else (i, large[i]) for i in range(n)]

def genCase(matching_gen):
    n = random.randint(MAXN - 10000, MAXN)
    vallist = randomVallist(n)
    matching = matching_gen(n)
    for ind in range(n):
        x, y = matching[ind]
        matching[ind] = (vallist[x], vallist[y])
    output(matching)

genCase(randomMatching)
genCase(randomMatching)
genCase(randomMatching)
genCase(pairMatching)
genCase(pairMatching)
genCase(mintmaxMatching)
genCase(mintmaxMatching)
genCase(mintmaxMatching)
genCase(maxtminMatching)
genCase(maxtminMatching)
genCase(maxtminMatching)
genCase(randomminmaxMatching)
genCase(randomminmaxMatching)
genCase(randomminmaxMatching)
genCase(randomminmaxMatching)
