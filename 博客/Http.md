[toc]
---
# 前言
&nbsp;&nbsp;&nbsp;&nbsp;在互联网世界中，HTTP（HyperText Transfer Protocol，超文本传输协议）是一个至关重要的协议。它定义了客户端（如浏览器）与服务器之间如何通信，以交换或传输超文本
# Http报文
## 格式
&nbsp;&nbsp;&nbsp;&nbsp;Http请求由请求行, 报头, 请求正文组成, Http应答由状态行, 报头, 应答正文组成
## 请求行
&nbsp;&nbsp;&nbsp;&nbsp;请求行由请求方法, URL, Http版本组成
### 请求方法
- GET: 用于向服务器获取资源
- POST: 用于向服务器上传文件或表单
- PUT: 用于向服务器上传或更新资源
- DELETE: 要求服务器删除特定资源
- PATCH: 用于对资源进行部分更新
- HEAD: 要求服务器响应只返回响应头
- OPTIONS: 要求服务器返回支持的HTTP方法列表
- CONNECT: 用于代理服务器隧道连接
- TRACE: 用于测试, 返回原始的请求报文
### URL
&nbsp;&nbsp;&nbsp;&nbsp;URL(统一资源定位符), 是指互联网上资源的地址，它标识了资源的具体位置以及如何访问该资源
URL 通常由以下几个部分组成：
- 协议（scheme）：指定访问资源所使用的协议，比如 http://、https://、ftp:// 等。
- 域名或IP地址（host）：标识资源所在的服务器，比如 www.example.com 或 IP 地址 192.168.1.1。
- 端口号（port）：标识服务器的具体服务端口，默认情况下 HTTP 使用端口 80，HTTPS 使用端口 443。如果使用的是默认端口，可以省略不写。
- 路径（path）：服务器上资源的具体路径，比如 /folder/page.html。
- 查询参数（query）：用于传递给资源的附加信息，以 ? 开头，比如 ?id=123&name=abc。
- 片段标识符（fragment）：标识资源中的某一部分，通常用于定位网页中的具体位置，以 # 开头，比如 #section1。
比如我们访问百度的某个资源
`
https://www.baidu.com/?tn=68018901_16_pg
`
## 状态行
&nbsp;&nbsp;&nbsp;&nbsp;状态行由HTTP版本, 状态码, 状态码描述组成
### 状态码
&nbsp;&nbsp;&nbsp;&nbsp;HTTP有五种状态码
- 1XX(信息型状态码): 用于提醒信息, 比如100(提示客户端可继续发送数据), 101(提示客户端服务端已接受协议转化)
- 2XX(成功状态码): 表示请求已经处理完成, 比如200(请求成功), 201(请求成功, 资源已创建(POST));
- 3XX(重定向状态码): 表示需要附加操作完成请求, 比如301(资源已被永久重定向), 302(暂时重定向)
- 4XX(客户端错误码): 表示客户端错误, 比如404(请求的资源不存在), 401(请求未授权)
- 5XX(服务端错误码): 表示服务端错误, 比如500(服务器内部错误), 503(服务不可用);
## 报头
&nbsp;&nbsp;&nbsp;&nbsp;HTTP报头存放了报文的附加信息, 以下是常见的一些报文
- Content-Type: 数据类型(text/html 等)
- Content-Length: Body 的长度
- Host: 客户端告知服务器, 所请求的资源是在哪个主机的哪个端口上;
- User-Agent: 声明用户的操作系统和浏览器版本信息;
- referer: 当前页面是从哪个页面跳转过来的;
- Location: 搭配 3xx 状态码使用, 告诉客户端接下来要去哪里访问;
- Cookie: 用于在客户端存储少量信息. 通常用于实现会话(session)的功能;
## 正文
&nbsp;&nbsp;&nbsp;&nbsp;正文存放着实际数据, 比如我们使用post方法请求时, 正文里就存放了提交的表单数据, 使用get请求一个页面时, 得到的响应报文中的正文中就包括了该网页的html代码
- 示例: 使用GET请求一个网页
得到的响应正文
# Cookie和Session
## Cookie
&nbsp;&nbsp;&nbsp;&nbsp;Cookie是HTTP报头中的一个可选字段, 在报文中使用Set-Cookie选项设置Cookie发送给客户端,保存在用户浏览器上，它会在浏览器之后向同一服务器再次发起请求时被携带并发送到服务器上。通常，它用于告知服务端两个请求是否来自同一浏览器，如保持用户的登录状态
### 基本格式
比如设置这样一个Cookie
`
Set-Cookie: username=peter; expires=Thu, 18 Dec 2024 12:00:00 UTC ;path=/;domain=.example.com; secure;HttpOnly
`
- expires=<date>：设置 Cookie 的过期日期/时间。如果未指定此属性，则 Cookie 默认为会话 Cookie，即当浏览器关闭时过期。
- path=<some_path>：限制 Cookie 发送到服务器的哪些路径。默认为设置它的路径。
- domain=<domain_name>：指定哪些主机可以接受该 Cookie。默认为设置它的主机。
- secure：仅当使用 HTTPS 协议时才发送 Cookie。这有助于防止Cookie 在不安全的 HTTP连接中被截获
- HttpOnly：标记 Cookie 为 HttpOnly，意味着该 Cookie 不能被 客户端脚本（如 JavaScript）访问。这有助于防止跨站脚本攻击（XSS）。
### 工作原理
- 当用户第一次访问网站时，服务器会在响应的 HTTP 头中设置 Set-Cookie字段，用于发送 Cookie 到用户的浏览器, 用这个Cookie表示用户身份,
- 浏览器在接收到 Cookie 后，会将其保存在本地。
- 在之后的请求中，浏览器会自动在 HTTP 请求头中携带 Cookie 字段，将之前保存的 Cookie 信息发送给服务器, 
## Session
&nbsp;&nbsp;&nbsp;&nbsp;HTTP Session 是服务器用来跟踪用户与服务器交互期间用户状态的机制。由于 HTTP协议是无状态的（每个请求都是独立的），因此服务器需要通过 Session 来记住用户的信息, Session需要后端自行管理
### 保持用户登录状态的工作原理
- 当用户首次访问网站时，服务器会为用户创建一个唯一的 Session ID，并通过Cookie 将其发送到客户端。
- 客户端在之后的请求中会携带这个 Session ID，服务器通过 Session ID 来识别用户，从而获取用户的会话信息。
- 服务器通常会将 Session 信息存储在内存、数据库或缓存中。