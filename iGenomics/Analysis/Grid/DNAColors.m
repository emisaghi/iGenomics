//
//  DNAColors.m
//  iGenomics
//
//  Created by Stuckinaboot Inc. on 3/17/13.
//
//

#import "DNAColors.h"

@implementation DNAColors

@synthesize defaultBackground, defaultLbl, covLbl, refLbl, foundLbl, aLbl, cLbl, gLbl, tLbl, delLbl, insLbl, mutHighlight, black, white;

- (void)setUp {
    defaultBackground = [[RGB alloc] initWithVals:203/255.0f :203/255.0f :203/255.0f];
    defaultLbl = [[RGB alloc] initWithVals:191/255.0f :191/255.0f :191/255.0f];
    covLbl = [[RGB alloc] initWithVals:0 :0 :0];
    refLbl = [[RGB alloc] initWithVals:95/255.0f :150/255.0f :197/255.0f];
    foundLbl = [[RGB alloc] initWithVals:197/255.0f :215/255.0f :233/255.0f];
    aLbl = [[RGB alloc] initWithVals:78/255.0f :130/255.0f :185/255.0f];
    cLbl = [[RGB alloc] initWithVals:194/255.0f :77/255.0f :78/255.0f];
    gLbl = [[RGB alloc] initWithVals:117/255.0f :147/255.0f :72/255.0f];
    tLbl = [[RGB alloc] initWithVals:254/255.0f :250/255.0f :80/255.0f];
    delLbl = [[RGB alloc] initWithVals:0/255.0f :0/255.0f :0/255.0f];
    insLbl = [[RGB alloc] initWithVals:0/255.0f :0/255.0f :0/255.0f];
    mutHighlight = [[RGB alloc] initWithVals:255/255.0f :165/255.0f :0/255.0f];
    black = [[RGB alloc] initWithVals:0 :0 :0];
    white = [[RGB alloc] initWithVals:1 :1 :1];
}

@end