❌ Don’t edit other people’s files randomly
❌ Don’t push to main
✔ Always pull latest code
✔ Commit small changes
=============================
 Task Distribution + First Steps:
 
1️⃣ Team Lead + Integration (Aysl)
👉 First steps:

- Create GitHub repo + project structure
- Create files (Queue, Worker, Server, Simulation, main)
- Define naming conventions
- Push initial setup

---

2️⃣ Queue Implementation (Hana)
👉 First steps:

- Implement circular queue structure
- Define variables: front, rear, count, maxSize
- Implement: initializeQueue(), isEmpty(), isFull()
- Then: addQueue(), deleteQueue()

---

3️⃣ Worker System
(Shahd)
👉 First steps:

- Create Worker class (ID, arrivalTime, serviceTime)
- Create list/array of workers
- Generate sample workers with different arrival times

---

4️⃣ Server (Scanner) Logic (Noha)
👉 First steps:

- Create Server class (busy/free, remainingTime)
- Implement function to assign worker to server
- Handle service time countdown

---

5️⃣ Simulation Engine
(Asmaa)
👉 First steps:

- Create time loop (system clock)
- At each time step:
  - check worker arrivals → add to queue
  - assign workers to free servers
  - update servers

---

6️⃣ Output + Statistics + UI Design (Hana Mohamed)
👉 First steps:

- Print basic system output (who arrives, who is served)
- Track waiting time for each worker
- Start simple UI design (Figma dashboard layout)

---

📊 System Enhancements (integrated in our work):

- Support multiple servers (to study performance differences)
- Track average waiting time and max queue length
- Show queue state clearly (in output + design)
- Design interface that reflects real-time system behavior
