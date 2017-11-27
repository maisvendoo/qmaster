#define Name        "QMaster"
#define Version       "0.2.0"
#define Publisher     "maisvendoo"
#define URL           "https://github.com/maisvendoo/qmaster.git"
#define ExeName       "qmaster.exe"
#define BinDir        "..\..\bin"
#define SrcDir        "..\"
#define ResourceDir   "..\resources\"

[Setup]
AppId={{40786C42-8EC8-445D-98DB-C6BBCC31111B}}

AppName={#Name}
AppVersion={#Version}
AppPublisher={#Publisher}
AppSupportURL={#URL}
AppUpdatesURL={#URL}

DefaultDirName={pf}\{#Name}
DefaultGroupName={#Name}

OutputDir=..\..\bin-setup
OutputBaseFilename=qmaster-v{#Version}-setup

SetupIconFile={#ResourceDir}\img\logo.ico

Compression=lzma
SolidCompression=yes

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]

; Исполняемый файл
Source: "{#BinDir}\qmaster.exe"; DestDir: "{app}"; Flags: ignoreversion

; Прилагающиеся ресурсы
Source: "{#BinDir}\*.*"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs
Source: "{#ResourceDir}\img\logo.ico"; DestDir: "{app}"; Flags: ignoreversion recursesubdirs createallsubdirs


[Icons]
Name: "{group}\{#Name}"; Filename: "{app}\{#ExeName}"; IconFilename: "{app}\logo.ico"                            
Name: "{commondesktop}\{#Name}"; Filename: "{app}\{#ExeName}"; IconFilename: "{app}\logo.ico"; Tasks: desktopicon