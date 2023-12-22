{{ self.title() }}

{{ s('description') }}

小 I 正在学习使用 Pytorch。这是一个非常热门的用于机器学习训练的 Python 库。

小 I 注意到，Pytorch 中对于张量运算有称作“广播”(broadcast)的机制。你可以认为张量是高维数组。对于一个 $k$ 维张量 $A$，我们用长度为 $k$ 的序列 $(a_1,a_2,\cdots,a_k)$ 表示其各个维度的长度，也就是说 $A$ 是一个 $a_1 \times a_2 \times \cdots \times a_k$ 的张量。

对于两个张量 $A$ 和 $B$，设它们的维度分别为 $(a_1,a_2,\cdots,a_m)$ 和 $(b_1,b_2,\cdots,b_n)$，称 $A$ 和 $B$ 是 **可广播的**，当且仅当以下性质成立：

- 对于任意整数 $0 \le i \le \min(n,m) - 1$，要么 $a_{m-i} = b_{n-i}$，要么 $a_{m-i}$ 和 $b_{n-i}$ 中至少有一个是 $1$。

现在小 I 有两个张量，它们的维度分别是 $(p_1,p_2,\cdots,p_m)$ 和 $(q_1,q_2,\cdots,q_n)$，它们不一定是可广播的。

为此，小 I 可以使用 Pytorch 内置的函数进行若干次操作（可以不做操作），每次操作对序列 $p$ 或 $q$ 进行以下修改：

- 选择 $p$ 或 $q$，在选定序列的任意一个位置插入一个 $1$。

小 I 想知道他最少要多少次操作才能让两个张量变为可广播的。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行两个整数 $m,n(1 \le m,n \le 2000)$ 表示两个张量的维度。

第二行 $m$ 个整数 $p_1,p_2,\cdots,p_m (1 \le p_i \le 2000)$ 描述第一个张量每个维度的长度。

第三行 $n$ 个整数 $q_1,q_2,\cdots,q_n (1 \le q_i \le 2000)$ 描述第二个张量每个维度的长度。

{{ s('output format') }}

{{ self.output_file() }}

输入一行一个整数表示最少的插入 $1$ 的数量使得两个张量变为可广播的。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

在序列 $q$ 的第二个位置之前插入一个 $1$（得到 `4 1 2`），两个张量就会变为可广播的。