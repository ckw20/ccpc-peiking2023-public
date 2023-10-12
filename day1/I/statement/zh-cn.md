{{ self.title() }}

{{ s('description') }}

Ene 喜欢回文。

Ene 现在有一些单词。她想知道有多少种选出若干个单词，首尾相连成长度恰好为 $L$ 的回文串的方法。这里认为两个选出单词的方法不同，当且仅当选出单词的种类不同，各单词出现次数不同，或排列顺序不同。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含两个正整数 $N, L$，分别表示单词的数量和需要组成的回文串的长度。保证 $1\le N\le 333$，$1\le L\le 1000$。

接下来 $N$ 行，每行输入一个字符串 $s_i$，表示一个单词。保证 $1\le s_i\le L$，$\sum_{i=1}^N \le 600$，输入的单词仅包含小写字符，且互不相同。

{{ s('output format') }}

{{ self.output_file() }}

输出一个非负整数，表示组成回文串的方案数对 $1,000,000,007$ 取模后的结果。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('subtasks') }}

对于所有测试点，保证 $1\le N\le 333$，$1\le L\le 1000$，$1\le s_i\le L$，$\sum_{i=1}^N\le 600$，$s_i$ 仅包含小写字符且互不相同。