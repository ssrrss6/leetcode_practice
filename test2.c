#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


//int maximumLengthSubstring(char* s) {
//    int hash[128];
//    memset(hash, 0, sizeof(int) * 128);
//    int max = 0, tmp = 0;
//    int left = 0, right = 0;
//
//    while (s[right]) {
//        if (hash[s[right]] < 2) {
//            tmp++;
//            hash[right]++;
//            right++;
//        }
//        else {
//            tmp--;
//            hash[left]--;
//            left++;
//        }
//        max = max > tmp ? max : tmp;
//    }
//
//    return max;
//}

//int equalSubstring(char* s, char* t, int maxCost) {
//    int max = 0, tmp = 0;
//    int cost = 0, i = 0, j = 0;
//    for (i = 0; s[i]; i++) {
//        cost = s[i] - t[i];
//        maxCost -= abs(cost);
//        while (maxCost < 0 && j < i) {
//            cost = s[j] - t[j];
//            maxCost += abs(cost);
//            j++;
//            tmp--;
//        }
//        tmp++;
//        max = max > tmp ? max : tmp;
//    }
//    return max;
//}

//int totalFruit(int* fruits, int fruitsSize) {
//    int baseket[10];
//    memset(baseket, 0, sizeof(int) * fruitsSize);
//    int max = 0, tmp = 0;
//    int i = 0, j = 0, flag = 0;
//
//    for (i = 0; i < fruitsSize; i++) {
//        flag += baseket[fruits[i]] == 0 ? 1 : 0;
//        tmp++;
//        baseket[fruits[i]]++;
//
//        while (flag > 2) {
//            flag -= baseket[fruits[j]] == 0 ? 1 : 0;
//            tmp--;
//            baseket[fruits[j]]--;
//            j++;
//        }
//
//        max = max > tmp ? max : tmp;
//    }
//
//    return max;
//}
//
//char* shortestBeautifulSubstring(char* s, int k) {
//    int min = INT_MAX, tmp = 0, count = 0;
//    int left = 0, right = 0;
//    int flag[2] = { 0, 0 };
//
//    while (s[right]) { //"00101100110010110"
//        tmp++;
//        count += s[right] & 1;
//
//        while (count == k && left < right) { // 尝试缩小字符串
//            if (s[left] == '1' && tmp <= min) { // 无法继续缩小时
//                int i = 0;
//                while (s[left + i] == '1' && left + i < right)
//                    i++;
//                if (tmp < min) {
//                    min = tmp;
//                    flag[0] = left;
//                    flag[1] = i + left >= right ? 0 : i;
//                }
//                else if (tmp == min) {
//                    if (i < flag[1]) {
//                        flag[0] = left;
//                        flag[1] = i;
//                    }
//
//                }
//            }
//            tmp--;
//            count -= s[left] & 1;
//            left++;
//        }
//
//        right++;
//    }
//
//    if (min == INT_MAX)
//        return "";
//    char ch[10];
//    for (int i = 0; i < min; i++) {
//        ch[i] = s[flag[0]];
//        flag[0]++;
//    }
//    return ch;
//}

//int balancedString(char* s) {
//    int len = strlen(s) / 4;
//    int hash[128];
//    memset(hash, 0, 128 * sizeof(int));
//
//    for (int i = 0; s[i]; i++)
//        hash[s[i]]++;
//
//    int min = INT_MAX, tmp = 0, balen = 0;
//    int left = 0, right = 0;
//    char ch[4] = { 'Q', 'W', 'E', 'R' };
//    for (int i = 0; i < 4; i++) {
//        if (hash[ch[i]] > len)
//            balen += hash[ch[i]] - len;
//        else
//            hash[ch[i]] = -len;
//    }
//
//    while (s[right]) {
//        tmp++;
//        balen -= (hash[s[right]] == -len ? 0 : 1);
//        while (balen <= 0) {
//            min = min < tmp ? min : tmp;
//            tmp--;
//            balen += (hash[s[left++]] == -len ? 0 : 1);
//        }
//        right++;
//    }
//
//    return min == INT_MAX ? 0 : min;
//}

//int minSizeSubarray(int* nums, int numsSize, int target) {
//    int min = INT_MAX, tmp = 0;
//    int left = 0, right = 0;
//    int len = 0, newlen = 0;
//    int total = 0, ans = 0;
//
//    for (int i = 0; i < numsSize; i++)
//        total += nums[i];
//
//    len = target / total + numsSize;
//
//    while (newlen < len + numsSize) {
//        tmp++;
//        ans += nums[right];
//        right = (right + 1) % numsSize;
//
//        while (ans >= target) {
//            if (ans == target)
//                min = min < tmp ? min : tmp;
//            tmp--;
//            ans -= nums[left];
//            left = (left + 1) % numsSize;
//        }
//
//        newlen++;
//    }
//
//    return min == INT_MAX ? -1 : min;
//}

//char* minWindow(char* s, char* t) {
//    int Thash[128], Shash[128];
//    memset(Thash, -1, sizeof(Thash[0]) * 128);
//    memset(Shash, 0, sizeof(Shash[0]) * 128);
//    int min = INT_MAX, tmp = 0;
//    int left = 0, right = 0, len = 0, cur = 0;
//
//    for (int i = 0; t[i]; i++) {
//        len++;
//        if (Thash[s[i]] == -1)
//            Thash[s[i]] = 0;
//        Thash[t[i]]++;
//    }
//
//    while (s[right]) {
//        tmp++;
//
//        if (Thash[s[right]] != -1) {
//            Shash[s[right]]++;
//            if (Shash[s[right]] <= Thash[s[right]])
//                len--;
//        }
//
//        while (len <= 0) {
//            if (tmp < min) {
//                cur = left;
//                min = tmp;
//            }
//            tmp--;
//            if (Thash[s[left]] != -1) {
//                Shash[s[left]]--;
//                if (Shash[s[left]] < Thash[s[left]])
//                    len++;
//            }
//            left++;
//        }
//
//        right++;
//    }
//
//    if (min == INT_MAX)
//        return "";
//
//    char* ch = (char*)malloc(sizeof(char) * (min + 2));
//    memset(ch, '\0', sizeof(char) * (min + 2));
//    for (int i = 0; i < min; i++) {
//        ch[i] = s[cur++];
//    }
//    return ch;
//}

//int check(int* time, int timeSize, int t, int totalTrips) {
//    long long ans = 0;
//    for (int i = 0; i < timeSize; i++) {
//        ans += t / time[i];
//        if (ans >= totalTrips)
//            return 1;
//    }
//    return 0;
//}
//
//
//long long minimumTime(int* time, int timeSize, int totalTrips) {
//    long long min = time[0];
//    for (int i = 0; i < timeSize; i++)
//        min = min < time[i] ? min : time[i];
//
//    long long left = min, right = min * totalTrips - 1;
//    while (left <= right) {
//        long long mid = left + (right - left) / 2;
//
//        if (check(time, timeSize, mid, totalTrips)) {
//            right = mid - 1;
//        }
//        else
//            left = mid + 1;
//
//    }
//    return left;
//}

//int check(int* weights, int weightsSize, int days, int mid) {
//    int time = 0, tmp = 0, i = 0;
//
//    for (int i = 0; i < weightsSize; i++) {
//        tmp += weights[i];
//        if (tmp > mid) {
//            time++;
//            tmp = weights[i];
//        }
//    }
//
//    time++;
//
//    return time <= days ? 1 : 0;
//}
//
//
//int shipWithinDays(int* weights, int weightsSize, int days) {
//    int max = 0;
//    for (int i = 0; i < weightsSize; i++)
//        max = max > weights[i] ? max : weights[i];
//
//    int left = max, right = max * days - 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//
//        if (check(weights, weightsSize, days, mid))
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//
//
//    return left;
//}

//int check(int* piles, int pilesSize, int h, int k) {
//    int time = 0, ban = 0;
//    int i = 0;
//    while (i < pilesSize) {
//        ban += k;
//        if (ban >= piles[i]) {
//            i++;
//            ban = 0;
//        }
//
//        time++;
//        if (time >= h)
//            return 1;
//    }
//
//    return 0;
//}/*


//int minEatingSpeed(int* piles, int pilesSize, int h) {
//    int max = 0;
//    for (int i = 0; i < pilesSize; i++)
//        max = max > piles[i] ? max : piles[i];
//
//    int left = 1, right = max - 1;
//    while (left <= right) {
//        int mid = left + (right - left) / 2;
//
//        if (check(piles, pilesSize, h, mid)) {
//            left = mid + 1;
//        }
//        else {
//            right = mid - 1;
//        }
//    }
//
//    return left;
//}*/

//int sort(int* capacity, int i, int j) {
//    int tmp = capacity[i];
//    while (i < j) {
//        while (capacity[j] >= tmp && i < j) j--;
//        capacity[i] = capacity[j];
//
//        while (capacity[i] <= tmp && i < j) i++;
//        capacity[j] = capacity[i];
//    }
//    capacity[i] = tmp;
//    return i;
//}
//
//void my_qsort(int* capacity, int i, int j) {
//    if (i < j)
//    {
//        int pow = sort(capacity, i, j);
//        my_qsort(capacity, i, pow - 1);
//        my_qsort(capacity, pow + 1, j);
//    }
//
//}
//
//int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
//    my_qsort(capacity, 0, capacitySize - 1);
//}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int minDeletion(char* s, int k) {
    int hash[26];
    memset(hash, 0, sizeof(int) * 26);

    int len = 0;
    for (int i = 0; s[i]; i++) {
        int c = s[i] - 'a';
        if (!hash[c])
            len++;
        hash[c]++;
    }

    qsort(hash, 26, sizeof(int), cmp);
    int i = 0, cnt = 0;

    while (len > k) {
        cnt += hash[i];
        if (!hash[i])
            len--;
        i++;
    }

    return cnt;
}

int main()
{
    char arr[] = { "abc" };

    int len = sizeof(arr) / sizeof(arr[0]);

    minDeletion(arr, 2);
    
    
    return 0;
}