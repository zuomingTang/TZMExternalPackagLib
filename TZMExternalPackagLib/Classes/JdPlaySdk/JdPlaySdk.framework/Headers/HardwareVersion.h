//
//  HardwareVersion.h
//  JDMusic
//
//  Created by 沐阳 on 16/8/9.
//  Copyright © 2016年 henry. All rights reserved.
//

#import "JdBaseModel.h"



@interface HardwareVersion : JdBaseModel


@property (nonatomic,copy) NSString * board;
@property (nonatomic,copy) NSString * btModel;
@property (nonatomic,copy) NSString * device;
@property (nonatomic,copy) NSString * hardware;
@property (nonatomic,copy) NSString * manufacturer;
@property (nonatomic,copy) NSString * model;
@property (nonatomic,copy) NSString * password;
@property (nonatomic,copy) NSString * product;
@property (nonatomic,copy) NSString * smartHomeModel;
@property (nonatomic,copy) NSString * sn;
@property (nonatomic,copy) NSString * voiceModel;


+ (instancetype)hardVersionWithDictionary:(NSDictionary *)dic;

@end
