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
    
    IMYWebView* webView = [[IMYWebView alloc] initWithFrame:self.view.bounds usingUIWebView:YES];
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
