# 'Key = position' and 'Value = percent' for key:value pair
pct_women_in_occupation = {\
"CEO": 28, "Engineering Manager": 9, "Pharmacist": 58, \
"Physician": 40, "Lawyer": 37, "Aerospace Engineer": 9}

# .items() returns a dict_list object to get both key:value
for position, percent in pct_women_in_occupation.items():
   print(f"Women make up {percent} percent of {position}'s.")