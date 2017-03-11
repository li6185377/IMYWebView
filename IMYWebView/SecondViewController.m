//
//  SecondViewController.m
//  IMYWebView
//
//  Created by ljh on 15/7/3.
//  Copyright (c) 2015年 IMY. All rights reserved.
//

#import "SecondViewController.h"
#import "IMYWebView.h"
@interface SecondViewController ()
@property(strong,nonatomic)IMYWebView* webView;
@end

@implementation SecondViewController
-(instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if(self)
    {
        self.title = @"UIWebView";
    }
    return self;
}
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.webView = [[IMYWebView alloc] initWithFrame:self.view.bounds usingUIWebView:YES];
    self.webView.canLongPressSaveImage = YES;
    [self.view addSubview:_webView];
    
    if(_webView.usingUIWebView)
    {
        self.title = @"ClickRefresh-UIWebView";
    }
    else
    {
        self.title = @"ClickRefresh-WKWebView";
    }
    
    [_webView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://www.taobao.com"]]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
