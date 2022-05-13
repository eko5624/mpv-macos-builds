/*
    NSTitlebarAccessoryViewController.h
    Application Kit
    Copyright (c) 2014-2018, Apple Inc.
    All rights reserved.
*/

#import <AppKit/NSViewController.h>
#import <AppKit/NSLayoutConstraint.h>

@class NSClipView;

NS_ASSUME_NONNULL_BEGIN

/* For use with NSWindow's API addTitlebarAccessoryViewController:, etc. */
NS_CLASS_AVAILABLE(10_10, NA)
@interface NSTitlebarAccessoryViewController : NSViewController <NSAnimationDelegate, NSAnimatablePropertyContainer> {
@private
    NSLayoutAttribute _layoutAttribute APPKIT_IVAR;
    CGFloat _fullScreenMinHeight APPKIT_IVAR;
    NSClipView *_containingClipView APPKIT_IVAR;
    CGFloat _revealAmount APPKIT_IVAR;
    BOOL _inFullScreen APPKIT_IVAR;
    BOOL _isToolbarAccessoryView APPKIT_IVAR;
    NSInteger _updateCount APPKIT_IVAR;
    
    unsigned int _hidden:1 APPKIT_IVAR;
    unsigned int _unusedTVC2:1 __unused APPKIT_IVAR;
    unsigned int _updatingFrame:1 APPKIT_IVAR;
    unsigned int _registered:1 APPKIT_IVAR;
    unsigned int _reservedTVC:28 __unused APPKIT_IVAR;

    id _animationData APPKIT_IVAR;
    CGFloat _visibleAmount APPKIT_IVAR; // For animating visibility
}

/* The layoutAttribute defaults to NSLayoutAttributeBottom, telling the window to place this view controller's view under the titlebar. NSLayoutAttributeRight is also supported, telling the window to place the view controller's view on the right side of the window. For applications linked on Mac OS 10.11 or later, NSLayoutAttributeLeft is also supported; placing the item on the left side of the window (adjacent and to the right of the close/minimize/maximize buttons). All other values are currently invalid and will assert.
 
    For applications linked on 10.11 and higher, a layoutAttribute== NSLayoutAttributeRight will no longer right indent toolbar items (previously it would leave a space), unless  the titleVisibility == NSWindowTitleHidden. 
 
    For applications linked on 10.12 and higher, NSLayoutAttributeLeading and NSLayoutAttributeTrailing can also be used to specify an abstract position that automatically flips depending on the localized language.  For applications that do not link on 10.12, NSLayoutAttributeLeft will automatically flip to the Right when in a Right To Left language.
 
    For applications linked on 10.13 and higher, NSLayoutAttributeTop can also be used to specify a view that will be at the top of the titlebar area. Only one should be used per window, and if one is set the normal titlebar will not be drawn. Using the top attributed requires the window to have the NSWindowStyleMaskFullSizeContentView style mask set. The "hidden" property can be used to show and hide the view. The "hidden" property will animate the view via an alpha fade in and out if accessed through the animator proxy (such as: viewController.animator.hidden = YES).

 */
@property NSLayoutAttribute layoutAttribute;

/* The fullScreenMinHeight controls the visual minimum height of the view when it is in full screen. It only applies to controllers with the layoutAttribute set to NSLayoutAttributeBottom. Note that the view's height is never actually changed, and it is automatically clipped by an internal clip view.
 
    The minimum height is used when the menu bar is hidden. A minimum height of 0 will fully hide the view when the menu bar is hidden. 
 
    To always show a portion of the view, set the fullScreenMinHeight to some value greater than 0. To always have the view fully shown (i.e.: a fixed height accessory view), set the fullScreenMinHeight to the view.frame.size.height (and be sure to update it if you ever change the view's height).
 
    The default value is 0.
*/
@property CGFloat fullScreenMinHeight;

/* Indicates whether the accessory view is actually visible in the window. This property only applies to controllers set with the top or bottom layoutAtribute. When set, this property will collapse the accessory view to 0 height (animatable) but NOT remove it from the window. That way, you can easily show and hide it without difficulty. Set through the animator object to animate it. */
@property (getter=isHidden) BOOL hidden NS_AVAILABLE_MAC(10_12);

- (void)viewWillAppear NS_REQUIRES_SUPER;
- (void)viewDidAppear NS_REQUIRES_SUPER;
- (void)viewDidDisappear NS_REQUIRES_SUPER;

/* NOTE: Do not override the -view property! Instead, override loadView, and set the view property in that method (i.e.: self.view = ...; )
 
   NOTE: NSTitlebarAccessoryViewController will observe the view's frame for changes. You can change the view's frame in a direction that "makes sense". For instance, changing the height when the layoutAttribute is NSLayoutAttributeBottom, or changing the width when the layoutAttribute is NSLayoutAttributeRight. The other size direction will automatically be filled to the maximum size as required for the window.

 */

@end

NS_ASSUME_NONNULL_END
