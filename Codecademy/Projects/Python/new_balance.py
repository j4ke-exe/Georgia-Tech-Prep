old_balance = "500.45"
deposit = "10"

#You may modify the lines of code above, but don't move them!
#When you Submit your code, we'll change these lines to
#assign different values to the variables.

#Imagine you're writing code for an ATM that accepts cash
#deposits. You need to update the customer's balance based
#on a deposit amount. However, both the old balance and the
#deposit are given as strings.
#
#Write code below that will print the new balance after the
#deposit is processed. This should be printed along with
#the following text labeling the amount:
#
#The new balance is: 510.45
#
#Note that the old balance will always include change, but
#the deposit will never include change because the ATM has
#no coin slot, only a slot for paper money.
#
#With the initial values of the variables shown above, your
#code should print the text shown on line 17.


#Add your code here!
new_balance = float(old_balance) + int(deposit)
print("The new balance is:", round(float(new_balance),2))
