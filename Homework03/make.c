/********************************************
*********************************************
****TABS DO NOT COUNT AS WHITESPACE****
*********************************************
********************************************/


#include <stdlib.h>
#include <stdio.h>
#include "string.h"

int main ( int argc, char *argv[] )
{
    const char *filename = "MAKEFILE";
    FILE *file = fopen ( filename, "r" );
    FILE *temp = NULL;
    if ( file != NULL )
    {
        char line [ 128 ] = "";
        char targetList [ 200 ] = "";
        int command = 0;
        char commands [ 128 ][ 128 ];
        for(int i = 0; i < 128; i++)
            for(int j = 0; j < 128; j++)
                commands[i][j] = "";

        while ( fgets ( line, sizeof line, file ) != NULL )
        {
            int colonLocation = strchr ( line, 58 ) ? strchr ( line, 58 ) - line : 0;
            if ( colonLocation )
            {
                strncat ( targetList, line, colonLocation ); strcat ( targetList, " " );
                char *pch = line + colonLocation;
                pch = strtok ( pch, " :\n" );
                while (pch != NULL)
                {
                    //printf ( "%s\n", pch );
                    pch = strtok ( NULL, " :\n" );
                } command++;
            } else
            {
                commands [ command ] = line;
            }
        }
        fclose ( file );
        
        for ( int i = 0; i < 200; i++ )
            puts ( commands [ i ] );
    }
    else
    {
        perror ( filename );
    }
    
    return 0;
}
