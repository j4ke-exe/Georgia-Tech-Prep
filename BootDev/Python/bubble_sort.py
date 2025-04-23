def bubble_sort(nums):
    n = len(nums)
    if n <= 1:
        return nums

    swapped = True

    while swapped:
        swapped = False

        for i in range(n - 1):
            if nums[i] > nums[i + 1]:
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
                swapped = True

        if not swapped:
            break

    return nums
