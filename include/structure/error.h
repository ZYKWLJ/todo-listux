#ifndef ERROR_H
#define ERROR_H
#include "../include.h"
/**
 * data descp: 是不是要给每一个节点都加上一个专属的报错信息？应该是的，这样可以更加灵活！
 */
typedef struct E_error_
{
    enum
    {
        no_error, /*这是最开始的，如果检测到不是他，那就有报错！*/
        error_node_type,
        error_date_out_of_bounds,
        error_date_format,
        error_node_id_out_of_bounds,
    } error_type;

    enum /*年月周日的格式都有可能错误的*/
    {
        error_date_formats_year,
        error_date_formats_month,
        error_date_formats_week,
        error_date_formats_day,
    } error_date_formats_type;

} *E_error;

/**
* data descp: 总体思路就是按照node类型来进行的
*/

#endif