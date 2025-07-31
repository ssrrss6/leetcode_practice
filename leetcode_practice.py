# def check(points, s, l):
#     cnt = defaultdict(int)
#     i = 0
#     for p in points:
#         if abs(p[0]) <= l and abs(p[1]) <= l:
#             cnt[s[i]] += 1
#             if cnt[s[i]] == 2:
#                 return False
#         i += 1
#
#     return True
#
#
# class Solution:
#     def maxPointsInsideSquare(self, points: list[list[int]], s: str) -> int:
#         left = 0
#         right = 0
#         for p in points:
#             right = max(right, max(p))
#
#         while left < - right:
#             mid = (left + right) // 2
#
#             if check(points, s, mid):
#                 left = mid + 1
#             else:
#                 right = mid - 1
#
#         ans = 0
#         for p in points:
#             if abs(p[0]) <= right and abs(p[1]) <= right:
#                 ans += 1
#
#         return ans
#
#
# points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]]
# s = "abdca"
# getNums = Solution()
# getNums.maxPointsInsideSquare(points, s)


# class Solution:
#     def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
#         row = defaultdict(int)
#         col = defaultdict(int)
#
#         r = len(grid)
#         c = len(grid[0])
#
#         for i in range(r):
#             for j in range(c):
#                 row[i] += grid[i][j]
#         for j in range(c):
#             for i in range(r):
#                 col[j] += grid[i][j]
#
#         ans = 0
#         for i in range(r):
#             for j in range(c):
#                 row[i] -= grid[i][j]
#                 col[j] -= grid[i][j]
#                 if grid[i][j]:
#                     ans += row[i] * col[j]
#
#         return ans
#
#
# grid = [[0,1,0],[0,1,1],[0,1,0]]
# test = Solution()
# test.numberOfRightTriangles(grid)


# class Solution:
#     def matrixBlockSum(self, mat: list[list[int]], k: int) -> list[list[int]]:
#         m = len(mat)
#         n = len(mat[0])
#
#         s = [[0] * (n + 1) for _ in range(m + 1)]
#         for i, row in enumerate(mat):
#             for j, x in enumerate(row):
#                 s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + x
#
#         answer = []
#         for i in range(m):
#             ans = []
#             for j in range(n):
#                 row1 = max(i - k, 0)
#                 col1 = max(j - k, 0)
#                 row2 = min(i + k, m - 1)
#                 col2 = min(j + k, n - 1)
#
#                 ans.append(s[row2 + 1][col2 + 1] - s[row2 + 1][col1] - s[row1][col2 + 1] + s[row1][col1])
#             answer.append(ans)
#
#         return answer
#
# mat = [[1,2,3],[4,5,6],[7,8,9]]
# k = 1
# test = Solution()
# test.matrixBlockSum(mat, k)

from collections import defaultdict

class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        d = defaultdict(int)

        for l, r in intervals:
            d[l] += 1
            d[r] -= 1

        ans = []
        tmp = [0, 0]
        s = 0
        for k in sorted(d):
            s += d[k]
            if d[k] > 0 and s == 1:
                tmp[0] = k
            elif d[k] < 0 and s == 0:
                tmp[1] = k
                ans.append(tmp.copy())

        return ans

intervals = [[1,4],[0,0]]
test = Solution()
test.merge(intervals)