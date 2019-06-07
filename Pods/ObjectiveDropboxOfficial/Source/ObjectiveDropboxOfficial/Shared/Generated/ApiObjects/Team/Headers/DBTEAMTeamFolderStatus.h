///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBTEAMTeamFolderStatus;

#pragma mark - API Object

///
/// The `TeamFolderStatus` union.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBTEAMTeamFolderStatus : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBTEAMTeamFolderStatusTag` enum type represents the possible tag states
/// with which the `DBTEAMTeamFolderStatus` union can exist.
typedef NS_ENUM(NSInteger, DBTEAMTeamFolderStatusTag) {
  /// The team folder and sub-folders are available to all members.
  DBTEAMTeamFolderStatusActive,

  /// The team folder is not accessible outside of the team folder manager.
  DBTEAMTeamFolderStatusArchived,

  /// The team folder is not accessible outside of the team folder manager.
  DBTEAMTeamFolderStatusArchiveInProgress,

  /// (no description).
  DBTEAMTeamFolderStatusOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBTEAMTeamFolderStatusTag tag;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "active".
///
/// Description of the "active" tag state: The team folder and sub-folders are
/// available to all members.
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithActive;

///
/// Initializes union class with tag state of "archived".
///
/// Description of the "archived" tag state: The team folder is not accessible
/// outside of the team folder manager.
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithArchived;

///
/// Initializes union class with tag state of "archive_in_progress".
///
/// Description of the "archive_in_progress" tag state: The team folder is not
/// accessible outside of the team folder manager.
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithArchiveInProgress;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithOther;

- (nonnull instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value "active".
///
/// @return Whether the union's current tag state has value "active".
///
- (BOOL)isActive;

///
/// Retrieves whether the union's current tag state has value "archived".
///
/// @return Whether the union's current tag state has value "archived".
///
- (BOOL)isArchived;

///
/// Retrieves whether the union's current tag state has value
/// "archive_in_progress".
///
/// @return Whether the union's current tag state has value
/// "archive_in_progress".
///
- (BOOL)isArchiveInProgress;

///
/// Retrieves whether the union's current tag state has value "other".
///
/// @return Whether the union's current tag state has value "other".
///
- (BOOL)isOther;

///
/// Retrieves string value of union's current tag state.
///
/// @return A human-readable string representing the union's current tag state.
///
- (NSString * _Nonnull)tagName;

@end

#pragma mark - Serializer Object

///
/// The serialization class for the `DBTEAMTeamFolderStatus` union.
///
@interface DBTEAMTeamFolderStatusSerializer : NSObject

///
/// Serializes `DBTEAMTeamFolderStatus` instances.
///
/// @param instance An instance of the `DBTEAMTeamFolderStatus` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBTEAMTeamFolderStatus` API object.
///
+ (NSDictionary * _Nonnull)serialize:(DBTEAMTeamFolderStatus * _Nonnull)instance;

///
/// Deserializes `DBTEAMTeamFolderStatus` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBTEAMTeamFolderStatus` API object.
///
/// @return An instantiation of the `DBTEAMTeamFolderStatus` object.
///
+ (DBTEAMTeamFolderStatus * _Nonnull)deserialize:(NSDictionary * _Nonnull)dict;

@end
