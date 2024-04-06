import requests

url="http://www.weather.com.cn/weather/101010100.shtml"
response=requests.get(url=url)

tex_code=response.encoding
response_text=response.text.encode(tex_code).decode("utf-8")
print(response_text)
with open("2.html","w",encoding="utf-8") as fp:
    fp.write(response_text)