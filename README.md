# RTOS
ESP-IDF

To compile using ESP-IDF you will need to get the following packages. The command to run depends on ubuntu distribution of Linux you are using:
````
sudo apt-get install git wget flex bison gperf python3 python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
`````
````
python --version
python3 --version

````

if there is no python install python and python3
````
 sudo apt-get install python
 sudo apt-get install python3
 ````
 
 To get ESP-IDF, navigate to your installation directory and clone the repository with git clone, following instructions below specific to your operating system.
 ````
 mkdir -p ~/esp
 cd ~/esp
 git clone --recursive https://github.com/espressif/esp-idf.git
 ````

Aside from the ESP-IDF, you also need to install the tools used by ESP-IDF, such as the compiler, debugger, Python packages, etc, for projects supporting ESP32.
````
  cd ~/esp/esp-idf
  ./install.sh esp32
  ./install.sh esp32,esp32s2
  ````

In order to install tools for all supported targets please run the following command:
````
cd ~/esp/esp-idf
./install.sh all (or)
./intall.sh 
````
Set up the environment variables

````
cd ~/esp/esp-idf
. export.sh
`````
Now you are ready to prepare your application for ESP32. You can start with get-started/hello_world project from examples directory in ESP-IDF.
Connect Your Device
```
dmesg (it show the /dev/ttyUSB0 )
sudo chmod 777 /dev/ttyUSB0 
cd ~/esp/esp-idf/examples/get-started/hello_world/
ls
to build the project giving below cmd
open code . and cd main check the  hello_world_main.c after changes go back
cd ~/esp/esp-idf/examples/get-started/hello_world/
idf.py to check all commands
idf.py build (to build the project)
idf.py flash (to flash program into board)
idf.py monitor (to check the output serial terminal)
ctrl ] (to exit the loop)

````
creating own project example
````
cd ~/esp/esp-idf
. export.sh
cd ~/esp/esp-idf/examples/get-started
mkdir desd
cd desd 
mkdir main
cd main 
copy the  CMakelist.txt file from helloworld->main file
and create your own file.c file inside the main save it include the file.c name in the Cmakelist file
cd ..
again create onther  CMakefile.txt in desd folder copy the make file from the helloworld file 
the final file are required to build project " desd->CMakefile.txt,main->file.c,CMakefile.txt"
inside desd console give idf.py menuconfig -> enable freertos clock tick hz 
idf.py Build 
idf.py flash
idf.py -p /dev/ttyUSB0 monitor
```
