# Username Generator
def username_generator(first_name, last_name):
  if len(first_name) < 3:
    user_name = first_name
  else:
    user_name = first_name[:3]
  if len(last_name) < 4:
    user_name = user_name + last_name
  else:
    user_name = user_name + last_name[:4]
  return user_name

print(username_generator("Jake", "Garrison"))


# Password Generator
def password_generator(user_name):
  password = ""
  for char in range(0, len(user_name)):
    password += user_name[char-1]
  return password

print(password_generator("apple"))
