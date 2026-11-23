param([int]$Days=7,[string]$Out="",[int]$Serial=0,[string]$Fingerprint="")
$ErrorActionPreference="Stop"
$d=$PSScriptRoot
if(-not $Out){ $Out=Join-Path $d "licence.txt" }
$mg=(Get-ItemProperty "HKLM:\SOFTWARE\Microsoft\Cryptography").MachineGuid
if($Fingerprint){ [byte[]]$fp=@(); for($i=0;$i -lt 32;$i+=2){ $fp+=[Convert]::ToByte($Fingerprint.Substring($i,2),16) } } else { [byte[]]$fp=([System.Security.Cryptography.SHA256]::Create().ComputeHash([Text.Encoding]::UTF8.GetBytes($mg)))[0..15] }
$now=[DateTimeOffset]::UtcNow.ToUnixTimeSeconds()
$b=@()
$b+=[Text.Encoding]::ASCII.GetBytes("RRL1")
$b+=1
$b+=$fp
$b+=[BitConverter]::GetBytes([long]$now)
$b+=[BitConverter]::GetBytes([long]($now+[long]$Days*86400))
$b+=[BitConverter]::GetBytes([int]$Serial)
$k=[System.Security.Cryptography.CngKey]::Import([IO.File]::ReadAllBytes((Join-Path $d "private.p8")),[System.Security.Cryptography.CngKeyBlobFormat]::Pkcs8PrivateBlob)
$s=[System.Security.Cryptography.ECDsaCng]::new($k)
$sig=$s.SignData([byte[]]$b,[System.Security.Cryptography.HashAlgorithmName]::SHA256)
$tok=[Convert]::ToBase64String([byte[]]($b+$sig))
[IO.File]::WriteAllText($Out,$tok)
"serial=$Serial days=$Days exp=$([DateTimeOffset]::FromUnixTimeSeconds($now+[long]$Days*86400).ToString("yyyy-MM-dd HH:mm"))Z"
$tok
$s.Dispose()

