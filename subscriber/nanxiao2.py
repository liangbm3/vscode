import pickle
import json
import grequests
import requests
import datetime
import time
today=now_date=time.localtime().tm_mday
session1="9d887cd2-2232-4c1b-9e95-fa75ae341ff8"
session2="9d887cd2-2232-4c1b-9e95-fa75ae341ff8"
session3="9d887cd2-2232-4c1b-9e95-fa75ae341ff8"
cookies1 = {
    "SESSION":session1,
    "from": "undefined",
    }
cookies2 = {
    "SESSION":session2,
    "from": "undefined",
    }
cookies3 = {
    "SESSION":session3,
    "from": "undefined",
    }
with open("C:\\onedrive\\OneDrive - 中山大学\\桌面\\github工作区\\crawler\\txt\\data.json","r") as fp:
    info_list=json.load(fp)
    print(info_list)
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
url_2="https://gym.sysu.edu.cn/order/book.html"
data_list_1=[]
data_list_2=[]
data_list_3=[]
for item in range(len(info_list)):
    if info_list[item][3]==14:
        data_list_1.append({
            "param": "{\"activityPrice\":0,\"activityStr\":null,\"address\":null,\"dates\":null,\"extend\":null,\"flag\":\"0\",\"isBulkBooking\":null,\"isbookall\":\"0\",\"isfreeman\":\"0\",\"istimes\":\"1\",\"mercacc\":null,\"merccode\":null,\"order\":null,\"orderfrom\":null,\"remark\":null,\"serviceid\":null,\"shoppingcart\":\"0\",\"sno\":null,\"stock\":{\"stockid\":\"1\"},\"stockdetail\":{\"stockid\":\"ID\"},\"stockdetailids\":\"ID\",\"stockid\":null,\"subscriber\":\"0\",\"time_detailnames\":null,\"userBean\":null}".replace(
                        'ID', str(info_list[item][0]), 2).replace('stockid', str(info_list[item][1]), 2),
            "json": "true"
        })
for item in range(len(info_list)):
    if info_list[item][3] ==15:
        data_list_2.append({
            "param": "{\"activityPrice\":0,\"activityStr\":null,\"address\":null,\"dates\":null,\"extend\":null,\"flag\":\"0\",\"isBulkBooking\":null,\"isbookall\":\"0\",\"isfreeman\":\"0\",\"istimes\":\"1\",\"mercacc\":null,\"merccode\":null,\"order\":null,\"orderfrom\":null,\"remark\":null,\"serviceid\":null,\"shoppingcart\":\"0\",\"sno\":null,\"stock\":{\"stockid\":\"1\"},\"stockdetail\":{\"stockid\":\"ID\"},\"stockdetailids\":\"ID\",\"stockid\":null,\"subscriber\":\"0\",\"time_detailnames\":null,\"userBean\":null}".replace(
                        'ID', str(info_list[item][0]), 2).replace('stockid', str(info_list[item][1]), 2),
            "json": "true"
        })
for item in range(len(info_list)):
    if info_list[item][3] ==16 or info_list[item][3]==17:
        data_list_3.append({
            "param": "{\"activityPrice\":0,\"activityStr\":null,\"address\":null,\"dates\":null,\"extend\":null,\"flag\":\"0\",\"isBulkBooking\":null,\"isbookall\":\"0\",\"isfreeman\":\"0\",\"istimes\":\"1\",\"mercacc\":null,\"merccode\":null,\"order\":null,\"orderfrom\":null,\"remark\":null,\"serviceid\":null,\"shoppingcart\":\"0\",\"sno\":null,\"stock\":{\"stockid\":\"1\"},\"stockdetail\":{\"stockid\":\"ID\"},\"stockdetailids\":\"ID\",\"stockid\":null,\"subscriber\":\"0\",\"time_detailnames\":null,\"userBean\":null}".replace(
                        'ID', str(info_list[item][0]), 2).replace('stockid', str(info_list[item][1]), 2),
            "json": "true"
        })
requests_list=[]
for data in data_list_1:
    requests_list.append(grequests.post(url=url_2,headers=headers,params=data,cookies=cookies1))
for data in data_list_2:
    requests_list.append(grequests.post(url=url_2,headers=headers,params=data,cookies=cookies2))
for data in data_list_3:
    requests_list.append(grequests.post(url=url_2,headers=headers,params=data,cookies=cookies3))
print(len(requests_list))
print(today)
while True:
        print("运行")
        response_list=grequests.map(requests_list)
        for i in range(len(response_list)):
            print(response_list[i])
        print(response_list[i].text)
        time.sleep(5)