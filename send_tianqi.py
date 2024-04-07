from tianqi import TIANQI
import zmail
import datetime
sender = ('lbmwudi@163.com','ZFJZJPXCHIMFQMAD')
receiver = ['3095088766@qq.com']

tianqi=TIANQI()
tianqi.get_message()
content_list=tianqi.content_list
today=datetime.date.today()
filepath="/root/server/txt/"+str(today)+"-tianqi.txt"
with open(filepath,"w",encoding="utf-8") as fp:
    fp.write(str(today)+"的天气\n")
    for i in range(len(content_list)):
        fp.write(content_list[i]+"\n")
with open(filepath,"r",encoding="utf-8") as fp:
    s=fp.read()
mail_msg = {
    # 主题
    "subject":'主题：'+str(today)+"天气",
    # 正文-纯文本
    "content_text":s
}
server = zmail.server(*sender)
 
# 2-通过邮件的服务去发送邮件
server.send_mail(recipients=receiver,
                 mail=mail_msg,)
    