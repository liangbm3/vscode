import datetime
from weibo import WEIBO
import time
import xmltodict
from zhihu import ZHIHU
from tianqi import TIANQI
import json
def menu_process(xml_dict):

    msg_content_geted=xml_dict.get("Content")
    msg_type=xml_dict.get("MsgType")
    user_name=xml_dict.get("FromUserName")
    user_name_state,cookie=identify_user(user_name=user_name)
    if user_name_state==0:
        response_dic={
            "xml":{
                "ToUserName":xml_dict.get("FromUserName"),
                "FromUserName":xml_dict.get("ToUserName"),
                "CreateTime":int(time.time()),
                "MsgType":"text",
                "Content":"菜单：\n发送0进入ai模式\n正常菜单：\n1.微博热搜\n2.知乎热搜\n3.抖音热搜\n4.天气"
            }
        }
        response_xml=xmltodict.unparse(response_dic)
        return response_xml
    else:
        if cookie==0:
            # content=get_xunfei_content(msg_content_geted)
        if msg_type =="text" and msg_content_geted=="0":
            cookie=0
            with open("/root/server/weixin/txt/user_name_list.json","r",encoding="utf-8") as fp:
                user_dict=json.loads(fp.read())
                for user in user_dict["user"]:
                    if user_name==user["name"]:
                        user["cookie"]=cookie
            with open("/root/server/weixin/txt/user_name_list.json","w",encoding="utf-8") as fp:
                fp.write(json.dumps(user_dict))
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
        
def identify_user(user_name):
    with open("/root/server/weixin/txt/user_name_list.json","r",encoding="utf-8") as fp:
        user_dict=json.loads(fp.read())
        user_list=user_dict["user"]
        print(user_list)
    for user in user_list:
        print(user["name"])
        print(user_name)
        if  user_name == user["name"]:
            cookie=user["cookie"]
            return 1,cookie
    user_dict["user"].append({"name":user_name,"cookie":1})
    with open("/root/server/weixin/txt/user_name_list.json","w",encoding="utf-8") as fp:
        fp.write(json.dumps(user_dict))
    return 0,1

# def get_xunfei_content(request_content):
    