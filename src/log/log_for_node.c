#include "../../include/include.h"
// 打印 DISPLAY_NODE 的日志函数
void printDisplayNodeLog(DISPLAY_NODE *displayNode)
{
    if (displayNode == NULL)
    {
        printf("DISPLAY_NODE is NULL\n");
        return;
    }
    printf("DISPLAY_NODE:\n");
    printf("  Date: ");
    switch (displayNode->date->date_type)
    {
    case YEAR:
        printf("%d (Year)\n", displayNode->date->year);
        break;
    case MONTH:
        printf("%d-%d (Month)\n", displayNode->date->year, displayNode->date->month);
        break;
    case WEEK:
        printf("%d-%d (Week)\n", displayNode->date->year, displayNode->date->week);
        break;
    case DAY:
        printf("%d-%d-%d (Day)\n", displayNode->date->year, displayNode->date->month, displayNode->date->day);
        break;
    case CURRENT_DAY:
        printf("Current Day: %d-%d-%d\n", displayNode->date->year, displayNode->date->month, displayNode->date->day);
        break;
    case ERROR_DATE_TYPE:
        printf("Error Date Type\n");
        break;
    default:
        break;
    }
}

// 打印 ADD_NODE 的日志函数
void printAddNodeLog(ADD_NODE *addNode)
{
    if (addNode == NULL)
    {
        printf("ADD_NODE is NULL\n");
        return;
    }
    printf("ADD_NODE:\n");
    printf("  Date: ");
    switch (addNode->date->date_type)
    {
    case YEAR:
        printf("%d (Year)\n", addNode->date->year);
        break;
    case MONTH:
        printf("%d-%d (Month)\n", addNode->date->year, addNode->date->month);
        break;
    case WEEK:
        printf("%d-%d (Week)\n", addNode->date->year, addNode->date->week);
        break;
    case DAY:
        printf("%d-%d-%d (Day)\n", addNode->date->year, addNode->date->month, addNode->date->day);
        break;
    case CURRENT_DAY:
        printf("Current Day: %d-%d-%d\n", addNode->date->year, addNode->date->month, addNode->date->day);
        break;
    case ERROR_DATE_TYPE:
        printf("Error Date Type\n");
        break;
    default:
        break;
    }
    printf("  Content: %s\n", addNode->content);
}

// 打印 DELETE_NODE 的日志函数
void printDeleteNodeLog(DELETE_NODE *deleteNode)
{
    if (deleteNode == NULL)
    {
        printf("DELETE_NODE is NULL\n");
        return;
    }
    printf("DELETE_NODE:\n");
    printf("  Date: ");
    switch (deleteNode->date->date_type)
    {
    case YEAR:
        printf("%d (Year)\n", deleteNode->date->year);
        break;
    case MONTH:
        printf("%d-%d (Month)\n", deleteNode->date->year, deleteNode->date->month);
        break;
    case WEEK:
        printf("%d-%d (Week)\n", deleteNode->date->year, deleteNode->date->week);
        break;
    case DAY:
        printf("%d-%d-%d (Day)\n", deleteNode->date->year, deleteNode->date->month, deleteNode->date->day);
        break;
    case CURRENT_DAY:
        printf("Current Day: %d-%d-%d\n", deleteNode->date->year, deleteNode->date->month, deleteNode->date->day);
        break;
    case ERROR_DATE_TYPE:
        printf("Error Date Type\n");
        break;
    default:
        break;
    }
    printf("  Number: %d\n", deleteNode->num);
}

// 打印 EDIT_NODE 的日志函数
void printEditNodeLog(EDIT_NODE *editNode)
{
    if (editNode == NULL)
    {
        printf("EDIT_NODE is NULL\n");
        return;
    }
    printf("EDIT_NODE:\n");
    printf("  Date: ");
    switch (editNode->date->date_type)
    {
    case YEAR:
        printf("%d (Year)\n", editNode->date->year);
        break;
    case MONTH:
        printf("%d-%d (Month)\n", editNode->date->year, editNode->date->month);
        break;
    case WEEK:
        printf("%d-%d (Week)\n", editNode->date->year, editNode->date->week);
        break;
    case DAY:
        printf("%d-%d-%d (Day)\n", editNode->date->year, editNode->date->month, editNode->date->day);
        break;
    case CURRENT_DAY:
        printf("Current Day: %d-%d-%d\n", editNode->date->year, editNode->date->month, editNode->date->day);
        break;
    case ERROR_DATE_TYPE:
        printf("Error Date Type\n");
        break;
    default:
        break;
    }
    printf("  Number: %d\n", editNode->num);
    printf("  Content: %s\n", editNode->content);
    printf("  Edit Type: ");
    switch (editNode->edit_type)
    {
    case EDIT_ALL:
        printf("EDIT_ALL\n");
        break;
    case EDIT_PREFIX:
        printf("EDIT_PREFIX\n");
        break;
    case EDIT_SUFFIX:
        printf("EDIT_SUFFIX\n");
        break;
    default:
        printf("UNKNOWN EDIT TYPE\n");
        break;
    }
}

// 打印 COMPLETE_NODE 的日志函数
void printCompleteNodeLog(COMPLETE_NODE *completeNode)
{
    if (completeNode == NULL)
    {
        printf("COMPLETE_NODE is NULL\n");
        return;
    }
    printf("COMPLETE_NODE:\n");
    printf("  Date: ");
    switch (completeNode->date->date_type)
    {
    case YEAR:
        printf("%d (Year)\n", completeNode->date->year);
        break;
    case MONTH:
        printf("%d-%d (Month)\n", completeNode->date->year, completeNode->date->month);
        break;
    case WEEK:
        printf("%d-%d (Week)\n", completeNode->date->year, completeNode->date->week);
        break;
    case DAY:
        printf("%d-%d-%d (Day)\n", completeNode->date->year, completeNode->date->month, completeNode->date->day);
        break;
    case CURRENT_DAY:
        printf("Current Day: %d-%d-%d\n", completeNode->date->year, completeNode->date->month, completeNode->date->day);
        break;
    case ERROR_DATE_TYPE:
        printf("Error Date Type\n");
        break;
    default:
        break;
    }
    printf("  Number: %d\n", completeNode->num);
}

// 打印 TOGGLE_NODE 的日志函数
void printToggleNodeLog(TOGGLE_NODE *toggleNode)
{
    if (toggleNode == NULL)
    {
        printf("TOGGLE_NODE is NULL\n");
        return;
    }
    printf("TOGGLE_NODE:\n");
    printf("  Date: ");
    switch (toggleNode->date->date_type)
    {
    case YEAR:
        printf("%d (Year)\n", toggleNode->date->year);
        break;
    case MONTH:
        printf("%d-%d (Month)\n", toggleNode->date->year, toggleNode->date->month);
        break;
    case WEEK:
        printf("%d-%d (Week)\n", toggleNode->date->year, toggleNode->date->week);
        break;
    case DAY:
        printf("%d-%d-%d (Day)\n", toggleNode->date->year, toggleNode->date->month, toggleNode->date->day);
        break;
    case CURRENT_DAY:
        printf("Current Day: %d-%d-%d\n", toggleNode->date->year, toggleNode->date->month, toggleNode->date->day);
        break;
    case ERROR_DATE_TYPE:
        printf("Error Date Type\n");
        break;
    default:
        break;
    }
    printf("  Number: %d\n", toggleNode->num);
}

// 打印 HELP_NODE 的日志函数
void printHelpNodeLog()
{
    printf("HELP_NODE\n");
}

// 打印 CONFIGURATION_NODE 的日志函数
void printConfigurationNodeLog(CONFIGURATION_NODE *configurationNode)
{
    if (configurationNode == NULL)
    {
        printf("CONFIGURATION_NODE is NULL\n");
        return;
    }
    printf("CONFIGURATION_NODE:\n");
    printf("  KEY: %s\n", configurationNode->KEY);
    printf("  VALUE: %s\n", configurationNode->VALUE);
}