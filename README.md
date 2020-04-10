# Introduction

**Platform**: Linux

RTMP like protocol implementation, but without complicated header, it can be used as realtime transfer.  

they are where it can be used to:  

1. realtime file transfer  

2. realtime video, like rtmp protocol, server is just transfer what he received and copy many of it to puller which is match up with packet app 
 
3. etc.  

This project has three part: pusher,server and puller  

if you familiar with rtmp protocal, it would be self-explanatory.  

**[RTMPPusher](https://github.com/BrianYi/RTMPPusher)**: pushing local data to server  

**[RTMPServer](https://github.com/BrianYi/RTMPServer)**: transfer data and copy it to multi-copy to many pullers  

**[RTMPPuller](https://github.com/BrianYi/RTMPPuller)**: pulling data from server   

**Detail about this project, please go to [RTMPServer](https://github.com/BrianYi/RTMPServer)**.

# Authors
- Brian Yi