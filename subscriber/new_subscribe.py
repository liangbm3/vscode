import requests
import json
import time
import datetime
from Subscriber_logmode import Subscriber
from Pay import Pay
import threading
session=" "
name_list=[]
time_list=["18","19","20","21"]
sub=Subscriber(session,name_list,time_list)
sub.get_message()
target_list=sub.get_list()
print(target_list)
def subscribe():
    session_1="94e1234f-1eed-43f3-a671-efa5b5ee76f1"
    session_2="87bdeb00-080e-4d8f-8508-8b26c7eb3788"
    threads=[]
    for target in target_list:
        threads.append(threading.Thread(target=Subscriber(session=session_1,target_time_list=time_list,target_name_list=name_list).post_request_single(target)))
    while True:
        if(time.localtime().tm_mday==16):
            for thread in threads:
                thread.start()
            for thread in threads:
                thread.join()
            break 
subscribe()