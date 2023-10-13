import random
import os
import datetime
import numpy as np

TASK_NUM = 1

N_LIMIT = Q_LIMIT = 300
M_LIMIT = 60000
K_LIMIT = 10
ATOZ = "abcdefghijklmnopqrstuvwxyz"

def log(string):
	print(string, flush = True)
	with open("gen.log", "a") as f:
		f.write(f"[{datetime.datetime.now()}] {string}\n")

def genUniform(n, q, m, k, alphabet = ATOZ, **extra_param):
	# rng = np.random.default_rng()

	s = []
	t = []
	for i in range(n):
		s.append("".join(random.choices(alphabet, k = m)))
	for i in range(q):
		t.append("".join(random.choices(alphabet, k = m)))
	return s, t

def genFlat(n, q, m, k, n_init = 1, alphabet = ATOZ, pmf = None, **extra_param):
	rng = np.random.default_rng()

	if pmf is None:
		if k == 1:
			raise NotImplementedError
		pmf = {k // 2 - 1: 0.1, k // 2: 0.8, k // 2 + 1: 0.1}
	
	init_pop = ["".join(random.choices(alphabet, k = m)) for _ in range(n_init)]
	def mutate():
		x = random.choice(init_pop)
		for i in range(random.choices(list(pmf.keys()), list(pmf.values()))[0]):
			j = rng.integers(m)
			x = x[:j] + random.choice(alphabet) + x[j + 1:]
		return x
	
	s = [mutate() for _ in range(n)]
	t = [mutate() for _ in range(q)]

	return s, t

def genSwap(n, q, m, k, n_init = 1, alphabet = ATOZ, n_commuter = None, **extra_param):
	rng = np.random.default_rng()

	if n_commuter is None:
		n_commuter = min(2 * k, m)
	
	pop = ["".join(random.choices(alphabet, k = m)) for _ in range(n_init)]
	commuter = rng.choice(m, size = n_commuter, replace = False)
	for i in range(n + q - n_init):
		x = pop[-n_init]

		l, r = rng.choice(commuter, 2, replace = False)
		if l > r:
			l, r = r, l

		pop.append(x[:l] + x[r] + x[l + 1 : r] + x[l] + x[r + 1:])
	
	rng.shuffle(pop)

	return pop[:n], pop[n:]

def genTestcase(filename, n, q, m, k, gen, **extra_param):
	log(f"Generating input for case {filename}, params: {n = }, {q = }, {m = }, {k = }, {gen.__name__}, {extra_param = }")
	# assert ..., "Parameters invalid!"
	assert 1 <= n <= N_LIMIT and 1 <= q <= Q_LIMIT and 1 <= m <= M_LIMIT and 1 <= k <= K_LIMIT

	s, t = gen(n, q, m, k, **extra_param)
	assert len(s) == n and len(t) == q
	for i in s:
		assert len(i) == m
		assert i == i.lower()
	for i in t:
		assert len(i) == m
		assert i == i.lower()

	with open(f"{filename}.in", "w") as f:
		print(n, q, m, k, file = f)
		for i in s:
			print(i, file = f)
		for i in t:
			print(i, file = f)

	log(f"Generating output for case {filename}")
	# os.system(f'(time {os.path.join("..", "chj", "std")} < {filename}.in > {filename}.ans) 2>> gen.log')
	os.system(f'({os.path.join("..", "chj", "std")} < {filename}.in > {filename}.ans) 2>> gen.log')

class Cases:
	def __init__(self, prefix = ""):
		self.cnt = 0
		self.prefix = prefix
	
	def gen(self, n, q, m, k, gen, **extra_param):
		self.cnt += 1
		genTestcase(f"{self.prefix}{self.cnt}", n, q, m, k, gen, **extra_param)
	
	def skip(self, cnt = 1):
		self.cnt += cnt

os.system("rm gen.log")
testcase = Cases()
# precase = Cases("../pre/")
# sample = Cases("../down/")

for i in range(1, TASK_NUM + 1):
	log(f"Generating subtask {i}")
	pre = testcase.cnt
	# pre_pre = precase.cnt
	# add testcases below
	
	testcase.gen(N_LIMIT, Q_LIMIT, K_LIMIT - 1, K_LIMIT, genUniform)
	testcase.gen(N_LIMIT, Q_LIMIT, K_LIMIT, K_LIMIT, genUniform)
	testcase.gen(N_LIMIT, Q_LIMIT, K_LIMIT + 1, K_LIMIT, genUniform)
	testcase.gen(N_LIMIT, Q_LIMIT, K_LIMIT + 1, K_LIMIT, genUniform, alphabet = "abcd")
	testcase.gen(N_LIMIT, Q_LIMIT, K_LIMIT // 2 * 3, K_LIMIT, genUniform, alphabet = "bj")

	# K = 1 ?

	for delta in (-1, 0):
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genFlat)
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genFlat, alphabet = "ab")
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genFlat, n_init = 3)
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genFlat, n_init = 3, alphabet = "ab")
		
	for delta in (-1, 0):
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genSwap)
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genSwap, alphabet = "ab")
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genSwap, alphabet = "ab", n_commuter = int(K_LIMIT * 1.5))
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genSwap, alphabet = "ab", n_commuter = K_LIMIT + 2)
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genSwap, n_init = 3, alphabet = "ab")
		testcase.gen(N_LIMIT, Q_LIMIT, M_LIMIT + delta, K_LIMIT, genSwap, n_init = 3, alphabet = "ab", n_commuter = int(K_LIMIT * 1.5))

	# add testcases above		
	log(f"Subtask {i} done. ({pre + 1} - {testcase.cnt})")
	# log("Subtask {} done. (test: {} - {}; pre: {} - {})".format(i, pre + 1, testcase.cnt, pre_pre + 1, precase.cnt))

# for duck
# os.system("mkdir download")
# os.system("cp ../down/* ./download/")
