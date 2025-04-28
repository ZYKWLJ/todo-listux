#include "../include/include.h"

int main()
{
    // Allocate memory
    All_Files *all_files = (All_Files *)malloc(sizeof(All_Files));
    if (all_files == NULL)
    {
        perror("Memory allocation failed: all_files");
        return 1;
    }
    all_files->total_file_year_date = (Total_File_Year_Date *)malloc(sizeof(Total_File_Year_Date));
    if (all_files->total_file_year_date == NULL)
    {
        perror("Memory allocation failed: all_files->total_file_year_date");
        free(all_files);
        return 1;
    }
    all_files->setting = (Setting *)malloc(sizeof(Setting));
    if (all_files->setting == NULL)
    {
        perror("Memory allocation failed: all_files->setting");
        free(all_files);
        return 1;
    }
    all_files->setting->color = (SettingItem *)malloc(sizeof(SettingItem));
    if (all_files->setting->color == NULL)
    {
        perror("Memory allocation failed: all_files->setting->color");
        free(all_files->setting);
        free(all_files);
        return 1;
    }
    all_files->setting->show = (SettingItem *)malloc(sizeof(SettingItem));
    if (all_files->setting->show == NULL)
    {
        perror("Memory allocation failed: all_files->setting->show");
        free(all_files->setting->color);
        free(all_files->setting);
        free(all_files);
        return 1;
    }
    printf("malloced ok: %p\n", all_files->setting->color);
    // Initialize the allowed values of the settings
    set_settings_init(all_files->setting);
    printf("setting init ok: %p\n", all_files->setting->color);

    // Create a configuration node
    CONFIGURATION_NODE node;
    node.KEY = "color";
    node.VALUE = "o4ff";

    // Call the settings function
    int result = set_settings(all_files->setting, &node);
    printf("setting set ok: %p\n", all_files->setting->color);

    switch (result)
    {
    case 1:
        printf("Settings updated successfully!\n");
        printf("The color setting is: %s\n", all_files->setting->color->value_set);
        break;
    case 0:
        printf("No corresponding key -- %s!\n", node.KEY);
        printf("Setting failed\n");
        break;
    case 2:
        printf("No corresponding value -- %s!\n", node.VALUE);
        printf("Setting failed\n");
        break;
    }
    // Free the memory
    free(all_files->total_file_year_date);
    free(all_files->setting->color);
    free(all_files->setting->show);
    free(all_files->setting);
    free(all_files);

    return 0;
}

// gcc