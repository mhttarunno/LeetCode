import math
class Solution:
    def maxx(self, v):
        mx = v[0]
        for i in range(1, len(v)):
            mx = max(mx, v[i])
        return mx

    def func(self, v, hourly):
        THours = 0
        for i in range(len(v)):
            THours += math.ceil(v[i] / hourly)
        return THours

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if not piles:
            return 0

        low, high = 1, self.maxx(piles)
        ans = float('inf')

        while low <= high:
            mid = low + (high - low) // 2
            totalHours = self.func(piles, mid)

            if totalHours <= h:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans    