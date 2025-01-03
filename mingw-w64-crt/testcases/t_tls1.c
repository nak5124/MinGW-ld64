/*
 need gcc-4.3.4 (gcc-4_3-branch r149015)
   or gcc-4.4.1 (gcc-4_4-branch r149016)
   or gcc-4.5.x (trunk r149593) or newer
 which have a properly fixed gcc/emutls.c,
 along with mingw-w64-headers r960 and
 mingw-w64-crt r973.
*/

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#if __MINGW_GNUC_PREREQ(4, 3)
/* gcc >= 4.3, also needs binutils >= 2.19 */
#define __threadlocal__ __thread
#else
#error No keyword for TLS vars is defined.
#endif

__threadlocal__ int tvar = 0;

int main (int argc, char **argv)
{
  (void)argv;
  if (argc != 1)
    {
      printf("not referencing tvar\n");
    }
  else
    {
      printf("incrementing tvar..\n");
      ++tvar;
      printf("   .. done (%i)\n", tvar);
    }
  printf("exiting....\n");
  exit (0);
}

