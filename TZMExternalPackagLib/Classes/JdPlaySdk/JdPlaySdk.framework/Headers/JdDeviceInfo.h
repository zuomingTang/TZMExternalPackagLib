//
//  JDDeviceInfo.h
//  JdPlayOpenSDK
//
//  Created by 沐阳 on 16/5/20.
//  Copyright © 2016年 x-focus. All rights reserved.
//

#import "JdBaseModel.h"
#import "HardwareVersion.h"
#import "SoftwareVersion.h"

@interface JdDeviceInfo : JdBaseModel


/** 硬件版本 */
@property (nonatomic,strong) HardwareVersion * hardwareVersion;
/** 软件版本 */
@property (nonatomic,strong) SoftwareVersion * softwareVersion;
/** 设备名称 */
@property (nonatomic,copy) NSString * name;
/** 设备唯一标识 */
@property (nonatomic,copy) NSString * uuid;
/** 设备版本号 */
@property (nonatomic,copy) NSString * version;
/** 设备声波配网产生的随机数 */
@property (nonatomic,copy) NSString * swRand;
/** 设备在线状态 */
@property (nonatomic,assign) int onlineStatus;
/** 设备闹钟数组 */
@property (nonatomic,strong) NSMutableArray * clockArray;



/**
 *  初始化
 */
+ (instancetype)deviceInfoWithDictionary:(NSDictionary *)dictionary;

@end
