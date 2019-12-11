//
//  JdDeviceClock.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 17/3/13.
//  Copyright © 2017年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JdBaseModel.h"

/** 普通闹钟 */
#define ALARM_TYPE_ALARM        1
/** 开机闹钟 */
#define ALARM_TYPE_POWER_ON     2
/** 关机闹钟 */
#define ALARM_TYPE_POWER_OFF    3


@interface JdDeviceClock : JdBaseModel


/**
 闹铃id 时间戳 必填
 */
@property (nonatomic,strong) NSNumber * clockId;

/**
 闹铃时间必填(格式 "yyyy-MM-dd")
 */
@property (nonatomic,copy) NSString * clockDate;

/**
 闹铃时间 必填(格式 "HH:mm:ss")
 */
@property (nonatomic,copy) NSString * clockTime;

/**
 普通闹钟   ALARM_TYPE_ALARM        1
 开机闹钟   ALARM_TYPE_POWER_ON     2
 关机闹钟   ALARM_TYPE_POWER_OFF    3
 */
@property (nonatomic,assign) int  alarmType;


/**
 闹铃标签
 */
@property (nonatomic,copy) NSString * clockEvent;

/**
 闹铃音乐路径 暂时不支持
 */
@property (nonatomic,copy) NSString * clockUrl;

/**
 闹钟名称
 */
@property (nonatomic,copy) NSString * alarmName;

/**
 闹铃是否生效 必填（1生效 0不生效）
 */
@property (nonatomic,copy) NSString * alarmEffect;

/**
 闹铃类型 必填
 TYPE_REPEAT = "repeat";时间类型 (重复)  选择了重复日期时设置
 TYPE_ABSOLUTE = "absolute";时间类型 (绝对) 单次闹钟设置
 TYPE_RELATIVE = "relative";时间类型 (相对) 暂时不支持
 */
@property (nonatomic,copy) NSString * clockType;

/**
 闹铃重复（type 为"repeate"需填写 默认为"00000000000" 前四位预留 后七位分别表示从周一到周天）
 */
@property (nonatomic,copy) NSString * clockRepeat;

/**
 间隔（type 为"relative"需填写）
 */
@property (nonatomic,copy) NSString * clockInterval;

/**
 范围 暂时不支持
 */
@property (nonatomic,copy) NSString * clockRange;



/**
 通过类型筛选闹钟
 
 @param arr  闹钟数组
 @param type 闹钟类型 <普通、开机、关机>
 @return    筛选后的闹钟
 */
+(NSArray *)filterWithArr:(NSMutableArray *)arr withType:(int)type;



/**
 模型转json字符串
 
 @param clock   闹钟对象
 @param tip     闹钟提示语  比如：起床  睡觉等
 @param type    闹钟内省
 @return json字符串
 */
+(NSString *)buildJsonWithClock:(JdDeviceClock *)clock tip:(NSString *)tip type:(int)type;



/**
 字典转模型
 */
+(JdDeviceClock *)clockDicToModel:(NSDictionary *)dic;


@end
