//
//  WX:NongShiFu123 QQ:350722326
//  Created by 十三哥 on 2023/5/31.
//  Git:https://github.com/nongshifu/PUBG_China_imGui
//
#import <Foundation/Foundation.h>

//全局服务器地址
#define  BSPHP_HOST  @"https://myradar.cn/AppEn.php?appid=467645342&m=9e8ac707e317651e741a5131be49df7d"
//通信key
#define BSPHP_MUTUALKEY @"7c316f815214a1f86a18e62394528414"
//数据加密密码
#define BSPHP_PASSWORD @"6IrQ34YSce9hrFb2X1"
//接收Sgin验证 注意必须填写 并且有[KEY]
#define BSPHP_INSGIN @"[KEY]RHHGFGSNGRG"
//输出Sgin验证 注意必须填写 并且有[KEY]
#define BSPHP_TOSGIN @"[KEY]RHHGFGSNGRG"
//版本 和软件配置版本号一致 发布新版的时候 修改软件配置的版本号并且在URL那填写下载地址即可 客户端会弹出更新 确定会跳转浏览器下载
#define JN_VERSION @"v1.0"

//加密秘钥 这个在服务器文件后台 网站目录/include/applibapi/encryption下的bsphp_3des_vi.php 里面保持一致 搜索bsphp666就有3处地方都改掉 和这里源码一致
#define gIv   @"NongShiF"
//多少秒定时验证
#define  BS_DSQ 600

//软件高级选项-接收封包加密:返回封包加密 都选择baphp_3des_vi  数据输出格式选择bsphp_json

/*以下5个 参数 填写在BSPHP后台对应的软件设置-软件描述处 每个功能一个换行 切记 参数为BOOL 值 YES 或NO 大写 顺序不能错源码写死了
到期时间弹窗:YES
验证udid还是idfa:YES
验证版本更新:YES
过直播:YES
验证机器码是否是000:YES
 */

/*参数说明-详情可以看图片 说明.png
 到期时间弹窗:YES   设置YES每次启动都提示到期时间，设置NO 仅首次激活有提示 到期会有提示 正常使用期间不会提示
 验证udid还是idfa:YES  设置YES获取描述文件获取UDID ，设置NO 获取IDFA 无需描述文件
 验证版本更新:YES  设YES验证BS软件配置里面的版本号和上面JN_VERSION处是否一致 不一致就弹出URL 去浏览器下载同时app闪退 强制更新 弹出的URL更新地址在软件配置-URL地址 处 ，设置NO不验证
 过直播:YES  设置YES 弹窗就可以过直播 版本弹窗 时间到期弹窗 公告弹窗等 都能过录屏和截图 直播
 验证机器码是否是000:YES 设YES的话 上面第二个参数 验证udid还是idfa:NO 设置 为NO 仅对IDFA判断是否正常获取 系统设置-隐私-跟踪 没开启的话获取00000-
 */
//如果使用udid获取描述文件 需要udid.php上传到域名指定目录
#define  UDID_HOST  @"https://ios.weiyicent.com/udid/"

#define MyLog(fmt, ...) \
    if (isEnabledMyLog) { \
        NSLog((@"MyLog: " fmt), ##__VA_ARGS__); \
    }
//是否打印 
#define isEnabledMyLog NO

@interface NetTool : NSObject

/**
 *  AFN异步发送post请求，返回原生数据
 *
 *  @param appendURL 追加URL
 *  @param param     参数字典
 *  @param success   成功Block
 *  @param failure   失败Block
 *
 *  @return NSURLSessionDataTask任务类型
 */
+ (NSURLSessionDataTask *)__attribute__((optnone))Post_AppendURL:(NSString *)appendURL myparameters:(NSDictionary *)param mysuccess:(void (^)(id responseObject))success myfailure:(void (^)(NSError *error))failure;
@end
