{{ self.title() }}

{{ s('description') }}

给定一个长度为 $n$、字符集为 `01?` 的字符串 $s_1s_2 \cdots s_n$。

对于任意 $k \in [1,n]$，考察字符串 $T_k = t_1 t_2 \cdots t_n$，其中对于 $1 \le i \le n$，

- 若 $s_i \ne$ `?`，则 $t_i = s_i$；
- 否则，若 $i \le k$，$t_i =$ `0`；
- 否则 $t_i = t_{i-k}$，你可以通过递归地算出 $t_{i-k}$ 得到 $t_i$。

容易发现 $T_k$ 的字符集为 `01`。你需要对所有 $k \in [1,n]$ 求出 $T_k$ 中 `1` 的个数。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行一个整数 $n (1 \le n \le 10^5)$ 表示字符串长度，第二行一个长度为 $n$、字符集为 `01?` 的字符串 $s_1s_2\cdots s_n$。

{{ s('output format') }}

{{ self.output_file() }}

输出 $n$ 行，第 $i$ 行一个整数表示 $T_i$ 中 `1` 的个数。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

$T_1 =$ `10011`，$T_2 =$ `10111`，$T_3 =$ `10010`，$T_4 =$ `10011`，$T_5 =$ `10010`。