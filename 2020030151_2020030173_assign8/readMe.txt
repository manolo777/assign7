1.FINDING THE BUFFER AND THE RETURN ADDRESS LOCATION
RETURN ADDRESS
To determine the return address location we first open and run the program using the GDB . When the program ask for input we provide a long string of " A " , b
If the return address is overwritten the program will attempt to jump this address which is likely to be an invalid or inaccessible memory location .
The attempt to execute code at the invalid address results in a segmentation fault and the invalid address is returned . In our case the return address is in
BUFFERS ADDRESS
We start again the gdb by setting a breakpoint in the readString funtion .When the program reached the breakpoint , we utilized GDB's info locals command to
unsigned char Name [ 1024 ] : 0x80ef320
char buf [ 32 ] : Oxffffcecc

2.PAYLOAD GENERATION AND TEST
The mmap and mprotect functions are used to make a memory page executable in Linux . The mmap function allocates a memory page with specified permissions . In
