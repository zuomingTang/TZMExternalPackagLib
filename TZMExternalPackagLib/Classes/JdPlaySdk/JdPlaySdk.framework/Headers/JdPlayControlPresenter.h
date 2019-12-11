//
//  JdPlayControlPresenter.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 16/9/18.
//  Copyright © 2016年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "JdPlayControlContract.h"

@protocol PlayCtrlDelegate <NSObject>

/**
 当前播放歌曲改变的回调

 @param title 歌曲名
 */
- (void)onCurrentPlaySongChange:(NSString *)title;


/**
 当前播放状态改变的回调

 @param state true表播放状态 false表暂停状态
 */
- (void)onCurrentPlayStatusChange:(BOOL)state;

@end

@protocol SearchMusicDelegate <NSObject>

/**
 查询歌曲的回调
 
 @param songs 查询到的歌曲数组
 */
-(void)onSearchMusic:(NSMutableArray *)songs;

/**
 查询歌曲超时的回调
 */
-(void)onTimeOut;

@end

@protocol NextPlayDelegate <NSObject>

/**
 添加歌曲至下一首播放成功的回调
 */
- (void)onNextToPlaySuccess;

/**
 添加歌曲至下一首播放失败的回调

 @param msg 失败信息
 */
- (void)onNextToPlayFail:(NSString *)msg;

/**
 添加歌曲至下一首播放超时的回调
 */
- (void)onNextToPlayTimeOut;

@end

@interface JdPlayControlPresenter : NSObject<PlayCtrlPresenter>

@property (nonatomic,weak) id<PlayCtrlView>delegate;
@property (nonatomic,weak) id<PlayCtrlDelegate> ctrlDelgate;
@property (nonatomic,weak) id<SearchMusicDelegate> searchDelgate;
@property (nonatomic,weak) id<NextPlayDelegate> nextDelgate;


/**
    初始化
 */
+(instancetype)sharedManager;

/**
 *  媒体类信息的回调
 *  @param payLoadInfoStr 详细信息
 */
-(void)getCurrentPlayInfoWithType:(int)type action:(int)action payload:(char *)payLoadInfoStr;


@end
