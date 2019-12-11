//
//  JdLrtsJSInterface.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 17/4/12.
//  Copyright © 2017年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

//首先创建一个实现了JSExport协议的协议
@protocol JSObjectProtocol <JSExport>

-(void)openVideo:(NSString*)url;

@end

@interface JdLrtsJSInterface : NSObject<JSObjectProtocol>
{
    @private
    int index;
}


@end
