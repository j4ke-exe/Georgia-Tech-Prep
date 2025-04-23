spouse_1 = "Caitlin"
spouse_2 = "David"
month = "November"
day = 3
year = 2012
time = "5:00PM"

#You may modify the lines of code above, but don't move them!
#When you Submit your code, we'll change these lines to
#assign different values to the variables.
#
#The variables above give some information about a wedding:
#the names of the spouses and the month, day, year, and time
#of the wedding.
#
#Add some code that will write the text to appear on a wedding
#invitation based on these values. For the values shown above,
#this would read:
#
#You are cordially invited to attend the wedding of Caitlin and David, to take place on November 3, 2012 at 5:00PM.
#
#Note that all components of this statement are required: start
#"You are cordially invited to attend the wedding of ", followed
#by spouse_1's name, followed by " and ", followed by spouse_2's
#name, then a comma and space, followed by "to take place on ",
#followed by the month, a space, the day, a comma and space, the
#year, a space, the word "at", a space, the time, and then a
#period.
#
#HINT: Copy the sentence below and replace the current values
#(Caitlin, David, November, etc.) with variables to reduce the
#risk of typoes throwing off your answers.


#Add your code here!
print("You are cordially invited to attend the wedding of", str(spouse_1), "and", str(spouse_2) + ", to take place on", month, str(day) + ",", year, "at", str(time) + ".")
