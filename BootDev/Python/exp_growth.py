def exponential_growth(n, factor, days):
    result = [] # Sets empty list
    current = n # Initializes current to n

    for day in range(0, days + 1): # Loops from 0 to x days
        result.append(current) # Append the current value to result
        growth = (current * factor) # Formula to calculate exponential growth
        current = growth # Assign the calculated growth: (For x days, growth factor * previous days value = current)
    return result

# Inputs: n: 10, factor: 2, days: 4
# Output: [10, 20, 40, 80, 160]
