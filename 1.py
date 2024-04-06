from urllib.request import urlopen
from bs4 import BeautifulSoup
import re

resp=urlopen('http://www.weather.com.cn/weather/101010100.shtml')
soup=BeautifulSoup(resp,'html.parser')
tagToday=soup.find('p',class_="tem")  #第一个包含class="tem"的p标签即为存放今天天气数据的标签
try:
    temperatureHigh=tagToday.span.string  #有时候这个最高温度是不显示的，此时利用第二天的最高温度代替。
except AttributeError as e:
    temperatureHigh=tagToday.find_next('p',class_="tem").span.string  #获取第二天的最高温度代替

temperatureLow=tagToday.i.string  #获取最低温度
weather=soup.find('p',class_="wea").string #获取天气
with open("./1.text","w",encoding="utf-8") as fp:
    fp.write(str(soup))
print('最低温度:' + temperatureLow)
print('最高温度:' + temperatureHigh)
print('天气:' + weather)