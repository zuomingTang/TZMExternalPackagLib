//
//  JdDeviceListPresenter.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 16/9/19.
//  Copyright © 2016年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JdDeviceListContract.h"

@interface JdDeviceListPresenter : NSObject<DeviceListPresenter>

@property (nonatomic,weak) id<DeviceListView> delegate;
@property (nonatomic,weak) id<SoundWaveDeviceDelegate> soundWaveDelegate;
@property (nonatomic,strong) NSMutableArray * deviceListArr;

//声波配网时产生的设备随机数    用于区分连接的是哪台设备
@property (nonatomic,copy) NSString * deviceRandom;



/**
 *  初始化
 *
 *  @return JdDeviceListPresenter实例
 */
+(instancetype)sharedManager;

/**
 *  获取当前设备信息
 */
-(void)getDeviceStateInfo:(char *)deviceInfoStr;

@end
