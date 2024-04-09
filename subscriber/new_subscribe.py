import requests
import json
import time
import datetime
from Subscriber_logmode import Subscriber
from Pay import Pay
import threading
session=" "
name_list=[]
time_list=[]
sub=Subscriber(session,name_list,time_list)
sub.get_message()
target_list=sub.get_list()
print(target_list)
def subscribe():
    session_1="6de0549f-4b58-4bd5-acb3-6aa3011b7722"
    session_2="87bdeb00-080e-4d8f-8508-8b26c7eb3788"
    time_1=["20","21","19"]
    time_2=["19"]
    time_3=["20"]
    time_4=["21"]
    name_1=["场地2","场地3","场地4"]
    name_2=["场地9","场地8","场地5"]
    name_3=["场地7","场地6"]
    name_4=["场地1","场地10","场地6"]
    thread1 = threading.Thread(target=Subscriber(session=session_1,target_time_list=time_2,target_name_list=name_1).run)
    thread2 = threading.Thread(target=Subscriber(session=session_2,target_time_list=time_3,target_name_list=name_2).run)
    thread3 = threading.Thread(target=Subscriber(session=session_1,target_time_list=time_4,target_name_list=name_3).run)

    while True:
        if(time.localtime().tm_mday==7):
            thread1.start()
            thread2.start()
            thread3.start()
            thread4.start()
            thread5.start()

            thread1.join()
            thread2.join()
            thread3.join()
            thread4.join()
            thread5.join()
            break 
