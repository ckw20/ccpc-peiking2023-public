{{ self.title() }}

{{ s('description') }}

Ene 喜欢回文。

Ene 现在有一些单词。她想选出若干个单词并将它们首尾相连，形成长度恰好为 $L$ 的回文串。每个单词都可以选择多次，也可以不选。

Ene 想知道这样做的方案数。认为两个方案不同，当且仅当各单词出现次数不同或它们的排列顺序不同，注意可能多种不同的方案会得到同一个回文串。由于答案很大，你需要将答案对 $1,000,000,007$ 取模

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含两个正整数 $N, L$，分别表示单词的数量和需要组成的回文串的长度。保证 $1\le N\le 333$，$1\le L\le 1000$。

接下来 $N$ 行，每行输入一个字符串 $s_i$，表示一个单词。保证 $1\le |s_i| \le L$，$\sum_{i=1}^N |s_i| \le 600$。输入的单词仅包含小写字符，且互不相同。

{{ s('output format') }}

{{ self.output_file() }}

输出一个非负整数，表示组成回文串的方案数对 $1,000,000,007$ 取模后的结果。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

有以下五种方案：

- `stack` `cats`
- `evil` `olive`
- `eel` `eve` `lee`
- `lee` `eve` `eel`
- `eve` `eve` `eve`

{{ s('sample', 2) }}

{{ self.sample_text() }}
