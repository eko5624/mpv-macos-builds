/*
    NSMagnificationGestureRecognizer.h
    Application Kit
    Copyright (c) 2013-2018, Apple Inc.
    All rights reserved.
*/

#import <Foundation/Foundation.h>
#import <AppKit/NSGestureRecognizer.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, NA)
@interface NSMagnificationGestureRecognizer : NSGestureRecognizer {
@private
    NSPoint _location APPKIT_IVAR;
    NSPoint _reserved1 APPKIT_IVAR;
    NSInteger _mflags __unused APPKIT_IVAR;
    CGFloat _magnification APPKIT_IVAR;
    id _reserved2 APPKIT_IVAR;
#ifndef __OBJC2__
    NSInteger _reserved3 APPKIT_IVAR;
#endif
}

@property CGFloat magnification;

@end

NS_ASSUME_NONNULL_END
