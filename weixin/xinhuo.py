from datetime import datetime
from time import mktime
from wsgiref.handlers import format_date_time
import hmac
import hashlib
import base64
from urllib.parse import urlencode
cur_time = datetime.now()
date = format_date_time(mktime(cur_time.timetuple()))
tmp = "host: " + "spark-api.xf-yun.com" + "\n"
tmp += "date: " + date + "\n"
tmp += "GET " + "/v1.1/chat" + " HTTP/1.1"
"""上方拼接生成的tmp字符串如下
host: spark-api.xf-yun.com
date: Fri, 05 May 2023 10:43:39 GMT
GET /v1.1/chat HTTP/1.1
"""
APISecret = "Njg5NjhiMDRmMGJmNWM2MDNlMmJlOGVi"
tmp_sha = hmac.new(APISecret.encode('utf-8'), tmp.encode('utf-8'),digestmod=hashlib.sha256).digest()
"""此时生成的tmp_sha结果如下
b'\xcf\x98\x07v\xed\xe9\xc5Ux\x0032\x93\x8e\xbb\xc0\xe5\x83C\xda\xba\x05\x0c\xd1\xdew\xccN7?\r\xa4'
"""
signature = base64.b64encode(tmp_sha).decode(encoding='utf-8')
APIKey="4d93903f9f27810a446161efe68a153e"
authorization_origin = f"api_key='{APIKey}', algorithm='hmac-sha256', headers='host date request-line', signature='{signature}'"
"""此时生成的authorization_origin字符串如下
api_key="addd2272b6d8b7c8abdd79531420ca3b", algorithm="hmac-sha256", headers="host date request-line", signature="z5gHdu3pxVV4ADMyk467wOWDQ9q6BQzR3nfMTjc/DaQ="
"""
authorization = base64.b64encode(authorization_origin.encode('utf-8')).decode(encoding='utf-8')
"""此时生成的authorization如下
YXBpX2tleT0iYWRkZDIyNzJiNmQ4YjdjOGFiZGQ3OTUzMTQyMGNhM2IiLCBhbGdvcml0aG09ImhtYWMtc2hhMjU2IiwgaGVhZGVycz0iaG9zdCBkYXRlIHJlcXVlc3QtbGluZSIsIHNpZ25hdHVyZT0iejVnSGR1M3B4VlY0QURNeWs0Njd3T1dEUTlxNkJRelIzbmZNVGpjL0RhUT0i
"""
v = {
		"authorization": authorization, # 上方鉴权生成的authorization
        "date": date,  # 步骤1生成的date
    	"host": "spark-api.xf-yun.com" # 请求的主机名，根据具体接口替换
}
url = "wss://spark-api.xf-yun.com/v1.1/chat?" + urlencode(v)
"""生成的最终url如下
wss://spark-api.xf-yun.com/v1.1/chat?authorization=YXBpX2tleT0iYWRkZDIyNzJiNmQ4YjdjOGFiZGQ3OTUzMTQyMGNhM2IiLCBhbGdvcml0aG09ImhtYWMtc2hhMjU2IiwgaGVhZGVycz0iaG9zdCBkYXRlIHJlcXVlc3QtbGluZSIsIHNpZ25hdHVyZT0iejVnSGR1M3B4VlY0QURNeWs0Njd3T1dEUTlxNkJRelIzbmZNVGpjL0RhUT0i&date=Fri%2C+05+May+2023+10%3A43%3A39+GMT&host=spark-api.xf-yun.com
"""
print(url)