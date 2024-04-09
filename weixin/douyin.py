import requests
import lxml
from urllib import parse
import json
class DOUYIN():
    def __init__(self) -> None:
        self.url="https://www.douyin.com/aweme/v1/web/hot/search/list/?"
        self.headers={
            "Host":"www.douyin.com",
            "Connection": "keep-alive",
            "sec-ch-ua": '"Microsoft Edge";v="123", "Not:A-Brand";v="8", "Chromium";v="123"',
            "sec-ch-ua-mobile": "?0",
            "sec-ch-ua-platform": '"Windows"',
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36 Edg/123.0.0.0",
            "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
            "Sec-Fetch-Site": "same-origin",
            "Sec-Fetch-Mode": "cors",
            "Sec-Fetch-Dest": "empty",
            "Referer": "https://www.douyin.com/hot",
            "Accept-Encoding": "gzip",
            "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6"

        }
        self.param={
            "device_platform":"webapp",
            "aid":"6383",
            "channel":"channel_pc_web",
            "detail_list":"1",
            "source":"6",
            "pc_client_type":"1",
            "version_code":"290100",
            "version_name":"29.1.0",
            "cookie_enabled":"true",
            "screen_width":"1707",
            "screen_height":"1067",
            "browser_language":"zh-CN",
            "browser_platform":"Win32",
            "browser_name":"Edge",
            "browser_version":"123.0.0.0",
            "browser_online":"true",
            "engine_name":"Blink",
            "engine_version":"123.0.0.0",
            "os_name":"Windows",
            "os_version":"10",
            "cpu_core_num":"20",
            "device_memory":"8",
            "platform":"PC",
            "downlink":"5.8",
            "effective_type":"4g",
            "round_trip_time":"150",
            "webid":"7340870683050362403",
            "msToken":"wYppdfpMasKZwfPUtA5dN-IHnjovn3d-94RAETv57tgSxXYci7Cg3yhmwgEBI3y_BcUMKN5j_9xEtnquyTH8zXvObIVdCaI3Wl6dlWOzKasBXl8jlq5TCOMKMlFF",
            "a_bogus":"Dvm0BmzXdDdiDfS3535LfY3q6fN3YDyx0trEMD2fLdV8Uy39HMOC9exosfTvFrSjLT/AIegjy4hbTNCQrQIJ81wf9WLKUoqBM6gDtF1dsqbC5ZUjCjumE0DF-vwltBBB5v1IrOXQq7pHFbYZldAn5w96bfatcHhMHjkrPVrUfptsHRg="
        }
    def get_message(self):
        self.response=requests.get(url=self.url,headers=self.headers,params=self.param)
        self.json_data=json.loads(self.response.text)
        self.content_list=[]
        for content in self.json_data["data"]["word_list"]:
            self.content_list.append(content["word"])
    def get_content_list(self):
        return self.content_list
if __name__=="__main__":
    douyin=DOUYIN()
    douyin.get_message()
    print(douyin.get_content_list())
# s = s.encode('unicode_escape')
# ss = s.decode('utf-8').replace('\\x', '%')
# un = parse.unquote(ss)
# print(json.loads(un))
