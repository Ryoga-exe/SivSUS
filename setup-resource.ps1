$resources = (Get-ChildItem -Recurse *.rc)

foreach ($resource in $resources) {
    $directory = $resource.DirectoryName
    Write-Host "Resource.rc Found! (${resource})" -ForegroundColor Green
    $content = (Get-Content $resource.FullName -Raw) -replace "/\*[\s\S]*?\*/|//.*", ""
    
    $m = [regex]::Matches($content, "(?<=(^|\s)Resource\()[^\(\)]+(?=\))", "Multiline")
    
    foreach ($item in $m) {
        $path = $item.Value
        $abspath = (Join-Path -Path $directory -ChildPath $item.Value)
        if ($path.StartsWith("engine/") -or $path.StartsWith("example/")) {
            if (-Not(Test-Path -Path $abspath)) {
                Write-Host "${abspath} does not exist." -ForegroundColor Red
                Write-Host "Download..." -ForegroundColor Cyan
                New-Item -ItemType "directory" -Path ([System.IO.Path]::GetDirectoryName($abspath)) -Force | Out-Null
                Invoke-WebRequest -Uri "https://github.com/Siv3D/OpenSiv3D/raw/main/WindowsDesktop/App/${path}" -OutFile $abspath | Out-Null
            }
        }
    }
}
