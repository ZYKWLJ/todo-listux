#include "../../include/include.h"
// 获取应用数据目录（跨平台）
const char *get_appdata_path()
{
    static char path[MAX_PATH] = {0};

    if (path[0] != '\0')
        return path;

#ifdef _WIN32
    // Windows获取AppData路径
    wchar_t wpath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, wpath)))
    {
        WideCharToMultiByte(CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL);
        strcat_s(path, MAX_PATH, "\\tl");
        // 确保目录存在
        _mkdir(path);
    }
    else
    {
        strcpy_s(path, MAX_PATH, ".\\data"); // 回退到当前目录
        _mkdir(path);
    }
#else
    // Linux/macOS使用/tmp/tl
    strcpy(path, "/tmp/tl");
    mkdir(path, 0755); // 创建目录并设置权限
#endif

    return path;
}

// 跨平台安全的目录创建函数
int create_directory(const char *path)
{
#ifdef _WIN32
    // 将UTF-8路径转换为宽字符
    wchar_t wpath[MAX_PATH];
    if (MultiByteToWideChar(CP_UTF8, 0, path, -1, wpath, MAX_PATH) == 0)
    {
        fprintf(stderr, "路径转换失败: %d\n", GetLastError());
        return -1;
    }

    // 尝试直接创建目录
    if (_wmkdir(wpath) == 0)
    {
        return 0; // 创建成功
    }

    // 处理错误情况
    switch (errno)
    {
    case EEXIST:
        return 0; // 目录已存在
    case ENOENT:
    {
        // 父目录不存在，尝试递归创建
        char parent[MAX_PATH];
        strncpy(parent, path, MAX_PATH);
        char *slash = strrchr(parent, '\\');
        if (slash)
        {
            *slash = '\0';
            return create_directory(parent) == 0 ? _wmkdir(wpath) == 0 || errno == EEXIST ? 0 : -1 : -1;
        }
        return -1;
    }
    default:
        fprintf(stderr, "无法创建目录 '%s': %s\n", path, strerror(errno));
        return -1;
    }
#else
    // Linux/macOS使用mkdir -p
    char command[512];
    snprintf(command, sizeof(command), "mkdir -p \"%s\"", path);
    return system(command);
#endif
}
