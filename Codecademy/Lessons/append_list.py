def append_size(my_list):
   my_list.append(len(my_list))
   return my_list

print(append_size([23, 42, 108]))