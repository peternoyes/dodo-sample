# dodo-sample
Sample Game for Dodo the 6502 Game System

# Requirements
##  cc65 	- https://github.com/cc65/cc65
##  gododo 	- https://github.com/peternoyes/gododo

# Steps
## Build cc65 and make sure the /bin folder is in the system path
## Build gododo and run 'go install'
## Run 'make' to run the sample
## To test in the console: 'gododo -c'
## To test in the web simulator: 'gododo' and then point browser to 'http://localhost:3000'

# Programming
## See api.h for the system calls
## Video memory is 1k starting at 0x3C00