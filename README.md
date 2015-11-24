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

2015.11.16
100 Same Tree
判断两个二叉树是否相同
递归

2015.11.16
101 Symmetric Tree
判断一棵二叉树是否时对称的。
1、递归，递归判断两颗子树是否对称。
2、迭代，从根节点的左右节点逐层向下判断两个对应的节点值是否相等。

2015.11.16
102 Binary Tree Level Order Traversal
二叉树层次遍历
用队列，进行逐层遍历。

2015.11.17
104 Maximum Depth of Binary Tree
二叉树的最大深度。
递归。

2015.11.17
107 Binary Tree Level Order Traversal II
二叉树的层次遍历 II
从叶子到根，逐层输出。

2015.11.17
110 Balanced Binary Tree
判断是否是一棵平衡二叉树
递归。

2015.11.17
111 Minimum Depth of Binary Tree
求二叉树的最小深度
递归，注意只有一棵子树的情况。

2015.11.17
112 Path Sum
判断是否存在长为sum的路径。
深度优先搜索。

2015.11.18
118 Pascal's Triangle
杨辉三角。

2015.11.18
119 Pascla's Triangle II
杨辉三角
获得指定行。可只使用一个数组节省空间。

2015.11.18
125 Valid Palindrome
判断是否是回文串。
只考虑字母和数字。头尾依次判断。

2015.11.18
155 Min Stack
最小栈
实现能够在常量时间获取到栈的最小值。
单独设置一个变量保存最小值。每次push时比较更新。在pop时，如果当前的最小值已全部出栈，则遍历堆栈，找到新的最小值。

2015.11.19
160 Intersection of Tow Linked Lists
两个链表的交叉点
计算链表长度，根据长度差移动节点到相同长度的位置，逐一进行比较。

2015.11.19
165 Compare Version Numbers
比较版本号
将版本号根据'.'分割成多个整数逐一比较

2015.11.19 
168 Excel Sheet Column Number
数字到Excel列标题的转换
处理时，将数字n减一进行处理，这样可以从0开始，而不是从1开始。

2015.11.19
169 Majority Element
次数出现大于【n/2】的数
先统计出现次数，最后得出出现最多的数。

2015.11.19
171 Excel Sheet Column Number
题目的168的相反操作

2015.11.23
172 Factorial Trailing Zeroes
阶乘的尾0数
计算n的阶乘的尾零数，要求对数时间。
只需计算5的个数。注意，25,50,...包含多个5，所以不仅需要计算n/5, 还要计算n/5/5, n/5/5/5,...。

2015.11.23
189 Rotate Array
数组右旋
每次旋转一位；左右部分翻转，再整体翻转；对应位右移，每次移动都得到一位正确的结果。

2015.11.23
190 Reverse Bits 
位的翻转
将一个整数按位翻转。
优化：以4位为单位执行反转，将0x0至0xF的反转结果预存在一个长度为16的数组中，反转时直接查询即可。

2015.11.23
191 Number of 1 Bits
数中的位为1的个数
逐位判断。

2015.11.23
198 House Robber
抢劫问题。
动态规划。

2015.11.23
202 Happy Number
幸福数
不是幸福数，再其计算过程中，会出现一段循环。

2015.11.23
203 Remove Linked List Elements
删除链表指定元素
逐一判断。

2015.11.24
204 Count Primes
计算素数的数目
计算小于n的素数的数目。
Sieve of Eratosthenes。 

2015.11.24
205 Isomorphic Strings
同构字符串
注意两个字符不能映射到同一个字符。

2015.11.24
206 Reverse Linked List
翻转链表
逐一翻转，递归或迭代。
