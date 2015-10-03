/**
	Author: Peter Huynh
	File Name: AssignmentNine.java
	Assignment: 9 -– First Java Program
	Description: A Java converted version of a small Python program (Assignment 3).
*/

import java.text.*;
import java.util.*;

public class AssignmentNine
{
	
	public static void main(String[] args) throws java.lang.Exception
	{
		DecimalFormat rounded = new DecimalFormat("###.##");
		DecimalFormat whole = new DecimalFormat("###");
		
		System.out.println("\r\nThis program calculates the future value of an investment.\r\n");
		
		System.out.println("Enter the initial principal: ");
		Scanner princ = new Scanner(System.in); 
		double principal = princ.nextDouble();
		
		System.out.println("Enter the interest rate: ");
		Scanner rt = new Scanner(System.in); 
		double rate = rt.nextDouble();
		
		System.out.println("Enter the number of compounding periods per year: ");
		Scanner prd = new Scanner(System.in); 
		double periods = prd.nextDouble();
		
		System.out.println("Enter the number of years: ");
		Scanner yrs = new Scanner(System.in); 
		double years = yrs.nextDouble();
		
		System.out.println("\r\n");
		princ.close();
		rt.close();
		prd.close();
		yrs.close();
		
		for(int calc = 0; calc < (years * periods); calc++)
		{
			double interest = (principal * (rate/periods));
			principal += interest;
			System.out.println("Year " + whole.format(Math.floor((calc/periods) + 1)) + " period " + ((calc % 4) + 1) + " interest earned: " + rounded.format(interest));
		}
		
		System.out.println("\nThe amount in " + whole.format(years) + " years is: $" + rounded.format(principal));
		
	}
}