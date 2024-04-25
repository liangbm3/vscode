import requests
import time
import json

class SYSU_ReserveVene():
    def __init__(self):
        self.headers_1 = {
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
        self.cookies_1 = {
    "from": "undefined",
}
        self.url_1 = "https://gym.sysu.edu.cn/product/findOkArea.html"
        self.headers_2 = {
    "Accept": "application/json, text/javascript, */*; q=0.01",
    "Accept-Language": "zh-CN,zh;q=0.9",
    "Cache-Control": "no-cache",
    "Connection": "keep-alive",
    "Content-Type": "application/x-www-form-urlencoded; charset=UTF-8",
    "Origin": "https://gym.sysu.edu.cn",
    "Pragma": "no-cache",
    "Referer": "https://gym.sysu.edu.cn/order/show.html?id=35",
    "Sec-Fetch-Dest": "empty",
    "Sec-Fetch-Mode": "cors",
    "Sec-Fetch-Site": "same-origin",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36",
    "X-Requested-With": "XMLHttpRequest",
    "sec-ch-ua": "\"Chromium\";v=\"122\", \"Not(A:Brand\";v=\"24\", \"Google Chrome\";v=\"122\"",
    "sec-ch-ua-mobile": "?0",
    "sec-ch-ua-platform": "\"Windows\""
}
        self.cookies_2 = {
            "from": "undefined",
            "SESSION": "ZMRhjlxmTSDe80S=xP8LuvnNdYSxK5frIAz7T6omMYX3RBj4EIJLRqeYcl_zKuXoSACnvnnFFXMtce_Y; ZMRhjlxmTSDe80T=5R3I47BL9wUd.xwLrAvh6SPL.tAUPLegfVL.I7FOAU1QHc2ZmkLfHYJvff95PKRLvq51XV3cusHwNvayf6Kp93VZwmFwmlr77KEz4VHh.s.TCUYVcL_ff6Gmxr54MfKEFDnj06vE9BnMVIt9ID7KmsoLX4fnwdjSN7Um0CgmYlajjoujmOI157UepxtKkbGwTrL7BHBVVUBm5BoRxFLZPA0ewJJjtyqNXpr3XO6ZyWvblFl12Pt3rJ25.f9DXsXPN1kP5xc_fwCJLSuoM_Zai5XZus1cTD_pEuis1JXUGm4aw.LoR6LQHfJEqRGyYq94UIU8HJgmz5vABvIRWNXeysuU9lyJvR8U6_I3G3NOeYQC_1rvX2RcWAP5RD8e3El7qcdtrrFs7Zh_rcLzNCnzUSFbB; SESSION=a348190b-0507-48dd-b271-e36fb86baaf5; from=undefined; JSESSIONID=EC4C0937928ECC1B1E5FEF66E5BFFC2D", # 登陆预订系统后从浏览器复制cookie
        }
        self.url_2 = "https://gym.sysu.edu.cn/order/book.html"
        self.Reverse_count = 2 # 希望预定的场地数，可修改，但一个用户一天最多订两个场
        self.VENE_lst = ['场地3', '场地4', '场地7', '场地8', '场地9', '场地2', "场地10", "场地5", "场地6", "场地1"] # 目标场地
        self.TIME_lst = [19 , 20 , 21 , 12] # 目标时间段，19-20的时间段在列表中对应为19，以此类推
        self.date = "2024-03-10" # 目标日期，试过提前两天请求，服务器会拒绝

    def GetVeneInfo(self):
        ts = round(int(time.time())*1000)
        params = {
            "s_date": self.date,
            "serviceid": "35",
            "_": f"{ts}"
        }
        response = requests.get(self.url_1, headers=self.headers_1, cookies=self.cookies_1, params=params)
        return response

    def GetId(self,response):
        info_lst = []
        for info in json.loads(response.text)['object']:
            if str(info['sname']) in self.VENE_lst:
                if int(str(info['stock']['time_no']).split(':')[0]) in self.TIME_lst:
                    info_lst.append([info['id'],info['stockid']])
            else:
                continue
        return info_lst

    def Reserve(self,lst):
        for item in range(len(lst)):
            if self.Reverse_count <= 0:
                break
            data = {
                "param": "{\"activityPrice\":0,\"activityStr\":null,\"address\":null,\"dates\":null,\"extend\":null,\"flag\":\"0\",\"isBulkBooking\":null,\"isbookall\":\"0\",\"isfreeman\":\"0\",\"istimes\":\"1\",\"mercacc\":null,\"merccode\":null,\"order\":null,\"orderfrom\":null,\"remark\":null,\"serviceid\":null,\"shoppingcart\":\"0\",\"sno\":null,\"stock\":{\"stockid\":\"1\"},\"stockdetail\":{\"stockid\":\"ID\"},\"stockdetailids\":\"ID\",\"stockid\":null,\"subscriber\":\"0\",\"time_detailnames\":null,\"userBean\":null}".replace(
                    'ID', str(lst[item][0]), 2).replace('stockid', str(lst[item][1]), 2),
                "json": "true"
            }
            response = requests.post(self.url_2, headers=self.headers_2, cookies=self.cookies_2, data=data)
            print(response.text)
            if "未支付" in str(response.text):
                print('------------------------------------------------------------------------------------------------------------')
                print("      -->预定成功<--")
                print("----->需要在规定时间内缴费<-----")
                print('------------------------------------------------------------------------------------------------------------')
                self.Reverse_count -= 1
            if str(json.loads(response.text)['message']) == "USERNOTLOGINYET":
                self.cookies_2['SESSION'] = input("输入从浏览器复制的cookie")

    def main(self):
        resp = self.GetVeneInfo()
        id_lst = self.GetId(resp)
        self.Reserve(id_lst)
        print("程序结束...")

sysu = SYSU_ReserveVene()
sysu.main()