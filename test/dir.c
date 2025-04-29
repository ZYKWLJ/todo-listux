#include <windows.h>
#include <stdio.h>
#include <shlobj.h>
#include <tchar.h>

// int main() {
//     // 方法1：使用显式宽字符版本（推荐）
//     WCHAR appDataPath[MAX_PATH];
//     if (SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, appDataPath) == S_OK) {
//         WCHAR folderPath[MAX_PATH];
//         swprintf_s(folderPath, MAX_PATH, L"%s\\MyFolder", appDataPath);

//         if (CreateDirectoryW(folderPath, NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
//             wprintf(L"文件夹创建成功或已存在: %s\n", folderPath);
//         } else {
//             wprintf(L"文件夹创建失败，错误码: %d\n", GetLastError());
//         }
//     } else {
//         wprintf(L"获取AppData路径失败\n");
//     }
//     return 0;
// }


#include <stdlib.h>  // 添加头文件

int main() {
    WCHAR appDataPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, appDataPath) == S_OK) {
        WCHAR folderPath[MAX_PATH];
        swprintf_s(folderPath, MAX_PATH, L"%s\\MyFolder", appDataPath);

        if (CreateDirectoryW(folderPath, NULL) || GetLastError() == ERROR_ALREADY_EXISTS) {
            wprintf(L"文件夹创建成功或已存在: %s\n", folderPath);
        } else {
            wprintf(L"文件夹创建失败，错误码: %d\n", GetLastError());
        }
    } else {
        wprintf(L"获取AppData路径失败\n");
    }

    // 添加暂停代码（仅调试用）
    system("pause");
    return 0;
}