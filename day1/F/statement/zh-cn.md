{{ self.title() }}

{{ s('description') }}

小 I 发明了 $O(n + m)$ 的有向图最小环，于是他想考考你。

给定一个 $n$ 个节点、$m$ 条边的有向图，每条边有正整数边权。你需要求出图上的一个环使得环上边的边权和最小。求出这个最小值，或者报告不存在环。

当然，由于你不会 $O(n + m)$ 的有向图最小环，于是小 I 放宽了条件：保证输入的图是弱连通的，且 $m-n$ 不会很大。一个图是弱连通的当且仅当将有向边换为无向边后图连通。

{{ s('input format') }}

{{ self.input_file() }}

第一行两个整数 $n,m (1 \le n \le 3 \times 10^5, -1 \le m-n \le 1500)$，表示图的点数和边数。

接下来 $m$ 行每行三个整数 $u_i,v_i,w_i (1 \le u_i,v_i \le n, 1 \le w_i \le 10^9)$，表示一条从 $u_i$ 到 $v_i$、边权为 $w_i$ 的有向边。保证图是弱连通的。

{{ s('output format') }}

{{ self.output_file() }}

如果图中不存在环，输出 `-1`，否则输出一个整数表示最小环的长度和。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

最小环为 $1 \to 2 \to 4 \to 3 \to 1$。

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', 3) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

最小环为 $1 \to 1$。
