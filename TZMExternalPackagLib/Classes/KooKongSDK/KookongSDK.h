//
//  KookongSDK.h
//  kookongIphone
//
//  Created by shuaiwen on 16/1/28.
//  Copyright © 2016年 shuaiwen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface KookongSDK : NSObject

/**
 *  （使用单，例）实例化一个KooKongSDK的对象
 *
 *  @return KooKongSDK的对象
 */
+(id)shareKooKongSDK;


/**
 设置SDK方案（默认为非压缩方案)

 @param scheme YES:压缩方案，NO:非压缩方案
 */
- (void)setKKSDKScheme:(BOOL)scheme;


/**
 *  验证权限
 *
 *  @param apikey     key
 *  @param uuidString （非数量限制客户，传nil即可，数量限制客户，传设备的id，该id是自己定义的，一个id代表一个设备）
 */
-(void)checkUserAuthority:(NSString * )apikey uuidString:(NSString *)uuidString __deprecated_msg("该接口已过期，请使用：checkUserAuthority: deviceId:");


/**
 *  验证权限
 *
 *  @param apikey     key
 *  @param deviceId （最好跟Android端保持一致，非数量限制客户，传nil即可，数量限制客户，传设备的id，该id是自己定义的，一个id代表一个设备）
 */
-(void)checkUserAuthority:(NSString * )apikey deviceId:(NSString *)deviceId;



/**
 *  1.根据定位到省 ，市，区，获取areaid
 *
 *  @param provinceName 省名称（山东省）
 *  @param cityName     市名称（青岛市）
 *  @param districtName 区名称（崂山区）
 *  taskid = 0
 */
-(void)getAreaIdWithProvince:(NSString *)provinceName City:(NSString *)cityName District:(NSString *)districtName;


/**
 *  2.根据areaid获取运营商列表
 *
 *  @param areaid 根据省，市，区获得的areaid
 *  taskid = 1
 */
-(void)getOperatersWithAreaid:(NSNumber*)areaid;


/**
 *  3.获取选中的运营商（spid）下，含有的所有的机顶盒的遥控器
 *  devicetypeid:   设备类型1：STB  2：TV  3：BOX  4：DVD   5：AC
 *  @param areaid 根据省，市，区获得的areaid
 *  @param spid   获取的运营商的spid
 *  @param did    devicetypeid
 *  @param bid    brandid
 *  taskid = 2
 */
-(void)getAllRemoteIdsWithAreaid:(NSNumber*)areaid spid:(NSNumber*)spid did:(NSNumber *)did bid:(NSNumber *)bid;


/**
 *  4.获取遥控器的红外码进行测试
 *
 *  @param remoteIds remoteid（可以是多个，分别用，隔开）
 *  taskid = 3
 */
-(void)getIRDataByIdWithRemoteIds:(NSString *)remoteIds __deprecated_msg("该接废弃，请使用：downloadIRDataByIdWithRemoteId: deviceTypeId:");

/**
 *  5.该接口不用访问
 *
 *  @param functionid
 *  @param remoteid
 *  @param remoteids
 *  taskid = 4
 */
//-(void)getFilterIRDataWithFunctionid:(NSNumber *)functionid remoteid:(NSNumber *)remoteid remoteids:(NSString * )remoteids __deprecated_msg("该接口停止访问...");

/**
 *  6.获取这个运营商（spid）下，所有的品牌（每个品牌都带有他的所有遥控器码）
 *
 *  @param spid 获取到的运营商的spid
 *  taskid = 5
 */
-(void)getIPTVWithSpid:(NSNumber *)spid;

/**
 *  7.获取所有的品牌（每个品牌都带有所有他的遥控器码）
 *
 *  @param nameString 品牌名称
 *  @param areaid     根据省市区获取的areaid
 *  taskid = 6
 */
-(void)searchSTBWithNameString:(NSString * )nameString areaid:(NSNumber*)areaid;

/**
 *  8.获取电视（或者其他，通过typeid区分）品牌列表
 *  devicetypeid:   设备类型1：STB  2：TV  3：BOX  4：DVD   5：AC
 *  @param did devicetype
 *  taskid = 7
 */
-(void)getBrandListFromNetWithDid:(NSNumber * )did;

/**
 *  9.获得这个品牌（brandid）下，所有的遥控器
 *
 *  @param did devicetypeid
 *  @param bid brandid(获取所有的品牌，取到brandid)
 *  taskid = 8
 */
-(void)getAllRemoteIdsWithDid:(NSNumber *)did bid:(NSNumber *)bid;


/**
 *  10.获得红外数据数据
 *
 *  @param remoteId 调用接口3，得到空调的remoteid
 *  taskid = 9
 */

-(void)getAirConditionIRDataWithRemoteId:(NSNumber*)remoteId __deprecated_msg("该接口废弃，请使用：downloadIRDataByIdWithRemoteId: deviceTypeId:");



#pragma mark----------------------EPG-------------------------
/**
 *  11.Lineup列表
 *
 *  @param areaId 根据省，市，区获取的areaid
 *  @param spid   获取到的运营商spid
 *  taskid = 10
 */
-(void)getLineUpsListWithAreaId:(NSNumber * )areaId spId:(NSNumber *)spid;

/**
 *  12.从网络获取Lineup数据
 *
 *  @param lid  Lineup列表中的lineupid
 *  taskid = 11
 */
-(void)downloadLineupDataAndSaveWithLid:(NSNumber * )lid rid:(NSNumber*)rid;

/**
 *  13.从数据库获取Lineup数据
 *
 *  @param lid lineupid
 *
 *  @return 返回一个字典，字典保存lineup数据
 */
-(NSDictionary *)getLineupDataFromDataBaseWithLineup:(NSNumber * )lid __deprecated_msg("该接口已弃用");

/**
 *  14.从数据库删除Lineup数据
 *
 *  @param lid lineipid(根据lineupid删除数据库中存储的lineup数据)
 */
-(void)deleteLineupDataFromDateBaseWithLineup:(NSNumber * )lid __deprecated_msg("该接口已弃用");

/**
 *  15.搜索山东新闻联播播出时间
 *
 *  @param resourceid resid（从获取电视墙接口取该参数）
 *  @param typeId     typeId（从获取电视墙数据接口取该参数）
 *  taskid = 12
 */
-(void)searchProgramWithResourceId:(NSString * )resourceid typeId:(NSNumber *)typeId;

/**
 *  搜索指定频道，指定节目的一周以内的播出时间。
 *
 *  @param resourceid resId（从电视墙接口获取）
 *  @param typeId     typeId（从电视墙接口获取）
 *  @param cid        频道ID（从电视墙接口获取）
 *  @param ctry       ctry（从电视墙接口获取）
 *  taskid = 17
 */
-(void)searchProgramWithResourceId:(NSString *)resourceid typeId:(NSNumber *)typeId cid:(NSNumber *)cid ctry:(NSString *)ctry;

/**
 *  获取高清和标清的节目播出时间
 *
 *  @param programListArray 将 搜索指定频道，指定节目的一周以内的播出时间取到数据传入
 *  @param lid              lineupid
 *
 *  @return 返回高清和标清所有的节目播放数据。
 */
-(NSMutableArray *)searchProgramWithProgramList:(NSArray *)programListArray lid:(NSNumber *)lid __deprecated_msg("该接口已弃用");


/**
 *  16.搜索山东卫视
 *
 *  @param stime 开始时间
 *  @param etime 结束时间
 *  @param cid   频道id（根据lineup数据得到cid）
 *  @param isHd  是否是高清（1:高清；0:标清） 
 *  taskid = 13
 */

-(void)getProgramGuideWithStime:(NSString * )stime etime:(NSString * )etime cid:(NSNumber *)cid isHd:(NSNumber * )isHd;

/**
 *  17.CCTV1 今天播放的节目
 *
 *  @param day 星期几（1:表示星期一）
 *  @param cid 频道id（根据lineup数据得到的cid）
 *  taskid = 14
 */
-(void)getProgramGuideWithDay:(NSNumber *)day cid:(NSNumber *)cid;

/**
 *  18.获取cid = 1 的节目
 *
 *  @param cid  频道id（根据lineup数据得到的cid）
 *  @param lid  lineupid（调用接口：获取lingup列表）
 *  @param time 0（传0，表示当前时间）
 *  taskid = 15
 */
-(void)getProgramsByCatIDWithCid:(NSNumber * )cid lid:(NSNumber *)lid time:(NSString *)time;

/**
 *  19.电视墙数据
 *
 *  @param lid  lineupid(调用接口：获取lingup列表)
 *  @param time 0(表示当前时间)
 *  taskid = 16
 */
-(void)getTVWallDataWithLid:(NSNumber * )lid time:(NSString * )time;

/**
 *  20.节目详情数据
 *
 *  @param typeId     typeId>0（从电视墙接口获取）
 *  @param resourceId resourceId!=NULL（从获取电视墙接口取该参数）
 *  typeId=0&&resourceId=@"";没有节目详情
 *  taskid = 18
 */
-(void)getDetailMessageOfProgramWithTypeid:(NSNumber *)typeId resourceId:(NSString *)resourceId;


#pragma mark-------------------EPG---END------------------


/**
 *  ***获取遥控器的红外码（rid），进行对码
 *
 *  @param remoteId     remoteid
 *  @param deviceTypeId 设备类型id
 *  taskid = 19
 */
-(void)testIRDataByIdWithRemoteId:(NSString *)remoteId deviceTypeId:(NSNumber *)deviceTypeId;

/**
 *  ***对码成功后调用该接口，取完整的码取
 *
 *  @param remoteId     remoteid
 *  @param deviceTypeId 设备类型id
 *  taskid = 20
 */
-(void)downloadIRDataByIdWithRemoteId:(NSString *)remoteId deviceTypeId:(NSNumber *)deviceTypeId;



#pragma mark----------------全球版接口------------------------
/**
 *  21.获取某种类型的设备的品牌列表（全球版）
 *
 *  @param countryId    国家代码
 *  @param deviceTypeId          设备类型Id（did）
 *  taskid = 21
 */
-(void)getBrandListFromNetWithCountryId:(NSString *)countryId deviceTypeId:(NSNumber * )deviceTypeId;

/**
 *  获得这个品牌（brandid）下，所有的遥控器(全球版)
 *
 *  @param did devicetypeid
 *  @param bid brandid(获取所有的品牌，取到brandid)
 *  taskid = 8
 */
-(void)getAllRemoteIdsWithDid:(NSNumber *)did bid:(NSNumber *)bid countryId:(NSString *)countryId;


/**
 *  22.获取码库数据（全球版）
 *
 *  @param countryId    国家代码
 *  @param remoteId     rid
 *  @param deviceTypeId 设备类型Id（did）(非限制码库数据套数客户 传nil)
 *  taskid = 22
 */
-(void)downloadIRDataByIdWithCountryId:(NSString *)countryId remoteId:(NSString *)remoteId deviceTypeId:(NSNumber *)deviceTypeId __deprecated_msg("该接口和取码接口合并，全球版和非全球版共用接口：downloadIRDataByIdWithRemoteId: deviceTypeId:");


/**
 *  23.获取国家列表及国家代码（全球版）
 *
 *  @param lanCode    语言代码、
 *  taskid = 23
 */
-(void)getCountryListWithLancode:(NSString *)lanCode;
#pragma mark---------------------全球版接口END---------------------------


/**
 24.单键对码

 @param deviceTypeId 设备类型
 @param deviceSwitch 开关状态
 @param mr 所有的remoteid及测试过的键的结果
 taskid = 24
 */
-(void)singleKeyTestWith:(NSNumber *)deviceTypeId deviceSwitch:(NSNumber *)deviceSwitch mr:(NSString *)mr;


/**
 25.频道表匹配

 @param areaId 地区id
 @param spId 运营商id
 @param mr 所有选择的频道集合
 taskid = 25
 */
-(void)lineUpMatchWith:(NSNumber *)areaId spId:(NSNumber *)spId mr:(NSString *)mr;



/**
 26.获取空调的全解码

 @param remoteId remoteId
 taskid = 26
 */
-(void)getNoStateIRDataByIdWith:(NSString *)remoteId;


/**
 27.获取空调的全解码进行对码
 
 @param remoteId remoteIds
 taskid = 27
 */
-(void)getTestNoStateIRDataByIdWith:(NSString *)remoteId;

#pragma mark------------------压缩码--------------------
/**
 获取空调的全解码

 @param remoteIds remoteIds
 @param isCompress (获取压缩码，传YES,否则传NO)
 taskid = 26
 */
-(void)getNoStateIRDataByIdWith:(NSString *)remoteIds isCompress:(BOOL)isCompress;


/**
 获取空调的全解码进行对码
 
 @param remoteId remoteIds
 @param isCompress （获取压缩码，传YES,否则传NO）
 taskid = 27
 */
- (void)getTestNoStateIRDataByIdWith:(NSString *)remoteId isCompress:(BOOL)isCompress;

/**
 单键对码
 
 @param deviceTypeId 设备类型
 @param deviceSwitch 开关状态
 @param mr 所有的remoteid及测试过的键的结果
 @param isCompress (获取压缩码，传YES,否则传NO)
 taskid = 24
 */
-(void)singleKeyTestWith:(NSNumber *)deviceTypeId deviceSwitch:(NSNumber *)deviceSwitch mr:(NSString *)mr isCompress:(BOOL)isCompress;


/**
 *  ***获取遥控器的红外码（rid），进行对码
 *
 *  @param remoteId     remoteid
 *  @param deviceTypeId 设备类型id
 *  @param isCompress (获取压缩码，传YES,否则传NO)
 *  taskid = 19
 */
-(void)testIRDataByIdWithRemoteId:(NSString *)remoteId deviceTypeId:(NSNumber *)deviceTypeId isCompress:(BOOL)isCompress;

/**
 *  ***对码成功后调用该接口，取完整的码取
 *
 *  @param remoteId     remoteid
 *  @param deviceTypeId 设备类型id
 *  @param isCompress (获取压缩码，传YES,否则传NO)
 *  taskid = 20
 */
-(void)downloadIRDataByIdWithRemoteId:(NSString *)remoteId deviceTypeId:(NSNumber *)deviceTypeId isCompress:(BOOL)isCompress;


@end
