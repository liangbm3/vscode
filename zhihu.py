import requests
from lxml import etree

class ZHIHU():
    def __init__(self) -> None:
        self.url="https://www.zhihu.com/billboard"
    def get_messgage(self):
        self.response=requests.get(url=self.url)
        tree=etree.HTML(self.response.text)
        self.content_list=[]
        for i in range(0,50):
            r=tree.xpath('//*[@id="root"]/div/main/div/a['+str(i+1)+']/div[2]/div[1]/text()')
            self.content_list.append(r)
        
if __name__=="__main__":
    zhihu=ZHIHU()
    zhihu.get_messgage()
    print(zhihu.content_list)