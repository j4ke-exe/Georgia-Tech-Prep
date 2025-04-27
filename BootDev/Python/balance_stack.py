from stack import Stack

def is_balanced(input_str):
    my_stack = Stack()

    for char in input_str:
        if char == "(":
            my_stack.push(char)
        elif char == ")":
            if my_stack.pop() is None:
                return False
  
    return my_stack.peek() is None
