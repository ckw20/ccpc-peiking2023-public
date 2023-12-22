{{ self.title() }}

{{ s('description') }}

给定一个 $n$ 个点的无向正权完全图，请对于每一条边 $(a,b)$，求出是否存在一个点对 $(x,y)$ 使得 $x\rightarrow y$ 的所有最短路都经过 $(a,b)$。

{{ s('input format') }}

{{ self.input_file() }}

第一行一个正整数 $n (1 \le n \le 500)$ 表示图的点数。

接下来 $n$ 行每行 $n$ 个数，构成一个大小为 $n\times n$ 的矩阵，第 $i$ 行第 $j$ 个数 $a_{i,j}(1\leq a_{i,j}\leq 10^6)$ 表示 $(i,j)$ 之间的边长度，特别地，$a_{i,i} = 0$.

保证 $a_{i,j}=a_{j,i}$。

{{ s('output format') }}

{{ self.output_file() }}

输出一个大小为 $n$ 的 $01$ 矩阵，其中第 $i$ 行第 $j$ 列为 $1$ 表示边 $(i,j)$ 满足题目中提出的要求，$0$ 表示不满足。

特别的，当 $i=j$ 时输出 $0$。

{{ s('sample', 1) }}

{{ self.sample_text() }}
