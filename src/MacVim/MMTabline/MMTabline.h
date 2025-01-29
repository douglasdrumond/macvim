#import <Cocoa/Cocoa.h>
#import "MMHoverButton.h"
#import "MMTab.h"

// A tabline containing one or more tabs.

#define MMTablineHeight (23)

@protocol MMTablineDelegate;

@interface MMTabline : NSView

/// The index of the selected tab. Can be -1 if nothing is selected.
@property (nonatomic, readonly) NSInteger selectedTabIndex;
@property (nonatomic) NSInteger optimumTabWidth;
@property (nonatomic) NSInteger minimumTabWidth;
@property (nonatomic) BOOL showsAddTabButton;
@property (nonatomic) BOOL showsTabScrollButtons;
@property (nonatomic) BOOL useAnimation;
@property (nonatomic, readonly) NSInteger numberOfTabs;
@property (nonatomic, retain, readonly) MMHoverButton *addTabButton;
@property (nonatomic, retain) NSColor *tablineBgColor;
@property (nonatomic, retain) NSColor *tablineFgColor;
@property (nonatomic, retain) NSColor *tablineSelBgColor;
@property (nonatomic, retain) NSColor *tablineSelFgColor;
@property (nonatomic, retain) NSColor *tablineFillFgColor;
@property (nonatomic, weak) id <MMTablineDelegate> delegate;

/// Add a tab at the end. It's not selected automatically.
- (NSInteger)addTabAtEnd;
/// Add a tab after the selected one. It's not selected automatically.
- (NSInteger)addTabAfterSelectedTab;
/// Add a tab at specified index. It's not selected automatically.
- (NSInteger)addTabAtIndex:(NSInteger)index;

- (void)closeTab:(MMTab *)tab force:(BOOL)force layoutImmediately:(BOOL)layoutImmediately;
- (void)closeAllTabs;

/// Batch update all the tabs using tab tags as unique IDs. Tab line will handle
/// creating / removing tabs as necessary, and moving tabs to their new
/// positions.
///
/// The tags array has to have unique items only, and each existing MMTab also
/// has to have unique tags.
///
/// @param tags The list of unique tags that are cross-referenced with each
///        MMTab's tag. Order within the array indicates the desired tab order.
/// @param len The length of the tags array.
/// @param delayTabResize If true, do not resize tab widths until the the tab
///        line loses focus. This helps preserve the relative tab positions and
///        lines up the close buttons to the previous tab. This will also
///        prevent scrolling to the new selected tab.
- (void)updateTabsByTags:(NSInteger *)tags len:(NSUInteger)len delayTabResize:(BOOL)delayTabResize;

- (void)selectTabAtIndex:(NSInteger)index;
- (MMTab *)tabAtIndex:(NSInteger)index;
- (void)scrollTabToVisibleAtIndex:(NSInteger)index;
- (void)scrollLeftOneTab;
- (void)scrollRightOneTab;
- (void)setTablineSelBackground:(NSColor *)back foreground:(NSColor *)fore;

@end

@protocol MMTablineDelegate <NSObject>
@optional

- (BOOL)tabline:(MMTabline *)tabline shouldSelectTabAtIndex:(NSInteger)index;
- (BOOL)tabline:(MMTabline *)tabline shouldCloseTabAtIndex:(NSInteger)index;
- (void)tabline:(MMTabline *)tabline didDragTab:(MMTab *)tab toIndex:(NSInteger)index;
- (NSDragOperation)tabline:(MMTabline *)tabline draggingEntered:(id <NSDraggingInfo>)dragInfo forTabAtIndex:(NSInteger)index;
- (BOOL)tabline:(MMTabline *)tabline performDragOperation:(id <NSDraggingInfo>)dragInfo forTabAtIndex:(NSInteger)index;

@end
