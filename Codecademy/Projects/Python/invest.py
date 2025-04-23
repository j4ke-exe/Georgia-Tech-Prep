goal = 50000
rate = 0.05
years = 5

#You may modify the lines of code above, but don't move them!
#When you Submit your code, we'll change these lines to
#assign different values to the variables.

#Earlier, we created a program that would calculate the
#value of an investment account after a certain period of
#time using the formula Amount = Principal * e^(Rate * Time).
#
#Let's revisit that, but let's flip the question around.
#Instead of asking, "What will the value of this account
#be?", let's instead ask, "How much do I need to invest to
#have a certain amount by a certain year?" For example,
#"How much do I need to invest to have $50,000 in 5 years
#at 5% (0.05) interest?"
#
#Add your code here!
import math

principal = goal / math.e ** (rate * years)

print("Saved: $" + "{:,.2f}".format(principal))
