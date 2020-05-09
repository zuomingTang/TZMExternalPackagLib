//
//  SoftwareVersion.h
//  JDMusic
//
//  Created by 沐阳 on 16/8/9.
//  Copyright © 2016年 henry. All rights reserved.
//

#import "JdBaseModel.h"



@interface SoftwareVersion : JdBaseModel

@property (nonatomic,copy) NSString * display;
@property (nonatomic,copy) NSString * jdplay;
/** 硬件平台 */
@property (nonatomic,copy) NSString * os;
@property (nonatomic,copy) NSString * packageName;
@property (nonatomic,assign) int phoneMinVersion;
@property (nonatomic,copy) NSString * releaseVersion;
/** 固件版本 */
@property (nonatomic,copy) NSString * releaseV;
@property (nonatomic,assign) int verCode;
@property (nonatomic,copy) NSString * verName;

+(instancetype)softwareWithDictionary:(NSDictionary *)dic;

@end
