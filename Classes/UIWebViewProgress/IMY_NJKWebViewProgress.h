//
//  IMY_NJKWebViewProgress.h
//
//  Created by Satoshi Aasano on 4/20/13.
//  Copyright (c) 2013 Satoshi Asano. All rights reserved.
//

#import <UIKit/UIKit.h>

#undef IMY_NJK_weak
#if __has_feature(objc_arc_weak)
#define IMY_NJK_weak weak
#else
#define IMY_NJK_weak unsafe_unretained
#endif

extern const float IMY_NJKInitialProgressValue;
extern const float IMY_NJKInteractiveProgressValue;
extern const float IMY_NJKFinalProgressValue;

typedef void (^IMY_NJKWebViewProgressBlock)(float progress);
@protocol IMY_NJKWebViewProgressDelegate;
@interface IMY_NJKWebViewProgress : NSObject<UIWebViewDelegate>
@property (nonatomic, IMY_NJK_weak) id<IMY_NJKWebViewProgressDelegate>progressDelegate;
@property (nonatomic, IMY_NJK_weak) id<UIWebViewDelegate>webViewProxyDelegate;
@property (nonatomic, copy) IMY_NJKWebViewProgressBlock progressBlock;
@property (nonatomic, readonly) float progress; // 0.0..1.0

- (void)reset;
@end

@protocol IMY_NJKWebViewProgressDelegate <NSObject>
- (void)webViewProgress:(IMY_NJKWebViewProgress *)webViewProgress updateProgress:(float)progress;
@end

