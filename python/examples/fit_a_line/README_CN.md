# 线性回归预测服务示例

(简体中文|[English](./README.md))

## 获取数据

```shell
sh get_data.sh
```



## RPC服务

### 开启服务端

```shell
python -m paddle_serving_server.serve --model uci_housing_model --thread 10 --port 9393
```

### 客户端预测

`test_client.py`中使用了`paddlepaddle`包，需要进行下载（`pip install paddlepaddle`）。

``` shell
python test_client.py uci_housing_client/serving_client_conf.prototxt
```



## HTTP服务

### 开启服务端

通过下面的一行代码开启默认web服务：

``` shell
python -m paddle_serving_server.serve --model uci_housing_model --thread 10 --port 9393 --name uci
```

### 客户端预测

``` shell
curl -H "Content-Type:application/json" -X POST -d '{"feed":[{"x": [0.0137, -0.1136, 0.2553, -0.0692, 0.0582, -0.0727, -0.1583, -0.0584, 0.6283, 0.4919, 0.1856, 0.0795, -0.0332]}], "fetch":["price"]}' http://127.0.0.1:9393/uci/prediction
```

## 性能测试
``` shell
bash benchmark.sh uci_housing_model uci_housing_client
```
性能测试的日志文件为profile_log_uci_housing_model

如需修改性能测试用例的参数，请修改benchmark.sh中的配置信息。

注意:uci_housing_model和uci_housing_client路径后不要加'/'符号,示例需要在GPU机器上运行。
