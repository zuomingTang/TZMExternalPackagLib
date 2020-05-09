//
//  JDPlayListModel.h
//  JdPlayOpenSDK
//
//  Created by 沐阳 on 16/5/24.
//  Copyright © 2016年 x-focus. All rights reserved.
//

#import "JdBaseModel.h"

@interface JdPlayListModel : JdBaseModel

/** 与设备的绑定键 */
@property (nonatomic,assign) int  bind_key;
/** 扩展字段 */
@property (nonatomic,copy) NSString * ext1;
/** 歌单列表md5加密后的字符串 */
@property (nonatomic,copy) NSString * md5;
/** 当前播放歌曲在列表中的位置 */
@property (nonatomic,assign) int  pos;
/** 歌单列表id */
@property (nonatomic,copy) NSString * song_list_id;
/** 歌单名称 */
@property (nonatomic,copy) NSString * song_list_name;
/** 歌单类型 */
@property (nonatomic,copy) NSString * song_list_type;
/** 该列表中的歌曲数组 */
@property (nonatomic,strong) NSMutableArray * songsArr;



/**
 *  初始化 
 */
+(instancetype)playListModelWithDictionary:(NSDictionary *)dictionary;

@end
