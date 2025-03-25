def greetings(names):
   name_list = []
   for name in names:
      name_list.append(f"Hello, {name}.")
   return name_list

print(greetings(["Dave", "Alice", "James", "Mark"]))