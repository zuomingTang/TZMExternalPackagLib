//
//  JdDeviceContract.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 17/3/12.
//  Copyright © 2017年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol DeviceStatusDelegate <NSObject>

@optional

/**
 获取设备模式的回调
 @param dict 装有模式的字典
 */
-(void)onGetDeviceMode:(NSMutableDictionary *)dict;
/**
 改变设备模式的回调
 @param mode 当前模式
 */
-(void)onChangeDeviceMode:(NSString *)mode;

/**
 获取设备开关机状态的回调
 @param result 开关机状态  result为1表示开机状态，为0表示关机状态
 */
-(void)onGetShutDowmStatus:(int)result;


/**
 获取设备所有闹钟的回调
 @param alarms 装有全部闹钟的数组  <包括普通闹钟、开机闹钟、关机闹钟>
 @param nextAlarms 装有下一个响应闹钟的数组   <包括普通闹钟、开机闹钟、关机闹钟>
 */
-(void)onGetAlarm:(NSMutableArray *)alarms nextAlarmArr:(NSMutableArray *)nextAlarms;


/**
 获取蓝牙名称的回调
 @param btName 蓝牙名称
 */
-(void)onGetBTName:(NSString *)btName;



/**
 获取蓝牙密码的回调
 @param btPwd 蓝牙密码
 */
-(void)onGetBTPassword:(NSString *)btPwd;



/**
 获取灯开关状态的回调
 @param mode 开关状态  mode值为1表示开，为0表示关
 */
-(void)onGetLightMode:(int)mode;



/**
 获取灯亮度的回调
 @param bright 灯的亮度  取值范围在0 ~ 100
 */
-(void)onGetLightBrightness:(int)bright;



/**
 获取登录状态的回调
 @param res 状态信息
 */
-(void)onGetSmartLogInfo:(NSString *)res;



/**
 设置闹钟的回调
 @param res 闹钟id
 */
-(void)onSetClock:(NSString *)res;


/**
 更新闹钟的回调

 @param res   等于1表示更新成功，等于0表示更新失败
 */
-(void)onUpdateClock:(NSString *)res;

/**
 删除闹钟的回调
 
 @param res   等于1表示删除成功，等于0表示删除失败
 */
-(void)onDeleteClock:(NSString *)res;

/**
 设置蓝牙密码的回调
 
 @param res  蓝牙密码
 */
-(void)onSetBTPwd:(NSString *)res;

/**
 获取蓝牙名称的回调
 
 @param res 蓝牙名称
 */
-(void)onSetBTName:(NSString *)res;

/**
 更改设备名称的回调

 @param code 标志是否更改成功   code为1成功，为0失败
 @param data 设备名称
 */
-(void)onSetDeviceName:(int)code data:(NSString *)data;


/**
 设置设备模式的回调

 @param res  默认成功，暂不处理
 */
-(void)onSetDeviceMode:(NSString *)res;

/**
 设置灯开关的回调

 @param res 等于1表示设置成功，等于0表示设置失败
 */
-(void)onSetLightMode:(NSString *)res;

/**
 设置灯亮度的回调

 @param res  默认成功，暂不处理
 */
-(void)onSetLightBrightness:(NSString *)res;

/**
 登录回调

 @param code 为0表示登录成功 非0表示登录失败
 @param message 登录信息
 */
-(void)onSmartDeviceLogin:(int)code message:(NSString *)message;


/**
 登出回调

 @param code 为0表示登出成功 非0表示登出失败
 @param message 登出信息
 */
-(void)onSmartDeviceLogout:(int)code message:(NSString *)message;



/**
 注册成功的回调

 @param email 注册邮箱
 @param pwd 密码
 */
-(void)onRegisterSuccessWithEmail:(NSString *)email pwd:(NSString *)pwd;


/**
 注册失败的回调

 @param msg 失败详情
 */
-(void)onOperationFail:(NSString *)msg;


/**
 美的分享成功的回调
 */
-(void)onNotifyShareSuccess;

/**
 美的分享失败的回调
 @param errCode 错误码
 @param erroMsg 错误信息
 */
-(void)onNotifyShareFailWitherrCode:(int)errCode erroMsg:(NSString *)erroMsg;


/**
 *  获取设备绑定者的回调
 *  @param binders  绑定者数组
 */
-(void)onQueryBinderSuccess:(NSMutableArray *)binders;


/**
 *  解绑设备联系人的回调
 *  @param code  0 解绑成功  非0 解绑失败
 */
-(void)onUnbindSuccess:(int)code;


/**
 *  检查设备是否有更新的回调
 @param state 更新状态码  UPDATE_STATE_NO_UPDATE 无更新
                        UPDATE_STATE_MSG 更新过程中提示信息
                        UPDATE_STATE_START_UPDATE 存在更新 (存在更新调用startUpdate()则设备端会自动下载并更新)
 @param msg 更新消息
 */
-(void)onUpdate:(int)state msg:(NSString *)msg;

/**
 指令超时的回调
 */
-(void)onTimeOut;


/**
 取消分享失败
 @param code 错误码 0表成功  非0表失败
 @param msg 信息详情
 */
-(void)onQuitShareFail:(int)code msg:(NSString *)msg;

/**
 取消分享成功
 */
-(void)onQuitShareSuccess;
@end

@protocol DeviceCtrlPresenter <NSObject>

@optional


/** 参数设置详情见demo */


/**
 取消分享
 @param houseId 家庭ID
 */
-(void)quitShareHomeWithHouseId:(NSString *)houseId;

/** 设置闹钟 */
-(void)setClock:(NSString *)args;
/** 更新闹钟 */
-(void)updateClock:(NSString *)arg;
/** 删除闹钟 */
-(void)deleteClock:(NSString *)args;
/** 获取闹钟 */
-(void)getAlarmClock;


/** 更改设备名 */
-(void)setDeviceName:(NSString *)args;
/** 设置设备 开 关 */
-(void)setDeviceStatus:(BOOL)args;
/** 获取设备模式 */
-(void)getDeviceMode;
/** 获取开关机状态 */
-(void)getShutdownStatus;
/** 设置设备模式 */
-(void)setDeviceMode:(NSString *)args;



/** 获取蓝牙名称 */
-(void)getBtName;
/** 获取蓝牙密码 */
-(void)getBtPassword;
/** 设置蓝牙名称 */
-(void)setBtName:(NSString *)args;
/** 设置蓝牙密码 */
-(void)setBtPwd:(NSString *)args;



/** 获取灯状态 */
-(void)getLightMode;
/** 获取灯亮度 */
-(void)getLightBrightness;
/** 设置灯 开 关 */
-(void)setLightMode:(NSString *)args;
/** 设置灯亮度 */
-(void)setLightBrightness:(NSString *)args;



/** 检查设备更新 */
-(void)checkDeviceUpdate;
/** 开始更新设备 */
-(void)startUpdate;


/** 解除QQ物联绑定 */
-(void)unBindWithQQ;
/** 查询QQ物联绑定者列表
 *   TYPE_QQ = 1
 *   TYPE_WX = 2
 *   TYPE_BOX = 3
 */
-(void)getQQBinders:(int)binderType;


/** 登录 */
-(void)loginWithAccount:(NSString *)acc pwd:(NSString *)pwd;
/** 登出 */
-(void)logout:(NSString *)args;
/** 获取登录信息 */
-(void)getDeviceLogInfo;
/**
 注册
 @param vendor 厂商
 @param sn 设备的uuid
 */
-(void)mideaRegisterWithVendor:(NSString *)vendor sn:(NSString *)sn;
/**
 *  分享接口
 *  @param vendor 厂商
 */
-(void)notifyShareWithVendor:(NSString *)vendor msg:(NSString *)msg;


/**
 获取当前设备模式
 @return 设备模式
 */
-(NSString *)getCurrentDeviceMode;

@end

@interface JdDeviceContract : NSObject



@end
