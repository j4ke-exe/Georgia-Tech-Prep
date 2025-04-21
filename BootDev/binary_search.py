def binary_search(target, arr):
    n = len(arr)
    if n == 0:
        return False
        
    low = 0
    high = n - 1

    while low <= high:
        mid = (low + high) // 2
        middle_element = arr[mid]
        if middle_element == target:
            return True
        elif middle_element < target:
            low = mid + 1
        elif middle_element > target:
            high = mid - 1

    return False
