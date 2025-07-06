#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

//
//int findLHS(int* nums, int numsSize) {
//
//	/*
//	和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
//
//给你一个整数数组 nums ，请你在所有可能的 子序列 中找到最长的和谐子序列的长度。
//
//数组的 子序列 是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
//*/
//
//	int CountNums[50];
//	int min = nums[0];	// nums数组中的最小值
//	int count = 0; // 相差为1的序列最大值
//
//	for (int i = 0; i < numsSize; i++) // 初始化
//		CountNums[i] = 0;
//
//	for (int i = 0; i < numsSize; i++) // 找出最小值
//		if (min > nums[i])
//			min = nums[i];
//
//	for (int i = 0; i < numsSize; i++)
//		if ((nums[i] - min) < numsSize)
//			CountNums[(nums[i] - min)]++;
//
//	for (int i = 1; i < numsSize; i++)
//	{
//		if (CountNums[i] && CountNums[i-1]) // 保证相差正好为1
//		{
//			count = CountNums[i] + CountNums[i - 1] > count ? CountNums[i] + CountNums[i - 1] : count;
//		}
//	}
//
//	return count;
//
//}
//
//
//int main() {
//
//	int nums[] = { 1,2,3,3,1,-14,13,4 };
//	int len = sizeof(nums) / sizeof(nums[0]);
//
//
//	int num = findLHS(nums, len);
//
//	printf("%d\n", num);
//	
//
//}

//char* mergeAlternately(char* word1, char* word2) {
//	/*
//	给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。
//
//返回 合并后的字符串 。
//
//
//	*/
//
//	int len1 = strlen(word1);
//	int len2 = strlen(word2);
//	int len = len1 + len2;
//	char word[20];
//
//	int i = 0, w1 = 0, w2 = 0;
//	for (i = 0; w1 < len1 && w2 < len2; i++)
//	{
//		if (i % 2 == 1 && w1 < len1)
//			word[i] = word1[w1++];
//		if (i % 2 == 0 && w2 < len2)
//			word[i] = word2[w2++];
//	}
//	while (w1 < len1)
//		word[i++] = word1[w1++];
//	while(w2 < len2)
//		word[i++] = word2[w2++];
//
//	return word;
//
//}
//
//
//char findTheDifference(char* s, char* t) {
//	/*
//	
//	给定两个字符串 s 和 t ，它们只包含小写字母。
//
//字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
//
//请找出在 t 中被添加的字母。
//
// */
//
//	int hash[26] = {0};
//	int i = 0;
//	while (s[i] != '\0') {
//		hash[s[i] - 'a']++;
//		i++;
//	}
//	i = 0;
//	while (t[i] != '\0') {
//		hash[t[i] - 'a']--;
//		if (hash[t[i] - 'a'] < 0)
//			return t[i];
//		i++;
//	}
//	return 0; // 防止编译器警告
//}
// 

//int cmp(char* s, char* t, int len) {
//    int i = 0;
//    while (i < len && s[i] && t[i])
//    {
//        if (s[i] - t[i] == 0)
//            i++;
//        else
//            return 0;
//    }
//    return 1;
//}
//
//
//int repeatedSubstringPattern(char* s) {
//    int len = strlen(s);
//    int i = 0, j = 0;
//    for (i = 1; i <= len / 2; i++) {
//        int k = 1;
//        for (j = i; j <= len - i; j = i * k) {
//            k++;
//            if (cmp(s, s + j, i) != 1)
//                break;
//        }
//        if (j == i * k && i % len == 0)
//            return 1;
//    }
//
//    return 0;
//}


//void moveZeroes(int* nums, int numsSize) {
//
//    /*
//    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。*/
//
//    int count = 0;
//    int j = 0;
//    for (int i = 0; i < numsSize; i++) {
//        while (i < numsSize && nums[i++] == 0)
//            count++;
//        
//        if(i < numsSize)
//            nums[j++] = nums[i];
//    }
//
//    for (int i = j; i < numsSize; i++)
//        nums[i] = 0;
//
//}

//int calPoints(char** operations, int operationsSize) {
//    char* num[20];
//    int i = 0, j = 0;
//    int ret = 0;
//    while (i < operationsSize)
//    {
//        while (i < operationsSize && operations[i][0] == 'C')
//            i++;
//        if (i < operationsSize)
//            num[j++] = operations[i++];
//    }
//
//    for (i = 0; i < j; i++) {
//        if (num[i][0] == 'D')
//        {
//            ret += atoi(num[i - 1]) * 2;
//            sprintf(num[i], "%d", atoi(num[i - 1]) * 2);
//        }
//        else if (num[i][0] == '+')
//        {
//            ret += atoi(num[i - 2]) + atoi(num[i - 1]);
//            sprintf(num[i], "%d", atoi(num[i - 2]) + atoi(num[i - 1]));
//        }
//        else
//            ret += atoi(num[i]);
//    }
//
//    return ret;
//}
//
//int isRobotBounded(char* instructions) {
//    /*
//    在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。注意:
//
//北方向 是y轴的正方向。
//南方向 是y轴的负方向。
//东方向 是x轴的正方向。
//西方向 是x轴的负方向。
//机器人可以接受下列三条指令之一：
//
//"G"：直走 1 个单位
//"L"：左转 90 度
//"R"：右转 90 度
//机器人按顺序执行指令 instructions，并一直重复它们。
//
//只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。
//*/
//
//    int x = 0, y = 0;
//    char des = 'GL';
//    for (int i = 0; i < 4; i++)
//    {
//        int j = 0;
//        while (instructions[j])
//        {
//            if (instructions[j] == 'G') {
//                if (des == 'N')
//                    y++;
//                else if (des == 'S')
//                    y--;
//                else if (des == 'W')
//                    x--;
//                else if (des == 'E')
//                    x++;
//            }
//            else if (instructions[j] == 'L') {
//                if (des == 'N')
//                    des = 'W';
//                else if (des == 'S')
//                    des = 'E';
//                else if (des == 'W')
//                    des = 'S';
//                else if (des == 'E')
//                    des = 'N';
//            }
//            else if (instructions[j] == 'R') {
//                if (des == 'N')
//                    des = 'E';
//                else if (des == 'S')
//                    des = 'W';
//                else if (des == 'W')
//                    des = 'N';
//                else if (des == 'E')
//                    des = 'S';
//            }
//            j++;
//        }
//    }
//
//    if (x == 0 && y == 0)
//        return 1;
//    else
//        return 0;
//}

//int* spiralOrder(int matrix[][4], int matrixSize, int* matrixColSize, int* returnSize) {
//    int* arr = (int*)malloc(*returnSize * sizeof(int));
//    int len = 0;
//    int cyc = 0;
//
//    while (len < *returnSize) {
//        int row = cyc, col = cyc;
//        while (col < *matrixColSize - cyc)
//            arr[len++] = matrix[row][col++];
//        col--;
//        row++;
//        while (row < matrixSize - cyc)
//            arr[len++] = matrix[row++][col];
//        row--;
//        col--;
//        while (col >= cyc)
//            arr[len++] = matrix[row][col--];
//        col++;
//        row--;
//        while (row > cyc)
//            arr[len++] = matrix[row--][col];
//        cyc++;
//    }
//
//    return arr;
//}

//char* addBinary(char* a, char* b) {
//    int al = strlen(a) - 1;
//    int bl = strlen(b) - 1;
//    int len = (al > bl ? al : bl) + 2;
//    char B[10];
//    int flag = 0;
//    int i = 0;
//    for (i = len - 1; i >= 0 && al >= 0 && bl >= 0; i--) {
//        if (a[al] == '1' && b[bl] == '1') {
//            if (flag)
//                B[i] = '1';
//            else
//                B[i] = '0';
//            flag = 1;
//        }
//        else if (a[al] == '1' || b[bl] == '1') {
//            if (flag)
//                B[i] = '0';
//            else {
//                B[i] = '1';
//                flag = 0;
//            }
//        }
//        else {
//            if (flag)
//                B[i] = '1';
//            else
//                B[i] = '0';
//            flag = 0;
//        }
//        al--;
//        bl--;
//    }
//
//    while (al >= 0) {
//        if (flag) {
//            if (a[al--] == '1')
//                B[i--] = '0';
//            else {
//                B[i--] = '1';
//                flag = 0;
//            }
//        }
//        else
//            B[i--] = a[al--];
//    }
//    while (bl >= 0) {
//        if (flag) {
//            if (b[bl--] == '1')
//                B[i--] = '0';
//            else {
//                B[i--] = '1';
//                flag = 0;
//            }
//        }
//        else
//            B[i--] = b[bl--];
//    }
//    if (i == 0)
//        B[i] = '1';
//
//    char* ans = B;
//    return ans;
//}

//
//void add(char* tmp, char* produce) {
//    int j = 0;
//    int carry = 0;
//    while (tmp[j]) {
//        int t = (!produce[j] ? tmp[j] - '0' + carry : ((produce[j] - '0') + (tmp[j] - '0') + carry));
//        produce[j] = t % 10 + '0';
//        carry = t / 10;
//        j++;
//    }
//}
//
//void reverse(char* num) {
//    int len = strlen(num);
//    for (int i = 0; i < len / 2; i++) {
//        char t = num[i];
//        num[i] = num[len - i - 1];
//        num[len - i - 1] = t;
//    }
//}
//
//char* multiply(char* num1, char* num2) {
//    /*给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//        注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。*/
//    
//    int len1 = strlen(num1);
//    int len2 = strlen(num2);
//    int carry = 0;
//    int prolen = len1 + len2;
//    char* produce = (char*)malloc((prolen + 1) * sizeof(char)); // 积
//    char* tmp = (char*)malloc((len1 + 2) * sizeof(char));   // 乘数位的积和
//    memset(produce, '\0', (prolen + 1) * sizeof(char)); // 初始化
//    memset(tmp, '\0', (len1 + 2) * sizeof(char));   // 初始化
//    reverse(num1);
//    reverse(num2);
//
//    for (int i = 0; i < len2; i++) {
//        int j = 0;
//        carry = 0;
//        for (j = 0; j < len1; j++) {
//            int t = (num1[j] - '0')* (num2[i] - '0') + carry;
//            tmp[j] = t % 10 + '0';
//            carry = t / 10;
//        }
//        if (carry && !tmp[j]) {
//            tmp[j] = carry + '0';
//        }
//        add(tmp, produce + i);
//    }
//
//    reverse(produce);
//    return produce;
//}

//double myPow(double x, int n) {
//    if (x == 1 || x == 0 || n == 1)
//        return x;
//
//    int sign = 1;
//    unsigned int j = 0;
//    if (n < 0) {
//        j = -n;
//        sign = -sign;
//    }
//
//    double ret = x;
//    int i = 1;
//    while (2 * i <= j) {
//        x *= x;
//        i *= 2;
//    }
//
//    while (i < j || i == 2) {
//        x *= ret;
//        i++;
//    }
//
//    if (sign == -1)
//        return 1 / x;
//    else
//        return x;
//}

//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
//    struct ListNode* L = NULL;
//    struct ListNode* Lp = NULL;
//    // if(list1 && list2){
//    //     L = (list1->val > list2->val ? list2 : list1);
//    //     L = L->next;
//    //     list1 = list1->next;
//    //     list2 = list2->next;
//    // }
//
//    while (list1 && list2) {
//        L = (list1->val > list2->val ? list2 : list1);
//        if (Lp = NULL)
//            Lp = L;
//        L = L->next;
//        list1 = list1->next;
//        list2 = list2->next;
//    }
//    if (list1)
//        L = list1;
//    else if (list2)
//        L = list2;
//
//    return Lp;
//
//}

//
// struct ListNode {
//    int val;
//    struct ListNode *next;
//  };
// 
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    struct ListNode L;
//    struct ListNode* Lp = &L;
//    int carry = 0;
//    while (l1 && l2) {
//        Lp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        Lp->val = (l1->val + l2->val) % 10 + carry;
//        carry = (l1->val + l2->val) / 10;
//        l1 = l1->next;
//        l2 = l2->next;
//        Lp = Lp->next;
//    }
//    /*while (l1) {
//        Lp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        Lp->val = (l1->val % 10) + carry;
//        carry = (l1->val + carry) / 10;
//        l1 = l1->next;
//        Lp = Lp->next;
//    }
//    while (l2) {
//        Lp->next = (struct ListNode*)malloc(sizeof(struct ListNode));
//        Lp->val = (l2->val % 10) + carry;
//        carry = (l2->val + carry) / 10;
//        l2 = l2->next;
//        Lp = Lp->next;
//    }*/
//    
//    Lp->next = (l1 ? l1 : l2);
//    if(Lp)
//        Lp = Lp->next;
//    while (Lp) {
//        Lp->val = (Lp->val + carry) % 10;
//        carry = Lp->val / 10;
//        Lp = Lp->next;
//    }
//    if (carry) {
//        Lp = (struct ListNode*)malloc(sizeof(struct ListNode));
//        Lp->val = 1;
//        Lp->next = NULL;
//    }
//
//    return &L;
//}

//int maxVowels(char* s, int k) {
//    int ch[128];
//    memset(ch, 0, sizeof(int) * 128);
//    ch['a'] = ch['e'] = ch['i'] = ch['o'] = ch['u'] = 1;
//    int len = strlen(s);
//
//    int max = 0;
//    for (int i = 0; i < k; i++) {
//        max += ch[s[i]];
//    }
//    int tmp = max;
//    for (int i = 1; i < len - k && k != max; i++) {
//        tmp -= ch[s[i - 1]];
//        tmp += ch[s[i + k - 1]];
//        max = (tmp > max ? tmp : max);
//    }
//
//    return max;
//}

//int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
//    double avg = 0.0;
//    int count = 0;
//    for (int i = 0; i < arrSize; i++) {
//        avg += arr[i] / (double)k;
//        if (i < k - 1)
//            continue;
//        if ((int)avg > threshold)
//            count++;
//        avg -= arr[i - k + 1] / (double)k;
//    }
//    return count;
//}

//int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
//    int* avgs = (int*)malloc(sizeof(int) * numsSize);
//    int avg = 0, j = 0;
//    *returnSize = numsSize;
//
//    for (int i = 0; i < numsSize; i++) {
//        avg += nums[i];
//        if (i < k)
//            avgs[j++] = -1;
//        if (i < 2 * k)
//            continue;
//        avgs[j++] = (k ? avg / (2*k) : avg);
//        avg -= nums[i - (2 * k)];
//    }
//    for (int i = j; i < numsSize; i++)
//        avgs[i] = -1;
//
//    return avgs;
//}

//int minimumRecolors(char* blocks, int k) {
//    int min = k;
//    int tmp = 0;
//    for (int i = 0; blocks[i]; i++) {
//        if (blocks[i] == 'W')
//            tmp++;
//        if (i < k - 1)
//            continue;
//        min = (min < tmp ? min : tmp);
//        if (blocks[i - k + 1] == 'B')
//            tmp--;
//    }
//    return min;
//
//}

long long maxSum(int* nums, int numsSize, int m, int k) {
    long long max = INT_MIN, tmp = 0, uni = 1;
    for (int i = 0; i < numsSize; i++) {
        uni = 0;
        tmp += nums[i];
        if (i < k - 1)
            continue;
        for (int j = i - 1; j >= i - k + 1; j--) {
            if (nums[i] != nums[j])
                uni++;
        }
        if (uni >= m)
            max = max > tmp ? max : tmp;
        tmp -= nums[i - k + 1];
    }
    return tmp;
}

int main()
{
    int arr[] = { 1,1,4,4 };
    int len = sizeof(arr) / sizeof(arr[0]);
    maxSum(arr, len, 3, 3);
   
    

 /*   moveZeroes(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }*/
    printf("\n");

	return 0;
}


