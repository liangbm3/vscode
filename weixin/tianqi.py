import requests
from lxml import etree
import re
import json

class TIANQI():
    def __init__(self) -> None:
        self.url="http://www.weather.com.cn/weather1d/101280102.shtml"
    def get_message(self):
        self.response=requests.get(url=self.url)
        tex_code=self.response.encoding
        self.response_text=self.response.text.encode(tex_code).decode("utf-8")
        tree=etree.HTML(self.response_text)
        r=tree.xpath('//*[@id="today"]/script/text()')
        pattern=r".*?hour3data=(\{.*?\})"
        match=re.findall(pattern,str(r[0]))
        json_data=json.loads(match[0])
        one_day_data=json_data["1d"]
        pattern2=r"(\d{2}日\d{2}时,)\w{3},(.*?级),\d"
        self.content_list=[]
        for i in range(len(one_day_data)):
            new_data=re.findall(pattern2,one_day_data[i])
            self.content_list.append(str(new_data[0][0])+str(new_data[0][1]))

if __name__=="__main__":
    tianqi=TIANQI()
    tianqi.get_message()
    print(tianqi.content_list)