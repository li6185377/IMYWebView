//
//  IMYWebView.h
//  IMY_ViewKit
//
//  Created by ljh on 15/7/1.
//  Copyright (c) 2015年 IMY. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol WKScriptMessageHandler;
@class IMYWebView, JSContext;

@protocol IMYWebViewDelegate <NSObject>
@optional

- (void)webViewDidStartLoad:(IMYWebView*)webView;
- (void)webViewDidFinishLoad:(IMYWebView*)webView;
- (void)webView:(IMYWebView*)webView didFailLoadWithError:(NSError*)error;
- (BOOL)webView:(IMYWebView*)webView shouldStartLoadWithRequest:(NSURLRequest*)request navigationType:(UIWebViewNavigationType)navigationType;
- (void)wkWebViewShowAlterInfo:(NSString *)message;

- (void)wkWebViewShowConformInfo:(NSString *)message block:(void (^_Nonnull)(BOOL result))completionHandler;

- (void)wkWebViewShowInputPanelInfo:(nullable NSString *)prompt defaultText:(nullable NSString *)defaultText block:(void (^_Nonnull)(NSString * _Nullable result))completionHandler;

@end

///无缝切换UIWebView   会根据系统版本自动选择 使用WKWebView 还是  UIWebView
@interface IMYWebView : UIView

///使用UIWebView
- (instancetype)initWithFrame:(CGRect)frame usingUIWebView:(BOOL)usingUIWebView;

///会转接 WKUIDelegate，WKNavigationDelegate 内部未实现的回调。
@property (weak, nonatomic) id<IMYWebViewDelegate> delegate;

///内部使用的webView
@property (nonatomic, readonly) id realWebView;
///是否正在使用 UIWebView
@property (nonatomic, readonly) BOOL usingUIWebView;
///预估网页加载进度
@property (nonatomic, readonly) double estimatedProgress;

@property (nonatomic, readonly) NSURLRequest* originRequest;

///只有ios7以上的UIWebView才能获取到，WKWebView 请使用下面的方法.
@property (nonatomic, readonly) JSContext* jsContext;
///WKWebView 跟网页进行交互的方法。
- (void)addScriptMessageHandler:(id<WKScriptMessageHandler>)scriptMessageHandler name:(NSString*)name;

- (void)removeScriptMessageHandlerName:(NSString*)name;


///back 层数
- (NSInteger)countOfHistory;
- (void)gobackWithStep:(NSInteger)step;

///---- UI 或者 WK 的API
@property (nonatomic, readonly) UIScrollView* scrollView;

- (id)loadRequest:(NSURLRequest*)request;
- (id)loadHTMLString:(NSString*)string baseURL:(NSURL*)baseURL;
- (id)loadData:(NSData *)data MIMEType:(NSString *)MIMEType characterEncodingName:(NSString *)characterEncodingName baseURL:(NSURL *)baseURL;

@property (nonatomic, readonly, copy) NSString* title;
@property (nonatomic, readonly) NSURLRequest* currentRequest;
@property (nonatomic, readonly) NSURL* URL;

@property (nonatomic, readonly, getter=isLoading) BOOL loading;
@property (nonatomic, readonly) BOOL canGoBack;
@property (nonatomic, readonly) BOOL canGoForward;

- (id)goBack;
- (id)goForward;
- (id)reload;
- (id)reloadFromOrigin;
- (void)stopLoading;

- (void)evaluateJavaScript:(NSString*)javaScriptString completionHandler:(void (^)(id, NSError*))completionHandler;
///不建议使用这个办法  因为会在内部等待webView 的执行结果
- (NSString*)stringByEvaluatingJavaScriptFromString:(NSString*)javaScriptString __deprecated_msg("Method deprecated. Use [evaluateJavaScript:completionHandler:]");

///是否根据视图大小来缩放页面  默认为YES
@property (nonatomic) BOOL scalesPageToFit;

@end
