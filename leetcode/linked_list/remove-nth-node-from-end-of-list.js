function removeNthFromEnd(head, n) {
  // noop -> head -> ... -> last
  let headAppend = { next: head };
  let start = headAppend;
  let end = head;
  for (let x = 1; x < n; x++) {
    end = end.next;
  }

  // run until the last
  while (end.next !== null) {
    start = start.next;
    end = end.next;
  }

  // if start === noop, so start.next = head -> start.next = head.next
  start.next = start.next.next;

  return headAppend.next;
}

// Recursive
function remove(prev, current, n) {
  if (current === null) {
    return 1;
  }

  const idx = remove(current, current.next, n);

  if (idx === n) {
    if (prev === current) {
      return -1;
    } else {
      prev.next = current.next;
    }
  }

  return idx + 1;
}

function removeNthFromEnd(head, n ) {
  const result = remove(head, head, n);
  if (result === -1) {
    return head.next;
  }

  return head;
}
