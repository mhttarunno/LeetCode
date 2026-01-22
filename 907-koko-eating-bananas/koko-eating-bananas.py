import math
class Solution:
    def func(self, v, hourly):
        THours = 0
        for i in range(len(v)):
            THours += math.ceil(v[i] / hourly)
        return THours

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        if not piles:
            return 0

        low, high = 1, max(piles)
        ans = float('inf')

        while low <= high:
            mid = low + ((high - low) >> 1)
            totalHours = self.func(piles, mid)

            if totalHours <= h:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1

        return ans    