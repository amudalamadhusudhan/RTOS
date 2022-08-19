RTOS Assignment
1. Find what is the task priority numbering for the RTOS you are using. eg. Higher the
number higher the priority or vice-versa. Find the range of priority that can be assigned to
a task for your RTOS.
2. What is the mechanism used to make a task periodic for the RTOS you are using? Write a
program to make a task periodic with periodicity of 500ms.
3. Find the APIs in your RTOS that provides timestamp and use it to print the periodic task.
Observe the jitter in the timestamp vs the periodicity. Enhance the code to 10 periodic tasks
with different periodicity. Futher observe the jitter in each of the task.
4. Create two task with priority 10 and 20. Each task prints its own custom message.
5. Swap the priority and observe the changes in the output. What is your conclusion on the
sequence of printing the messages.
6. What are the maximum number of tasks that can be created on the RTOS you are using?
Is it limited by the RTOS design or underlying hardware resources or both.
7. What is the scheduling algorithm used by your RTOS?
8. List the customization options for creating a task for the RTOS you are using. eg. priority
etc
9. Find the fields that are maintained in the Task Control Block / Process Control Block of the
RTOS you are using.
10. Draw a process or task state diagram for the RTOS you are using.
11. What is the API for deleting a task? Write a program demonstrate this capability.
12. What are the APIs provided by your RTOS for enabling and disabling the interrupts? Write
a program to demonstrate this capability?
13. Does your RTOS provide APIs to collect task statistics. If yes, list the statistics parameters
that are collected and write a program to display the runtime task statistics?
14. Find the tick frequency configuration for your RTOS.
15. Create a task to suspend itself after 1200 ms and resume it from another task
16. Write a RTOS application to demonstrate the use of changing priority
17. If you RTOS supports idle task hooking, write a program to demonstrate it
18. Write a RTOS application to demonstrate the use of task to task communication using
Queue management APIs. Also demonstrate blocking on a queue.
19. Write a RTOS application to demonstrate the effects of task priorities when sending to and
receiving from a queue.
20. Write a RTOS application to demonstrate deferred interrupt processing using binary semaphores
21. Write a RTOS application to demonstrate counting semaphores to synchronize a task
22. Write a RTOS application to demonstrate the usage of queues within an interrupt service
routine
23. Write a RTOS application to manage resources using mutual exclusion
24. Write a RTOS application to demonstrate a priority inversion problem. If your RTOS sup-
ports priority inheritance or priority ceiling, use it to solve the priority inversion problem.
25. Write a RTOS application to create a software timer that invokes a callback function every
5 seconds.
