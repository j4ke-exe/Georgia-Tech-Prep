amount = 17

#You may modify the lines of code above, but don't move them!
#When you Submit your code, we'll change these lines to
#assign different values to the variables.
#
#The variable above describes an amount of money measured in
#dollars. Imagine you want to select the bills (1-dollar bills,
#5-dollar bills, 10-dollar bills, etc.) that make up that
#amount of money. For example, 17 dollars is one $10, one $5,
#and two $1s.
#
#Write a program that will print out the bills needed to
#arrive at the amount shown above. Assume that we always want
#the maximum number of large bills: for example, for 17 dollars,
#we want one $10, one $5, and two $1s, not three $5s and two $1s.
#You may assume that the largest bill you have on hand is a
#$50-dollar bill.
#
#Your code should print the following (with the correct numbers
#based on the value of amount):
#
#Fifties: 0
#Twenties: 0
#Tens: 1
#Fives: 1
#Ones: 2

#Add your code here!
fifties = amount // 50
remaining = amount % 50

twenties = remaining // 20
remaining %= 20

tens = remaining // 10
remaining %= 10

fives = remaining // 5
remaining %= 5

ones = remaining

# Print the results
print("Fifties:", fifties)
print("Twenties:", twenties)
print("Tens:", tens)
print("Fives:", fives)
print("Ones:", ones)