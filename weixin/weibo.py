import requests
from lxml import etree

class WEIBO():
    def __init__(self) -> None:
        self.url="https://s.weibo.com/top/summary/"
        self.headers={
                "Host": "s.weibo.com",
                "Connection": "keep-alive",
                "Cache-Control": "max-age=0",
                "sec-ch-ua": '"Microsoft Edge";v="123", "Not:A-Brand";v="8", "Chromium";v="123"',
                "sec-ch-ua-mobile": "?0",
                "sec-ch-ua-platform": '"Windows"',
                "Upgrade-Insecure-Requests": "1",
                "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36 Edg/123.0.0.0",
                "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7",
                "Sec-Fetch-Site": "same-site",
                "Sec-Fetch-Mode": "navigate",
                "Sec-Fetch-User": "?1",
                "Sec-Fetch-Dest": "document",
                "Referer": "https://passport.weibo.com/",
                "Accept-Encoding": "gzip, deflate, br, zstd",
                "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6"
                    }
        self.cookies={
                "SUB":"_2AkMRU-Gbf8NxqwFRmfsUxG3nbIV1ygzEieKnDxBAJRMxHRl-yT8XqnMBtRB6OtPPdHEcGdBAv-vQCbBi5l5DyXEWhKJk",
                "SUBP":"0033WrSXqPxfM72-Ws9jqgMF55529P9D9W593SeO6blWiG5v_cFqa_2L",
                "_s_tentry":"passport.weibo.com", 
                "Apache":"392024452818.23596.1712287403830",
                "SINAGLOBAL":"392024452818.23596.1712287403830",
                "ULV":"1712287403861:1:1:1:392024452818.23596.1712287403830:"
                    }
    def get_message(self):
        self.response=requests.get(url=self.url,headers=self.headers,cookies=self.cookies)
        tree=etree.HTML(self.response.text)
        self.content_list=[]    
        for i in range(0,50):
            r=tree.xpath('/html/body/div[1]/div[2]/div/div[2]/div[1]/table/tbody/tr['+str(i+1)+']/td[2]/a/text()')
            self.content_list.append(r)
            
if __name__=="__main__":
    weibo=WEIBO()
    weibo.get_message()
    print(weibo.content_list[0][0])