/*************************************************************************
	> File Name: channel_convert.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Wed 16 Nov 2016 10:08:06 AM CST
 ************************************************************************/

/*
 * Usage: channel_convert input_channel(s) input_file output_channel(s) output_file
 *
 * Function: 支持音频切割(切尾巴)和合成(一路到多路,最大16路)
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"buffer.h"

int main(int argc, const char *argv[])
{
    if(argc != 5)
    {
        fprintf(stderr,"Usage: channel_convert input_channel(s) input_file output_channel(s) output_file\n");
        exit(EXIT_FAILURE);
    }
    
    int raw = atoi(argv[1]);
    int new = atoi(argv[3]);
    if (raw < 0 || new < 0 || raw > 16 || new > 16)
    {
        fprintf(stderr,"Error: channel(s) must be positive number and max channels is 16.\n");
        exit(EXIT_FAILURE);
    }
    
    /* channel judge */
    if (raw >= new)
    {
        printf("Action: cut audio data\n");
    }
    else if(raw != 1)
    {
        fprintf(stderr,"Error: only one channel data can be synthetised to multichannel audio data.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Action: synthetise audio data\n");
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

    int frame_len = sizeof(short int);
    short int *in_buf = (short int *)audio_calloc(raw,frame_len);
    short int *out_buf = (short int *)audio_calloc(new,frame_len);
    
    printf("Running message:\n  input_file:%s\n  input_channel(s):%d\n  output_file:%s\n  output_channel(s):%d\n\n",argv[2],raw,argv[4],new);
    
    int i = 0;
    
    while(1)
    {
        if(fread(in_buf,frame_len,raw,in) != raw)
            break;

        for(i = 0;i < new;i++)
        {
            if (raw == 1)
                out_buf[i] = in_buf[0];
            else
                out_buf[i] = in_buf[i];
        } 
        
        fwrite(out_buf,frame_len,new,out);
        memset(in_buf, 0, raw*frame_len);
        memset(out_buf, 0, new*frame_len);
    }
   
    printf("\nSuccess\n");

    audio_free(in_buf);
    audio_free(out_buf);
    fclose(in);
    fclose(out);
    
    return 0;
}
