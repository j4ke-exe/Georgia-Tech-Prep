balance = 500
income = 200
price = 1000
months = 6

#You may modify the lines of code above, but don't move them!
#When you Submit your code, we'll change these lines to
#assign different values to the variables.

#You're thinking of buying a new computer. The variables
#above represent the balance of your bank account, your
#monthly disposable income, the total price of the computer,
#and the number of months that the retailer will give you to
#pay off the computer.
#
#You can buy the computer if either (a) you can afford to
#buy the computer in cash right now (balance is greater than
#price), or (b) you can afford the monthly payments (income
#is greater than price divided by months).
#
#In other words, if a computer cost $1200 and you spread it
#out over 12 months, you would need your monthly available
#income to be at least $100 to buy the computer, or you
#would need your current bank balance to be at least $1200.
#
#Add some code below that will print True if you're able to
#afford the computer given the values above, and False if you
#are not.


#Add your code below!
print((balance > price) or (income >= (price/months)))