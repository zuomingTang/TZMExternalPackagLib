//
//  JsonUtils.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 16/11/12.
//  Copyright © 2016年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface JsonUtils : NSObject


/**
 *  数组或字典转json字符串
 @return  json字符串
 */
+(NSString *)dataToJsonString:(id)object;


/**
 json字符串转字典
 */
+(NSDictionary *)jsonStrToDictionary:(NSString *)str;


/**
 json字符串转数组
 */
+(NSArray *)jsonStrToArray:(NSString *)str;



/**
 将字符串进行md5加密
 @param str 原字符串
 @return 加密后的字符串
 */
+ (NSString *)md5:(NSString *)str;

@end
