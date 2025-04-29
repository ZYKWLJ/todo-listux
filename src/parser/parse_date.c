#include "../../include/include.h"

void parse_date(Date_Type date_type, char *date_str, Date *date)
{
    // Date date = {0};
    switch (date_type)
    {
    case DAY:
        validate_date_format(date_str, date);
        break;
    case WEEK:
        validate_week_format(date_str, date);
        break;
    case MONTH:
        validate_year_month_format(date_str, date);
        break;
    case YEAR:
        validate_year_format(date_str, date);
        break;
    }
    // return;
}
