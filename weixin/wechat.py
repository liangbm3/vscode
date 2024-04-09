from flask import Flask ,request,abort
import hashlib
import xmltodict
import time
from weibo import WEIBO
from zhihu import ZHIHU
import datetime
from tianqi import TIANQI
WECHAT_TOKEN="lbm666"
app=Flask(__name__)

@app.route("/wechat",methods=["GET","POST"])
def wechat():
    signature=request.args.get("signature")
    timestamp=request.args.get("timestamp")
    nonce=request.args.get("nonce")
    
    if not all([signature,timestamp,nonce]):
        abort(400)
    li=[WECHAT_TOKEN,timestamp,nonce]
    li.sort()
    tmp_str="".join(li)
    sign=hashlib.sha1(tmp_str.encode("utf-8")).hexdigest()
    if signature!=sign:
        abort(403)
    else:
        if request.method=="GET":
            echostr=request.args.get("echostr")
            if not echostr:
                abort(400)
            return echostr
        elif request.method=="POST":
            xml_str=request.data
            print(xml_str)
            if not xml_str:
                abort(400)
            xml_dict=xmltodict.parse(xml_str)
            xml_dict=xml_dict.get("xml")
            msg_type=xml_dict.get("MsgType")
            msg_content_geted=xml_dict.get("Content")
            print(msg_content_geted)
            if msg_type =="text" and msg_content_geted=="微博热搜":
                today=datetime.date.today()
                filepath="/root/server/weixin/txt"+str(today)+"-weibo.txt"
                weibo=WEIBO()
                weibo.get_message()
                with open(filepath,"w",encoding="utf-8") as fp:
                    fp.write(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())+"的微博热搜\n")
                    for i in range(len(weibo.content_list)):
                        fp.write(str(i+1)+"."+weibo.content_list[i][0]+"\n")
                with open(filepath,"r",encoding="utf-8") as fp:
                    s=fp.read()
                response_dic={
                    "xml":{
                        "ToUserName":xml_dict.get("FromUserName"),
                        "FromUserName":xml_dict.get("ToUserName"),
                        "CreateTime":int(time.time()),
                        "MsgType":"text",
                        "Content":s
                    }
                }
                response_xml=xmltodict.unparse(response_dic)
                return response_xml
    
            elif msg_type=="text" and msg_content_geted=="知乎热搜":
                today=datetime.date.today()
                filepath="/root/server/weixin/txt/"+str(today)+"-zhihu.txt"
                zhihu=ZHIHU()
                zhihu.get_message()
                with open(filepath,"w",encoding="utf-8") as fp:
                    fp.write(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime())+"的知乎热搜\n")
                    for i in range(len(zhihu.content_list)):
                        fp.write(str(i+1)+"."+zhihu.content_list[i][0]+"\n")
                with open(filepath,"r",encoding="utf-8") as fp:
                    string=fp.read()
                response_dic={
                    "xml":{
                        "ToUserName":xml_dict.get("FromUserName"),
                        "FromUserName":xml_dict.get("ToUserName"),
                        "CreateTime":int(time.time()),
                        "MsgType":"text",
                        "Content":string
                    }
                }
                response_xml=xmltodict.unparse(response_dic)
                return response_xml
            elif msg_type=="text" and msg_content_geted=="天气":
                today=datetime.date.today()
                filepath="/root/server/weixin/txt/"+str(today)+"-tianqi.txt"
                tianqi=TIANQI()
                tianqi.get_message()
                with open(filepath,"w",encoding="utf-8") as fp:
                    fp.write(str(today)+"的天气\n")
                    for i in range(len(tianqi.content_list)):
                        fp.write(tianqi.content_list[i]+"\n")
                with open(filepath,"r",encoding="utf-8") as fp:
                    s=fp.read()
                response_dic={
                    "xml":{
                        "ToUserName":xml_dict.get("FromUserName"),
                        "FromUserName":xml_dict.get("ToUserName"),
                        "CreateTime":int(time.time()),
                        "MsgType":"text",
                        "Content":s
                    }
                }
                response_xml=xmltodict.unparse(response_dic)
                return response_xml
            else:
                response_dic={
                    "xml":{
                        "ToUserName":xml_dict.get("FromUserName"),
                        "FromUserName":xml_dict.get("ToUserName"),
                        "CreateTime":int(time.time()),
                        "MsgType":"text",
                        "Content":"其他"
                    }
                }
                response_xml=xmltodict.unparse(response_dic)
                return response_xml
        # return echostr
    
if __name__ =="__main__":
    app.run(port=80,debug=True,host='0.0.0.0')