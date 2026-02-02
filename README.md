# 🤔 Philosophers

Dining **Philosophers** Problem implemented in **C** using **POSIX Threads**.
Focused on synchronization, race conditions, mutexes, and precise timing.

---

## 📌 Overview

This project is an implementation of the classical Dining **Philosophers** Problem, one of the most famous concurrency problems in computer science.

The goal is to simulate **philosophers** sitting around a table, alternating between:

- **Thinking**
- **Eating**
- **Sleeping**

while sharing limited resources (forks) without:

- Deadlocks
- Race conditions
- Starvation

This implementation strictly follows **42 School** constraints, using:

- `pthread`
- `mutexes`
- Accurate time management (millisecond precision)

---

## 🎯 Learning Objectives

This project focuses on mastering:

- 🧵 Multithreading with `pthread`
- 🔒 Mutex synchronization
- ⏱ Precise time handling
- 🧠 Deadlock prevention
- ⚠️ Race condition avoidance
- 🛠 Robust error handling

---

## 🧪 Program Arguments

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments Explanation

|	Argument									|	Description																|
|-----------------------------------------------|---------------------------------------------------------------------------|
|	number_of_philosophers						|	Number of philosophers (and forks)										|
|	time_to_die									|	Time (ms) before a philosopher dies if not eating						|
|	time_to_eat									|	Eating duration (ms)													|
|	time_to_sleep								|	Sleeping duration (ms)													|
|	number_of_times_each_philosopher_must_eat	|	(Optional) Simulation ends when all philosophers eat this many times	|

---

## 🏗️ Project Structure

```
philo/
├── Makefile
├── include/
│  └── philo.h
└── src/
   ├── philo.c
   ├── ft_inputs.c
   ├── ft_philos_init.c
   ├── ft_simulation.c
   ├── ft_time.c
   ├── mutexes_utils.c
   └── utils.c
```

---

## 🧩 Core Architecture

### `t_data` — Global Simulation State

```c
typedef struct s_data
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_times_eat;
	pthread_t		m_th_id;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_time			start;
	int				end;
	pthread_mutex_t	end_mx;
	pthread_mutex_t	print_mx;
}	t_data;
```

- Holds shared state, protected by mutexes
- `end` flag safely stops all threads
- `print_mx` ensures ordered output

---

### `t_philo` — Philosopher Representation

```c
struct s_philo
{
	int				id;
	pthread_t		p_th_id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_time			l_meal;
	int				n_meal;
	pthread_mutex_t	l_meal_mx;
	pthread_mutex_t	n_meal_mx;
	t_data			*data;
};
```

Each philosopher:

- Owns right fork
- Shares left fork
- Tracks last meal time and meal count
- Has independent mutexes for sensitive data

---

## 🔁 Simulation Flow

### 1️⃣ Initialization

- Parse & validate inputs **(ft_inputs)**
- Allocate philosophers and forks
- Initialize all mutexes
- Assign forks in circular fashion

> Last philosopher’s left fork → first fork (circular table)

---

### 2️⃣ Thread Creation Strategy

Philosophers are created in two phases:

```
Even IDs → created first
Odd  IDs → created second
```

✔️ This prevents deadlock by avoiding simultaneous fork grabs.

Additionally:

```c
if (philo->id % 2 == 0)
	ft_sleep_ms(1);
```

⏳ Slight desynchronization reduces contention.

---

### 3️⃣ Philosopher Routine

```
Take right fork
Take left fork
Eat
Release forks
Sleep
Think
Repeat
```

✔️ Each step is protected by mutexes
✔️ Loop exits immediately when simulation ends

---

### 4️⃣ Monitor Thread (The Brain 🧠)

A dedicated thread continuously checks:

- 💀 Death Condition

```c
current_time - last_meal >= time_to_die
```

- ➡️ Ends simulation instantly.

- 🍽 Eat Count Condition (optional)

- All philosophers reached `n_times_eat`

- ➡️ Graceful termination.

---

## 🔐 Synchronization Strategy

|	Resource		|	Protection			|
|-------------------|-----------------------|
|	Forks			|	`pthread_mutex_t`	|
|	Printing		|	`print_mx`			|
|	Simulation end	|	`end_mx`			|
|	Last meal time	|	`l_meal_mx`			|
|	Meal counter	|	`n_meal_mx`			|

✔️ No shared variable is accessed without a mutex
✔️ No busy waiting
✔️ No data races

---

## ⏱ Time Management

- Uses `gettimeofday`
- Time unit: milliseconds
- Custom sleep loop for accuracy:

```c
while (current_time < target)
	usleep(500);
```

✔️ Avoids long sleeps
✔️ Ensures responsive death detection

---

## 🧹 Cleanup & Resource Safety

- All threads are pthread_joined
- All mutexes destroyed
- All allocated memory freed
- No leaks, no orphan threads

---

## ✅ Key Strengths of This Implementation

✔️ Deadlock-free
✔️ Starvation-free
✔️ Accurate timing
✔️ Clean separation of concerns
✔️ Robust error handling
✔️ Fully compliant with 42 rules

---

## 🛠 Build & Run

### 📦 Build
```bash
# Clone the repository
git clone git@github.com:zakariatalbii/42_Philosophers.git
cd 42_Philosophers

# Compile the project
make
```

### ▶️ Run
```bash
# Example Usage
./philo 5 800 200 200
```

---

## 🏁 Final Notes

This project demonstrates a solid understanding of concurrency, mutex design, and real-world synchronization problems.

It is not just a working solution — it is a carefully engineered simulation.

---

## 👤 Author

**Zakaria Talbi**
- GitHub: [@zakariatalbii](https://github.com/zakariatalbii)

---

## 📜 License

This project is part of the 42 School cursus.