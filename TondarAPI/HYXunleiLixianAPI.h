//
//  HWXunleiLixianAPI.h
//  XunleiLixian-API
//
//  Created by Liu Chao on 6/10/12.
//  Copyright (c) 2012 HwaYing. All rights reserved.
//
/*This file is part of XunleiLixian-API.
 
 XunleiLixian-API is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 Foobar is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#import <Foundation/Foundation.h>
@class XunleiItemInfo;
typedef enum{
    QMiddleQuality=1,
    QLowQuality=2,
    QHighQuality=3
}YUNZHUANMAQuality;

@interface HYXunleiLixianAPI : NSObject
-(XunleiItemInfo *) getTaskWithTaskID:(NSString*) aTaskID;
#pragma mark - Cookies Methods
-(NSString *) cookieValueWithName:(NSString *)aName;
-(NSHTTPCookie *) setCookieWithKey:(NSString *) key Value:(NSString *) value;
-(BOOL) hasCookie:(NSString*) aKey;
#pragma mark - Login/LogOut Methods
//Login
-(BOOL) loginWithUsername:(NSString *) aName Password:(NSString *) aPassword;
-(BOOL) isLogin;
-(void) logOut;
#pragma mark - UserID,UserNmae
//UserID,UserName
-(NSString *)userID;
-(NSString *)userName;
#pragma mark - GDriveID
//GdriveID是一个关键Cookie，在下载文件的时候需要用它进行验证
-(NSString*)GDriveID;
-(BOOL) isGDriveIDInCookie;
-(void) setGdriveID:(NSString*) gdriveid;
#pragma mark - Referer
//获得Referer
-(NSString*) refererWithStringFormat;
-(NSURL*) refererWithURLFormat;


#pragma mark - Task
//获得不同下载状态的任务列表
-(NSMutableArray*) readAllCompleteTasks;
-(NSMutableArray*) readCompleteTasksWithPage:(NSUInteger) pg;

-(NSMutableArray*) readAllDownloadingTasks;
-(NSMutableArray*) readDownloadingTasksWithPage:(NSUInteger) pg;

-(NSMutableArray *) readAllOutofDateTasks;
-(NSMutableArray *) readOutofDateTasksWithPage:(NSUInteger) pg;

-(NSMutableArray*) readAllDeletedTasks;
-(NSMutableArray*) readDeletedTasksWithPage:(NSUInteger) pg;

#pragma mark - BT Task
//BT任务列表
-(NSMutableArray *) btTaskPageWithTaskID:(NSString *) taskid hashID:(NSString *)dcid;
#pragma mark - Add Task
//添加任务
-(NSString *) addMegnetTask:(NSString *) url;
-(NSString *) addNormalTask:(NSString *)url;
#pragma mark - Delete Task
//删除任务
-(BOOL) deleteTasksByIDArray:(NSArray *)ids;
-(BOOL) deleteSingleTaskByID:(NSString*) id;
-(BOOL) deleteSingleTaskByXunleiItemInfo:(XunleiItemInfo*) aInfo;
-(BOOL) deleteTasksByXunleiItemInfoArray:(NSArray *)ids;
#pragma mark - Pause Task
//TO DO
#pragma mark - ReStart Task
//TO DO
#pragma mark - Rename Task
//TO DO
#pragma mark - YunZhuanMa Task
//云转码任务列表
-(NSMutableArray*) readAllYunTasks;
-(NSMutableArray *) readYunTasksWithPage:(NSUInteger) pg;
//添加任务到云转码
-(BOOL) addYunTaskWithFileSize:(NSString*) size downloadURL:(NSString*) url dcid:(NSString*) cid fileName:(NSString*) aName Quality:(YUNZHUANMAQuality) q;
@end