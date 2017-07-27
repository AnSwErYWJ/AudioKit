# AudioKits 
[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badge/)
[![stable](http://badges.github.io/stability-badges/dist/stable.svg)](http://github.com/badges/stability-badges)

## Introduction
This is a series of kits to opreate audio data.

Welcome pull request to me , if you have any other kits or recommendations.


## Installation
```
$ git clone git@github.com:AnSwErYWJ/AudioKits.git
```

## Usage
1. Compile: you can modify ``SRC`` in ``Makefie`` to change kits.
    ```
    $ make
    ```
    
2.   Modify ``Sample length`` in ``config.h``,default is **signed 16 bit**.
    
    
3. Then,run your program with :
    ```
    # cut mutilchannels audio data(cut from tail) 
    $ channel_convert input_channel(s) input_file output_channel(s) output_file
    
    # get one of the channels from mutilchannels audio 
    $ ./channel_get input_channel(s) input_file output_channel_number output_file
    
    # merge some mono audios to one mutilchannels audio
    $ ./channel_merge output_channel(s) input_file1(mono) input_file2(mono) ... input_filen(mono) output_file
    
    # separate one mutilchannels audio to some mono audios
    $ ./channel_separate input_channel(s) input_file
    
    # read header infonmation of wave audio
    $ ./read_wavheader xxx.wav
    
    # convert pcm file to wave file
    $ ./pcm_2_wav <wave header length> <pcm file> <wave file>
    
    # convert wave file to pcm file
    $ ./wav_2_pcm <wave header length> <wave file> <pcm file>
    ```
    
4. clean:
    ```
    $ make clean
    ```

## Environment
+ Linux
+ POSIX C
+ Bash Shell

## Todo
- [ ] improve efficiency by multithreading

## About me
[![forthebadge](http://forthebadge.com/images/badges/ages-20-30.svg)](http://forthebadge.com)
- WebSite：[http://www.answerywj.com](http://www.answerywj.com)
- Email：[yuanweijie1993@gmail.com](https://mail.google.com)
- GitHub：[AnSwErYWJ](https://github.com/AnSwErYWJ)
- Blog：[AnSwEr不是答案的专栏](http://blog.csdn.net/u011192270)
- Weibo：[@AnSwEr不是答案](http://weibo.com/1783591593)

## Copyright and License
BSD 2-Clause License

Copyright (c) 2016-2017, AnSwErYWJ(Weijie Yuan),yuanweijie1993@gmail.com
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
