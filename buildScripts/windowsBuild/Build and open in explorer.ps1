cd ../..

pio run

cd .pio\build\wt32-eth01\

Write-Host ""
Write-Host "Build script build portion completed."
Write-Host ""
Write-Host "Open explorer folder with firmware bin and firefox to upload page? Press Y to open, any other key to not: " -NoNewLine

$key = $Host.UI.RawUI.ReadKey('NoEcho,IncludeKeyDown');

if ($key.Character -eq 'y')
{
    explorer .

    echo "Drag firmware.bin onto the ElegantOTA page"

    ."C:\Program Files\Mozilla Firefox\firefox.exe" "http://192.168.1.50/update"
}

cd ../../../buildScripts/windowsBuild

Write-Host ""
Write-Host ""
Write-Host "Build script execution completed."
Write-Host ""
