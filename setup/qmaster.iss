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
OutputBaseFilename=qmaster-v0.1.0-setup

SetupIconFile=F:\work\vr\Lastochka\soft\qmaster\qmodbus-master\resources\img\logo.ico

Compression=lzma
SolidCompression=yes

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]

; Исполняемый файл
Source: "F:\work\vr\Lastochka\soft\qmaster\bin\qmaster.exe"; DestDir: "{app}"; Flags: ignoreversion

; Прилагающиеся ресурсы
Source: "F:\work\vr\Lastochka\soft\qmaster\bin\*.*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs


[Icons]
Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"; IconFilename: "{app}\logo.ico"                            
Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; IconFilename: "{app}\logo.ico"; Tasks: desktopicon