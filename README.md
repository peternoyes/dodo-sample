# dodo-sample
Sample Game for Dodo the 6502 Game System

# Requirements
- cc65 	- https://github.com/cc65/cc65
- gododo 	- https://github.com/peternoyes/gododo

# Steps
- Build cc65 and make sure the /bin folder is in the system path
- Build gododo and run 'go install'
- Run 'make' to run the sample
- To test in the console: 'gododo -c'
	- To exit the simulator press 'X'
- To test in the web simulator: 'gododo' and then point browser to 'http://localhost:3000'

# Programming
- See api.h for the system calls
- Video memory is 1k starting at 0x7800, the screen is 128x64
- A maxiumum of 50,000 CPU cycles are allowed per frame. The simulator in the terminal reports the cycle count.

# Background
- Dodo games need to fit into a maximum of 8k
- The games are flashed onto FRAM game cartridges
- When Dodo boots, it copies the game into RAM starting at location 0x5800
- The entry point for the game is 0x5900
- The system code is stored in an EEPROM in Dodo. 'firmware' in the folder is the binary.
- Updated firmware can be downloaded and built from: https://github.com/peternoyes/dodo
- When the simulator runs, it expects 'firmware' and 'fram.bin' to be in the current folder
