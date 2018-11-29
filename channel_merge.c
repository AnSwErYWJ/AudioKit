/*************************************************************************
	> File Name: channel_merge.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 22 Nov 2016 02:12:58 PM CST
 ************************************************************************/

/*
 * Usage: channel_merge output_channel(s) input_file1(mono) input_file2(mono) ... input_filen(mono) output_file
 * Function: merge mono audio data to mutilchannels
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include"buffer.h"
#include"config.h"

/* 获取文件大小 */
static int get_size_of_file(const char *file,int channels)
{
    int frame_len = channels * LENGTH;

    /* get size of input_file */
    struct stat statbuf;
    stat(file,&statbuf);
    size_t size = statbuf.st_size; // st_size: long long int/long int 64/32
    //printf("%d\n",size);
    size = size%frame_len ? size - size%frame_len : size;  // file size
    //printf("%ld\n",size);
    return size;
}

int main(int argc, const char *argv[])
{
    /* judge arg */
    if(argc < 4)
    {
        fprintf(stderr,"Usage: channel_merge output_channel(s) input_file1(mono) input_file2(mono) ... input_filen(mono) output_file\n");
        exit(EXIT_FAILURE);
    }
    
    int raw = atoi(argv[1]);
    if (raw <= 0 || raw > 16) //channel(s) between 1 and 16
    {
        fprintf(stderr,"Error: channel(s) must be positive number and max channels is 16.\n");
        exit(EXIT_FAILURE);
    }
   
    /* judge channel */
    if (raw != (argc-3))
    {
        fprintf(stderr,"Error: output_channel(s) is not to equal numbers of input_files(mono).\n");
        exit(EXIT_FAILURE);
    }
    else if (raw == 1)
    {
        fprintf(stderr,"Note: output_channel is one,exit.\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Action: merge audio data\n");
    }

    int i = 0;
    size_t j = 0,n = 0;

    short int *in_buf = NULL;
    size_t size[raw];

    /* get size */
    //size_t allSize = 0;
    size_t calSize = 0;
    for(i = 0; i < raw;i++)
    {
        size[i] = get_size_of_file(argv[i+2],1);
        //allSize += size[i];
        if (i >= 1)
            calSize = size[i] > size[i-1]? size[i]:size[i-1];
    }
    calSize *= raw;
    short int *out_buf = (short int *)audio_calloc(1,calSize);
    //printf("%ld\n",allSize);
    //printf("%ld\n",calSize);
    
    /* message */
    printf("Running message:\n");
    printf("  input_file: ");
    for(i = 0;i < raw;i++)
    {
        printf("%s  ",argv[i+2]);
    }
    printf("\n  input_file_type:mono\n  output_file:%s\n  output_channel(s):%d\n\n",argv[raw+2],raw);

   
    /* read input_files to buf */
    for(i = 0;i < raw;i++)
    {
        FILE *in = fopen(argv[i+2],"rb");
        if(in == NULL)
        {
            fprintf(stderr,"Error:%s open failed!\n",argv[i+2]);
            exit(EXIT_FAILURE);
        }
        
        fseek(in, 44, SEEK_SET);
        in_buf = (short int *)audio_calloc(1,size[i]);
        //printf("%ld\n",size[i]);
        n = size[i]/(LENGTH*1);
        //printf("%ld\n",n);
        
        if(fread(in_buf,size[i],1,in) != 1)
            break;
        
        for(j = 0;j < n;j++)
        {
            out_buf[i+raw*j] = in_buf[j];
        }
       
        audio_free(in_buf);
        fclose(in);
    }
    
    /* write output_file */
    FILE *out = fopen(argv[raw+2],"wb");
    if(out == NULL)
    {
        fprintf(stderr,"Error:%s open failed!\n",argv[raw+2]);
        exit(EXIT_FAILURE);
    }
    fwrite(out_buf,calSize,1,out);
    audio_free(out_buf);
    fclose(out);
    
    printf("\nSuccess\n");

    return 0;
}


