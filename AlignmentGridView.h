//
//  AlignmentGridView.h
//  iGenomics
//
//  Created by Stuckinaboot Inc. on 7/10/14.
//
//

#import "QuickGridView.h"
#import "GlobalVars.h"
#import "AlignmentGridPosition.h"
#import "ReadPopoverController.h"
#import <malloc/malloc.h>
#import <objc/runtime.h>

#define kAlignmentGridViewMaxCharsReadSpacing 2

#define kAlignmentGridViewNumOfGridSections 4 //Includes graph row for spacing reasons and to possibly put insertion buttons there

#define kReadLongPressRecognizerMinDuration 1.0f

@interface AlignmentGridView : QuickGridView {
    __strong AlignmentGridPosition **alignmentGridPositionsArr;//Strong means ARC won't destory this object unless it is set to nil, ** is a Pointer to a pointer
    int currYOffset;
    
    BOOL isScrollingHorizontally;
    
    UILongPressGestureRecognizer *longPressRecognizer;
}
- (IBAction)readLongPressed:(id)sender;
- (void)displayReadPopoverForRead:(ED_Info *)read atPosInGenome:(int)pos atPointOnScreen:(CGPoint)point;
- (void)setUpAlignmentGridPositionsArr;
- (int)readInfoNumForX:(int)x len:(int)len andInsCount:(int)insCount;
//- (void)setUpPositionMatchedCharsArr;
- (void)drawReadStartAtPoint:(CGPoint)point;
- (void)drawReadEndAtPoint:(CGPoint)point;
- (void)drawReadBodyAtPoint:(CGPoint)point;
- (void)drawReadBodyAtPoint:(CGPoint)point nextToAnEnd:(int)end;
//- (void)drawReadWithEDInfo:(ED_Info*)read atX:(float)x andY:(float)y;
//- (void)drawCharColumnWithTxt:(NSString*)txt atX:(float)x andY:(float)y;
- (void)drawCharColumnWithAlignmentGridPos:(AlignmentGridPosition*)gridPos atX:(float)x andY:(float)y andYToNotCross:(int)yToNotCross;
@end