//
//  JdPlayControlContract.h
//  JdPlayOpenSDKWithUI
//
//  Created by 沐阳 on 16/9/18.
//  Copyright © 2016年 沐阳. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EglSong.h"

@protocol PlayCtrlView <NSObject>
/**
 *  设置音量百分比
 *
 *  @param percent 0-100 音量百分比
 */
-(void)setVolume:(int)percent;
/**
 *  设置当前播放时间
 *
 *  @param position 时间，单位秒
 */
-(void)setPosition:(int)position;
/**
 *  设置总时间
 *
 *  @param duration 时间，单位秒
 */
-(void)setDuration:(int)duration;
/**
 *  设置跳播
 *
 *  @param percent 跳播的百分比 0-1
 */
-(void)setSeekProgress:(float)percent;
/**
 *  设置播放或暂停状态
 *
 *  @param isPlay  0:暂停 1:播放
 */
-(void)setPlayOrPause:(BOOL)isPlay;
/**
 *  设置播放模式
 *
 *  @param order 0：顺序播放 1：单曲循环 2：随机播放
 */
-(void)setPlayMode:(int)order;
/**
 *  设置歌曲名称
 *
 *  @param name 歌曲名称
 */
-(void)setSongName:(NSString *)name;
/**
 *  设置歌手名称
 *
 *  @param name 歌手名称
 */
-(void)setSingerName:(NSString *)name;
/**
 *  设置专辑图片链接
 *
 *  @param url 专辑图片链接
 */
-(void)setAlbumPic:(NSString *)url;
/**
 *  设置播放列表
 *
 *  @param songs 播放列表
 */
-(void)setPlaylist:(NSArray *)songs;


/**
 *  编辑播放列表的反馈状态
 *  @param code 状态码   0 成功  非0 不成功
 */
-(void)onEditPlaylist:(int)code;




@end

@protocol PlayCtrlPresenter <NSObject>
/**
 *  播放暂停切换
 */
-(void)togglePlay;
/**
 *  下一首
 */
-(void)next;
/**
 *  上一首
 */
-(void)prev;
/**
 *  改变播放模式
 */
-(void)changePlayMode;
/**
 *  设置音量
 *
 *  @param percent 0-100 音量百分比
 */
-(void)changeVolume:(int)percent;
/**
 *  跳播
 *
 *  @param percent 跳播百分比
 */
-(void)seekTo:(float)percent;
/**
 *  获取播放列表
 */
-(void)getPlayList;
/**
 *  播放播放列表中点击的歌曲
 *
 *  @param pos 选中的歌曲在播放列表中的下标（从0开始）
 */
-(void)playPlaylistWithPos:(int)pos;

/**
 *  获取当前播放模式
 *  0：顺序播放 1：单曲循环 2：随机播放
 */
-(int)getPlayMode;

/**
 *  清空整个列表
 */
-(void)clearPlayList;

/**
 *  根据下标删除当前播放列表中的某首歌
 *  @param pos  待删除的歌曲下标
 */
-(void)deletePlayListByPos:(int)pos;


/**
 *  设置歌曲为下一首播放
 *  @param song 待播放的歌曲
 */
-(void)addSongToNextPlay:(EglSong *)song;


/**
 搜索歌曲
 @param keyword 被搜索的关键字
 */
-(void)searchMusicWithKeyword:(NSString *)keyword;

@end

@interface JdPlayControlContract : NSObject



@end
