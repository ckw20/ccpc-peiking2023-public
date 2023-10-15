import random
import os
import datetime
import numpy as np

TASK_NUM = 1

N_LIMIT = 333
L_LIMIT = 1000
S_TOTAL_LIMIT = 600
ATOZ = "abcdefghijklmnopqrstuvwxyz"

def log(string):
	print(string, flush = True)
	with open("gen.log", "a") as f:
		f.write(f"[{datetime.datetime.now()}] {string}\n")

def getRandStr(length, alphabet = ATOZ):
	return "".join(random.choices(alphabet, k = length))

def getRandPal(length, alphabet = ATOZ):
	x = getRandStr((length + 1) // 2, alphabet)
	return x + x[::-1] if length % 2 == 0 else x[:-1] + x[::-1]

def genSpecified(l, s = None, **extra_param):
	return s

def genSingle(l, alphabet = ATOZ, **extra_param):
	return [c for c in alphabet]

def genPalindromes(l, alphabet = ATOZ, s_total = S_TOTAL_LIMIT, with_fake = False, **extra_param):
	rng = np.random.default_rng()

	n = s_total // l
	if with_fake is True:
		with_fake = 0.2
	
	s = []
	vis = set()
	for i in range(n):
		while True:
			x = getRandPal(l, alphabet)
			if isinstance(with_fake, float) and rng.random() < with_fake:
				r = rng.random()
				if r < 0.25:
					x = getRandStr(l, alphabet)
				elif r < 0.5:
					x = x[1:-1]
				elif r < 0.75:
					x = x[1:]
				else:
					x = x[:-1]
			if x not in vis:
				s.append(x)
				vis.add(x)
				break
	
	return s

def genPairs(l, alphabet = ATOZ, s_total = S_TOTAL_LIMIT, min_length = 2, max_length = 4, **extra_param):
	rng = np.random.default_rng()

	total_length = 0
	s = []
	vis = set()
	if l % 2 == 1:
		while total_length * 2 < s_total:
			a, b = getRandStr(2, alphabet)
			x = a + b + a
			if x in vis:
				continue
			s.append(x)
			vis.add(x)
			total_length += 3
			if rng.random() < 0.5:
				break
	
	while total_length + 2 * (max_length + 1) < s_total:
		x = getRandStr(rng.integers(min_length, max_length, endpoint = True), alphabet)
		if x in vis:
			continue
		if x == x[::-1]:
			s.append(x)
			total_length += len(x)
			vis.add(x)
		else:
			s.append(x)
			s.append(x[::-1])
			total_length += len(x) * 2
			vis.add(x)
			vis.add(x[::-1])
	
	while total_length < s_total:
		x = getRandStr(rng.integers(1, s_total - total_length, endpoint = True))
		if x in vis:
			continue
		s.append(x)
		total_length += len(x)
		vis.add(x)

	return s

def genShrunk(l, alphabet = ATOZ, s_total = S_TOTAL_LIMIT, min_length = 1, max_length = 7, **extra_param):
	rng = np.random.default_rng()

	total_length = 0
	s = []
	vis = set()
	while total_length + max_length + 1 < s_total:
		x = getRandPal(rng.integers(min_length, max_length, endpoint = True), alphabet)
		r = rng.random()
		if len(x) > 1:
			if r < 1 / 4:
				if rng.random() < 0.2 and len(x) > 2:
					x = x[2:]
				else:
					x = x[1:]
			elif r < 1 / 2:
				if rng.random() < 0.2 and len(x) > 2:
					x = x[:-2]
				else:
					x = x[:-1]
		if x in vis:
			continue
		s.append(x)
		total_length += len(x)
		vis.add(x)

	single = [c for c in alphabet if c not in vis]
	if s_total - total_length <= len(single):
		s += random.sample(single, s_total - total_length)
	else:
		while total_length < s_total:
			x = getRandStr(rng.integers(1, s_total - total_length, endpoint = True))
			if x in vis:
				continue
			s.append(x)
			total_length += len(x)
			vis.add(x)

	return s

def genSlices(l, alphabet = ATOZ, s_total = S_TOTAL_LIMIT, n = N_LIMIT, pal_length = None, **extra_param):
	rng = np.random.default_rng()

	if pal_length is None:
		pal_length = l
	k = s_total // pal_length
	s = []
	vis = set()
	while True:
		num_slices = rng.multinomial(n - k, np.ones(k) / k) + 1
		if (num_slices <= pal_length / 3.1).all():
			break

	for i in range(k):
		while True:
			x = getRandPal(pal_length, alphabet)
			indices = np.concatenate(([0], np.sort(rng.choice(pal_length - 1, num_slices[i] - 1, replace = False) + 1), [pal_length]))
			slices = [x[indices[j] : indices[j + 1]] for j in range(num_slices[i])]
			if len(set(slices)) != num_slices[i]:
				continue
			for sl in slices:
				if sl in vis:
					break
			else:
				break
		s += slices
		vis.update(slices)
	
	# print(s)
	
	return s

def genMajority_Minority(l, alphabet = ATOZ, s_total = S_TOTAL_LIMIT, min_length = 2, max_length = 12, **extra_param):
	rng = np.random.default_rng()

	a, b = alphabet[:2]
	s = [a, b]
	vis = set(s)
	total_length = 2
	while total_length + min_length + 2 < s_total:
		t = rng.integers(min_length, min(s_total - total_length, max_length), endpoint = True)
		x = a * t
		if x not in vis and rng.random() < 0.5:
			s.append(x)
			vis.add(x)
			total_length += t
		else:
			index = rng.integers(t)
			x = x[:index] + b + x[index + 1:]
			for i in range(1, t):
				if rng.random() < 2 / (t + 2 * i):
					index = rng.choice([j for j in range(t) if x[j] == a])
					x = x[:index] + b + x[index + 1:]
				else:
					break
			if x not in vis:
				s.append(x)
				vis.add(x)
				total_length += t

	return s

def genTestcase(filename, l, gen, **extra_param):
	log(f"Generating input for case {filename}, params: {l = }, {gen.__name__}, {extra_param = }")
	# assert ..., "Parameters invalid!"
	assert 1 <= l <= L_LIMIT

	s = gen(l, **extra_param)
	assert 1 <= len(s) <= N_LIMIT
	assert 1 <= sum(len(i) for i in s) <= S_TOTAL_LIMIT, f"sum of lengths {sum(len(i) for i in s)} out of range"
	assert len(set(s)) == len(s)
	for i in s:
		assert 1 <= len(i) <= l and i == i.lower()

	with open(f"{filename}.in", "w") as f:
		print(len(s), l, file = f)
		for i in s:
			print(i, file = f)

	log(f"Generating output for case {filename}")
	# os.system(f'(time {os.path.join("..", "chj", "std")} < {filename}.in > {filename}.ans) 2>> gen.log')		# Linux
	os.system(f'({os.path.join("..", "chj", "std")} < {filename}.in > {filename}.ans) 2>> gen.log')				# Windows

class Cases:
	def __init__(self, prefix = ""):
		self.cnt = 0
		self.prefix = prefix
	
	def gen(self, l, gen, **extra_param):
		self.cnt += 1
		genTestcase(f"{self.prefix}{self.cnt}", l, gen, **extra_param)
	
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
	
	# testcase.gen(L_LIMIT, genSingle)
	testcase.skip()

	for l in (15, 18):
		for alphabet in (ATOZ, "ab"):
			for with_fake in (False, 0.1, 0.7):
				# testcase.gen(l, genPalindromes, alphabet = alphabet, with_fake = with_fake)
				testcase.skip()
	
	for l in (L_LIMIT - 1, L_LIMIT):
		for alphabet in (ATOZ, "abcdefg"):
			for j in range(2):
				testcase.gen(l, genPairs, alphabet = alphabet)
	
	for l in (L_LIMIT - 1, L_LIMIT):
		for alphabet in (ATOZ, "abcdefg"):
			for j in range(2):
				testcase.gen(l, genShrunk, alphabet = alphabet)

	for l, pal_length in ((45, 45), (50, 50), (999, 27), (1000, 20)):
		for alphabet in (ATOZ, "abcdefg"):
			for n in (50, 100, 120):
				for j in range(2):
					testcase.gen(l, genSlices, alphabet = alphabet, n = n, pal_length = pal_length)
	
	for l in (L_LIMIT - 1, L_LIMIT):
		for min_length in (2, 4):
			for j in range(2):
				testcase.gen(l, genMajority_Minority, min_length = min_length)
	

	# add testcases above		
	log(f"Subtask {i} done. ({pre + 1} - {testcase.cnt})")
	# log("Subtask {} done. (test: {} - {}; pre: {} - {})".format(i, pre + 1, testcase.cnt, pre_pre + 1, precase.cnt))

# for duck
# os.system("mkdir download")
# os.system("cp ../down/* ./download/")
