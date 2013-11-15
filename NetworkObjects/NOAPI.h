//
//  NOAPI.h
//  NetworkObjects
//
//  Created by Alsey Coleman Miller on 10/21/13.
//  Copyright (c) 2013 CDA. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

typedef NS_ENUM(NSUInteger, NOAPIErrorCode) {
    
    NOAPIInvalidServerResponseErrorCode = 1000,
    NOAPILoginFailedErrorCode,
    NOAPIBadRequestErrorCode,
    NOAPIUnauthorizedErrorCode,
    NOAPIForbiddenErrorCode,
    NOAPINotFoundErrorCode,
    NOAPIServerInternalErrorCode
    
};

@interface NOAPI : NSObject

@property NSManagedObjectModel *model;

@property NSURLSession *urlSession;

@property NSString *sessionEntityName;

@property NSString *userEntityName;

@property NSString *clientEntityName;

#pragma mark - Connection Info

@property BOOL prettyPrintJSON;

@property NSURL *serverURL;

@property NSString *loginPath;

@property NSNumber *clientResourceID;

@property NSString *clientSecret;

@property NSString *username;

@property NSString *userPassword;

@property NSString *sessionToken;

@property NSNumber *userResourceID;

#pragma mark - Requests

-(void)loginWithCompletion:(void (^)(NSError *error))completionBlock;

-(void)getResource:(NSString *)resourceName
            withID:(NSUInteger)resourceID
        completion:(void (^)(NSError *error, NSDictionary *resource))completionBlock;

-(void)editResource:(NSString *)resourceName
             withID:(NSUInteger)resourceID
            changes:(NSDictionary *)changes
         completion:(void (^)(NSError *error))completionBlock;

-(void)deleteResource:(NSString *)resourceName
               withID:(NSUInteger)resourceID
           completion:(void (^)(NSError *error))completionBlock;

-(void)createResource:(NSString *)resourceName
    withInitialValues:(NSDictionary *)initialValues
           completion:(void (^)(NSError *error, NSNumber *resourceID))completionBlock;

-(void)performFunction:(NSString *)functionName
            onResource:(NSString *)resourceName
                withID:(NSUInteger)resourceID
        withJSONObject:(NSDictionary *)jsonObject
            completion:(void (^)(NSError *error, NSNumber *statusCode, NSDictionary *response))completionBlock;

@end
