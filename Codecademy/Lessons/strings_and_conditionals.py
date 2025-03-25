def contains(big_string, little_string):
  if little_string in big_string:
    return True
  else:
    return False

def common_letters(string_one, string_two):
  letters = []
  for letter in string_one:
    if (letter in string_two) and not (letter in letters):
      letters.append(letter)
  return letters

print(common_letters("banana", "cream"))