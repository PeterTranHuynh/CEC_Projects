"""
Filename: Peter_Huynh_Assignment3.py
Assignment Name: Assignment 3 - First Python 3
Author: Peter Tran Huynh
Description: A program to compute the value of compound interest in years and periods
Notes: Assignment Cooperation with Jordon Prosky
"""

# Step 1: it isn't always a 10 year investment now, change this so it makes sense
# Step 2: there isn't an annual interest rate now, so change this 
#	variable name and input string prompt to something more appropriate.
# Step 3: add a statement below to get the number of compound periods
# Step 4: add a statement below to get the number of years for the investment
# Step 5: the for-loop is no longer always going to execute 10 times
#  You need to change the expression inside range to make the
#  loop iterate the correct number of times	 range(<expr>).
# Hint: You will use two variables entered by the user to do this.
# Step 6: The principal calculation needs to be updated to use the
#	nominal interest rate instead of annual percentage rate
# Step 7: Change this print statement so that it displays the
#	number of years the user enters

def main():
	# Investment = Principal * (1 + (Interest Rate/Compount Periods per Year))^(Number of Years * Compound Periods per Year)
	print("This program calculates the future value of a compund investment.\n")
	principal = eval(input("Enter the initial principal: "))
	apr = eval(input("Enter the annual interest rate: "))
	period = eval(input("Enter the compound periods per year: "))
	years = eval(input("Enter the number of years: "))
	for i in range(years):
		principal = principal * (1 + (apr/period))**period
	print("The value in", years, "years is:", round(principal,2))

main()
