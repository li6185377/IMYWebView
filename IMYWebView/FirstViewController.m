//
//  FirstViewController.m
//  IMYWebView
//
//  Created by ljh on 15/7/3.
//  Copyright (c) 2015年 IMY. All rights reserved.
//

#import "FirstViewController.h"
#import "IMYWebView.h"

@interface FirstViewController ()

@end

@implementation FirstViewController
-(instancetype)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if(self)
    {
        self.title = @"IMYWebView";
    }
    return self;
}
- (void)viewDidLoad
{
    self.view.backgroundColor = [UIColor whiteColor];
    [super viewDidLoad];
    IMYWebView* webView = [[IMYWebView alloc] initWithFrame:self.view.bounds];
    [self.view addSubview:webView];
    
    if(webView.usingUIWebView)
    {
        self.title = @"IMYWebView-UIWebView";
    }
    else
    {
        self.title = @"IMYWebView-WKWebView";
    }
    
    [webView loadRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://www.baidu.com"]]];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
