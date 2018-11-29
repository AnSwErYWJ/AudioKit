/*************************************************************************
	> File Name: channel_convert.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 16 Nov 2016 10:08:06 AM CST
 ************************************************************************/

/*
 * Usage: channel_convert input_channel(s) input_file output_channel(s) output_file
 * Function: cut mutilchannels audio data(cut from tail)
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
        fprintf(stderr,"Usage: channel_convert input_channel(s) input_file output_channel(s) output_file\n");
        exit(EXIT_FAILURE);
    }
    
    int raw = atoi(argv[1]);
    int new = atoi(argv[3]);
    if (raw <= 0 || new <= 0 || raw > 16 || new > 16) //channel(s) between 0 and 16
    {
        fprintf(stderr,"Error: channel(s) must be positive number and max channels is 16.\n");
        exit(EXIT_FAILURE);
    }
    
    /* judge channel */
    if (raw <= new)
    {
        fprintf(stderr,"Error: input_channel(s) must more than output_channel(s).\n");
        exit(EXIT_FAILURE);
    }
    else if(raw == 1)
    {
        fprintf(stderr,"NOTE: input_channel(s) must more than one,exit.\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Action: cut audio data\n");
    }

    /* open file */
    FILE *in = fopen(argv[2],"rb");
    if(in == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[2]);
        exit(EXIT_FAILURE);
    }
    fseek(in, 44, SEEK_SET);
    FILE *out = fopen(argv[4],"wb");
    if(out == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[4]);
        exit(EXIT_FAILURE);
    }

    short int *in_buf = (short int *)audio_calloc(raw,LENGTH);
    short int *out_buf = (short int *)audio_calloc(new,LENGTH);
    
    printf("Running message:\n  input_file:%s\n  input_channel(s):%d\n  output_file:%s\n  output_channel(s):%d\n\n",argv[2],raw,argv[4],new);
    
    int i = 0;
    
    while(1)
    {
        if(fread(in_buf,LENGTH,raw,in) != raw)
            break;

        for(i = 0;i < new;i++)
        {
            out_buf[i] = in_buf[i]; // cut
        } 
        
        fwrite(out_buf,LENGTH,new,out);
        memset(in_buf, 0, raw*LENGTH);
        memset(out_buf, 0, new*LENGTH);
    }
   
    audio_free(in_buf);
    audio_free(out_buf);
    fclose(in);
    fclose(out);
    
    printf("\nSuccess\n");
    
    return 0;
}
