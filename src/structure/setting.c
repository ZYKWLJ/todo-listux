#include "../../include/include.h"
// #include "setting.h"
// #include "setting.h"
S_setting_item S_setting_item_init(S_setting_item t)
{
    // 分配 S_setting_item 结构体的内存
    S_setting_item s_it = (S_setting_item)checked_malloc(sizeof(*t));

    // 初始化 key 和 value_set
    s_it->key[0] = '\0';
    s_it->value_set[0] = '\0';

    // 初始化 value_allow 数组
    for (int i = 0; i < 10; i++)
    {
        s_it->value_allow[i] = (char *)checked_malloc(100 * sizeof(char));
    }

    return s_it;
}

S_setting S_setting_init(S_setting s)
{
    S_setting settings = (S_setting)checked_malloc(sizeof(*s));
    settings->color = S_setting_item_init(NULL);
    settings->show = S_setting_item_init(NULL);
    settings->time = S_setting_item_init(NULL);
    return settings;
}

// set_settings_init 修正
void set_settings_init(S_setting settings)
{
    /**
     * data descp: 初始化在外面设置了
     */
    // 首先判断是不是存在了默认配置,这个不需要，因为我们一定会在后面加载默认配置的！
    // FILE *fp = fopen(get_appdata_path(SETTING_FILE), "r");
    // if (fp != NULL)
    // {
    //     load_setting(get_appdata_path(SETTING_FILE));
    //     return;
    // }
    if (!settings)
    {
        LOG_PRINT("set_settings_allow: settings is NULL\n");
        exit(EXIT_FAILURE);
    }
    // 这里的color没有初始化
    LOG_PRINT("init color......\n");
    // 初始化 color
    strcpy(settings->color->key, SETTING_COLOR_KEY);
    // LOG_PRINT("color key: %s\n", settings->color->key);
    strcpy(settings->color->value_set, SETTING_COLOR_ALLOW_ON);
    // LOG_PRINT("color value_set: %s\n", settings->color->value_set);
    strcpy(settings->color->value_allow[0], SETTING_COLOR_ALLOW_ON);
    // LOG_PRINT("color value_allow[0]: %s\n", settings->color->value_allow[0]);
    strcpy(settings->color->value_allow[1], SETTING_COLOR_ALLOW_OFF);

    // 初始化time显示
    // 初始化 color
    strcpy(settings->time->key, SETTING_TIME_KEY);
    // LOG_PRINT("color key: %s\n", settings->color->key);
    strcpy(settings->time->value_set, SETTING_TIME_ALLOW_ON);
    // LOG_PRINT("color value_set: %s\n", settings->color->value_set);
    strcpy(settings->time->value_allow[0], SETTING_TIME_ALLOW_ON);
    // LOG_PRINT("color value_allow[0]: %s\n", settings->color->value_allow[0]);
    strcpy(settings->time->value_allow[1], SETTING_TIME_ALLOW_OFF);

    // LOG_PRINT("color value_allow[1]: %s\n", settings->color->value_allow[1]);
    settings->color->value_allow[2] = NULL;
    // LOG_PRINT("init show......\n");
    strcpy(settings->show->key, SETTING_SHOW_KEY);
    strcpy(settings->show->value_set, SETTING_SHOW_ALLOW_DAY);
    strcpy(settings->show->value_allow[0], SETTING_SHOW_ALLOW_YEAR);
    strcpy(settings->show->value_allow[1], SETTING_SHOW_ALLOW_MONTH);
    strcpy(settings->show->value_allow[2], SETTING_SHOW_ALLOW_WEEK);
    strcpy(settings->show->value_allow[3], SETTING_SHOW_ALLOW_DAY);
    strcpy(settings->show->value_allow[4], SETTING_SHOW_ALLOW_ALL);
    settings->show->value_allow[5] = NULL;
}

// try_set_value 修正
static int try_set_value(S_setting_item item, char *key, char *value)
{
    if (!item || !key || !value)
        return 0;

    for (int i = 0; item->value_allow[i] != NULL; i++)
    {
        if (item->value_allow[i] && value && strcmp(item->value_allow[i], value) == 0)
        {
            LOG_PRINT("try_set_value: %s\n", item->value_allow[i]);
            strcpy(item->value_set, value);
            LOG_PRINT("try_set_value: %s over .....\n", item->value_set);
            return 1; // 成功
        }
    }
    return 2; // 值不匹配
}

int set_settings(S_setting setting, KV_ node)
{
    // printf("begin to set_settings\n");
    if (!setting || !node || !node->key || !node->value)
    {
        fprintf(stderr, "Invalid arguments\n");
        return 0;
    }
    else if (strcmp(node->key, "color") == 0)
    {
        int ret = try_set_value(setting->color, node->key, node->value);
        return ret; // color 匹配
    }
    else if (strcmp(node->key, "show") == 0)
    {
        int ret = try_set_value(setting->show, node->key, node->value);
        return ret; // color 匹配
    }
    else if (strcmp(node->key, "time") == 0)
    {
        int ret = try_set_value(setting->time, node->key, node->value);
        return ret; // color 匹配
    }
    return 0; // key不匹配
}
void S_settings_print(S_setting settings)
{
    if (!settings)
    {
        LOG_PRINT("S_settings_print: settings is NULL\n");
    }
    LOG_PRINT("color: %s\n", settings->color->value_set);
    LOG_PRINT("time: %s\n", settings->time->value_set);
    LOG_PRINT("show: %s\n", settings->show->value_set);
}
