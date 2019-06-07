///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBPAPERSharingPolicy;
@class DBPAPERSharingPublicPolicyType;
@class DBPAPERSharingTeamPolicyType;

#pragma mark - API Object

///
/// The `SharingPolicy` struct.
///
/// Sharing policy of Paper doc.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBPAPERSharingPolicy : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// This value applies to the non-team members.
@property (nonatomic, readonly) DBPAPERSharingPublicPolicyType * _Nullable publicSharingPolicy;

/// This value applies to the team members only. The value is null for all
/// personal accounts.
@property (nonatomic, readonly) DBPAPERSharingTeamPolicyType * _Nullable teamSharingPolicy;

#pragma mark - Constructors

///
/// Full constructor for the struct (exposes all instance variables).
///
/// @param publicSharingPolicy This value applies to the non-team members.
/// @param teamSharingPolicy This value applies to the team members only. The
/// value is null for all personal accounts.
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithPublicSharingPolicy:(DBPAPERSharingPublicPolicyType * _Nullable)publicSharingPolicy
                                  teamSharingPolicy:(DBPAPERSharingTeamPolicyType * _Nullable)teamSharingPolicy;

///
/// Convenience constructor (exposes only non-nullable instance variables with
/// no default value).
///
///
/// @return An initialized instance.
///
- (nonnull instancetype)initDefault;

- (nonnull instancetype)init NS_UNAVAILABLE;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `SharingPolicy` struct.
///
@interface DBPAPERSharingPolicySerializer : NSObject

///
/// Serializes `DBPAPERSharingPolicy` instances.
///
/// @param instance An instance of the `DBPAPERSharingPolicy` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBPAPERSharingPolicy` API object.
///
+ (NSDictionary * _Nonnull)serialize:(DBPAPERSharingPolicy * _Nonnull)instance;

///
/// Deserializes `DBPAPERSharingPolicy` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBPAPERSharingPolicy` API object.
///
/// @return An instantiation of the `DBPAPERSharingPolicy` object.
///
+ (DBPAPERSharingPolicy * _Nonnull)deserialize:(NSDictionary * _Nonnull)dict;

@end
