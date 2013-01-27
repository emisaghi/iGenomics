//
//  ComputingController.m
//  iGenomics
//
//  Created by Stuckinaboot Inc. on 1/11/13.
//
//

#import "ComputingController.h"

@interface ComputingController ()

@end

@implementation ComputingController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

- (void)setUpWithReads:(NSString*)myReads andSeq:(NSString*)mySeq andParameters:(NSArray*)myParameterArray {
    analysisController = [[AnalysisController alloc] init];
    
    NSArray *a = [myReads componentsSeparatedByString:@"."];
    NSString *readsFileExt = [a objectAtIndex:[a count]-1];
    
    a = [mySeq componentsSeparatedByString:@"."];
    NSString *refFileExt = [a objectAtIndex:[a count]-1];
    
    //Creates new bwt setup for each new sequencing time
    bwt = [[BWT alloc] init];
    [bwt setUpForRefFile:[mySeq substringToIndex:(mySeq.length)-(refFileExt.length)-1] fileExt:refFileExt];
    
    //Set up parameters
    
    [bwt matchReedsFile:[myReads substringToIndex:(myReads.length)-(readsFileExt.length)-1] fileExt:readsFileExt withParameters:myParameterArray];//Obviously make this variable
    
    [bwt.bwtMutationFilter buildOccTableWithUnravStr:bwt.originalString];
    [bwt.bwtMutationFilter findMutationsWithOriginalSeq:bwt.originalString];
    [bwt.bwtMutationFilter filterMutationsForDetails];
    
    [analysisController readyViewForDisplay:bwt.originalString andInsertions:[bwt getInsertionsArray]];
}

- (void)viewDidAppear:(BOOL)animated {
    [self presentModalViewController:analysisController animated:YES];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end