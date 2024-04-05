#案例：发送一个邮件，邮件包含主题、收件人、邮件内容（文本格式）
import zmail
# 发件人（用户名、密码）
sender = ('lbmwudi@163.com','ZFJZJPXCHIMFQMAD')
# # 收件人
receiver = ['3095088766@qq.com']
# # 抄送人
copy = ['XXXXX@qq.com','XXXX@qq.com','XXXXXX@qq.com']
# 邮件内容 - 必须以字典来存储
mail_msg = {
    # 主题
    "subject":'主题：测试zmail邮件发送是否成功',
    # 正文-纯文本
    "content_text":"hhhh,python 你好，......."
}
 
# 发送邮件
# 1-构建发送邮件的服务
# server = zmail.server(sender[0],sender[1])
server = zmail.server(*sender)
 
# 2-通过邮件的服务去发送邮件
server.send_mail(recipients=receiver,
                 mail=mail_msg,)