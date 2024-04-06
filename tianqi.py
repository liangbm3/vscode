import requests
from lxml import etree
import re
import json
url="http://www.weather.com.cn/weather1d/101280102.shtml"
response=requests.get(url=url)

tex_code=response.encoding
response_text=response.text.encode(tex_code).decode("utf-8")
tree=etree.HTML(response_text)
r=tree.xpath('//*[@id="today"]/script/text()')
# with open("2.html","w",encoding="utf-8") as fp:
#     fp.write(response_text)
pattern=r".*?hour3data=(\{.*?\})"
match=re.findall(pattern,str(r[0]))
json_data=json.loads(match[0])
one_day_data=json_data["1d"]
pattern2=r"(\d{2}日\d{2}时,)\w{3},(.*?级),\d"
for i in range(len(one_day_data)):
    new_data=re.findall(pattern2,one_day_data[i])
    print(one_day_data[i])
    print(str(new_data[0][0])+str(new_data[0][1]))
