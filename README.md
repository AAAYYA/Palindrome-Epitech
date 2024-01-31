#PALINDROME

Palindrome is a Epitech synthesis project. The goal of this project is to find the smallest number of operations to transform a number into a palindrome.
This project has a few flags

-n: The number to be transformed (must be greater than 0, and strictly positive)
-p: The palindrome to be obtained (incompatible with the -n flag)
-b: The base in which the operation is carried out (1 < b <= 10), which is equal to 10 by default
-imin: Minimum number of iterations, included (>= 0), which is equal to 0 by default
-imax: Maximum number of iterations, included (>= 0), which is equal to 100 by default

Example:
./palindrome -n 10 -b 10 -imin 0 -imax 100

10 leads to 1 in 1 iteration(s) in base 10

Usage:
./palindrome -n number -p palindrome [-b base] [-imin i] [-imax i]
./palindrome -h

Description:
-n n       integer to be transformed (>=0)
-p pal     palindromic number to be obtained (incompatible with the -n option) (>=0)
            if defined, all fitting values of n will be output
            only the smallest number of iterations to reach the palindrome will be output
-b base    base in which the procedure will be executed (1<b<=10) [def: 10]
-imin i    minimum number of iterations, included (>=0) [def: 0]

Use make help to see the available commands of the Makefile

Check the bonus folder if you want to see a few bonuses I added to this project, use the bonus README

