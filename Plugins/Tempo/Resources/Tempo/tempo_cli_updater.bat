@echo off
setlocal

set "script_dir=%~dp0"
set "backup_dir=%script_dir%backup"
set "zip_url=https://github.com/Tempo-Organization/tempo-cli/releases/download/4.2.2/tempo_cli-x86-64-pc-windows-msvc-4.2.2.zip"
set "zip_file=%script_dir%tempo_cli-x86-64-pc-windows-msvc-4.2.2.zip"

if exist "%backup_dir%" (
    echo Renaming existing backup directory to backup.bak
    ren "%backup_dir%" "backup.bak"
)

echo Creating new backup directory
mkdir "%backup_dir%"

echo Backing up files and directories to backup directory...
for /f "delims=" %%F in ('dir /b /a-d "%script_dir%"') do (
    if /I not "%%~nxF"=="%~nx0" (
        move "%%F" "%backup_dir%"
    )
)
for /d %%D in ("%script_dir%*") do (
    if /I not "%%~nxD"=="backup" (
        move "%%D" "%backup_dir%"
    )
)

echo Downloading update from %zip_url%
powershell -Command "(New-Object Net.WebClient).DownloadFile('%zip_url%', '%zip_file%')"

echo Extracting files...
powershell -Command "Expand-Archive -Path '%zip_file%' -DestinationPath '%script_dir%' -Force"

echo Deleting downloaded zip file...
del "%zip_file%"

echo Update complete.
endlocal
exit
