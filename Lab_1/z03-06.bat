echo off
echo ��ப� ��ࠬ��஢: %1 , %2
echo �����: %1
echo ��� 䠩��: %2

if "%1"=="" (goto case1) else (goto case2)
if "%2"=="" (
    echo no filename
    goto exit
) else if "%1" neq "ᮧ����" or if "%1" neq "㤠����" (
    echo operation is incorrect
    goto exit
)
  else (
    echo good
)

:case1
    echo operation = {create,delete}
    echo name = filename
    goto exit

:case2
    if "%2"=="" (goto case3) else (goto case4)

:case3
    echo no filename
    goto exit

:case4
if "%1" == "ᮧ����" (goto createcase)
if "%1" == "㤠����" (goto deletecase) else (goto operationcase)
:operationcase
    echo operation is incorrect
    goto exit

:createcase
if exist %2 (goto casefound)
copy /b NUL %2
echo file %2 created
goto exit

:deletecase
if not exist %2 (goto casenotfound)
del %2
echo file %2 deleted
goto exit

:casefound
echo file %2 already exist
goto exit

:casenotfound
echo file %2 not found
goto exit

:exit