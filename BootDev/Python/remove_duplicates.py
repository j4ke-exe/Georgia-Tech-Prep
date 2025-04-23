def remove_duplicates(nums):
    new_list = []
    seen = set()

    for num in nums:
        if num not in seen:
            new_list.append(num)
            seen.add(num)
    return new_list
