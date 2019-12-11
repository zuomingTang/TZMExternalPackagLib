//
//  JDPayloadInfo.h
//  JdPlayOpenSDK
//
//  Created by 沐阳 on 16/5/21.
//  Copyright © 2016年 x-focus. All rights reserved.
//

#import "JdBaseModel.h"
#import "JdSongInfo.h"

@interface JdPayloadInfo : JdBaseModel

/** 歌曲持续时间 */
@property (nonatomic,assign) int  duration;
/** 歌曲信息对象 */
@property (nonatomic,strong) JdSongInfo * songInfo;
/** 播放模式 */
@property (nonatomic,copy) NSString * playmode;
/** 播放状态 */
@property (nonatomic,assign) int  playstate;
/** 当前播放位置 */
@property (nonatomic,assign) int  position;
/** 播放音量 */
@property (nonatomic,assign) int  volume;


/**
 *  初始化
 */
+(instancetype)payLoadInfoWithDictionary:(NSDictionary *)dictionary;


@end
