///
/// Copyright (c) 2016 Dropbox, Inc. All rights reserved.
///
/// Auto-generated by Stone, do not modify.
///

#import <Foundation/Foundation.h>

#import "DBSerializableProtocol.h"

@class DBPAPERExportFormat;

#pragma mark - API Object

///
/// The `ExportFormat` union.
///
/// The desired export format of the Paper doc.
///
/// This class implements the `DBSerializable` protocol (serialize and
/// deserialize instance methods), which is required for all Obj-C SDK API route
/// objects.
///
@interface DBPAPERExportFormat : NSObject <DBSerializable, NSCopying>

#pragma mark - Instance fields

/// The `DBPAPERExportFormatTag` enum type represents the possible tag states
/// with which the `DBPAPERExportFormat` union can exist.
typedef NS_ENUM(NSInteger, DBPAPERExportFormatTag) {
  /// The HTML export format.
  DBPAPERExportFormatHtml,

  /// The markdown export format.
  DBPAPERExportFormatMarkdown,

  /// (no description).
  DBPAPERExportFormatOther,

};

/// Represents the union's current tag state.
@property (nonatomic, readonly) DBPAPERExportFormatTag tag;

#pragma mark - Constructors

///
/// Initializes union class with tag state of "html".
///
/// Description of the "html" tag state: The HTML export format.
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithHtml;

///
/// Initializes union class with tag state of "markdown".
///
/// Description of the "markdown" tag state: The markdown export format.
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithMarkdown;

///
/// Initializes union class with tag state of "other".
///
/// @return An initialized instance.
///
- (nonnull instancetype)initWithOther;

- (nonnull instancetype)init NS_UNAVAILABLE;

#pragma mark - Tag state methods

///
/// Retrieves whether the union's current tag state has value "html".
///
/// @return Whether the union's current tag state has value "html".
///
- (BOOL)isHtml;

///
/// Retrieves whether the union's current tag state has value "markdown".
///
/// @return Whether the union's current tag state has value "markdown".
///
- (BOOL)isMarkdown;

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
/// The serialization class for the `DBPAPERExportFormat` union.
///
@interface DBPAPERExportFormatSerializer : NSObject

///
/// Serializes `DBPAPERExportFormat` instances.
///
/// @param instance An instance of the `DBPAPERExportFormat` API object.
///
/// @return A json-compatible dictionary representation of the
/// `DBPAPERExportFormat` API object.
///
+ (NSDictionary * _Nonnull)serialize:(DBPAPERExportFormat * _Nonnull)instance;

///
/// Deserializes `DBPAPERExportFormat` instances.
///
/// @param dict A json-compatible dictionary representation of the
/// `DBPAPERExportFormat` API object.
///
/// @return An instantiation of the `DBPAPERExportFormat` object.
///
+ (DBPAPERExportFormat * _Nonnull)deserialize:(NSDictionary * _Nonnull)dict;

@end
