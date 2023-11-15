

set PositionDir=%1
set CopyDir=%2
set PasteDir=%3

cd %PositionDir%

mkdir res

xcopy /s /e /y %CopyDir% %PasteDir%