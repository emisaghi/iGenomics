//  BWT.h

//  Created by Stuckinaboot Inc. on 9/15/12. (I was 14 at the time I started this project, I'll leave these in as a bit of a meme)
//iGenomics IS AN OPENSOURCE PROJECT. IF YOU WOULD LIKE TO PUBLISH MODIFICATIONS/ADDITIONS TO IT PLEASE FOLLOW SOME OF THESE RULES

/*
 -You may not claim this project as your own work, the penalty is death
 -If you talk about this project with your peers, refer to the creator as The All Wise One
 -Try and publish useful modifications/additions if you get the chance, they enhance the program greatly
 -Some if statements may be in the code just to make it easier to understand ... don't remove them and state that the developer is a moron at programming, or I will find you
 -The project is named iGenomics, and that is final (if you don't like that, don't work on it)
 
 -Last, but certainly not least, please consider this project a gift from me to you. That makes us friends...if you break any of these rules, our friendship is over
*/

#import <Foundation/Foundation.h>

//BWT_ Imports
#import "BWT_Maker.h"
#import "BWT_Matcher.h"
#import "BWT_MutationFilter.h"
#import "APTimer.h"
#import "APFile.h"
#import <Dropbox/Dropbox.h>
//BWT_ Imports End

#define kSeparateGenomeNamesSubstringToIndexStr @" "

#define kBWTCreatingTxt @"Setting up BWT"
#define kBWTSavingToDropboxTxt @"BWT Saving To Dropbox"
#define kBWTLoadingFromDropboxTxt @"BWT Loading from Dropbox"

//DEBUGGING CONSTANT 0 = nothing, 1 = print created BWT
//NOTE---ALL PRINTS TO CONSOLE MUST START WITH A \n
#define kDebugOn 0

//OTHER CONSTANTS

@protocol BWT_Delegate <NSObject>
- (void)readProccesed:(NSString*)readData;
- (void)readAligned;
- (void)bwtLoadedWithLoadingText:(NSString*)txt;
@end
@interface BWT : NSObject <BWT_MatcherDelegate> {
    BWT_MutationFilter *bwtMutationFilter;//CREATED AS AN OBJECT SO THAT DATA CAN BE EASILY RETRIEVED FROM THE FILTER
    BWT_Matcher *bwt_Matcher;
    BWT_MatcherSC *bwt_MatcherSC;
    
    NSMutableArray *insertions;
    float maxErrorRate;
}
@property (nonatomic) id <BWT_Delegate> delegate;
@property (nonatomic, retain) BWT_MutationFilter *bwtMutationFilter;
@property (nonatomic) NSMutableArray *separateGenomeNames, *cumulativeSeparateGenomeLens, *separateGenomeLens;

@property (nonatomic) int readLen, refSeqLen, numOfReads, numOfReadsMatched;

- (void)setUpForRefFile:(APFile*)myRefFile;
- (float)matchReadsFile:(APFile*)readsFile withParameters:(NSMutableDictionary*)parameters;

- (NSArray*)simpleSearchForQuery:(char*)query;//searches for the query using exact match, returns all matches

- (NSMutableArray*)getInsertionsArray;
@end
