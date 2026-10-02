class Solution:
    def rotateRight(self, head, k):
        if head is None or head.next is None or k == 0:
            return head

        # Step 1: Find the length and last node
        length = 1
        tail = head

        while tail.next is not None:
            tail = tail.next
            length += 1

        # Step 2: Remove unnecessary full rotations
        k = k % length

        if k == 0:
            return head

        # Step 3: Make the list circular
        tail.next = head

        # Step 4: Find the new tail
        steps = length - k

        new_tail = head

        for _ in range(steps - 1):
            new_tail = new_tail.next

        # Step 5: New head is after new tail
        new_head = new_tail.next

        # Step 6: Break the circle
        new_tail.next = None

        return new_head