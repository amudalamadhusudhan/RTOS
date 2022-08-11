# RTOS
ESP-IDF

To compile using ESP-IDF you will need to get the following packages. The command to run depends on ubuntu distribution of Linux you are using:

sudo apt-get install git wget flex bison gperf python3 python3-venv cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0
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
  /install.sh esp32,esp32s2
  ````

In order to install tools for all supported targets please run the following command:
````
cd ~/esp/esp-idf
./install.sh all
````


