#include "../../../include/include.h"
// 允许出现的配置文件值
// 这里传入进来的一定是在堆上分配的！
// 这里只是初始化本身允许的设置！
void free_setting_item(SettingItem *item)
{
    if (!item)
        return;
    free(item->key);
    free(item->value_set);
    for (int i = 0; item->value_allow[i] != NULL; i++)
    {
        free(item->value_allow[i]);
    }
    free(item);
}

void free_setting(Setting *s)
{
    if (!s)
        return;
    free_setting_item(s->color);
    free_setting_item(s->show);
    free(s);
}
// set_settings_init 修正
void set_settings_init(Setting *settings)
{
    // 首先判断是不是存在了默认配置,这个不需要，因为我们一定会在后面加载默认配置的！

    if (!settings)
    {
        LOG_PRINT("set_settings_allow: settings is NULL\n");
        exit(EXIT_FAILURE);
    }
    // 这里的color没有初始化
    LOG_PRINT("init color......\n");
    // 初始化 color
    settings->color->key = strdup("color");
    LOG_PRINT("init color key......\n");
    settings->color->value_set = strdup(SETTING_COLOR_ALLOW_ON); // 因为要在堆上分配，所以使用strdup！
    LOG_PRINT("init color value_set......\n");
    settings->color->value_allow[0] = strdup(SETTING_COLOR_ALLOW_ON);
    settings->color->value_allow[1] = strdup(SETTING_COLOR_ALLOW_OFF);
    LOG_PRINT("init color value_allow......\n");
    settings->color->value_allow[2] = NULL;
    LOG_PRINT("init show......\n");

    // 初始化 show
    settings->show->key = strdup("show");
    LOG_PRINT("init show key......\n");

    settings->show->value_set = strdup(SETTING_SHOW_ALLOW_CURRENT_DAY);
    LOG_PRINT("init show value_set......\n");

    settings->show->value_allow[0] = strdup(SETTING_SHOW_ALLOW_YEAR);
    LOG_PRINT("init show value_allow 1......\n");

    settings->show->value_allow[1] = strdup(SETTING_SHOW_ALLOW_MONTH);
    LOG_PRINT("init show value_allow 2......\n");

    settings->show->value_allow[2] = strdup(SETTING_SHOW_ALLOW_WEEK);
    LOG_PRINT("init show value_allow 3......\n");

    settings->show->value_allow[3] = strdup(SETTING_SHOW_ALLOW_DAY);
    LOG_PRINT("init show value_allow 4......\n");

    settings->show->value_allow[4] = strdup(SETTING_SHOW_ALLOW_CURRENT_DAY);
    LOG_PRINT("init show value_allow 5......\n");

    settings->show->value_allow[5] = strdup(SETTING_SHOW_ALLOW_ALL);
    LOG_PRINT("init show value_allow 6......\n");

    settings->show->value_allow[6] = NULL;
    LOG_PRINT("init show value_allow 7......\n");
}

// try_set_value 修正
static int try_set_value(SettingItem *item, char *key, char *value)
{
    if (!item || !key || !value)
        return 0;

    for (int i = 0; item->value_allow[i] != NULL; i++)
    {
        if (item->value_allow[i] && value && strcmp(item->value_allow[i], value) == 0)
        {
            free(item->value_set);
            item->value_set = strdup(value);
            return 1; // 成功
        }
    }
    return 2; // 值不匹配
}

int set_settings(Setting *setting, CONFIGURATION_NODE *node)
{
    printf("begin to set_settings\n");
    if (!setting || !node || !node->KEY || !node->VALUE)
    {
        fprintf(stderr, "Invalid arguments\n");
        return 0;
    }
    if (strcmp(node->KEY, "color") == 0)
    {
        int ret = try_set_value(setting->color, node->KEY, node->VALUE);
        return ret; // color 匹配
    }
    if (strcmp(node->KEY, "show") == 0)
    {
        int ret = try_set_value(setting->show, node->KEY, node->VALUE);
        return ret; // color 匹配
    }
    return 0; // key不匹配
}
