class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        n=len(nums)
        dic = {}
        for right in range(n):
            current=nums[right]
            if (current in dic):
                if (abs(dic[current]-right)<=k):
                    return True
                else:
                    dic[current]=right
            else:
                dic[current] =right
        return False
                
                
        return False