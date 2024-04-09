import requests
import json
import time

class Pay():
    def __init__(self,session) -> None:      
        self.cookies = {
                    "SESSION":session,
                    "from": "undefined",
                    
                }
    def get_pay_list(self): 
        url="https://gym.sysu.edu.cn/order/seachData.html" 
        headers = {
                "Accept": "application/json, text/javascript, */*; q=0.01",
                "Accept-Language": "zh-CN,zh;q=0.9",
                "Cache-Control": "no-cache",
                "Connection": "keep-alive",
                "Pragma": "no-cache",
                "Referer": "https://gym.sysu.edu.cn/order/showMyOrderDetail.html",
                "Origin": "https://gym.sysu.edu.cn",
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
            "orderid":"",
            "id":"",
            "page":1,
            "rows":10
        }    
        response=requests.post(url=url,headers=headers,cookies=self.cookies,data=param)
        print(response.text)
        if "绑定NetID - 中央身份验证服务(CAS)" in response.text[0:100]:
            return 0
        else:    
            json_object=json.loads(response.text)
            self.orderid_list=[]
            for item in json_object["rows"]:
                self.orderid_list.append(item["orderid"])
            return 1
    def try_pay(self):   
        url="https://gym.sysu.edu.cn/pay/account/topay.html"
        for orderid in self.orderid_list:
            headers = {
                    "Host": "gym.sysu.edu.cn",
                    "Connection": "keep-alive",
                    "Content-Length": "101",
                    "sec-ch-ua": '"Chromium";v="122", "Not(A:Brand";v="24", "Microsoft Edge";v="122"',
                    "Accept": "application/json, text/javascript, */*; q=0.01",
                    "Content-Type": "application/x-www-form-urlencoded; charset=UTF-8",
                    "X-Requested-With": "XMLHttpRequest",
                    "sec-ch-ua-mobile": "?0",
                    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36 Edg/122.0.0.0",
                    "sec-ch-ua-platform": '"Windows"',
                    "Origin": "https://gym.sysu.edu.cn",
                    "Sec-Fetch-Site": "same-origin",
                    "Sec-Fetch-Mode": "cors",
                    "Sec-Fetch-Dest": "empty",
                    "Referer": "https://gym.sysu.edu.cn/pay/show.html?id="+orderid,
                    "Accept-Encoding": "gzip, deflate, br",
                    "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6"
                    }
            da='param={"payid":2,"orderid":'+orderid+',"ctypeindex":0}&json=true'
            response2=requests.post(url=url,data=da,headers=headers,cookies=self.cookies)
            print(response2.text)
    def pay_process(self):
        state=self.get_pay_list()
        if state==0:
            print("cookie错误，请重新输入")
            return
        elif state==1:
            self.try_pay()
            
            
if __name__=="__main__":
    pay=Pay("87bdeb00-080e-4d8f-8508-8b26c7eb3788")
    pay.pay_process()