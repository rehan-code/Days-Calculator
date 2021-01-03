Description:
These programs output the number of days between the 2 dates entered. only daysCalculatorE supports calculations in different year and is the final program that contains all the features.

To compile any days calculator:
$ make daysCalculatorX

where X can be A,B,C,D,E depending on which program you want.
or 'make all' for compiling all.

to run daysCalculatorA:
./daysCalculatorA dd1 mm1 yyyy1 dd2 mm2 yyyy2

to run daysCalculatorB:
./daysCalculatorB dd1 mm1 yyyy1 dd2 mm2 yyyy2 include
The include is optional if you want to include the start date in the calculations. Works in all programs from daysCalculatorB to daysCalculatorE.

to run daysCalculatorC:
./daysCalculatorC dd1-mm1-yyyy1 dd2-mm2-yyyy2

to run daysCalculatorD:
./daysCalculatorD today dd2-mm2-yyyy2
today can be replaced by any date for this and the next program.

to run daysCalculatorE:
./daysCalculatorC dd1-mm1-yyyy1 dd2-mm2-yyyy2

