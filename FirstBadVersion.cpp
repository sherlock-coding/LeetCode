/*
 * 278 You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 *
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 *
 * You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 * */

bool isBadVersion(int version);

int firstBadVersion(int n) 
{
    int start = 1;
    int end = n;
    int mid;

    while (start < end) {
        //mid = (start + end) / 2; ->可能导致溢出
        mid = start + (end - start) / 2;
        if (isBadVersion(mid))
            end = mid;
        else
            start = mid + 1;
    }

    return end;
}