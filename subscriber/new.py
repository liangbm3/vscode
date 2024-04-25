import grequests
import requests
import time
import datetime
import json
target_time_list=["18","19","20","21"]
cookies = {
            "SESSION":"706da980-fa39-4b8d-b853-e526cedc2bc2",
            "from": "undefined",
            }
now_hour=time.localtime().tm_hour
now_date=datetime.date.today()
if now_hour>=12: 
    subscribe_date=str(now_date+datetime.timedelta(1))
else:
    subscribe_date=str(now_date+datetime.timedelta(1))
url_1="https://gym.sysu.edu.cn/product/findOkArea.html"
headers={
            "Accept": "application/json, text/javascript, */*; q=0.01",
            "Accept-Language": "zh-CN,zh;q=0.9",
            "Cache-Control": "no-cache",
            "Connection": "keep-alive",
            "Pragma": "no-cache",
            "Referer": "https://gym.sysu.edu.cn/product/show.html?id=522",
            "Sec-Fetch-Dest": "empty",
            "Sec-Fetch-Mode": "cors",
            "Sec-Fetch-Site": "same-origin",
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36",
            "X-Requested-With": "XMLHttpRequest",
            "sec-ch-ua": "\"Chromium\";v=\"122\", \"Not(A:Brand\";v=\"24\", \"Google Chrome\";v=\"122\"",
            "sec-ch-ua-mobile": "?0",
            "sec-ch-ua-platform": "\"Windows\""
        }
param={
    "s_date":subscribe_date,
    "serviceid": "522",
    "_": str(round(int(time.time())*1000))
    }
run_1=True
while run_1:  
    print("目标日期："+subscribe_date)
    response=requests.get(url=url_1,headers=headers,params=param)
    if response.status_code==200:
        run_1=False
        print("获取场地信息成功")
    else:
        print("获取场地信息失败，正在重新获取.....")
data_list=response.text
data_json_object=json.loads(data_list)
info_list=[]
for info in data_json_object["object"]:
    if str(info['stock']['time_no']).split(':')[0] in target_time_list:
        info_list.append([info["id"],info["stockid"],info["sname"],int(str(info['stock']['time_no']).split(':')[0])])
print(info_list)
url_2="https://gym.sysu.edu.cn/order/book.html"

data_list=[]
dat={
        "param": "{\"activityPrice\":0,\"activityStr\":null,\"address\":null,\"dates\":null,\"extend\":null,\"flag\":\"0\",\"isBulkBooking\":null,\"isbookall\":\"0\",\"isfreeman\":\"0\",\"istimes\":\"1\",\"mercacc\":null,\"merccode\":null,\"order\":null,\"orderfrom\":null,\"remark\":null,\"serviceid\":null,\"shoppingcart\":\"0\",\"sno\":null,\"stock\":{\"stockid\":\"1\"},\"stockdetail\":{\"stockid\":\"ID\"},\"stockdetailids\":\"ID\",\"stockid\":null,\"subscriber\":\"0\",\"time_detailnames\":null,\"userBean\":null}".replace(
                    'ID', str(info_list[0][0]), 2).replace('stockid', str(info_list[0][1]), 2),
        "json": "true"
    }
for item in range(len(info_list)):
    data_list.append({
        "param": "{\"activityPrice\":0,\"activityStr\":null,\"address\":null,\"dates\":null,\"extend\":null,\"flag\":\"0\",\"isBulkBooking\":null,\"isbookall\":\"0\",\"isfreeman\":\"0\",\"istimes\":\"1\",\"mercacc\":null,\"merccode\":null,\"order\":null,\"orderfrom\":null,\"remark\":null,\"serviceid\":null,\"shoppingcart\":\"0\",\"sno\":null,\"stock\":{\"stockid\":\"1\"},\"stockdetail\":{\"stockid\":\"ID\"},\"stockdetailids\":\"ID\",\"stockid\":null,\"subscriber\":\"0\",\"time_detailnames\":null,\"userBean\":null}".replace(
                    'ID', str(info_list[item][0]), 2).replace('stockid', str(info_list[item][1]), 2),
        "json": "true"
    })
requests_list=[]
for data in data_list:
    requests_list.append(grequests.post(url=url_2,headers=headers,params=data,cookies=cookies))
response_list=grequests.map(requests_list)
for i in range(len(response_list)):
    print(response_list[i].text)