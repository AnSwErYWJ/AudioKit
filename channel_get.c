/*************************************************************************
	> File Name: channel_get.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 21 Nov 2016 04:59:30 PM CST
 ************************************************************************/

/*
 * Usage: channel_get input_channel(s) input_file output_channel_number output_file
 * Function: get one of the channels from input_file, save sa output_file
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"buffer.h"
#include"config.h"

int main(int argc, const char *argv[])
{
    /* judge arg */
    if(argc != 5)
    {
        fprintf(stderr,"Usage: channel_get input_channel(s) input_file output_channel_number output_file\n");
        exit(EXIT_FAILURE);
    }
    
    int raw = atoi(argv[1]);
    int n = atoi(argv[3]); // which channel
    if (raw <= 0 || n <= 0 || raw > 16 || n > 16)
    {
        fprintf(stderr,"Error: channel(s) must be positive number and max channels is 16.\n");
        exit(EXIT_FAILURE);
    }
    
    /* judge channel(s) */
    if (raw == 1)
    {
        fprintf(stderr,"Note: %s is mono audio data,exit.\n",argv[2]);
        exit(EXIT_SUCCESS);
    }
    else if (raw >= n)
    {
        printf("Action: get NO.%d channel data from %s\n",n,argv[2]);
    }
    else
    {
        fprintf(stderr,"Error: %s is only %d channels,No.%d output_channel out of range.\n",argv[2],raw,n);
        exit(EXIT_FAILURE);
    }

    /* open file */
    FILE *in = fopen(argv[2],"rb");
    if(in == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    FILE *out = fopen(argv[4],"wb");
    if(out == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[4]);
        exit(EXIT_FAILURE);
    }

    //int frame_len = sizeof(short int) * raw;
    short int *in_buf = (short int *)audio_calloc(raw,LENGTH);
    short int *out_buf = (short int *)audio_calloc(1,LENGTH);
    
    printf("Running message:\n  input_file:%s\n  input_channel(s):%d\n  output_file:%s\n  output_channel(s):%d\n\n",argv[2],raw,argv[4],n);
    
    while(1)
    {
        if(fread(in_buf,LENGTH,raw,in) != raw)
            break;

        out_buf[0] = in_buf[n-1];
        
        fwrite(out_buf,LENGTH,1,out);
        memset(in_buf, 0, raw*LENGTH);
        memset(out_buf, 0, 1*LENGTH);
    }
   
    audio_free(in_buf);
    audio_free(out_buf);
    fclose(in);
    fclose(out);
    
    printf("\nSuccess\n");
    
    return 0;
}
