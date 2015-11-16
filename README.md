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

2015.11.9
20 Valid Parentheses
判断括号是否匹配
利用栈进行比对

2015.11.9
21 Merge Two Sorted Lists
合并两个有序的链表

2015.11.9
26 Remove Duplicates from Sorted Array
有序数组删除重复的数（不允许分配额外空间）
设置两个指针，一个指向新的数组的结尾，一个指向现在搜索到的位置。

2015.11.10
27 Remove Element
从数组中删除指定的值。
设置两个指针，一个指向新的数组的结尾，一个指向现在搜索到的位置。

2015.11.10
28 Implement strStr()
判断是否是子串，并返回第一次出现的索引
依次进行判断。

2015.11.12
36 Valid Sudoku
判断数独是否有效
设置三个数组,rows[i][j], cols[i][j],block[i][j],分别表示对应的行，列，区块i+1是否存在j+1这个数。 

2015.11.12
38 Count and Say
获取count-and-say序列的第n个数
关键是从前一个字符串获得下一个字符串

2015.11.12
58 Length of Last Word
字符串中最后一个单词的长度
直接搜索

2015.11.13
66 Plus One
将用数组表示的数加一
注意，进位的问题。

2015.11.13
67 Add Binary
将字符串表示的两个二进制相加
注意，进位的问题。

2015.11.13
70 Climbing Stairs
爬楼梯问题
dp[i]表示ｎ阶楼梯的不同方法数，则dp[i] = dp[i-1] + dp[i-2]

2015.11.16
83 Remove Duplicates from Sorted List
从有序链表中删除重复元素
设置两个指针。

2015.11.16
88 Merge Sorted Array
合并两个有序的数组。
注意，分配额外空间或不分配的区别。
