//
//  KKSingleMatchManager.h
//  kookongIphone
//
//  Created by shuaiwen on 2017/9/20.
//  Copyright © 2017年 shuaiwen. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger,KKSingleKeyMatchType) {
    KKSingleKeyMatchConfirmID, //匹配成功
    KKSingleKeyMatchContinue,  //继续匹配
    KKSingleKeyMatchFailed,     //匹配失败
    KKSingleKeyMatchDataDownFail
};


typedef void(^getMatchKeysBlock) (NSNumber * remoteid,NSArray * matchKeysArray,KKSingleKeyMatchType matchType);//返回匹配结果的block

@interface KKSingleMatchManager : NSObject
@property(nonatomic,copy)getMatchKeysBlock matchKeysBlock;

/**
 获取所有遥测的按键，按键会通过通知返回
 
 @param deviceTypeId 设备类型
 @param deviceSwitch 设备开关状态
 @param mr 当前品牌下所有的temoteid（用,拼接，例如：2397,1162,1177,1167,1192）
 @param matchBlock 返回结果（匹配成功，继续匹配，匹配失败）
 */
-(void)getMatchKeysWith:(NSNumber *)deviceTypeId deviceSwitch:(NSNumber *)deviceSwitch mr:(NSString *)mr matchBlock:(getMatchKeysBlock)matchBlock;


/**
 上报有用的按键

 @param matchKeyDict 单个按键的dict
 */
-(void)keyIsWorkingWith:(NSDictionary *)matchKeyDict;



/**
 测试完当前返回的所有按键，没有有用的，上报
 */
-(void)groupKeyNotWork;


@end
