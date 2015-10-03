"""
Filename: Peter_Huynh_Assignment4.py
Assignment Name: Assignment Four: Foxes & Rabbits
Author: Peter Tran Huynh
Description: 
Notes: Assignment Cooperation with Jordon Prosky
"""
import math

# 1. Gather data from user, one value per input 
# 2. print out some header info here with labels for days, rabbits, foxes 
# 3. print out the starting simulation values
# 4. write a for-loop to iterate through the simulated days
# 5. calculate the new daily populations	
# 6. print out new day population information 
   
def run_simulation():	
	print()	# adds a newline for nicer output.

	rBr = 0.01		# Rabbit birth rate without predation
	fBr = 0.005		# Fox birth rate 
	I = 0.00001		# INTERACT I is the likelihood that a rabbit and fox will meet
	S = 0.01		# SUCCESS S is the likelihood that when a fox & rabbit meet that the fox catches the rabbit
	DaysTable = 0	# Days displayed on the table.
	
	print("Hello, this is a predation simulator between Foxes and Rabbits.")

	R = eval(input("Please enter the initial rabbit population: "))
	print("You have entered: ", R)
	F = eval(input("Please enter the initial fox population: "))
	print("You have entered: ", F)
	D = eval(input("Please enter the number of days simulated: "))
	print("You have entered: ", D)
	
	print("The starting population of rabbits are: ", R)
	print("The starting population of foxes are: ", F, "\n")
	
	print("Day\t\t Rabbits\t Foxes")
	print("-------------------------------------------")
	for i in range(D+1):
		cR = ((rBr * R) - (I * R * F))
		cF = ((I * S * R * F) - (fBr * F))
		print(DaysTable, "\t\t", R, "\t\t", F)
		R = round(R + cR)
		F = round(F + cF)
		DaysTable = DaysTable + 1
		
	print()

run_simulation()
