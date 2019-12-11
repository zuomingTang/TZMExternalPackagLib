
#import <Foundation/Foundation.h>
#import "JdCategoryModel.h"
#import "SongListTypeUtils.h"
#import "PageInfo.h"
#import <UIKit/UIKit.h>


@interface RequestParam : NSObject


@property(nonatomic,strong) id ext1;

/**
 * 当前要请求的id
 */
@property(nonatomic,copy) NSString * id;

/**
 * 目录级别 0-》1-》2 获取category时用
 */
@property(nonatomic,assign) int level;

@property (nonatomic,strong) NSNumber * musicSourceId;

/**
 * 当前要请求的名字
 */
@property(nonatomic,copy) NSString *name;


/**
 *  分页对象
 */
@property(nonatomic,strong) PageInfo * pageInfo;

/**
 * 父节点，如当前界面专辑界面，父节点就是MusicCategoroes
 */
@property(nonatomic,retain) NSObject *parent;

/**
 *  歌曲类型
 */
@property(nonatomic) int type;


/**
 *  版本号
 */
@property(nonatomic,assign) int version;



/**
 *  根据分类模型创建RequestParam
 */
+ (RequestParam *)createRequestParamWithCategory:(JdCategoryModel *)category;

@end
