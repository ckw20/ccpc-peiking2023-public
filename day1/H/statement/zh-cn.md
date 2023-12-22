{{ self.title() }}

{{ s('description') }}

给出 $n$ 个二元组 $(a_i,b_i)$。

考虑 $n$ 个节点的带权有向完全图 $G$，其中从 $i (1 \le i \le n)$ 到 $j (1 \le j \le n)$ 的边边权为 $|a_i-b_j|$。

求 $G$ 的一条哈密顿回路使得其经过的边的边权和最大，并给出这个最大值。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行一个整数 $n(2 \le n \le 10^5)$ 表示二元组个数，接下来 $n$ 行每行两个整数 $a_i,b_i(0 \le a_i,b_i \le 10^9)$ 表示每个二元组。保证输入的 $n$ 个二元组中的总共 $2n$ 个数两两不同。

{{ s('output format') }}

{{ self.output_file() }}

输出一行一个整数表示最大的哈密顿回路边权和。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

考察哈密顿回路 $1 \to 2 \to 3 \to 1$，其边权和为 $|1-2| + |
8-5| + |4-10| = 10$。可以证明不存在哈密顿回路边权和超过 $10$，因此答案为 $10$。
