#ifndef __CALCULATE_DAYS__
#define __CALCULATE_DAYS__
typedef enum month {Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec} Month; //enum allow us to define a data type
//with typedef I can give alias.


int calculateDays(Month, int, int);
int isLeapYear(int);
#endif
