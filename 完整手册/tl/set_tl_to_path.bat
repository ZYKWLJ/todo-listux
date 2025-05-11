@REM 原理：
@REM 用户输入的路径下的最新修改的.exe文件改名为tl.exe(如果有原来的tl.exe,就强行覆盖)，
@REM 复制进C:\Windows\System32，如果C:\Windows\System32有原来的tl.exe,就强行覆盖。
@REM ================================================
@REM tl.exe Installer Script
@REM 
@REM Purpose: Copies the newest .exe file from specified directory
@REM          to System32 as tl.exe (with overwrite)
@REM Requirements: Administrator privileges
@REM ================================================

@echo off
setlocal enabledelayedexpansion

:: ======================
:: ADMIN PRIVILEGE CHECK
:: ======================
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo ERROR: This script requires Administrator privileges!
    echo Please right-click the script and select "Run as administrator"
    pause
    exit /b 1
)

:: ======================
:: USER INPUT SECTION
:: ======================
:get_input
cls
echo.
echo ====================================
echo tl.exe Installation Utility
echo ====================================
echo.
set "source_dir="
set /p "source_dir=Enter the directory path containing .exe files: "

:: Input validation
if "%source_dir%"=="" (
    echo ERROR: Directory path cannot be empty!
    pause
    goto get_input
)

:: Remove quotes if user entered them
set "source_dir=%source_dir:"=%"

:: Check directory exists
if not exist "%source_dir%\" (
    echo ERROR: Directory "%source_dir%" does not exist!
    pause
    goto get_input
)

:: ======================
:: FIND NEWEST EXE FILE
:: ======================
set "newest_file="
set "newest_time=0"

echo.
echo Scanning directory for .exe files...
echo.

for %%f in ("%source_dir%\*.exe") do (
    :: Get last modified time in YYYYMMDDHHMMSS format
    for %%t in ("%%~tf") do (
        set "file_time=%%~t"
        set "file_time=!file_time:/=!"
        set "file_time=!file_time::=!"
        set "file_time=!file_time: =0!"
        
        if !file_time! gtr !newest_time! (
            set "newest_file=%%~ff"
            set "newest_time=!file_time!"
            set "original_name=%%~nxf"
        )
    )
)

:: Verify we found an exe file
if not defined newest_file (
    echo ERROR: No .exe files found in "%source_dir%"
    pause
    exit /b 1
)

:: ======================
:: COPY TO SYSTEM32
:: ======================
echo.
echo Found newest file: %original_name%
echo Modified time: %newest_time%
echo.

echo Installing to C:\Windows\System32\tl.exe...
echo.

:: Copy directly from original location to System32
copy /Y "%newest_file%" "C:\Windows\System32\tl.exe" >nul

:: Verify success
if %errorlevel% equ 0 (
    echo SUCCESS: tl.exe has been installed in system directory
    echo.
    echo You can now use the "tl" command from any location
) else (
    echo ERROR: File copy failed
    echo Possible reasons:
    echo 1. Insufficient disk space
    echo 2. File permission issues
    echo 3. Antivirus software blocking
    echo 4. File in use by another process
)

:: ======================
:: CLEANUP AND EXIT
:: ======================
echo.
pause
exit /b 0