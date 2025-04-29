#include "../../include/include.h"
Date_Type parse_date_type(char *date_type)
{
    if (strcmp(date_type, "-day") == 0 || strcmp(date_type, "-d") == 0)
    {
        // date_type=DAY;
        return DAY;
    }
    else if (strcmp(date_type, "-week") == 0 || strcmp(date_type, "-w") == 0)
    {
        // date_type=WEEK;
        return WEEK;
    }
    else if (strcmp(date_type, "-month") == 0 || strcmp(date_type, "-m") == 0)
    {
        // date_type=MONTH;
        return MONTH;
    }
    else if (strcmp(date_type, "-year") == 0 || strcmp(date_type, "-y") == 0)
    {
        // date_type=YEAR;
        return YEAR;
    }
    else
    {
        return ERROR_DATE_TYPE;
    }
}