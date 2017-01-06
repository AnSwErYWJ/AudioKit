/*************************************************************************
	> File Name: buffer.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Mon 21 Nov 2016 05:54:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"buffer.h"

void *audio_calloc(size_t n,size_t size)
{
    void *men;
    
    men = (void *)calloc(n,size);
    if(men == NULL)
    {
        fprintf(stderr,"Error:calloc failed!\n");
        exit(EXIT_FAILURE);
    }
    
    return men;
}

void audio_free(void *men)
{
    if (men != NULL)
    {
        free(men);
        men = NULL;
    }
}

