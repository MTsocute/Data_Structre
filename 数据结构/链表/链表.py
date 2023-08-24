import random


# 节点实现
class Node:
    def __init__(self, data):
        self.data: int = data
        self.next: Node or None = None


# 链表
class LinkedList:
    def __init__(self):
        self.head = None  # 链表头
        self.length = 0  # 链表长度

    def is_empty(self) -> bool:
        return self.head is None

    def add_node(self, data):
        # 判断链表是否为空，就先插入一个新节点再说
        if self.is_empty():
            self.head = Node(data)
            self.length += 1
            return
        # 如果不为空，就找到最后一个的位置，插入新节点
        cur = self.head
        # 不要让 cur 指向最后的 None
        # 不然这个指针就和链表没有关系了，添加的数据不会写入到链表中
        while cur.next is not None:
            cur = cur.next
        cur.next = Node(data)
        self.length += 1  # 更新链表长度

    def delete_node(self, index: int):
        if self.is_empty():
            print("链表为空，请插入节点后再尝试")
            return
        if index < 0 or index >= self.length:
            print("下标越界")
            return

        # 处理删除是第一个元素的时候
        if index == 0:
            self.head = self.head.next
        else:
            cur = self.head
            pre = None

            for i in range(index + 1):
                pre = cur
                cur = cur.next

            """ 检查下遍历的前后位置对不对 """
            # print("pre =>", pre.data)
            # print("cur =>", cur.data)
            pre.next = cur.next

        self.length -= 1

    def insert_node(self, index: int, data: int):
        if self.is_empty():
            print("链表为空，请插入节点后再尝试")
            return
        if index < 0 or index >= self.length:
            print("数组越界")
            return

        if index == 0:
            new_node = Node(data)
            new_node.next = self.head
            self.head = new_node

        else:
            cur = self.head
            pre = None

            for i in range(index):
                pre = cur
                cur = cur.next

            print(f"pre => {pre.data}\ncur => {cur.data}")
            new_node = Node(data)
            new_node.next = cur
            pre.next = new_node

        self.length += 1

    def traverse_linked_list(self) -> None:
        if self.is_empty():
            print("链表为空，请插入节点后再尝试")
            return
        print("链表中的数据为：")
        cur = self.head
        while cur:
            print(f'{cur.data} ', end='')
            cur = cur.next
        print()  # 换行符


if __name__ == '__main__':
    link_list = LinkedList()  # 链表对象

    print(f'插入的数据为：')
    for i in range(5):
        random_num = random.randint(1, 100)  # 1 ~ 100 之间的随机整数
        print(f'{random_num} ', end='')
        link_list.add_node(random_num)

    print()  # 换行符

    link_list.traverse_linked_list()  # 显示链表

    # 删除数据
    # link_list.delete_node(0)

    # 插入数据
    # link_list.insert_node(0, 100)
    link_list.insert_node(1, 100)
    # link_list.insert_node(4, 100)

    link_list.traverse_linked_list()
