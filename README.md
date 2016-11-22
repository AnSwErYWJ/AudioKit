# 一些音频切割合成工具

# 基础知识介绍
- 采样率,代表一秒种采样的点,如采样率为16KHZ,则表示1s采样16k个点.
- 若音频为8声道音频,则1个采样点(帧)有8个声道,每个声道16位(样本长度),即2个字节.

# AudioKi 
[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badge/)
[![stable](http://badges.github.io/stability-badges/dist/stable.svg)](http://github.com/badges/stability-badges)

## Introduction
This is an audio resamplerate program based on [Secret Rabbit Code](http://www.mega-nerd.com/SRC/index.html) and [iniparser](http://ndevilla.free.fr/iniparser).

## Installation
```
$ git clone git@github.com:AnSwErYWJ/AudioResamplerate.git
```

## Usage
1. Compile:
    ```
    # to generate .so
    $ make iniparser
    $ make log
    $ make resamplerate
    ```
    
    ```
    # to generate bin
    $ make all
    ```

2. Modify the [**config.ini**](https://github.com/AnSwErYWJ/AudioResamplerate/blob/master/config.ini) to configure the parameters, input support PCM or WAV audio files, and output only support PCM audio files.

3. Then,run your program with :
    ```
    $ chmod +x configure.sh
    $ sh configure.sh
    $ ./bin/resamplerate
    ```

## Environment
+ Linux
+ POSIX C
+ Bash Shell

## Todo
- [ ] Use TOML replace iniparser.

## Reference
- [Convering 8/16/32 bits/sample array to floats-array](http://stackoverflow.com/questions/4632502/waveinproc-windows-audio-question)

## About me
[![forthebadge](http://forthebadge.com/images/badges/ages-20-30.svg)](http://forthebadge.com)
- WebSite：[http://www.answerywj.com](http://www.answerywj.com)
- Email：[yuanweijie1993@gmail.com](https://mail.google.com)
- GitHub：[AnSwErYWJ](https://github.com/AnSwErYWJ)
- Blog：[AnSwEr不是答案的专栏](http://blog.csdn.net/u011192270)
- Weibo：[@AnSwEr不是答案](http://weibo.com/1783591593)

## Copyright and License
[![GPL Licence](https://badges.frapsoft.com/os/gpl/gpl.svg?v=103)](https://opensource.org/licenses/GPL-3.0/)

    AudioResamplerate
    Copyright (C) 2016  AnSwErYWJ

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
