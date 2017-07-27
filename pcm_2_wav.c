/*************************************************************************
	> File Name: pcm_2_wav.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Thu 27 Jul 2017 05:34:10 PM CST
 ************************************************************************/

/*
 * Usage: pcm_2_wav <wave header length> <pcm file> <wave file>
 * Function: convert pcm file to wave file
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"buffer.h"
#include"config.h"

#define BUFFERSIZE 1024

int main(int argc, const char *argv[])
{
    /* judge arg */
    if(argc != 4)
    {
        fprintf(stderr,"Usage: pcm_2_wav <wave header length> <pcm file> <wave file>\n");
        exit(EXIT_FAILURE);
    }

    int header_len = atoi(argv[1]);

    if (header_len < 0 || header_len > 1024)
    {
        fprintf(stderr,"Error: wave header length must be between 0 and 1024 .\n");
        exit(EXIT_FAILURE);
    }

    FILE *in = fopen(argv[2],"rb");
    if(in == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    FILE *out = fopen(argv[3],"wb");
    if(out == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[4]);
        exit(EXIT_FAILURE);
    }

    fseek(out, header_len, SEEK_SET); // seek header_len in wave file

    short int *data_buf = (short int *)audio_calloc(1,BUFFERSIZE);

    printf("Running message:\n  wave header length: %d\n  pcm file: %s\n  wave file: %s\n",header_len,argv[2],argv[3]);

    while(1)
    {
        if(fread(data_buf,BUFFERSIZE,1,in) != 1)
            break;

        fwrite(data_buf,BUFFERSIZE,1,out);
        memset(data_buf, 0, BUFFERSIZE);
    }

    audio_free(data_buf);
    fclose(in);
    fclose(out);

    printf("Success\n");

    return 0;
}
