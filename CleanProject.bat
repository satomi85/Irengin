echo Cleaning Project...
del ".\.vs\*.*" /s /q
rmdir ".vs" /q /s
del ".\*.sln" /s /q /f
del ".\*.vcxproj" /s /q /f
del ".\*.vcxproj.filters" /s /q /f
del ".\*.vcxproj.user" /s /q /f
PAUSE