# HP_Project

This folder ocntains the three main program used in this project: 
  
  The C++ code Ardu.cpp
  The html interface2.html 
  The python script Script.py
  
 It also contains the input file used in Abaqus to interact with the software, and a CAE file (just in case someone would like to directly reuse an existing job.
 
Ardu.cpp controls the Arduino and gets the flex data from the flex sensor. The html interface fetches the flex value from the microcontroller using a usb serial connection. Finally, the python scrit is supposed to implement these values in the input files and launch new simulations using the CAE file.
  
