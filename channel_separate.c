/*************************************************************************
	> File Name: channel_separate.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 21 Nov 2016 04:55:18 PM CST
 ************************************************************************/

/*
 * Usage: channel_separate input_channel(s) input_file
 * Function: separate the input_file, save as ./channeln.pcm(n is number of channel)
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include"buffer.h"
#include"config.h"

int main(int argc, const char *argv[])
{
    /* judge arg */
    if(argc != 3)
    {
        fprintf(stderr,"Usage: channel_separate input_channel(s) input_file\n");
        exit(EXIT_FAILURE);
    }

    int raw = atoi(argv[1]);

    /* judge channel(s) */
    if (raw <= 0 || raw > 16)
    {
        fprintf(stderr,"Error: channel(s) must be positive number and max channels is 16.\n");
        exit(EXIT_FAILURE);
    }
    else if (raw == 1)
    { 
        fprintf(stderr,"Note: %s is mono audio data,exit.\n",argv[2]);
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Action: separate channel(s)\n");
    }

    /* open file */
    FILE *in = fopen(argv[2],"rb");
    if(in == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("Running message:\n  input_file:%s\n  input_channel(s):%d\n\n",argv[2],raw);

    int frame_len = LENGTH * raw;

    /* get size of input_file */
    struct stat statbuf;
    stat(argv[2],&statbuf);
    size_t size = statbuf.st_size; // st_size: long long int/long int 64/32
    //printf("%d\n",size);
    size = size%frame_len ? size - size%frame_len : size;  // file size
    //printf("%ld\n",size);
    size_t n = size/frame_len; // dot numbers

    /* read input_file to buf */
    short int *in_buf = (short int *)audio_calloc(1,size);
    if(fread(in_buf,1,size,in) != size)
    {
        fprintf(stderr,"Error:read %s failed.\n",argv[2]);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    size_t j = 0;
    FILE *out = NULL;
    short int *out_buf = (short int *)audio_calloc(n,LENGTH);

    char *output_file = (char *)audio_calloc(1,14);
    for (i = 0;i < raw;i++)
    {
        /* create output file */
        sprintf(output_file,"channel%d.pcm",i+1);
        // printf("%s\n",output_file);
        out = fopen(output_file,"wb");
        if(out == NULL)
        {
            fprintf(stderr,"Error:%s open failed!\n",output_file);
            exit(EXIT_FAILURE);
        }

        /* write one channel to output file */
        for (j = 0;j < n;j++)
        {
            out_buf[j] = in_buf[i+j*raw];
        }
        fwrite(out_buf,LENGTH,n,out);

        memset(out_buf, 0, n*LENGTH);
        memset(output_file, 0, 14);
        fclose(out);
    }

    audio_free(in_buf);
    audio_free(out_buf);
    audio_free(output_file);
    fclose(in);
    
    printf("\nSuccess,output_files in current dirctory.\n");

    return 0;
}
