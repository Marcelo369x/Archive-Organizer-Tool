@echo off


cls

echo.
powershell -Command "Write-Host       ' _______ _________ _        _______ '  -ForegroundColor Green -NoNewline; Write-Host '_______  _______  _______  _______'"
powershell -Command "Write-Host       '(  ____ \\__   __/( \      (  ____ \' -ForegroundColor Green -NoNewline; Write-Host '(  ___  )(  ____ )(  ____ \(  ___  )'"
powershell -Command "Write-Host       '| (    \/   ) (   | (      | (    \/' -ForegroundColor Green -NoNewline; Write-Host '| (   ) || (    )|| (    \/| (   ) |'"
powershell -Command "Write-Host       '| (__       | |   | |      | (__    ' -ForegroundColor Green -NoNewline; Write-Host '| |   | || (____)|| |      | (___) |'"
powershell -Command "Write-Host       '|  __)      | |   | |      |  __)   ' -ForegroundColor Green -NoNewline; Write-Host '| |   | ||     __)| | ____ |  ___  |'"
powershell -Command "Write-Host       '| (         | |   | |      | (      ' -ForegroundColor Green -NoNewline; Write-Host '| |   | || (\ (   | | \_  )| (   ) |'"
powershell -Command "Write-Host       '| )      ___) (___| (____/\| (____/\' -ForegroundColor Green -NoNewline; Write-Host '| (___) || ) \ \__| (___) || )   ( |'"
powershell -Command "Write-Host       '|/       \_______/(_______/(_______/' -ForegroundColor Green -NoNewline; Write-Host '(_______)|/   \__/(_______)|/     \|'"

powershell -Command "Write-Host        '_       _________ _______  _______  _______'"                            
powershell -Command "Write-Host       '( (    /|\__   __// ___   )(  ____ \(  ____ )'"                          
powershell -Command "Write-Host       '|  \  ( |   ) (   \/   )  || (    \/| (    )|' "                        
powershell -Command "Write-Host       '|   \ | |   | |       /   )| (__    | (____)|'  "                     
powershell -Command "Write-Host       '| (\ \) |   | |      /   / |  __)   |     __)' "                      
powershell -Command "Write-Host       '| | \   |   | |     /   /  | (      | (\ (   ' "                     
powershell -Command "Write-Host       '| )  \  |___) (___ /   (_/\| (____/\| ) \ \__'  "                   
powershell -Command "Write-Host       '|/    )_)\_______/(_______/(_______/|/   \__/'"
echo.

powershell -Command "Write-Host '---------------------------------Coded by: Marelo Folcarelli------'"
powershell -Command "Write-Host '----------------------------------------version: 0.2.1------------'"

echo.

set /p ruta=[+]enter the route that u want to organize [the archives has to be in a mother/main carpet]:
powershell -Command "Write-Host       'Working...'  -ForegroundColor Green -NoNewline
g++ main.cpp -std=c++17 -o main.exe
main.exe "%ruta%"

pause