//
//  PageInfo.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 16/11/16.
//  Copyright © 2016年 沐阳. All rights reserved.
//

#import "JdBaseModel.h"

@interface PageInfo : JdBaseModel

/** 第几页 */
@property (nonatomic) NSInteger pageIndex;
/** 一页多少项 */
@property  (nonatomic) NSInteger pageSize;
/** 是否分页 */
@property  (nonatomic) BOOL availablePage;

@end
