hot = True
cold = False
rainy = True
windy = False
snowy = False

#You may modify the lines of code above, but don't move them!
#When you Submit your code, we'll change these lines to
#assign different values to the variables.

#Earlier, you wrote a program that made clothing
#recommendations based on the weather. Your program could
#specifically recommend a jacket, boots, flip-flips, or a
#tshirt based on whether it was hot, cold, rainy, windy, or
#snowy.
#
#Let's add some accessories to that program: a hat, gloves,
#umbrella, and a scarf.
#
#Specifically, the program should recommend:
#
# - a hat if it's cold, or if it's hot but not rainy (cold
#   and rainy still means a hat, though).
# - gloves if it's cold and either snowy or rainy.
# - an umbrella if it's hot, snowy, or rainy.
# - a scarf if it's cold and windy or cold and snowy
#   unless it's rainy. Rain means no scarf regardless of
#   whether it's cold, windy, or snowy.
#
#Write some code below that will print four lines, one for
#each of the four types of clothing. The lines should look
#like this:
#
#Hat: True
#Gloves: True
#Umbrella: False
#Scarf: False
#
#The values (True and False) will differ based on the
#values assigned to hot, cold, windy, snowy, and rainy
#at the start of the program.


#Add your code here!
print("Hat:", cold or (hot and not rainy))
print("Gloves:", cold and (snowy or rainy))
print("Umbrella:", hot or snowy or rainy)
print("Scarf:", cold and (windy or snowy) and not rainy)