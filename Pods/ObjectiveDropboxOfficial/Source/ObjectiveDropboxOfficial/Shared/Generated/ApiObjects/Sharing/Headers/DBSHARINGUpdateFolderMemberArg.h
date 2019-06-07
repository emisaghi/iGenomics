///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBSHARINGAccessLevel;
@class DBSHARINGMemberSelector;
@class DBSHARINGUpdateFolderMemberArg;

#pragma mark - API Object

///
/// The `UpdateFolderMemberArg` struct.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBSHARINGUpdateFolderMemberArg : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The ID for the shared folder.
@property (nonatomic, readonly, copy) NSString * _Nonnull sharedFolderId;

/// The member of the shared folder to update.  Only the `dropboxId` in
/// `DBSHARINGMemberSelector` may be set at this time.
@property (nonatomic, readonly) DBSHARINGMemberSelector * _Nonnull member;

/// The new access level for member. `owner` in `DBSHARINGAccessLevel` is
/// disallowed.
@property (nonatomic, readonly) DBSHARINGAccessLevel * _Nonnull accessLevel;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param sharedFolderId The ID for the shared folder.
/// @param member The member of the shared folder to update.  Only the
/// `dropboxId` in `DBSHARINGMemberSelector` may be set at this time.
/// @param accessLevel The new access level for member. `owner` in
/// `DBSHARINGAccessLevel` is disallowed.
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithSharedFolderId:(NSString * _Nonnull)sharedFolderId
                                        member:(DBSHARINGMemberSelector * _Nonnull)member
                                   accessLevel:(DBSHARINGAccessLevel * _Nonnull)accessLevel;

- (nonnull instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `UpdateFolderMemberArg` struct.
///
@interface DBSHARINGUpdateFolderMemberArgSerializer : NSObject

///
/// Serializes `DBSHARINGUpdateFolderMemberArg` instances.
///
/// @param instance An instance of the `DBSHARINGUpdateFolderMemberArg` API
/// object.
///
/// @return A json-compatible dictionary representation of the
/// `DBSHARINGUpdateFolderMemberArg` API object.
///
+ (NSDictionary * _Nonnull)serialize:(DBSHARINGUpdateFolderMemberArg * _Nonnull)instance;

///
/// Deserializes `DBSHARINGUpdateFolderMemberArg` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBSHARINGUpdateFolderMemberArg` API object.
///
/// @return An instantiation of the `DBSHARINGUpdateFolderMemberArg` object.
///
+ (DBSHARINGUpdateFolderMemberArg * _Nonnull)deserialize:(NSDictionary * _Nonnull)dict;

@end
