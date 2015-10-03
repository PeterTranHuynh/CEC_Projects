"""
Assignment Name: Assignment 2 - Small Steps
Author: Peter Tran Huynh
Description: This program processes the sum, difference, product and quotient of two numbers inputed by the user.
Additional Notes: This program displays basic math, input, and print functions of Python 2.0 (I placed a large comment section to compare these functions to the 3.0 counterpart)
Date: 04 September 2013
"""

# Step 1: write code to get one value from the user
#   Page 16 has an example of this  
# Step 2: write code to get a second value from the user
# Step 3: display output to user
#   Use one print statement per math operator (+, -, /, *)
#    Look at examples at the top of page 10, type them into a terminal and experiment


#Python 3.0
print("Hello! This program is designed to find the sum, difference, product, and quotient of two numbers.")
x = eval(input("Please enter a number: "))
print("The user entered:", x)
y = eval(input("Please enter a second number: "))
print("The user entered:", y)
print(x, " + ", y, " = ", x+y)
print(x, " - ", y, " = ", x-y)
print(x, " * ", y, " = ", x*y)
print(x, " / ", y, " = ", x/y)

"""
#Python 2.0
print"Hello! This program is designed to find the sum, difference, product, and quotient of two numbers."
x = input("Please' enter a number: ")
print"The user entered ", x
y = input("Please enter a second number: ")
print"The user entered ", y
print x, " + ", y, " = ", x+y
print x, " - ", y, " = ", x-y
print x, " * ", y, " = ", x*y
print x, " / ", y, " = ", x/y
"""
