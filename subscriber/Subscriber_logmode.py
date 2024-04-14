import requests
import time
import json
import datetime
from logger import Logger
class Subscriber():
    def __init__(self,session,target_name_list,target_time_list) -> None: 
        self.target_name_list=target_name_list
        self.target_time_list=target_time_list
        self.logger = Logger("./log/"+str(datetime.date.today())+".log")
        self.headers={
            "Accept": "application/json, text/javascript, */*; q=0.01",
            "Accept-Language": "zh-CN,zh;q=0.9",
            "Cache-Control": "no-cache",
            "Connection": "keep-alive",
            "Pragma": "no-cache",
            "Referer": "https://gym.sysu.edu.cn/product/show.html?id=35",
            "Sec-Fetch-Dest": "empty",
            "Sec-Fetch-Mode": "cors",
            "Sec-Fetch-Site": "same-origin",
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36",
            "X-Requested-With": "XMLHttpRequest",
            "sec-ch-ua": "\"Chromium\";v=\"122\", \"Not(A:Brand\";v=\"24\", \"Google Chrome\";v=\"122\"",
            "sec-ch-ua-mobile": "?0",
            "sec-ch-ua-platform": "\"Windows\""
            }   
        self.cookies = {
            "SESSION":session,
            "from": "undefined",
            }
        now_hour=time.localtime().tm_hour
        now_date=datetime.date.today()
        if now_hour>=12: 
            self.subscribe_date=str(now_date+datetime.timedelta(1))
        else:
            self.subscribe_date=str(now_date+datetime.timedelta(1))
    def get_message(self):         
        url="https://gym.sysu.edu.cn/product/findOkArea.html"
        param={
            "s_date":self.subscribe_date,
            "serviceid": "35",
            "_": str(round(int(time.time())*1000))
            }
        run_1=True
        while run_1:  
            self.logger.logger.info("目标日期："+self.subscribe_date)
            response=requests.get(url=url,headers=self.headers,params=param,cookies=self.cookies)
            if response.status_code==200:
                run_1=False
                self.logger.logger.info("获取场地信息成功")
            else:
                self.logger.logger.info("获取场地信息失败，正在重新获取.....")
        data_list=response.text
        data_json_object=json.loads(data_list)
        self.info_list=[]
        for info in data_json_object["object"]:
            if str(info['stock']['time_no']).split(':')[0] in self.target_time_list:
                self.info_list.append([info["id"],info["stockid"],info["sname"],int(str(info['stock']['time_no']).split(':')[0])])
    def sort_data(self):
        self.info_list_sorted=[]
        for target_name in self.target_name_list:
            for i in range(len(self.info_list)):
                if target_name in self.info_list[i][2]:
                    self.info_list_sorted.append(self.info_list[i])
        # print(self.info_list_sorted)
    def post_request(self): 
        url = "https://gym.sysu.edu.cn/order/book.html"
        self.logger.logger.info("目标场地"+str(self.info_list_sorted))
        for item in range(len(self.info_list_sorted)):
            param={
                "param": "{\"activityPrice\":0,\"activityStr\":null,\"address\":null,\"dates\":null,\"extend\":null,\"flag\":\"0\",\"isBulkBooking\":null,\"isbookall\":\"0\",\"isfreeman\":\"0\",\"istimes\":\"1\",\"mercacc\":null,\"merccode\":null,\"order\":null,\"orderfrom\":null,\"remark\":null,\"serviceid\":null,\"shoppingcart\":\"0\",\"sno\":null,\"stock\":{\"stockid\":\"1\"},\"stockdetail\":{\"stockid\":\"ID\"},\"stockdetailids\":\"ID\",\"stockid\":null,\"subscriber\":\"0\",\"time_detailnames\":null,\"userBean\":null}".replace(
                            'ID', str(self.info_list_sorted[item][0]), 2).replace('stockid', str(self.info_list_sorted[item][1]), 2),
                "json": "true"
            }
            response=requests.post(url=url,headers=self.headers,params=param,cookies=self.cookies)
            if "未支付" in str(response.text):
                self.logger.logger.info(self.info_list_sorted[item][2]+"号场"+str(self.info_list_sorted[item][3])+"点预定成功")
            elif "USERNOTLOGINYET" in str(response.text):
                self.logger.logger.error("cookie不正确，请输入正确cookie后重试")
                return
            else:
                self.logger.logger.info(response.text)
    def post_request_single(self,target):
        url = "https://gym.sysu.edu.cn/order/book.html"
        self.logger.logger.info("目标场地"+str(target))
        param={
            "param": "{\"activityPrice\":0,\"activityStr\":null,\"address\":null,\"dates\":null,\"extend\":null,\"flag\":\"0\",\"isBulkBooking\":null,\"isbookall\":\"0\",\"isfreeman\":\"0\",\"istimes\":\"1\",\"mercacc\":null,\"merccode\":null,\"order\":null,\"orderfrom\":null,\"remark\":null,\"serviceid\":null,\"shoppingcart\":\"0\",\"sno\":null,\"stock\":{\"stockid\":\"1\"},\"stockdetail\":{\"stockid\":\"ID\"},\"stockdetailids\":\"ID\",\"stockid\":null,\"subscriber\":\"0\",\"time_detailnames\":null,\"userBean\":null}".replace(
                        'ID', str(target[0]), 2).replace('stockid', str(target[1]), 2),
            "json": "true"
        }
        response=requests.post(url=url,headers=self.headers,params=param,cookies=self.cookies)
        if "未支付" in str(response.text):
            self.logger.logger.info(target[2]+"号场"+str(target[3])+"点预定成功")
        elif "USERNOTLOGINYET" in str(response.text):
            self.logger.logger.error("cookie不正确，请输入正确cookie后重试")
            return
        else:
            self.logger.logger.info(response.text)
    def get_list(self):
            return self.info_list
    def run(self):
        self.get_message()
        self.sort_data()
        self.post_request()

            
if __name__=="__main__":
    session="c0fd3072-0a02-45ee-99bf-91e631a07889"
    time_=["20","21","19"]
    name=["场地2","场地3","场地4","场地7","场地6","场地9","场地8","场地5"]
    sb=Subscriber(session=session,target_name_list=name,target_time_list=time_) 
    sb.get_message()
    sb.sort_data()
    sb.post_request()
