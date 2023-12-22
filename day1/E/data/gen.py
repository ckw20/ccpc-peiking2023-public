import numpy as np
import random 
import os

random.seed(88736)
np.random.seed(88736)

MAXN = 2000
CUR_TEST_CASE_ID = 0

def coin_flip(prob):
    return random.random() < prob

def output(list: (list, list)):
    global CUR_TEST_CASE_ID
    CUR_TEST_CASE_ID = CUR_TEST_CASE_ID + 1
    with open("%d.in" % CUR_TEST_CASE_ID, "w") as f:
        f.write("%d %d\n" % (len(list[0]), len(list[1])))
        for l in list:
            for ind, elem in enumerate(l):
                f.write("%d" % elem)
                f.write(' ' if ind != len(l) - 1 else '\n')
    os.system("std.exe < %d.in > %d.ans" % (CUR_TEST_CASE_ID, CUR_TEST_CASE_ID))
    print(str(CUR_TEST_CASE_ID) + " Finished")

output(([2],[3]))
output(([1],[1]))
output(([2],[2]))
output(([1],[2]))

def gen(lcs_len, val_range):
    vallist = list(np.random.choice(2000, val_range) + 1)
    # generate lcs
    res = ([],[])
    lcs_len = max(0, lcs_len + random.randint(-30, 30))
    for _ in range(lcs_len):
        val = random.choice(vallist)
        res[0].append(val if coin_flip(0.8) else 1)
        res[1].append(val if coin_flip(0.8) else 1)
    # generate equal pairs
    npair = random.randint(max(MAXN - lcs_len - 100 , 0) , MAXN - lcs_len)
    for _ in range(npair):
        val = random.choice(vallist)
        res[0].insert(random.randint(0, len(res[0])), val)
        res[1].insert(random.randint(0, len(res[1])), val)
    
    # generate random things
    for arr in res:
        nrandom = random.randint(0, MAXN - len(arr))
        for _ in range(nrandom):
            val = 1 if coin_flip(0.1) else random.randint(2, MAXN)
            arr.insert(random.randint(0, len(arr)), val)
    output(res)

for lcs_len in [0, 100, 500, 1500, 1900]:
    for val_range in [5, 30, 250, 1000]:
        gen(lcs_len, val_range)

def hackgreedy():
    lcs_len = MAXN // 4 * 3 + random.randint(0, 20)
    vallist = list(np.random.choice(2000, val_range) + 1)
    res = ([],[])
    for _ in range(lcs_len):
        val = random.choice(vallist)
        res[0].append(val if coin_flip(0.95) else 1)
        res[1].append(val if coin_flip(0.95) else 1)
    while len(res[0]) < MAXN:
        res[0].append(random.randint(1, MAXN))
    res = (res[0], [1 for _ in range((MAXN - len(res[1])) // 2)] + res[1])
    output(res)

hackgreedy()