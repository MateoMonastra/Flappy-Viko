


set ProjectDir = %1
set ProjectTargetDir = %2

echo %ProjectDir%
echo %ProjectTargetDir%

@xcopy /y /i /s %ProjectDir% %ProjectTargetDir%

pause