//
//  JdDevicePresenter.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 17/3/12.
//  Copyright © 2017年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JdDeviceContract.h"
#import "JdShareClass.h"


@interface JdDevicePresenter : NSObject<DeviceCtrlPresenter>

{
    JdShareClass * shareObj;
}

/** 存放代理对象的数组 */
@property (nonatomic,strong) NSMutableArray * delegateList;
/** 存放各类型闹钟的数组 */
@property (nonatomic,strong) NSMutableArray * alarmArr;
/** 存放各类型下一个响应闹钟的数组 */
@property (nonatomic,strong) NSMutableArray * nextAlarms;

/** log打印开关 */
@property (nonatomic,assign) Boolean  enableDebug;

/**
 初始化
 */
+(instancetype)shareInstance;


/**
 设备端回调方法

 @param type   类型
 @param action 指令
 @param str    详情
 */
-(void)getCurrentDeviceInfo:(int)type action:(int)action str:(NSString *)str;

@end
