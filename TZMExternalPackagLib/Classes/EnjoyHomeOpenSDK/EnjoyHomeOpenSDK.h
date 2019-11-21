//
//  EnjoyHomeOpenSDK.h
//  EnjoyHomeOpenSDK
//
//  Created by Kimmo on 2019/10/15.
//  Copyright © 2019 EnjoyLink. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^authSuccess)(NSString *authCode);
typedef void (^authFail)(NSError *error);

/**
 需要被授权获取用户信息权限等级
 */
typedef NS_ENUM(NSInteger, EHAuthFetchInfoMode) {
    /** 默认等级--无需获取用户敏感信息，推荐静默模式授权使用 */
    EHAuthFetchInfoModeDefault,
    /** 基础信息等级--需要获取用户基础信息如头像昵称等，需用户确认授权方可使用 */
    EHAuthFetchInfoModeBasic,
    /** 超级权限等级--除头像昵称外还需要获取用户更多敏感信息如手机号等，需用户确认授权方可使用 */
    EHAuthFetchInfoModeSuper
};

enum  EHAuthErrCode {
    EHAuthErrCodeSuccess    = 0,    /**< 成功    */
    EHAuthErrCodeCommon     = -1,   /**< 普通错误类型    */
    EHAuthErrCodeUserCancel = -2,   /**< 用户点击取消并返回    */
    EHAuthErrCodeSentFail   = -3,   /**< 发送失败    */
    EHAuthErrCodeAuthDeny   = -4,   /**< 授权失败    */
    EHAuthErrCodeUnsupport  = -5,   /**< 享家不支持    */
};

@interface EnjoyHomeOpenSDK : NSObject

+ (BOOL)isAppInstalled;

+ (void)sendAuthLoginReqWithAppId:(NSString *)appId
                authFetchInfoMode:(EHAuthFetchInfoMode)authMode
                          Success:(authSuccess)success
                             Fail:(authFail)fail;

+ (void)handleOpenURL:(NSURL *)url;
@end
