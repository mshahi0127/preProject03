/*
 * Auth: Milan Shahi
 * Date: Oct. 8, 2021
 * Course: CSCI-4500(Sec: 002)
 * Desc:   PREPROJECT-3, The purpose of this program is to determine
 * if the file exists.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /*Comment Added */
    /*comment added to demo branch */
    /*hello*/

    /*Store the return value of mode F_OK*/
    int rvalRad;
    /*Store the return value of mode W_OK*/
    int rvalWrite;
    /*Store the return value of mode X_OK*/
    int rvalExecute;
    /*Store the return value of mode F_OK*/
    int rval;

    /*Check Whether users input commandline arguments*/
    if (argc < 2)
    {
        printf("ERROR: Usage: accesscheck <pathname>\n");
        exit(EXIT_FAILURE);
    }
    printf("Checking:  \"%s\" ...\n", argv[1]);

    rval = access(argv[1], F_OK);
    rvalExecute = access(argv[1], X_OK);
    rvalRad = access(argv[1], R_OK);
    rvalWrite = access(argv[1], W_OK);

    printf("F_OK = %d\n", rval);
    if (rval < 0)
    {
        printf("\tERROR: %s (errno = %d)\n", strerror(errno), errno);
    }
    printf("R_OK = %d\n", rvalRad);

    if (rvalRad < 0)
    {
        printf("\tERROR: %s (errno = %d)\n", strerror(errno), errno);
    }
    printf("W_OK = %d\n", rvalWrite);
    if (rvalWrite < 0)
    {
        printf("\tERROR: %s (errno = %d)\n", strerror(errno), errno);
    }
    printf("X_OK = %d\n", rvalExecute);
    if (rvalExecute < 0)
    {
        printf("\tERROR: %s (errno = %d)\n", strerror(errno), errno);
    }

    exit(EXIT_SUCCESS);
} /* end main  */