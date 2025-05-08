@echo off
setlocal enabledelayedexpansion

:: Check for administrator privileges
net session >nul 2>&1
if %errorlevel% neq 0 (
    echo ERROR: This script requires Administrator privileges!
    pause
    exit /b 1
)

:: Get source directory input
:get_input
set "source_dir="
set /p "source_dir=Enter the directory containing tl*.exe files: "

:: Validate input
if "%source_dir%"=="" (
    echo ERROR: Directory cannot be empty!
    goto get_input
)
if not exist "%source_dir%\" (
    echo ERROR: Directory "%source_dir%" does not exist!
    goto get_input
)

:: Find newest matching file
set "newest_file="
set "newest_time=0"
for %%f in ("%source_dir%\tl*.exe") do (
    for %%t in ("%%~tf") do (
        set "file_time=%%~t"
        set "file_time=!file_time:/=!"
        set "file_time=!file_time::=!"
        set "file_time=!file_time: =0!"
        
        if !file_time! gtr !newest_time! (
            set "newest_file=%%f"
            set "newest_time=!file_time!"
        )
    )
)

:: Verify file found
if not defined newest_file (
    echo ERROR: No tl*.exe files found in "%source_dir%"
    pause
    exit /b 1
)

:: Display file info
echo.
echo Latest file found: %newest_file%
echo Modified time: %%~tf

:: Copy to System32 with forced overwrite
echo.
echo Copying to C:\Windows\System32\tl.exe...
copy /Y "%newest_file%" "C:\Windows\System32\tl.exe" >nul

if exist "C:\Windows\System32\tl.exe" (
    echo Success: File copied and renamed to tl.exe
    echo NOTE: Existing file was overwritten.
) else (
    echo ERROR: Failed to copy file to System32
)
pause