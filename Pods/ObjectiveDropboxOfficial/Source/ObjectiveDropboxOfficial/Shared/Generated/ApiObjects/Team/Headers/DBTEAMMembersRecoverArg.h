///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMMembersRecoverArg;
@class DBTEAMUserSelectorArg;

#pragma mark - API Object

///
/// The `MembersRecoverArg` struct.
///
/// Exactly one of team_member_id, email, or external_id must be provided to
/// identify the user account.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMMembersRecoverArg : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// Identity of user to recover.
@property (nonatomic, readonly) DBTEAMUserSelectorArg * _Nonnull user;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param user Identity of user to recover.
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithUser:(DBTEAMUserSelectorArg * _Nonnull)user;

- (nonnull instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `MembersRecoverArg` struct.
///
@interface DBTEAMMembersRecoverArgSerializer : NSObject

///
/// Serializes `DBTEAMMembersRecoverArg` instances.
///
/// @param instance An instance of the `DBTEAMMembersRecoverArg` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMMembersRecoverArg` API object.
///
+ (NSDictionary * _Nonnull)serialize:(DBTEAMMembersRecoverArg * _Nonnull)instance;

///
/// Deserializes `DBTEAMMembersRecoverArg` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMMembersRecoverArg` API object.
///
/// @return An instantiation of the `DBTEAMMembersRecoverArg` object.
///
+ (DBTEAMMembersRecoverArg * _Nonnull)deserialize:(NSDictionary * _Nonnull)dict;

@end
