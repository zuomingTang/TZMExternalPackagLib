//
//  JdBinderInfo.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 17/6/13.
//  Copyright © 2017年 沐阳. All rights reserved.
//

#import "JdBaseModel.h"

@interface JdBinderInfo : JdBaseModel

/**
 *  绑定者从属关系
 */
@property (nonatomic,assign) int  binderDependentType;

/**
 *  绑定者性别
 */
@property (nonatomic,assign) int  binderGender;

/**
 *  联系人的绑定类型 TYPE_QQ = 1   TYPE_WX = 2  TYPE_BOX = 3
 */
@property (nonatomic,assign) int  binderType;

/**
 *  绑定者id
 */
@property (nonatomic,assign) long long  tinyId;

/**
 *  头像url
 */
@property (nonatomic,copy) NSString * headUrl;

/**
 *  昵称
 */
@property (nonatomic,copy) NSString * nickName;


+(JdBinderInfo *)binderInfoWithDict:(NSDictionary *)dic;

@end
