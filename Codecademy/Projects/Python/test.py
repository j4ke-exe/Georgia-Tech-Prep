import random

def magic_8ball(question):
   response = random.randint(1, 9)
   
   match response:
      case 1:
         response = "Yes."
      case 2:
         response = "No."
      case 3:
         response = "Maybe."
      case 4:
         response = "Likely."
      case 5:
         response = "Most definitely!"
      case 6:
         response = "Decent Chance."
      case 7:
         response = "Sorry, doesn't look good."
      case 8:
         response = "50/50."
      case 9:
         response = "Meh."
   
   print(f"Your response: {response}")
   return response

question = input("Ask your question: ")
magic_8ball(question)
