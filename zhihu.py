import requests
from lxml import etree

url="https://www.zhihu.com/billboard"

response=requests.get(url=url)
tree=etree.HTML(response.text)
for i in range(0,50):
    r=tree.xpath('//*[@id="root"]/div/main/div/a['+str(i+1)+']/div[2]/div[1]/text()')
    print(r)