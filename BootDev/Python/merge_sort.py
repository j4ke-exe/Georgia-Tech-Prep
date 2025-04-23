def merge_sort(nums):
    # Base case: List is already sorted if it has 0 or 1 element
    if len(nums) < 2:
        return nums

    # Divide: Find the middle point and split the list
    middle_index = len(nums) // 2
    left_index = nums[0:middle_index]
    right_index = nums[middle_index:]

    # Conquer: Revursively sort each half
    sorted_left = merge_sort(left_index)
    sorted_right = merge_sort(right_index)

    # Combine: Merge the sorted halves
    merged_list = merge(sorted_left, sorted_right)

    return merged_list


def merge(first, second):
    merged_list = []
    i = 0
    j = 0

    # Compare elements while both lists have elements left
    while i < len(first) and j < len(second):
        if first[i] <= second[j]:
            merged_list.append(first[i])
            i += 1
        else:
            merged_list.append(second[j])
            j += 1

    # Append any remaining elements from sorted_left
    while i < len(first):
        merged_list.append(first[i])
        i += 1

    # Append any remaining elements from sorted_right
    while j < len(second):
        merged_list.append(second[j])
        j += 1
    
    return merged_list
