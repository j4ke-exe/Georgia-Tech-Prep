num1 = 6
num2 = 3

result = (lambda x, y: x + y, num1, num2)

if result != 10:
   not_ten = True
else:
   not_ten = False
   
print(f"Is the sum of the numbers not equal to 10? {not_ten}")