# -*- coding: utf-8 -*-
#单向列表的定义

#定义节点类
class Node(object):
    def __init__(self, item):
        self.item = item
        self.next = None
#定义无序列表类
class UnorderedList(object):
    def __init__(self):
        self.head = None

    def is_empty(self):
        """判断链表是否为空"""
        return self.head is None

    def length(self):
        """链表长度"""
        # 初始指针指向head
        cur = self.head
        count = 0
        # 指针指向None 表示到达尾部
        while cur is not None:
            count += 1
            # 指针下移
            cur = cur.next
        return count

    def items(self):
        """遍历链表"""
        # 获取head指针
        cur = self.head
        # 循环遍历
        while cur is not None:
            # 返回生成器
            yield cur.item
            # 指针下移
            cur = cur.next

    def add(self, item):
        """向链表头部添加元素"""
        node = Node(item)
        # 新结点指针指向原头部结点
        node.next = self.head
        # 头部结点指针修改为新结点
        self.head = node

    def append(self, item):
        """尾部添加元素"""
        node = Node(item)
        # 先判断是否为空链表
        if self.is_empty():
            # 空链表，_head 指向新结点
            self.head = node
        else:
            # 不是空链表，则找到尾部，将尾部next结点指向新结点
            cur = self.head
            while cur.next is not None:
                cur = cur.next
            cur.next = node

    def insert(self, index, item):
        """指定位置插入元素"""
        # 指定位置在第一个元素之前，在头部插入
        if index <= 0:
            self.add(item)
        # 指定位置超过尾部，在尾部插入
        elif index > (self.length() - 1):
            self.append(item)
        else:
            # 创建元素结点
            node = Node(item)
            cur = self.head
            # 循环到需要插入的位置
            for i in range(index - 1):
                cur = cur.next
            node.next = cur.next
            cur.next = node

    def remove(self, item):
        """删除节点"""
        cur = self.head
        pre = None
        while cur is not None:
            # 找到指定元素
            if cur.item == item:
                # 如果第一个就是删除的节点
                if not pre:
                    # 将头指针指向头节点的后一个节点
                    self.head = cur.next
                else:
                    # 将删除位置前一个节点的next指向删除位置的后一个节点
                    pre.next = cur.next
                return True
            else:
                # 继续按链表后移节点
                pre = cur
                cur = cur.next

    def find(self, item):
        """查找元素是否存在"""
        return item in self.items()

if __name__ == '__main__':
    link_list = UnorderedList()
    # 向链表尾部添加数据
    for i in range(5):
        link_list.append(i)
    # 向头部添加数据
    link_list.add(6)
    # 遍历链表数据
    for i in link_list.items():
        print(i, end=' ')
    # 链表数据插入数据
    link_list.insert(3, 9)
    print('\n', list(link_list.items()))
    # 删除链表数据
    link_list.remove(0)
    # 查找链表数据
    print(link_list.find(4))