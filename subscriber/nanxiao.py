import requests
import time
import json
import datetime
from logger import Logger
import pickle
target_time_list=["14","15","16","17","18"]
target_name_list=["场地7","场地8","场地9","场地10","场地11","场地12","场地13","场地14","场地15","场地16","场地17"]
cookies = {
            "SESSION":"4c5fe6bf-ee38-4164-83d2-bb46cb9df29d",
            "from": "undefined",
            }
now_hour=time.localtime().tm_hour
now_date=datetime.date.today()
if now_hour>=12: 
    subscribe_date=str(now_date+datetime.timedelta(2))
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
    if str(info['stock']['time_no']).split(':')[0] in target_time_list and info["sname"] in target_name_list:
        info_list.append([info["id"],info["stockid"],info["sname"],int(str(info['stock']['time_no']).split(':')[0])])
with open("C:\\onedrive\\OneDrive - 中山大学\\桌面\\github工作区\\crawler\\txt\\data.json","w") as fp:
    json.dump(info_list,fp)