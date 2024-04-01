import threading
from Subscriber import Subscriber

class MyThread:
    def __init__(self, thread_name):
        self.thread_name = thread_name

    def run(self):
        print(f"Thread {self.thread_name} is running.")

def main():
    session="5bf97800-a47a-498d-b007-4e9a35705100"
    time_1=["20","21","19"]
    time_2=["19"]
    time_3=["20"]
    name_1=["场地2","场地3","场地4","场地7","场地6"]
    name_2=["场地9","场地8","场地5"]
    thread1 = threading.Thread(target=Subscriber(session=session,target_time_list=time_1,target_name_list=name_1).run)
    thread2 = threading.Thread(target=Subscriber(session=session,target_time_list=time_2,target_name_list=name_2).run)

    thread1.start()
    thread2.start()

    thread1.join()
    thread2.join()

if __name__ == "__main__":
    main()
