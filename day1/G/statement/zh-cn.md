{{ self.title() }}
{{ s('description') }}

有一个长度为 $n$ 的序列 $a_1,a_2,\cdots,a_n$，保证 $a_i$ 为**奇数**。

有两种操作：

1. 给定 $l,r,x$，将 $a_l,a_{l+1},\cdots,a_r$ 加上**偶数** $x$；

2. 给定 $l,r$，求 $a_l,a_{l+1},\cdots,a_r$ 的乘积，答案对 $2^{20}$ 取模；

{{ s('input format') }}

{{ self.input_file() }}

第一行两个正整数 $n,q$ 表示序列的长度和询问的个数. 保证 $1 \le n,q \le 2\times 10^5$。

第二行 $n$ 个**奇数** $a_1,a_2,\cdots,a_n$. 保证 $1 \le a_i < 2^{20}$。

接下来 $q$ 行，每一行表示一个操作，格式为以下两种之一：

- $1 ~ l ~ r ~ x$：表示进行第一种操作. 保证 $1 \le l \le r \le n$，$0 \le x < 2 ^ {20}$。
- $2 ~ l ~ r$：表示进行第二种操作. 保证 $1 \le l \le r \le n$。

{{ s('output format') }}

{{ self.output_file() }}

对于每一次 $2$ 操作，输出一行一个整数表示答案。

{{ s('sample') }}

{{ self.sample_text() }}

