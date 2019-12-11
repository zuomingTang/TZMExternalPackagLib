//
//  JdMiGuJSInterface.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 17/4/12.
//  Copyright © 2017年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JdMiGuJSInterface : NSObject
{
    //歌曲下标
    int index;
}



/**
 播放歌曲

 @param data 带有歌曲信息的字典字符串
 @param songIdOrIndex 歌曲下标或是ID
 */
- (void)setPlaying:(NSString *)data song:(NSString *)songIdOrIndex;



@end
