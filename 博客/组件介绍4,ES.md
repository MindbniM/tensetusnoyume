# 前言
&nbsp;&nbsp;&nbsp;&nbsp;Elasticsearch，简称 ES，它是个开源分布式搜索引擎, 它可以近乎实时的存储、检索数据；本身扩展性很好，可以扩展到上百台服务器，处理 PB 级别的数据
# 安装
## 安装ES
1. 使用包管理器安装
``` sh
#添加仓库密钥, 如果下载不了, 可手动访问下载密钥文件传到Linux上再添加
curl -s https://artifacts.elastic.co/GPG-KEY-elasticsearch | sudo gpg --no-default-keyring --keyring gnupg-ring:/etc/apt/trusted.gpg.d/icsearch.gpg --import
#添加镜像源仓库
echo "deb https://artifacts.elastic.co/packages/7.x/apt stable main" | sudo tee /etc/apt/sources.list.d/elasticsearch.list
# 更新软件包列表并安装es
sudo apt update
sudo apt-get install elasticsearch=7.17.21
#启动
sudo systemctl start elasticsearch
#安装 ik 分词器插件
sudo /usr/share/elasticsearch/bin/elasticsearch-plugin install https://get.infini.cloud/elasticsearch/analysis-ik/7.17.21
```
2. 从官网下载
从[官网](https://www.elastic.co/cn/downloads/elasticsearch)下载, 将压缩包传到Linux, 使用tar命令解压即可
### 解决内存不足问题
&nbsp;&nbsp;&nbsp;&nbsp;调整 ES 虚拟内存，虚拟内存默认最大映射数为 65530，无法满足 ES 系统要求，需要调整为 262144 以上
``` sh
sysctl -w vm.max_map_count=262144
# 增加虚拟机内存配置
vim /etc/elasticsearch/jvm.options
# 新增如下内容
-Xms512m
-Xmx512m
```
### 验证安装
``` sh
curl -X GET "http://localhost:9200/"
```
如果出现以下内容，说明ES安装成功
``` json
{
  "name" : "iZf8z39ru2s81ejbnz7aa4Z",
  "cluster_name" : "elasticsearch",
  "cluster_uuid" : "atc3qRn2QXKFmiTCPkrDrQ",
  "version" : {
    "number" : "7.17.25",
    "build_flavor" : "default",
    "build_type" : "deb",
    "build_hash" : "f9b6b57d1d0f76e2d14291c04fb50abeb642cfbf",
    "build_date" : "2024-10-16T22:06:36.904732810Z",
    "build_snapshot" : false,
    "lucene_version" : "8.11.3",
    "minimum_wire_compatibility_version" : "6.8.0",
    "minimum_index_compatibility_version" : "6.0.0-beta1"
  },
  "tagline" : "You Know, for Search"
}
```
## 安装kibana
&nbsp;&nbsp;&nbsp;&nbsp;Kibana 是 Elasticsearch 的图形化用户界面工具，用于可视化和分析存储在 Elasticsearch 中的数据
1. 使用包管理器直接安装即可
``` sh
sudo apt install kibana
#启动
sudo systemctl start kibana
```
2. 从官网下载
从[官网](https://www.elastic.co/cn/downloads/kibana)下载传到Linux
### 验证安装
访问http://<你的ip>:5601
出现此界面就说明安装成功
## 安装客户端
&nbsp;&nbsp;&nbsp;&nbsp;源码安装即可
``` sh
git clone https://github.com/seznam/elasticlient
cd elasticlient
# 更新子模块
git submodule update --init --recursive
# 编译代码
mkdir build
cd build
cmake ..
make
make install
```
### 接口介绍
1. 初始化
我们后续的操作都要通过这个完成
``` cpp
//使用一个vector<string>构造
elasticlient::Client client({"http://127.0.0.1:9200/"});
```
2. 创建索引
``` cpp
//调用index方法创建索引, 传入索引名, 类型, id, body(就是之前手动输入的json串)
cpr::Response re=client.index(name,type,id,body);
```


# 简单使用
&nbsp;&nbsp;&nbsp;&nbsp;这里重点讲解客户端的使用和封装,对于其他的只提一下
## 简单介绍
1. **索引（Index）**
一个索引就是一个拥有几分相似特征的文档的集合。
2. **类型（Type）**
在一个索引中，你可以定义一种或多种类型
3. **字段（Field）**
字段相当于是数据表的字段，对文档数据根据不同属性进行的分类标识

| 类型         | 备注 |
| ----------- | ----------- |
| text keyword  | 这俩是字符串类型, text 会被分词生成索引;keyword 不会被分词生成索引，只能精确值搜索       |
| integer, long, short, byte   | 整形        |
| double， float| 浮点数|
| boolean| true 或 false| 
| date, date_nanos| 时间字符串或者时间戳|
|binary| 二进制|
| range| 范围|
4. 映射（mapping）
映射是在处理数据的方式和规则方面做一些限制，如某个字段的数据类型、默认值、分析器、是否被索引等等，这些都是映射里面可以设置的
5. 各种详细请查看[官方文档](https://www.elastic.co/guide/en/elasticsearch/reference/current/index.html);
## 示例
### 创建索引
&nbsp;&nbsp;&nbsp;&nbsp;使用Kibana 访问 es, 进入开发工具
创建一个用户索引, 
``` json
PUT /user
{
  "settings": {
    "analysis": {
      "analyzer": {
        "ik": {
          "tokenizer": "ik_max_word" 
        }
      }
    }
  },
  "mappings": {
    "dynamic": true,
    "properties": {
      "nickname": {
        "type": "text",
        "analyzer": "ik_max_word"
      },
      "user_id": {
        "type": "keyword"
      },
      "description": {
        "type": "text",
        "enabled": false
      },
    }
  }
}

```
- 设置了一个名为 ik 的自定义分析器（Analyzer）。索引创建后，所有使用 analyzer: "ik_max_word" 的字段都会用这个分词器进行分词。
- nickname: 字段类型：text, 存储为倒排索引，可以对分词后的内容进行搜索
- user_id: 字段类型：keyword, 存储为精确值
- description: 字段类型：text，但 enabled: false 禁用了该字段的索引。
### 插入
插入的格式就很简单了
``` json
POST /user/_doc
{
  "nickname": "张三",
  "user_id": "12345",
  "description": "描述内容"
}
```
也可指名id, 不指名会自动生成
``` json
PUT /user/_doc/123
{
  "nickname": "李四",
  "user_id": "67890",
  "description": ""
}
```
### 删除
通过id删除数据即可
``` json
DELETE /user/_doc/123
``` 
删除索引
``` json
DELETE /user
```
### 查找


