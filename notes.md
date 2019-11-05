# installation notes  
  check also https://docs.zephyrproject.org/latest/getting_started/index.html  
  
# environment windows7, cmd, cygwin, msys2  
  
1) download and install python3  
   in cmd  
   where python --> C:\Python37\python.exe  
   python --version --> Python 3.7.2
   
2) pip3 install --upgrade pip  
   pip3 install west  
  
3) mkdir _  && cd _
  
4) west init  
  
5) west update  
   in cmd  
   dir  
   .west  
   modules  
   tools  
   zephyr  
  
6) pip3 install -r zephyr/scripts/requirements.txt  
  
7) download and install gcc-arm-none-eabi-7-2018-q2-update-win32  
  
8) install C:\GNU_Tools_ARM_Embedded\7_2018  
  
9) cd _ && cd zephyr  
   edit zephyr-env.cmd  
  
   set ZEPHYR_BASE=%~dp0  
   set ZEPHYR_TOOLCHAIN_VARIANT=gnuarmemb  
   set GNUARMEMB_TOOLCHAIN_PATH=C:\\GNU_Tools_ARM_Embedded\\7_2018  
  
10) download (as binary) and install cmake  
   in cmd  
   where cmake --> C:\CMake\bin\cmake.exe  
   cmake --version --> cmake version 3.15.2  
  
11) download (as binary) and install ninja  
   in cmd (set PATH)  
   where ninja --> C:\bin\ninja.exe  
   ninja --version --> 1.9.0  
  
12) download msys2  
    pacman -Sy gperf  
    cp msys-2.0.dll into system32  
    set PATH  --> C:\msys64\usr\bin  
  
12) download, compile and install dtc  
    in msys2
    git clone https://github.com/dgibson/dtc  
    git checkout 1.5.1
    make  
    note that msys2 may require packages  
    pacman -S bison flex diffutils gcc make gperf pkg-config  
    pacman -Qe  
  
13) west build -b nucleo_l432kc samples/hello_world  
  
14) repeat build  
   del build -> [Y/N]  
   west build -b nucleo_l432kc samples/hello_world  
  
15) how successfully build looks like  
  
E:\embedded\01_zephyr\zephyr_west\zephyr>west build -b nucleo_l432kc samples/hello_world  
-- west build: build configuration:  
       source directory: E:\embedded\01_zephyr\zephyr_west\zephyr\samples\hello_world  
       build directory: E:\embedded\01_zephyr\zephyr_west\zephyr\build  
       BOARD: nucleo_l432kc (origin: command line)  
-- west build: generating a build system  
Zephyr version: 2.0.99  
-- Found PythonInterp: C:/Python37/python.exe (found suitable version "3.7.2", minimum required is "3.4")  
-- Selected BOARD nucleo_l432kc  
-- Found west: C:/Python37/Scripts/west.exe (found suitable version "0.6.3", minimum required is "0.6.0")  
-- Loading E:/embedded/01_zephyr/zephyr_west/zephyr/boards/arm/nucleo_l432kc/nucleo_l432kc.dts as base  
Devicetree configuration written to E:/embedded/01_zephyr/zephyr_west/zephyr/build/zephyr/include/generated/generated_dts_board.conf  
Parsing Kconfig tree in E:/embedded/01_zephyr/zephyr_west/zephyr/Kconfig  
Loaded configuration 'E:/embedded/01_zephyr/zephyr_west/zephyr/build/zephyr/.config'  
No change to 'E:/embedded/01_zephyr/zephyr_west/zephyr/build/zephyr/.config'  
-- The C compiler identification is GNU 7.3.1  
-- The CXX compiler identification is GNU 7.3.1  
-- The ASM compiler identification is GNU  
-- Found assembler: C:/GNU_Tools_ARM_Embedded/7_2018/bin/arm-none-eabi-gcc.exe  
-- Cache files will be written to: C:\Users\Dell\AppData\Local/.cache/zephyr  
-- Configuring done  
-- Generating done  
-- Build files have been written to: E:/embedded/01_zephyr/zephyr_west/zephyr/build  
-- west build: building application  
[115/120] Linking C executable zephyr\zephyr_prebuilt.elf  
Memory region         Used Size  Region Size  %age Used  
           FLASH:       12912 B       256 KB      4.93%  
            SRAM:        4152 B        64 KB      6.34%  
        IDT_LIST:         120 B         2 KB      5.86%  
[120/120] Linking C executable zephyr\zephyr.elf  
  
# installation notes add on
on the second pc (windows10) the toolchain  
gcc-arm-none-eabi-7-2018-q2-update-win32-sha1  
has been replaced with  
gcc-arm-none-eabi-8-2019-q3-update-win32-sha1  
because of .unknown link errors  
  
assert(toolchain_is_ok "The toolchain is unable to build a dummy C file. See CMakeError.log.")  
toolchain_is_ok  failed  
when commented out  the build process failed later at linking the modules  
after toolchain replacement build succedded  
  
C:\Users\yadaniel\01_embedded\01_zephyr\zephyr>west build -b nucleo_l432kc samples/hello_world  
-- west build: build configuration:  
       source directory: C:\Users\yadaniel\01_embedded\01_zephyr\zephyr\samples\hello_world  
       build directory: C:\Users\yadaniel\01_embedded\01_zephyr\zephyr\build  
       BOARD: nucleo_l432kc (origin: command line)  
-- west build: generating a build system  
Zephyr version: 2.0.99  
-- Found PythonInterp: C:/Python38/python.exe (found suitable version "3.8.0", minimum required is "3.4")  
-- Selected BOARD nucleo_l432kc  
-- Found west: C:/Python38/Scripts/west.exe (found suitable version "0.6.3", minimum required is "0.6.0")  
-- Loading C:/Users/yadaniel/01_embedded/01_zephyr/zephyr/boards/arm/nucleo_l432kc/nucleo_l432kc.dts as base  
Devicetree configuration written to C:/Users/yadaniel/01_embedded/01_zephyr/zephyr/build/zephyr/include/generated/generated_dts_board.conf  
Parsing Kconfig tree in C:/Users/yadaniel/01_embedded/01_zephyr/zephyr/Kconfig  
Loaded configuration 'C:/Users/yadaniel/01_embedded/01_zephyr/zephyr/build/zephyr/.config'  
No change to 'C:/Users/yadaniel/01_embedded/01_zephyr/zephyr/build/zephyr/.config'  
-- The C compiler identification is GNU 8.3.1  
-- The CXX compiler identification is GNU 8.3.1  
-- The ASM compiler identification is GNU  
-- Found assembler: C:/GNU_Tools_Arm_Embedded/8_2019/bin/arm-none-eabi-gcc.exe  
-- Cache files will be written to: C:\Users\yadaniel\AppData\Local/.cache/zephyr  
-- Configuring done  
-- Generating done  
-- Build files have been written to: C:/Users/yadaniel/01_embedded/01_zephyr/zephyr/build  
-- west build: building application  
[115/120] Linking C executable zephyr\zephyr_prebuilt.elf  
Memory region         Used Size  Region Size  %age Used  
           FLASH:       12880 B       256 KB      4.91%  
            SRAM:        4152 B        64 KB      6.34%  
        IDT_LIST:         120 B         2 KB      5.86%  
[120/120] Linking C executable zephyr\zephyr.elf  
  

