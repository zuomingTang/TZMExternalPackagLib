//
//  TimeUtils.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 17/3/13.
//  Copyright © 2017年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TimeUtils : NSObject


/**
 将时间转化为中文（某年某月某日某天某时某分某秒）
 */
+(NSString *) getChineaseTimeStr:(int64_t) period;


/**
 获取目标时间与当前时间差
 @param nowTime 当前时间
 @param targetTime 目标时间
 @return 时间差
 */
+(NSString *) getDifference:(int64_t) nowTime withTargeTime:(int64_t) targetTime;


/**
 获取闹钟每周的重复时间
 */
+(NSString*)getWeekTime:(NSString*)clockRepeat;



/**
 获取毫秒时间戳
 */
+(NSString*)getTimeInterval;

@end
