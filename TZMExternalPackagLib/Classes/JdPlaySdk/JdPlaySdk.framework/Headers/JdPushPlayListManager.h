//
//  JdPushPlayListManager.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 16/11/14.
//  Copyright © 2016年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JdCategoryModel.h"

@interface JdPushPlayListManager : NSObject


/**
 *  初始化单例
 */
+(JdPushPlayListManager *)sharedInstance;



/**
 *  推送豆瓣歌单至设备端播放
 *  @param model 音乐分类模型
 */
- (void)pushDouBanListWithCategory:(JdCategoryModel *)model;



/**
 *  推送歌单中的某首歌曲至设备端播放
 *  @param models 歌曲数组
 *  @param index 要播放的歌曲在列表中的下标
 */
-(void)pushPlayListWithInfos:(NSArray *)models withIndex:(int)index;

@end
