// #include "All_Files.h"

#include "../../include/include.h"

void set_all_files(All_Files *all_files, Total_File_Year_Date *total_file_year_date, Setting *setting)
{
    if (all_files == NULL)
    {
        LOG_PRINT("all_files is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (total_file_year_date == NULL)
    {
        LOG_PRINT("total_file_year_date is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (setting == NULL)
    {
        LOG_PRINT("setting is NULL\n");
        exit(EXIT_FAILURE);
    }
    all_files->total_file_year_date = total_file_year_date;
    all_files->setting = setting;
}

void free_all_files(All_Files *all_files)
{
    if (all_files == NULL)
    {
        LOG_PRINT("all_files is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (all_files->total_file_year_date == NULL)
    {
        LOG_PRINT("all_files->total_file_year_date is NULL\n");
        exit(EXIT_FAILURE);
    }
    if (all_files->setting == NULL)
    {
        LOG_PRINT("all_files->setting is NULL\n");
        exit(EXIT_FAILURE);
    }
    free_total_file_year_date(all_files->total_file_year_date);
    free(all_files->setting);
    free(all_files);
}
