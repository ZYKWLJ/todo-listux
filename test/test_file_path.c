#include "../include/include.h"
int main()
{

    printf("%s\n", get_appdata_path(2025, DATE_FILE));
    printf("%s\n", get_appdata_path(2025, SETTING_FILE));
}