from flask import Flask ,request,abort
import hashlib
import xmltodict
import time
from weibo import WEIBO
from zhihu import ZHIHU
import datetime
from tianqi import TIANQI
import wechat_main_process as mp
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
            if not xml_str:
                abort(400)
            xml_dict=xmltodict.parse(xml_str)
            xml_dict=xml_dict.get("xml")
            return mp.menu_process(xml_dict=xml_dict)
if __name__ =="__main__":
    app.run(port=80,debug=True,host='0.0.0.0')