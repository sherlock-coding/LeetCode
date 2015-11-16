/*
 * 88 Merge Sorted Array
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 * */

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    vector<int> nums3;
    int p = 0;
    int q = 0;

    while ((p != m) && (q != n)) {
        if (nums1[p] < nums2[q]) {
            nums3.push_back(nums1[p]);
            ++p;
        }
        else {
            nums3.push_back(nums2[q]);
            ++q;
        }
            
    }

    if (p != m)
        nums3.insert(nums3.end(), nums1.begin()+p, nums1.begin()+m);
    if (q != n)
        nums3.insert(nums3.end(), nums2.begin()+q, nums2.begin()+n);
    nums1.resize(m+n);
    for (int i = 0 ;i < m+n; ++i)
        nums1[i] = nums3[i];
}

int main()
{
    vector<int> a;
    vector<int> b{1};
    merge(a,0,b,1);
    for (int i = 0; i < 1; ++i)
        cout << a[i] << " ";
    cout << endl;
}
