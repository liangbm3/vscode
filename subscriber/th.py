import threading
from Subscriber_logmode import Subscriber
import time
class MyThread:
    def __init__(self, thread_name):
        self.thread_name = thread_name

    def run(self):
        print(f"Thread {self.thread_name} is running.")

def subscribe():
    session_1="e8ade6bd-4a3e-4c06-94b7-1170b562a09d"
    session_2="088c609f-f29f-4239-ad52-59f28ec4ec40"
    time_1=["20","21","19"]
    time_2=["19"]
    time_3=["20"]
    time_4=["21"]
    name_1=["场地2","场地3","场地4"]
    name_2=["场地9","场地8","场地5"]
    name_3=["场地7","场地6"]
    thread1 = threading.Thread(target=Subscriber(session=session_1,target_time_list=time_1,target_name_list=name_1).run)
    thread2 = threading.Thread(target=Subscriber(session=session_2,target_time_list=time_2,target_name_list=name_2).run)
    thread3 = threading.Thread(target=Subscriber(session=session_1,target_time_list=time_3,target_name_list=name_3).run)
    thread4 = threading.Thread(target=Subscriber(session=session_2,target_time_list=time_4,target_name_list=name_2).run)
    while True:
        if(time.localtime().tm_mday==2):
            thread1.start()
            thread2.start()
            thread3.start()
            thread4.start()

            thread1.join()
            thread2.join()
            thread3.join()
            thread4.join()
            break 
if __name__ == "__main__":
    subscribe()
