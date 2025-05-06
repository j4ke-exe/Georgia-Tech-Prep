"""
Task:
  Given n names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers.
  You will then be given an unknown number of names to query your phone book for. For each name queried, print the associated 
  entry from your phone book on a new line in the form name=phoneNumber; if an entry for name is not found, print Not found instead.

Note:
  Your phone book should be a Dictionary/Map/HashMap data structure.

Input Format:
  The first line contains an integer, n, denoting the number of entries in the phone book.
  Each of the n subsequent lines describes an entry in the form of 8 space-separated values on a single line.
  The first value is a friend's name, and the second value is an -digit phone number.

  After the n lines of phone book entries, there are an unknown number of lines of queries. Each line (query) contains a name to look 
  up, and you must continue reading lines until there is no more input.

Note:
  Names consist of lowercase English alphabetic letters and are first names only.
"""

if __name__ == "__main__":
    n = int(input())
    phone_book = {}
    
    for _ in range(n):
        line = input().split()
        name = line[0]
        number = line[1]
        phone_book[name] = number
    
    while True:
        try:
            query_name = input()
            if query_name in phone_book:
                print(f"{query_name}={phone_book[query_name]}")
            else:
                print("Not found")
        except EOFError:
            break
        except Exception:
            break
