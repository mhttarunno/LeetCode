class Solution:
    def findMedianSortedArrays(self, v, vv):
        if len(v) > len(vv):
            return self.findMedianSortedArrays(vv, v)  # swap

        low, high = 0, len(v)
        left = (len(v) + len(vv) + 1) // 2
        total = len(v) + len(vv)

        while low <= high:
            mid1 = low + ((high - low) >> 1)
            mid2 = left - mid1

            l1 = float('-inf')
            l2 = float('-inf')
            r1 = float('inf')
            r2 = float('inf')

            if mid1 < len(v):
                r1 = v[mid1]
            if mid2 < len(vv):
                r2 = vv[mid2]
            if mid1 - 1 >= 0:
                l1 = v[mid1 - 1]
            if mid2 - 1 >= 0:
                l2 = vv[mid2 - 1]

            if l1 <= r2 and l2 <= r1:
                if total & 1:
                    return max(l1, l2)
                else:
                    return (max(l1, l2) + min(r1, r2)) / 2.0
            elif l1 > r2:
                high = mid1 - 1
            else:
                low = mid1 + 1

        return 0.0
