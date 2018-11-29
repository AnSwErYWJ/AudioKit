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
GNU General Public License v3.0

Copyright (C) <2018> AnSwErYWJ(Weijie Yuan),yuanweijie1993@gmail.com

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 3.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
