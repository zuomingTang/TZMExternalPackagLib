//
//  JdMusicSourcePresenter.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 16/11/12.
//  Copyright © 2016年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JdMusicResourceContract.h"



@interface JdMusicResourcePresenter : NSObject<MusicResourcePresenter>


@property (nonatomic,weak)   id<MusicResourceView> mView;


/**
 初始化方法

 @param vc 代理对象
 @return JdMusicResourcePresenter实例
 */
-(JdMusicResourcePresenter *)initWithDelegate:(id<MusicResourceView>)vc;



@end
