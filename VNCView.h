//
//  VNCView.h
//  Vnsea
//
//  Created by Chris Reed on 9/5/07.
//  Copyright 2007 __MyCompanyName__. All rights reserved.
//

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>
#import <UIKit/CDStructures.h>
#import <UIKit/UIWindow.h>
#import <UIKit/UIView-Hierarchy.h>
#import <UIKit/UIHardware.h>
#import <UIKit/UIKit.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UINavBarButton.h>
#import <UIKit/UIPushButton.h>
#import <UIKit/UIKeyboard.h>
#import <UIKit/UIKeyboardInput.h>
#import <CoreGraphics/CoreGraphics.h>
#import "RFBConnection.h"
#import "EventFilter.h"
#import "FrameBuffer.h"
#import "RFBViewProtocol.h"
#import "VNCContentView.h"
#import "VNCScrollerView.h"

/*!
 * @brief Main view to display and control the remote computer.
 *
 * This view class handles everything related to showing the remote display
 * and interacting with it. It is tightly coupled with the RFBConnection
 * instance and is its delegate. The actual drawing of the framebuffer
 * is done by the VNCContentView that is this view's child. And this view
 * inherits from UIScroller so it can modify the default scrolling
 * behaviour. A number of method invocations are forwarded to the content
 * view rather than be implemented directly by this class.
 */
@interface VNCView : UIView <RFBViewProtocol> //, UIKeyboardInput>
{
    RFBConnection * _connection;	//!< The connection object, nil if not currently connected.
	EventFilter * _filter;			//!< Event filter for the current connection.
	VNCScrollerView * _scroller;	//!< Scroller subview.
	VNCContentView * _screenView;	//!< Child content view that draws the framebuffer.
	UINavBarButton * _keyboardButton;	//
	UIPushButton * _shiftButton;
	UIPushButton * _commandButton;
	UIPushButton * _optionButton;
	UIPushButton * _controlButton;
	id _keyboardView;
	id _controlsView;
//	id _textInputView;
	bool _areControlsVisible;
	bool _isKeyboardVisible;
}

//! \name Controls and keyboard
//@{
- (bool)areControlsVisible;
- (void)showControls:(bool)show;
- (void)toggleControls;
- (void)toggleKeyboard:(id)sender;
//@}

//! \name Implementation of RFBViewProtocol
//@{
- (void)setRemoteDisplaySize:(CGSize)remoteSize;
- (void)setFrameBuffer:(id)aBuffer;
- (void)setConnection:(RFBConnection *)connection;
- (RFBConnection *)connection;
- (void)displayFromBuffer:(CGRect)aRect;
- (void)drawRectList:(id)aList;
//@}

- (void)characterWasTyped:(NSString *)character;

@end


