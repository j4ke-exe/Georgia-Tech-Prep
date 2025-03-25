import random

def magic_8ball(question):
    answer = random.randint(1, 9)
    
    match answer:
        case 1:
            response = "Yes - definitely."
        case 2:
            response = "It is decidedly so."
        case 3:
            response = "Without a doubt."
        case 4:
            response = "Reply hazy, try again."
        case 5:
            response = "Ask again later."
        case 6:
            response = "Better not tell you now."
        case 7:
            response = "My sources say no."
        case 8:
            response = "Outlook not so good."
        case 9:
            response = "Very doubtful."
        case _:
            response = "Error!"
    
    print(f"Response: {response}")
    return response

question = input("Ask your question: ")
magic_8ball(question)