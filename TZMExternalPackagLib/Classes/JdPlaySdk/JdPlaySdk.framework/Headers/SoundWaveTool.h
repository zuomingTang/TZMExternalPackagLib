//
//  SoundWaveTool.h
//  DemoSwtr
//
//  Created by 沐阳 on 17/2/28.
//  Copyright © 2017年 lys. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#include "encode.h"


#define QUEUE_BUFFER_SIZE 4 //队列缓冲个数
#define EVERY_READ_LENGTH 1000 //每次从文件读取的长度
#define MIN_SIZE_PER_FRAME 2000 //每侦最小数据长度
#define SAMPLE_RATE_SENDER     44100   //采样率

@protocol SoundWaveDelegate <NSObject>

/**
 
 声波发送完毕的接口
 */
- (void)onSoundWaveEnd;

@end


@interface SoundWaveTool : NSObject

{
    
    AudioStreamBasicDescription audioDescription;///音频参数
    AudioQueueRef audioQueue;//音频播放队列
    AudioQueueBufferRef audioQueueBuffers[QUEUE_BUFFER_SIZE];//音频缓存
    NSLock *synlock ;///同步控制
    Byte *pcmDataBuffer;//pcm的读文件数据区
}

@property (nonatomic,copy) NSString * wifiName;
@property (nonatomic,copy) NSString * wifiPwd;
@property (nonatomic,copy) NSString * randomNum;

@property (nonatomic,weak) id<SoundWaveDelegate> delegate;

/**
 获取网关
 @return  WiFi名
 */
- (NSString*)getWifiName;

/**
 开始发送声波

 @param pwd WiFi密码
 */
- (void)startPlayWithPwd:(NSString *)pwd;


/**
 退出配网模式
 */
-(void)exitNetConfig;

/**
 获取声波随机数

 @return 随机数字符串
 */
- (NSString *)generatedRandomNumber;


@end
