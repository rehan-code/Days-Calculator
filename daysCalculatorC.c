#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 *   Program name: daysCalculatorC.c
 *   Author: Rehan Nagoor Mohideen
 *   Student ID: 1100592
 *   Function: to find the number of days between two dates of the same year
 *   Compilation: gcc -ansi -o daysCalculatorC daysCalculatorC.c
 */

int main ( int argc, char *argv[] ) {

   /* The number of days in each month */
   int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   int DayofYear[12] = { 1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };

   int dd1 = 0;
   int mm1 = 0;
   int yyyy1 = 0;
   int dd2 = 0;
   int mm2 = 0;
   int yyyy2 = 0;
   int StartDayofYear = 0;
   int EndDayofYear = 0;
   int NoofDays = 0;
   bool include = false;

   char dayStr1[3];
   char dayStr2[3];
   char monthStr1[3];
   char monthStr2[3];
   char yearStr1[5];
   char yearStr2[5];

   if (argc == 4 && strcmp("include", argv[3]) == 0 ) {
     include = true ;
   } else if (argc != 3 ) {
     printf ( "Error - Input not in valid format of: dd1-mm1-yyy1 dd2-mm2-yyyy2 (include)\n" );
     exit ( 1 );
   }

   dayStr1[0] = argv[1][0];
   dayStr1[1] = argv[1][1];
   dayStr1[2] = '\0';
   monthStr1[0] = argv[1][3];
   monthStr1[1] = argv[1][4];
   monthStr1[2] = '\0';
   yearStr1[0] = argv[1][6];
   yearStr1[1] = argv[1][7];
   yearStr1[2] = argv[1][8];
   yearStr1[3] = argv[1][9];
   yearStr1[4] = '\0';
   dayStr2[0] = argv[2][0];
   dayStr2[1] = argv[2][1];
   dayStr2[2] = '\0';
   monthStr2[0] = argv[2][3];
   monthStr2[1] = argv[2][4];
   monthStr2[2] = '\0';
   yearStr2[0] = argv[2][6];
   yearStr2[1] = argv[2][7];
   yearStr2[2] = argv[2][8];
   yearStr2[3] = argv[2][9];
   yearStr2[4] = '\0';

   dd1 = atoi ( dayStr1 );
   mm1 = atoi ( monthStr1 );
   yyyy1 = atoi ( yearStr1 );
   dd2 = atoi ( dayStr2 );
   mm2 = atoi ( monthStr2)  ;
   yyyy2 = atoi ( yearStr2 );



   if (yyyy1 % 4 == 0 && (!(yyyy1 % 100 == 0) || yyyy1 % 400 == 0)) {
      monthLength[1]=29;
      DayofYear[2] = 61;
      DayofYear[3] = 92;
      DayofYear[4] = 122;
      DayofYear[5] = 153;
      DayofYear[6] = 183;
      DayofYear[7] = 214;
      DayofYear[8] = 245;
      DayofYear[9] = 275;
      DayofYear[10] = 306;
      DayofYear[11] = 336;
   }

   if ( mm1 > 12 || mm1 < 1 ){
      printf ("Error - the month entered (%d) is not in the proper range (1-12) \n", mm1);
      exit (1);
   } else if ( dd1>monthLength[mm1-1] || dd1<1  ){
      printf ("Error - you entered %d for the day and that is not in the range (1-%d) \n", dd1, monthLength[mm1-1]);
      exit (1);
   } else if ( mm2 > 12 || mm2 < 1 ){
      printf ("Error - the month entered (%d) is not in the proper range (1-12) \n", mm2);
      exit (1);
   } else if ( dd2>monthLength[mm2-1] || dd2<1  ){
      printf ("Error - you entered %d for the day and that is not in the range (1-%d) \n", dd2, monthLength[mm2-1]);
      exit (1);
   }


   StartDayofYear = DayofYear[mm1 - 1] + (dd1 - 1);
   EndDayofYear = DayofYear[mm2 - 1] + (dd2 - 1);

   if (StartDayofYear > EndDayofYear) {
     printf ("Error - start date is after end date \n");
     exit ( 1 );
   } else if (StartDayofYear == EndDayofYear) {
     NoofDays = 0;
   } else {
     NoofDays = EndDayofYear - StartDayofYear;
   }

   if (include == true) {
     NoofDays = NoofDays + 1;
   }

   printf ("%d \n", NoofDays);

   return (0);
}
