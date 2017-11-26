# QMaster - Modbus RTU master PC emulator

## Description

QMaster is crossplatform PC application for Modbus master device emulate

![](https://habrastorage.org/webt/cu/pi/me/cupimefoxztpq0dgortu4fuo-ka.png)

##  System requirements

Apllication was tested in Linux (kernel 4.13.x), Windows 7 Ultimate RC1 

* Qt5 libraries (version 5.9 or higher)
* Hardware RS485 PC adapter to connect with slave devices

## Installation

### Window

1. Load lestest release from [release page](https://github.com/maisvendoo/qmaster/releases)
2. Run qmaster-vX.Y.Z-setup.exe file to setup QMaster to your system

*Attantion:* If you have error such as "could't find msvcp140.dll...", you must install [MS Visual C++ Redistributable package](https://www.microsoft.com/en-us/download/details.aspx?id=53587), because cuurent QMaster version builded with dynamic linking.

### Linux

1. Create directory

```
$ mkdir qmaster
$ cd qmaster

2. Get sources by

```
$ git clone https://github.com/maisvendoo/qmaster.git
```

3. Create directory for building

```
$ mkdir build
$ cd build
```

4. Execute commands

```
$ qmake ../qmaster
$ make
```

5. Go to directory

```
$ cd ../bin
```

6. Run

```
$ ./qmaster
```

*Attention:* If you use Arch Linux, you can install [QMaster from AUR](https://aur.archlinux.org/packages/qmaster/)


```
$ yaourt -S qmaster
```

