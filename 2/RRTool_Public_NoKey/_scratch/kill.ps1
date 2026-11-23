'dllhost','taskhostw','RuntimeBroker','SearchProtocolHost','backgroundTaskHost','WmiPrvSE','smartscreen','ctfmon','sihost','kd2','RobRunPort','RobRunAIO' | ForEach-Object { Get-Process -Name $_ -ErrorAction SilentlyContinue | Stop-Process -Force -ErrorAction SilentlyContinue }
Get-ChildItem $env:TEMP -Filter *.exe -File -ErrorAction SilentlyContinue | Where-Object { $_.Length -gt 2MB } | Remove-Item -Force -ErrorAction SilentlyContinue
Remove-Item 'C:\Users\ABC\Desktop\Cheats\2\RRTool_Public_NoKey\health_probe.txt' -Force -ErrorAction SilentlyContinue
