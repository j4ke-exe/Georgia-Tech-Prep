def insertion_sort(nums):
    for i in range(1, len(nums)):
        index = nums[i]
        j = i - 1

        while j >= 0 and nums[j] > index:
            nums[j + 1] = nums[j]
            j = j - 1

        nums[j + 1] = index
        
    return nums
