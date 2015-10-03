"""
Filename: Huynh_Kerns_Assignment4_5.py
Assignment Name: Improved Fox and Rabbit Simulation
Author: Peter Tran Huynh
Description: This is improved version of assignment 4, which simulated the fox and rabbit prey/predator relationship. In this version, more calculations are made to display averages 
Partner: Evan Karl Kerns
"""
import math

def main():
	rBr = 0.01		# Rabbit birth rate without predation
	fBr = 0.005		# Fox birth rate 
	I = 0.00001		# INTERACT I is the likelihood that a rabbit and fox will meet
	S = 0.01		# SUCCESS S is the likelihood that when a fox & rabbit meet that the fox catches the rabbit
	
	R = eval(input("\nPlease enter the initial rabbit population: "))					# R is the current rabbit population
	F = eval(input("Please enter the initial foxes population: "))						# F is the current fox population
	D = eval(input("Please enter the number of days to run the simulation: "))			# D is the number of days to run the simulation
	Fr = int(input("Please enter the frequency of days for displaying data: "))		# Fr is how often to display results in the table, does not impact calculations display always starts with initial populations	
	rR, fR, cR = R, R, R	# Rabbit Population values for round, floor, ceiling
	rF, fF, cF = F, F, F	# Fox Population values for round, floor, ceiling
	
	# The first values in the list are the starting populations entered by the user
	rR_List = [round(rR)]				# Lists to contain the populations from the rounding calculations
	rF_List = [round(rF)]
	fR_List = [math.floor(fR)]			# Lists to contain the populations from the floored calculations
	fF_List = [math.floor(fF)]
	cR_List = [math.ceil(cR)]			# Lists to contain the populations from the ceiling calculations
	cF_List = [math.ceil(cF)]
	R_List = [R]						# Lists to contain the populations from the raw calculations
	F_List = [F]
	
	for i in range(1, D + 1):
		# Computes the new number of rabbits and foxes for the day and round the results
		chR_r = round(rBr * rR - I * rR * rF)
		chF_r = round(I * S * rR * rF - fBr * rF)
		rR = rR + chR_r
		rF = rF + chF_r
		rR_List.append(round(rR))
		rF_List.append(round(rF))
		
		# Computes the new number of rabbits and foxes for the day and take the ceiling of results
		chR_c = math.ceil(rBr * cR - I * cR * cF)
		chF_c = math.ceil(I * S * cR * cF - fBr * cF)
		cR = cR + chR_c
		cF = cF + chF_c
		cR_List.append(math.ceil(cR))
		cF_List.append(math.ceil(cF))
		
		# Computes the new number of rabbits and foxes for the day and take the floor of results
		chR_f = math.floor(rBr * fR - I * fR * fF)
		chF_f = math.floor(I * S * fR * fF - fBr * fF)
		fR = fR + chR_f
		fF = fF + chF_f
		fR_List.append(math.floor(fR))
		fF_List.append(math.floor(fF))
		
		# Computes the new number of rabbits and foxes for the day and leave as a fraction
		chR = (rBr * R - I * R * F)
		chF = (I * S * R * F - fBr * F)
		R = R + chR
		F = F + chF
		R_List.append(R)
		F_List.append(F)

	# Calculating all of the averages
	rR_Avg = sum(rR_List[ : ]) / len(rR_List)
	rF_Avg = sum(rF_List[ : ]) / len(rF_List)
	fR_Avg = sum(fR_List[ : ]) / len(fR_List)
	fF_Avg = sum(fF_List[ : ]) / len(fF_List)
	cR_Avg = sum(cR_List[ : ]) / len(cR_List)
	cF_Avg = sum(cF_List[ : ]) / len(cF_List)
	R_Avg = sum(R_List[ : ]) / len(R_List)
	F_Avg = sum(F_List[ : ]) / len(F_List)
	
	# Print out the averages
	print("\nRounded Population Averages:")
	print("{:9s}{:>10.3f}".format("Rabbits:", rR_Avg))
	print("{:9s}{:>10.3f}".format("Foxes:", rF_Avg))
	print("\nFloor Population Averages:")
	print("{:9s}{:>10.3f}".format("Rabbits:", fR_Avg))
	print("{:9s}{:>10.3f}".format("Foxes:", fF_Avg))
	print("\nCeil Population Averages:")
	print("{:9s}{:>10.3f}".format("Rabbits:", cR_Avg))
	print("{:9s}{:>10.3f}".format("Foxes:", cF_Avg))
	print("\nRaW Population Averages:")
	print("{:9s}{:>10.3f}".format("Rabbits:", R_Avg))
	print("{:9s}{:>10.3f}".format("Foxes:", F_Avg))
	
	# Table Heading
	print()
	displayStr = "{:<10s}{:^20s}{:^19s}{:^20s}{:^29s}".format("", "Rounded Values", "Floor Values", "Ceil Values", "Raw Values")
	print(displayStr)
	displayStr = "{:>10s}{:>10s}{:>10s}{:>10s}{:>10s}{:>10s}{:>10s}{:>15s}{:>15s}".format("Day", "Rabbits", "Foxes", "Rabbits", "Foxes", "Rabbits", "Foxes", "Rabbits", "Foxes")
	print(displayStr)
	print("-" * 100)
	
	# for-loop to print out the values using the frequency that the user specified
	for i in range(0, D + 1, Fr):
		displayStr = "{:>10s}{:>10s}{:>10s}{:>10s}{:>10s}{:>10s}{:>10s}{:>5s}{:>10.3f}{:>5s}{:>10.3f}".format(str(i), str(rR_List[i]), str(rF_List[i]), str(fR_List[i]), str(fF_List[i]), str(cR_List[i]), str(cF_List[i]), "", R_List[i], "", F_List[i])
		print(displayStr)
	print()
main()
