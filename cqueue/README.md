# A simple concurrent queue

This example shows the simplest concurrent queue one could ever imagine.

Requirements:

* The queue stores elements.
* The queue has no maximum size.
* The queue element type is a template argument.
* It must offer a *push* operation to place a value at the end of the queue.
* It must offer a *pop* operation to get the oldest element in the queue and remove it from the queue.
* It must offer an *empty* operation to indicate whether the queue is empty or not.
* All operations in the queu must work even if they are used by multiple threads simultaneously.