from flask import Flask ,request,abort
import hashlib
WECHAT_TOKEN="lbm666"
app=Flask(__name__)

@app.route("/wechat")
def wechat():
    signature=request.args.get("signature")
    timestamp=request.args.get("timestamp")
    nonce=request.args.get("nonce")
    echostr=request.args.get("echostr")
    
    if not all([signature,timestamp,nonce,echostr]):
        abort(400)
    li=[WECHAT_TOKEN,timestamp,nonce]
    li.sort()
    tmp_str="".join(li)
    sign=hashlib.sha1(tmp_str.encode("utf-8")).hexdigest()
    if signature!=sign:
        abort(403)
    else:
        return echostr
    
if __name__ =="__main__":
    app.run(port=80,debug=True,host='0.0.0.0')