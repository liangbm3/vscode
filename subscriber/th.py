import threading
from Subscriber_logmode import Subscriber
import time
class MyThread:
    def __init__(self, thread_name):
        self.thread_name = thread_name

    def run(self):
        print(f"Thread {self.thread_name} is running.")

def subscribe():
    session_1="	987b1daa-739e-4b56-a1ec-cdd2491fb20e"
    session_2="	30775313-a75f-4f21-a75e-7ecee985e10b"
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
    thread4 = threading.Thread(target=Subscriber(session=session_1,target_time_list=time_2,target_name_list=name_2).run)
    thread5 = threading.Thread(target=Subscriber(session=session_2,target_time_list=time_1,target_name_list=name_4).run)
    while True:
        if(time.localtime().tm_mday==3):
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
if __name__ == "__main__":
    subscribe()
