/*************************************************************************
	> File Name: read_wavheader.c
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Fri 06 Jan 2017 01:46:16 PM CST
 ************************************************************************/

/*
 * Usage: Usage: ./read_wavheader xxx.wav
 * Function: read header infonmation of wave audio
 */

#include <stdio.h>

typedef struct
{
    char  riff_id[4];                       //"RIFF"
    int   riff_datasize;                    // RIFF chunk data size,exclude riff_id[4] and riff_datasize,total - 8

    char  riff_type[4];                     // "WAVE"

    char  fmt_id[4];                        // "fmt "
    int   fmt_datasize;                     // fmt chunk data size,16 for pcm
    short fmt_compression_code;             // 1 for PCM
    short fmt_channels;                     // 1(mono) or 2(stereo)
    int   fmt_sample_rate;                  // samples per second
    int   fmt_avg_bytes_per_sec;            // sample_rate * channels * bit_per_sample / 8
    short fmt_block_align;                  // number bytes per sample, bit_per_sample * channels / 8
    short fmt_bit_per_sample;               // bits of each sample(8,16,32).

    char  data_id[4];                       // "data"
    int   data_datasize;                    // data chunk size,pcm_size - 44
}WaveHeader_t;

static int get_int(FILE *fp)
{
    char *s;
    int i;
    s = (char *)&i;
    size_t len = sizeof(int);
    int n = 0;
    for(;n < len;n++)
    {
    	s[n]=getc(fp);
    	//printf("%x\n",s[n]);
    }
    return i;
}

static short int get_sint(FILE *fp)
{
    char *s;
    short int i;
    s = (char *)&i;
    size_t len = sizeof(short);
    int n = 0;
    for(;n < len;n++)
    {
    	s[n]=getc(fp);
    	//printf("%x\n",s[n]);
    }

    return i;
}

static int read_wavheader(FILE *fp,WaveHeader_t *wavheader)
{
	if (fp ==NULL)
		return -1;

    fread(wavheader->riff_id,4,1,fp);
    wavheader->riff_datasize = get_int(fp);
    fread(wavheader->riff_type,4,1,fp);
    fread(wavheader->fmt_id,4,1,fp);
    wavheader->fmt_datasize = get_int(fp);
    wavheader->fmt_compression_code = get_sint(fp);
    wavheader->fmt_channels = get_sint(fp);
    wavheader->fmt_sample_rate = get_int(fp);
    wavheader->fmt_avg_bytes_per_sec = get_int(fp);
    wavheader->fmt_block_align = get_sint(fp);
    wavheader->fmt_bit_per_sample = get_sint(fp);
    fread(wavheader->data_id,4,1,fp);
    wavheader->data_datasize = get_int(fp);

    return 0;
}

static void print_wavheader(WaveHeader_t wavheader)
{
    printf("wavheader.riff_id: %c%c%c%c\n",wavheader.riff_id[0],wavheader.riff_id[1],wavheader.riff_id[2],wavheader.riff_id[3]);
    printf("wavheader.riff_datasize: %d\n",wavheader.riff_datasize);
    printf("wavheader.riff_type: %c%c%c%c\n",wavheader.riff_type[0],wavheader.riff_type[1],wavheader.riff_type[2],wavheader.riff_type[3]);
    printf("wavheader.fmt_id: %c%c%c%c\n",wavheader.fmt_id[0],wavheader.fmt_id[1],wavheader.fmt_id[2],wavheader.fmt_id[3]);
    printf("wavheader.fmt_datasize: %d\n",wavheader.fmt_datasize);
    printf("wavheader.fmt_compression_code: %hd\n",wavheader.fmt_compression_code);
    printf("wavheader.fmt_channels: %hd\n",wavheader.fmt_channels);
    printf("wavheader.fmt_sample_rate: %d\n",wavheader.fmt_sample_rate);
    printf("wavheader.fmt_avg_bytes_per_sec: %d\n",wavheader.fmt_avg_bytes_per_sec);
    printf("wavheader.fmt_block_align: %hd\n",wavheader.fmt_block_align);
    printf("wavheader.fmt_bit_per_sample: %hd\n",wavheader.fmt_bit_per_sample);
    printf("wavheader.data_id: %c%c%c%c\n",wavheader.data_id[0],wavheader.data_id[1],wavheader.data_id[2],wavheader.data_id[3]);
    printf("wavheader.data_datasize: %d\n",wavheader.data_datasize);
}

int main(int argc,char *argv[])
{
	WaveHeader_t wavheader;

	if (argc != 2)
	{
		fprintf(stderr,"Usage: ./read_wavheader xxx.wav\n");
		return -1;
	}

    FILE * fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        fprintf(stderr,"open file: %s failed.\n",argv[1]);
        return -1;
    }

    /* read */
    if (read_wavheader(fp,&wavheader) == -1)
        fprintf(stderr,"read header failed.\n");

    fclose(fp);
    fp = NULL;

    print_wavheader(wavheader);

    return 0;
}
