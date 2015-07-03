# IMYWebView
UIWebView seamless switching to WKWebView <br>
无缝切换 UIWebView 为 WKWebView  

QQ群号 113767274  有什么问题或者改进的地方大家一起讨论


------------------------------------
要求
====================================

* ARC only

##如何添加到项目中

```objective-c
pod 'IMYWebView'
```

##使用方法

直接把你项目中的 'UIWebView' 名称替换为 'IMYWebView'

##警告
由于WKWebView 调用js 方法是延迟主线程调用  所以要把调用方法 换为 

```objective-c
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id, NSError *))completionHandler;
///如果内部使用了 WKWebView 返回值永远为nil
- (NSString *)stringByEvaluatingJavaScriptFromString:(NSString *)javaScriptString __deprecated_msg("Method deprecated. Use [evaluateJavaScript:completionHandler:]");
```

