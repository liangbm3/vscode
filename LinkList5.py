# -*- coding: utf-8 -*-

class Node(object):
    """双向链表的结点"""
    def __init__(self, item):
        # item存放数据元素
        self.item = item
        # next 指向下一个节点的标识
        self.next = None
        # prev 指向上一结点
        self.prev = None

class BilateralCycleLinkList(object):
    """双向循环列表"""
    def __init__(self):
        self._head=None
    def is_empty(self):
        """判断列表是否为空"""
        return self._head is None
    def length(self):
        """链表长度"""
        #链表为空
        if self.is_empty():
            return 0
        #链表不为空
        count=1
        cur=self._head
        while cur.next !=self._head:
            cur=cur.next
            count+=1
        return count
    def items(self):
        """ 遍历链表 """
        # 链表为空
        if self.is_empty():
            return
        # 链表不为空
        cur = self._head
        while cur.next != self._head:
            yield cur.item
            cur = cur.next
        yield cur.item
    def add(self,item):
        """头部添加节点"""
        node=Node(item)
        if self.is_empty():
            self._head=node
            node.next=self._head
            node.prev=self._head
        else:
            node.next=self._head
            node.next.prev=node
            cur=self._head
            while cur.next!=self._head:
                cur=cur.next
            cur.next=node
            node.prev=cur
            self._head=node
    def append(self,item):
        """尾部添加节点"""
        node=Node(item)
        if self.is_empty():
            self._head=node
            node.next=self._head
            node.prev=self._head
        else:
            cur=self._head
            while cur.next!=self._head:
                cur=cur.next
            node.prev=cur
            cur.next=node
            node.next=self._head
    def insert(self,index,item):
        """插入节点"""
        if index<=0:
            self.add(item)
        elif index>(self.length()-1):
            self.append(item)
        else:
            node=Node(item)
            cur=self._head
            for i in range(index):
                cur=cur.next
            node.next=cur
            node.prev=cur.prev
            cur.prev.next=node
            cur.prev=node

                
    def remove(self,item):
        """删除节点"""
        if self.is_empty():
            return
        cur=self._head
        if cur.item==item:
            if cur.next==self._head:
                self._head=None
                return True
            else:
                while cur.next!=self._head:
                    cur=cur.next
                cur.next=self._head.next
                self._head.next.prev=cur.next
                return True
        while cur.next!=self._head:
            if cur.item==item:
                cur.prev.next=cur.next
                cur.next.prev=cur.prev
                return True
            cur=cur.next
        if cur.item==item:
            cur.prev.next=self._head
            self._head.prev=cur.prev
            return True
    def find_item(self,item):
        return item in self.items()

if __name__ == '__main__':
    link_list = BilateralCycleLinkList()
    print(link_list.is_empty())
    # 头部添加元素
    for i in range(5):
        link_list.add(i)
    print(list(link_list.items()))
    # 尾部添加元素
    for i in range(6):
        link_list.append(i)
    print(list(link_list.items()))
    # 添加元素
    link_list.insert(5, 45)
    print(list(link_list.items()))
    # 删除元素
    link_list.remove(5)
    print(list(link_list.items()))
    # 元素是否存在
    print(4 in link_list.items())
                
                