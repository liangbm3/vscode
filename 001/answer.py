class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        index=0
        for i in range(len(nums)):
            sum=nums[index]
            for k in range(i+1,len(nums)):
                sum=sum+nums[k]
                if sum==target:
                    return [index,k]
                else:
                    sum=nums[index]
                    i=i+1
            index+=1

if __name__=="__main__":
    SO=Solution()
    answer=SO.twoSum(nums=[0,4,3,0],target=0)
    print(answer)
    