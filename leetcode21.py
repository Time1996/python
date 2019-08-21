class Solution:
    def mergeTwoLists(self, l1, l2);

    prehead = ListNode(-1) //从-1开始
    prev = prehead //先指向最初的头-1
    while l1 and l2:
        if l1.val <= l2://l1小于或等于l2就要让头指向l1
            prev.next = l1
            l1 = l1.next//然后指向l1的下一个再比大小
        else:
            prev.next = l2
            l2 = l2.next
        prev = prev.next

    prev.next = l1 if l1 is not None else l2//这样的话会按从大到小顺序合并两个序列，最后如果指向空就停下

    return prehead.next
            
