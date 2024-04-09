import requests
import json
import threading
url="https://libic.sysu.edu.cn/ic-web/reserve"
cookies={
    "ic-cookie":"6f796ff4-e214-46c4-b254-c0e2553c0268"
}
headers={
    "Host": "libic.sysu.edu.cn",
    "Connection": "keep-alive",
    "Content-Length": "264",
    "sec-ch-ua": '"Microsoft Edge";v="123", "Not:A-Brand";v="8", "Chromium";v="123"',
    "sec-ch-ua-mobile": "?0",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36",
    "Content-Type": "application/json;charset=UTF-8",
    "Accept": "application/json, text/plain, */*",
    "lan": "1",
    "token": "74bd8a9da2fb409797d8c239485566bf",
    "sec-ch-ua-platform":'"Windows"',
    "Origin": "https://libic.sysu.edu.cn",
    "Sec-Fetch-Site": "same-origin",
    "Sec-Fetch-Mode": "cors",
    "Sec-Fetch-Dest": "empty",
    "Accept-Encoding": "gzip, deflate, br, zstd",
    "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6"
}
da2={
    "sysKind":1,
    "appAccNo":101273855,
    "memberKind":1,
    "resvBeginTime":"2024-04-04 19:00:00",
    "resvEndTime":"2024-04-04 21:30:00",
    "testName":"学习",
    "resvKind":2,
    "resvProperty":0,
    "appUrl":"",
    "resvMember":[101273855],
    "resvDev":[5],
    "memo":"",
    "captcha":"",
    "addServices":[]
}
da={
  "sysKind": 1,
  "appAccNo": 101273855,
  "memberKind": 1,
  "resvBeginTime": "2024-04-07 20:30:00",
  "resvEndTime": "2024-04-07 21:30:00",
  "testName": "学习",
  "resvKind": 2,
  "resvProperty": 0,
  "appUrl": "",
  "resvMember": [
    101273855
  ],
  "resvDev": [
    5
  ],
  "memo": "",
  "captcha": "",
  "addServices": []
}
def reserve(d): 
    response=requests.post(url=url,headers=headers,cookies=cookies,json=d)
    print(response.text)
    print("---------")
if __name__=="__main__":
    thread1 = threading.Thread(target=reserve(da))
    # thread2 = threading.Thread(target=reserve(da2))  
    thread1.start()
    # thread2.start()
    thread1.join()
    # thread2.join()
