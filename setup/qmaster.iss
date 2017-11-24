#define Name      "QMaster"
#define Version   "0.1.0"
#define Publisher "maisvendoo"
#define URL       "https://github.com/maisvendoo/qmaster.git"
#define ExeName   "qmaster.exe"

[Setup]
AppId={{40786C42-8EC8-445D-98DB-C6BBCC31111B}}

AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

DefaultDirName={pf}\{#Name}
DefaultGroupName={#Name}

OutputDir=F:\work\vr\Lastochka\soft\qmaster\bin
OutputBaseFilename=qmaster-v0.1.0-setup.exe

SetupIconFile=F:\work\vr\Lastochka\soft\qmaster\qmodbus-master\resources\img\logo.ico

Compression=lzma
SolidCompression=yes

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]

; Исполняемый файл
Source: "F:\work\vr\Lastochka\soft\qmaster\bin\qmaster.exe"; DestDir: "{app}"; Flags: ignoreversion

; Прилагающиеся ресурсы
Source: "C:\Qt\5.9.1\msvc2015_64\bin\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\5.9.1\msvc2015_64\bin\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\5.9.1\msvc2015_64\bin\Qt5SerialBus.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\5.9.1\msvc2015_64\bin\Qt5SerialPort.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\5.9.1\msvc2015_64\bin\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "C:\Qt\5.9.1\msvc2015_64\bin\Qt5Network.dll"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "F:\work\vr\Lastochka\soft\qmaster\qmodbus-master\resources\img\logo.ico"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs

[Icons]
Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"; IconFilename: "{app}\logo.ico"                            
Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; IconFilename: "{app}\logo.ico"; Tasks: desktopicon