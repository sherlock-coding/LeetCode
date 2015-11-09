2015.4.14
127 Word Ladder
利用ＢＦＳ
起点终点并不一定在字典中
节点是每个单词，边就是修改一个字母
注意避免重复

2014.4.15
126 Word Ladder II
利用BFS
注意存放每个单词的前驱
利用前驱输出整个单词序列

2015.5.18
144 Binary Tree Preorder Traversal
二叉树前序遍历
DFS

2015.5.18
94 Binary Tree Inorder Traversal
二叉树中序遍历
DFS

2015.5.18
145 Binary Tree Postorder Traversal
二叉树后序遍历
DFS

2015.5.19
52 N-Queens II
n皇后问题，获取解的个数
DFS

2015.5.19
51 N-Queens
n皇后问题，获取解的具体图形分布
DFS

2015.5.21
64 Minimum Path Sum
动态规划

2015.5.22
53 Maximum Subarray
最大子数组和
动态规划

2015.5.25
91 Decode Ways
动态规划

2015.5.26
97 Interleaving String
动态规划

2015.5.26
120 Triangle
动态规划

2015.5.28
132 Palindrome Partitioning II
字符串回文划分
动态规划
超时问题：避免判断回文的次数过多，利用dp将所有的子串是否是回文打表

2015.5.28
139 Word Break
单词划分
动态规划

2015.5.28
152 Maximum Product Subarray
最大子数组乘积
动态规划
注意与最大字数组和的比较，需要保存最大值和最小值

2015.11.8
14 Longest Common Prefix 
最长相同前缀
注意比较每一个字符，每个字符串字符与上个字符串的字符比较，如果不相同就结束。

2015.11.8
19 Remove Nth Node From End of List
移除链表中倒数第n个节点
设置相距n的两个节点指针，同时进行移动。

2015.11.8
20 Valid Parentheses
判断括号是否匹配
利用栈进行比对
