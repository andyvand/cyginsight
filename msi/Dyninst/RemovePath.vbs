Dim WSHShell, strPath, strNewPath, strTargetDir

Set WSHShell = CreateObject("WScript.Shell")

strPath = WSHShell.RegRead("HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment\Path")
strTargetDir = WSHShell.RegRead("HKLM\SOFTWARE\University of Maryland\Dyninst\Path")

strNewPath = Replace(strPath, ";" & strTargetDir & "Lib", "")

WSHShell.RegWrite "HKLM\SYSTEM\CurrentControlSet\Control\Session Manager\Environment\Path", strNewPath, "REG_EXPAND_SZ"
