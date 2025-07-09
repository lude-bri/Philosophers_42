<!-------Philosophers_42 Image---------->

<a name="readme-top"><a/>
<p align="center">
    <img src="https://capsule-render.vercel.app/api?type=venom&height=200&color=0:00C9FF,100:92FE9D&text=Philosophers&animation=fadeIn&fontColor=fcf3f2" />
</p>

<!-----------About---------------------->

# About

This project is about the classic computer science Dining Philosophers Problem.

We are going to work with concurrent algorithm, threads, mutexes and data racing.

---


<!-----------Index---------------------->

# Index
<ul>
    <li><strong><a href="#1-the-dining-philosophers-problem" style="color:white">1. The dining philosophers problem</a></strong></li>
    <ul style="list-style-type:disc">
        <li><a href="#11-origins-and-context">1.1. Origins and Context</a></li>
        <li><a href="#12-theoretical-foundations">1.2. Theoretical Foundations</a></li>
        <li><a href="#13-approaches-to-the-problem">1.3. Approaches to the Problem</a></li>
        <li><a href="#14-42-version-of-the-dining-philosophers-problem">1.4. 42 version of the Dining Philosophers Problem</a></li>
    </ul>
    <li><strong><a href="#2-threads" style="color:white">2. Threads</a></strong></li>
    <ul style="list-style-type:disc">
        <li><a href="#21-origins-and-context">2.1. Origins and Context</a></li>
        <li><a href="#22-theoretical-foundations">2.2. Theoretical Foundations</a></li>
    </ul>
    <li><strong><a href="#3-mutexes" style="color:white">3. Mutexes</a></strong></li>
    <ul style="list-style-type:disc">
        <li><a href="#31-usage-in-pthread">3.1. Usage in pthread</a></li>
    </ul>
    <li><strong><a href="#4-concurrent-algorithms-and-data-racing" style="color:white">4. Concurrent Algorithms and Data Racing</a></strong></li>
    <ul style="list-style-type:disc">
        <li><a href="#41-what-is-a-data-race">4.1. What is a Data Race?</a></li>
        <li><a href="#42-designing-safe-concurrent-algorithms">4.2. Designing Safe Concurrent Algorithms</a></li>
    </ul>
    <li><strong><a href="#conclusion" style="color:white">Conclusion</a></strong></li>
    <li><strong><a href="#license" style="color:white">License</a></strong></li>
</ul>

<!-----------Content---------------------->

# 1. The Dining philosophers problem

The Dining Philosophers Problem is a classic concurrency challenge introduced by Edsger W. Dijkstra in his seminal 1971 paper, Hierarchical Ordering of Sequential Processes (Acta Informatica I). It has since become a cornerstone in understanding synchronization and resource allocation in concurrent systems.

At its core, the problem is deceptively simple: five philosophers sit around a circular table, alternating between two activities—thinking and eating. To eat, a philosopher must acquire two chopsticks (or forks), one on their left and one on their right. However, each chopstick is shared with their neighboring philosopher. This setup creates a system of shared resources that must be managed to avoid deadlock, starvation, or resource contention.

## 1.1. Origins and Context

Dijkstra’s work highlights the evolution of computing from strictly sequential operations to systems where concurrency became a necessity. As he noted, the increasing speed of central processors compared to peripheral devices introduced a strong economic incentive to allow multiple processes to operate simultaneously. This shift demanded novel approaches to handle shared resources effectively, especially in scenarios where processes might compete for access.

The Dining Philosophers Problem emerged as a thought experiment to illustrate the challenges inherent in concurrency. The problem's simplicity—embodied in the imagery of philosophers and chopsticks—belies the complexity of managing synchronization and preventing issues like:

- Deadlock: A situation where every philosopher simultaneously picks up one chopstick and waits for the other, causing the system to freeze indefinitely.
- Starvation: A condition where a philosopher perpetually fails to acquire both chopsticks due to unfair allocation of resources.
- Livelock: Philosophers repeatedly attempting and failing to acquire chopsticks due to over-cautious synchronization mechanisms.

## 1.2. Theoretical Foundations

As outlined by Ramadhan and Siahaan (2016) in their exploration of concurrency within operating systems, the Dining Philosophers Problem is a metaphor for the challenges faced by multitasking operating systems. These systems must enable multiple processes to execute concurrently while ensuring proper synchronization and resource allocation.

Concurrency is the bedrock of modern operating systems. It allows multiple processes to share system resources, such as CPU time, memory, and I/O devices. However, as processes interact, synchronization becomes critical to ensure data integrity and system stability. The Dining Philosophers Problem serves as a microcosm of these interactions, highlighting key issues:

- Synchronization: Philosophers must coordinate their actions (picking up and putting down chopsticks) without explicit communication.
- Mutual Exclusion: Chopsticks can only be held by one philosopher at a time, reflecting the exclusivity required for certain resources.
- Avoidance of Deadlock and Starvation: The system must ensure that no philosopher is perpetually blocked from eating.

## 1.3. Approaches to the Problem

Several algorithms have been proposed to solve the Dining Philosophers Problem, (e.g. the Peterson's Filter Algorithm, Chandy/Misra solution and Dijkstra solution) each with its trade-offs:

- Resource Hierarchies: Assigning priorities to chopsticks ensures that philosophers always pick them up in a predefined order, preventing circular wait conditions that lead to deadlocks.
- Asymmetric Solutions: Introducing asymmetry, such as having one philosopher pick up their right chopstick first while others pick up their left, breaks symmetry and avoids deadlocks.
- Timed Waiting: Philosophers give up their chopsticks after a certain period if unable to acquire both, reducing the likelihood of prolonged contention.
- Semaphores and Monitors: Advanced synchronization primitives like semaphores (introduced by Dijkstra himself) or monitors can control access to chopsticks, ensuring mutual exclusion and fairness.

The Dining Philosophers Problem is more than an abstract puzzle; it encapsulates real-world challenges in operating systems, distributed computing, and even human resource management. Modern applications include:

- Database Management: Ensuring that transactions do not conflict when accessing shared data.
-Network Protocols: Managing contention for bandwidth or channels in communication systems.
- Embedded Systems: Allocating limited hardware resources in devices like printers or medical equipment.

By examining the problem through the lens of concurrency theory, we gain a deeper understanding of the delicate balance required to manage shared resources effectively.

## 1.4. 42 version of the Dining Philosophers Problem

In this context, the 42 school challanges us to solve this problem. This is the 42's version of this classic computer science problem:

```
Here are the things you need to know if you want to succeed this assignment:
• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
• Every philosopher needs to eat and should never starve.
• Philosophers don’t speak with each other.
• Philosophers don’t know if another philosopher is about to die.
• No need to say that philosophers should avoid dying
```
Before deep diving in this problem, we need to discuss a little bit more about very fundamental concepts: **Threads** and **Mutexes**

# 2. Threads

Threads are one of the most fundamental abstractions in modern computer systems, playing a pivotal role in multitasking and concurrency. They allow multiple sequences of instructions to execute within a single process, sharing resources while maintaining independence in execution. The concept of threads has deep theoretical underpinnings and practical applications, making it a cornerstone of operating systems, parallel computing, and software design.

## 2.1. Origins and Context

The evolution of computing hardware and software necessitated a shift from strictly sequential programs to systems capable of performing multiple tasks simultaneously. Early computers executed programs sequentially, as highlighted by Edsger W. Dijkstra in his influential works. With the advent of higher processing speeds and multitasking operating systems, the need for concurrency became evident. This led to the development of threads—a lightweight mechanism for achieving parallelism within processes.

Threads were introduced to address limitations in traditional process-based multitasking, particularly the high overhead of context switching between processes. Unlike processes, threads within the same process share memory space and resources, enabling more efficient communication and synchronization. This efficiency makes threads particularly suited for modern applications requiring high performance, such as web servers, video processing, and real-time systems.

### What Are Threads?
A thread is the smallest unit of execution within a program. It operates within the context of a process, sharing its memory and resources while maintaining its own stack, program counter, and execution state. This duality—independence in execution yet shared context—makes threads both powerful and challenging to manage.

Threads can be categorized into:

- User-Level Threads: Managed by user-space libraries without kernel involvement. While lightweight and fast, they face challenges in integrating with system-level scheduling.
- Kernel-Level Threads: Managed directly by the operating system kernel. They offer better integration with system resources but come with higher overhead due to kernel involvement.
- Hybrid Models: Combine the advantages of both user-level and kernel-level threads, optimizing for performance and flexibility.

## 2.2. Theoretical Foundations

Threads are a direct response to the demands of concurrency, where multiple tasks must progress simultaneously. The benefits of threads are rooted in their ability to exploit parallelism, both on single-core systems (via time slicing) and on modern multicore processors.

However, this concurrency introduces challenges, including:

- Synchronization: Threads within the same process share memory, leading to potential data races and inconsistencies if not properly synchronized. Mechanisms like mutexes, semaphores, and condition variables are used to ensure thread-safe operations.
- Deadlock: When threads compete for resources in a circular dependency, they can become stuck indefinitely. Avoiding deadlock requires careful resource allocation and management.
- Starvation: Threads with lower priority or limited access to resources may be perpetually blocked, leading to unfair execution.
- Overhead: While lighter than processes, threads still introduce overhead in context switching and synchronization.

In order to use threads in C, we have to use the `pthread.h` library

## 2.3. pthread.h

In POSIX Threads (or pthread), is an execution model that allows a program to control multiple different flows of work that overlap in time.

The main purpose is to enable cuncurrent programming in C and C++ on POSIX systems.

### Main features

- Thread creation and termination
- Mutexes (for data protection)
- Condition variables (for event waiting)
- Thread-specific data
- Thread attributes

### Common Functions

- `pthread_create()`: Create a new thread.
- `pthread_exit()`: Terminate a thread.
- `pthread_join()`: Wait for a specific thread to finish.
- `pthread_mutex_lock()` & `pthread_mutex_unlock()`: Lock and Unlock a Mutex.
- `pthread_cond_wait()` & `pthread_cond_signal()`: Wait and signal on condiotion variables.

>[!IMPORTANT]
> While pthread is powerful, it requires careful programming to avoid issues like deadlocks, race conditions, and other concurrency-related bugs.

### Data type

The `pthread_t` data type is an identifier used by the POSIX threads library to uniquely identify threads. Its actual implementation is platform and implementation-dependent, as the POSIX standard doesn't dictate how it must be implemented, only how it should behave.

In many systems:

- `pthread_t` is often implemented as an opaque type, which might be a simple integer, pointer, or a more complex type.
- Underneath, this identifier typically points to or represents data structures containing all information related to a particular thread, such as its stack, state and attributes.


# 3. Mutexes
Mutexes, short for mutual exclusions, are essential synchronization mechanisms used to prevent multiple threads from simultaneously accessing shared resources, thereby avoiding unpredictable behavior and data races.

A mutex functions like a lock: only one thread can hold it at a time. When a thread needs access to a shared resource (such as a global variable or a critical section of code), it attempts to acquire the associated mutex. If another thread already holds the mutex, the requesting thread will be blocked until the mutex is released.

## 3.1. Usage in pthread
In the `pthread` library, mutexes are implemented via the `pthread_mutex_t` type. To use a mutex, it must first be initialized (typically with `pthread_mutex_init()` or statically via `PTHREAD_MUTEX_INITIALIZER`). Once initialized, a mutex can be locked and unlocked using:

* `pthread_mutex_lock(&mutex)`: Locks the mutex. If it is already locked, the calling thread will wait.

* `pthread_mutex_unlock(&mutex)`: Unlocks the mutex, allowing another waiting thread to acquire it.

* `pthread_mutex_destroy(&mutex)`: Destroys the mutex object when it is no longer needed.



# 4. Concurrent Algorithms and Data Racing
Concurrency introduces a fundamental shift in algorithm design. Unlike sequential algorithms that assume exclusive control over the processor, concurrent algorithms must account for interleaving operations, resource sharing, and synchronization.

## 4.1. What is a Data Race?
A data race occurs when two or more threads access a shared variable concurrently, and at least one of the accesses is a write, without proper synchronization. This leads to undefined behavior, as the outcome of the program becomes dependent on the unpredictable timing of thread execution.

Example:

```c
// Potential data race
shared_var += 1;
```
If multiple threads execute this line without a mutex, they might read and write the value simultaneously, leading to inconsistent or incorrect results.

## 4.2. Designing Safe Concurrent Algorithms

To prevent data races and ensure consistency, concurrent algorithms typically rely on one or more of the following techniques:

* **Mutexes and Locks**: Enforce exclusive access to shared data.

* **Atomic Operations**: Perform read-modify-write operations indivisibly, avoiding the need for locks.

* **Condition Variables**: Allow threads to wait for specific conditions to be met before proceeding.

* **Lock-Free Algorithms**: Avoid traditional locking by using atomic primitives (like compare-and-swap) to coordinate between threads efficiently.

Each strategy has trade-offs between performance, complexity, and safety. In the context of the Dining Philosophers Problem, mutexes are often used to represent forks. Proper algorithm design ensures that philosophers acquire forks (mutexes) in a way that prevents deadlocks and starvation.

# Conclusion

The Dining Philosophers Problem is more than a theoretical challenge; it is a practical gateway to understanding core concepts in concurrent programming. Through the metaphor of philosophers competing for shared forks, it exposes deep insights into synchronization, resource allocation, and algorithmic fairness.

By studying threads, we understand how modern systems achieve parallelism and responsiveness. With mutexes, we learn to coordinate access to shared data safely. And through careful design of concurrent algorithms, we avoid the dangers of data races and deadlocks, ensuring system stability and efficiency.

Solving the 42 version of the Dining Philosophers Problem is not merely about implementing code—it is about grasping the delicate balance between freedom and coordination in concurrent environments. Mastery of these concepts is essential for any systems-level programmer, as the principles extend beyond academic problems into real-world systems, from operating systems to networked applications and beyond.

---

## Sources

---
### License

This work is published under the terms of <a href="https://github.com/lude-bri/42_Common_Core/blob/main/LICENSE.md">42 Unlicense</a>

<p align="right">(<a href="#readme-top">get to top</a>)</p>

