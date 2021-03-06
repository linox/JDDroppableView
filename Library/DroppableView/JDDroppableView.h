//
//  JDDroppableView.h
//  JDDroppableView
//
//  Created by Markus Emrich on 01.07.10.
//  Copyright 2010 Markus Emrich. All rights reserved.
//


@class JDDroppableView;

@protocol JDDroppableViewDelegate <NSObject>
@optional
- (void) droppableViewBeganDragging: (JDDroppableView*) view;
- (void) droppableViewDidMove: (JDDroppableView*) view;
- (void) droppableView: (JDDroppableView*) view enteredTarget: (UIView*) target;
- (void) droppableView: (JDDroppableView*) view leftTarget: (UIView*) target;
- (BOOL) shouldAnimateDroppableViewBack: (JDDroppableView*) view wasDroppedOnTarget: (UIView*) target;
- (void) droppableViewEndedDragging: (JDDroppableView*) view;
@end


@interface JDDroppableView : UIView
{	
	UIView * mDropTarget;
    
	UIView * mOuterView;
	UIScrollView * mScrollView;
	
    BOOL mIsDragging;
    BOOL mIsOverTarget;
	CGPoint mOriginalPosition;
}

@property (nonatomic, assign) id<JDDroppableViewDelegate> delegate;

- (id) initWithFrame:(CGRect)frame;
- (id) initWithDropTarget:(UIView*)target;

@end
