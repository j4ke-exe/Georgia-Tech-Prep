# Lambda is essentially a defined function, simplified
# def func(parameter): is the same as lambda x: expression

# Strings with lambda
greeting = lambda name: f"Hello, {name}!"

print(greeting(input("What's your name? ")))


# Math Operators with Lambda
add = lambda x, y: x + y # Passes values into x, y parameter's and adds them
print(add(10, 20))


# Squared Numbers with Lambda Function
numbers = [1, 2, 3, 4, 5] # Number list

squared = list(map(lambda x: x ** 2, numbers))
print(squared)

# Filter List of Even Numbers
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

even_numbers = list(filter(lambda x: x % 2 == 0, numbers)) # If remainder of x in numbers is 0, then filter x to even_numbers
print(even_numbers)

# Sort Tuples
students = [("Bob", "A", 10), ("Dave", "B", 11), ("Alice", "A", 9)]

sorted_grade = sorted(students, key=lambda x: x[2]) # Sorts students list by youngest age (2nd key or x[2])
print(sorted_grade)