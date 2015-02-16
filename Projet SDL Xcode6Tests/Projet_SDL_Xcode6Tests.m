//
//  Projet_SDL_Xcode6Tests.m
//  Projet SDL Xcode6Tests
//
//  Created by ArthurJ972 on 16/02/2015.
//  Copyright (c) 2015 A-J-Evolution.com. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <XCTest/XCTest.h>

@interface Projet_SDL_Xcode6Tests : XCTestCase

@end

@implementation Projet_SDL_Xcode6Tests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    // This is an example of a functional test case.
    XCTAssert(YES, @"Pass");
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
