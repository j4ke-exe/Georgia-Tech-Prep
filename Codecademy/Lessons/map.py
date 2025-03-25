def double(x):
   return x * 2
numbers = range(1, 10)
double_numbers = map(double, numbers)
print(list(double_numbers))


# Convert Strings to Integers
str_nums = ["1", "2", "3", "4", "5"]
int_nums = list(map(int, str_nums))
print(int_nums)


# Find Length of Strings
words = ["apple", "orange", "mango"]
len_words = list(map(len, words))
print(len_words)


# map() with Lambda
numbers = range(0, 6)
doubled = list(map(lambda x: x * 2, numbers))
print(doubled)


# Multiple Iterables with Lambda using map()
list1 = [5, 10, 35]
list2 = [2, 9, 14]
result = list(map(lambda x, y: x + y, list1, list2))
print(result)