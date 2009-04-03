#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main( int argc, char *argv[] )
{
   struct stat fileStatus;

   if ( stat( argv[1], &fileStatus ) < 0 )
      perror( "Stat file" );
   else
      printf("File of %d bytes, last accessed at %s\n",
         fileStatus.st_size, ctime(&fileStatus.st_atime));
}
