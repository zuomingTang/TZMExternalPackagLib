//
//  NonACManager.h
//  kookongIphone
//
//  Created by shuaiwen on 16/3/15.
//  Copyright © 2016年 shuaiwen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface NonACManager : NSObject
/**
 重写的类的init方法
 
 @param irData {@"keys":@[按键的数据集合]}
 @return 类的对象
 */
- (instancetype)initWith:(NSDictionary * )irData;


/**
 给NonACManager类赋值
 
 @param irData {@"keys":@[按键的数据集合]}
 */
-(void)KKNonACManagerWith:(NSDictionary * )irData __deprecated_msg("该接口已废弃，请使用initWith: 代替");


/**
 获取所有的按键数据集合
 
 @return 所有的按键数据集合
 */
-(NSArray *)getAllKeys;


/**
 获取remoteid
 
 @return remoteid
 */
-(int)getRemoteID;


/**
 获取遥控器参数
 
 @return 遥控器参数
 */
-(NSArray *)getParams;


/**
 根据fkey获取按键参数
 
 @param fkey fkey
 @return 按键参数
 */
-(NSArray *)getKeyIrWith:(NSString *)fkey __deprecated_msg("该接口已废弃，请使用getKeyIrWithFid:");


/**
 根据fid获取按键参数
 
 
 @param fid fid
 @return 按键参数
 */
-(NSArray *)getKeyIrWithFid:(NSNumber *)fid;

@end
