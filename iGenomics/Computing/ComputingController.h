//
//  ComputingController.h
//  iGenomics
//
//  Created by Stuckinaboot Inc. on 1/11/13.
//
//

#import <UIKit/UIKit.h>
#import "AnalysisController.h"
#import "BWT.h"

@interface ComputingController : UIViewController {
    BWT *bwt;
    
    AnalysisController *analysisController;
}
- (void)setUpWithReads:(NSString*)myReads andSeq:(NSString*)mySeq andParameters:(NSArray*)myParameterArray;
@end
