# High-Performance Genomic Data Structures for Large-Scale DNA Querying

## 📌 Overview

This project implements a **high-performance genomic query engine** for large-scale DNA sequences, specifically targeting **human chromosome Y (~62 million bases)**.

The system supports efficient **rank/select queries in O(1) time**, enabling fast analysis of nucleotide occurrence patterns while maintaining strong memory efficiency.

---

## 🚀 Key Features

* ⚡ **O(1) Rank/Select Queries** for genomic sequences
* 🧬 Handles large-scale DNA data (~62M bases)
* 📦 Integration of **succinct data structures (SDSL-lite)**
* 🧠 Comparison between **naive vs succinct representations**
* 📊 Benchmarking for **latency vs memory trade-offs**

---

## 🏗️ System Design

### 1. Data Structures

* **Naive Representation**

  * Stores full nucleotide sequences
  * Higher memory usage but simple implementation

* **Succinct Representation**

  * Uses **bit-vectors (SDSL-lite)**
  * Efficient encoding of nucleotide occurrences
  * Supports constant-time rank/select operations

---

### 2. Query Engine

Supports:

* `rank(c, i)` → Number of occurrences of character `c` up to index `i`
* `select(c, k)` → Position of the k-th occurrence of character `c`

---

## ⚙️ Tech Stack

* **Language:** C++
* **Libraries:** SDSL-lite
* **Concepts:**

  * Succinct Data Structures
  * Bit Vectors
  * Rank/Select Operations
  * Memory Optimization

---

## 📊 Performance Insights

| Aspect       | Observation                                     |
| ------------ | ----------------------------------------------- |
| Memory Usage | Significant reduction using succinct structures |
| Query Time   | Maintained near O(1) latency                    |
| Trade-off    | Minor latency overhead for large memory savings |

---

## 🧪 Benchmarking

* Evaluated across large query workloads
* Compared:

  * Naive vs succinct structures
* Measured:

  * Query latency
  * Memory consumption

---

## 📁 Dataset

* **Human Chromosome Y (~62M bases)**
* Source: NCBI Genome Database

---

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone <your-repo-link>
cd <repo-name>
```

### 2. Install dependencies

* Install **SDSL-lite** (follow official docs)

### 3. Compile

```bash
g++ -O3 main.cpp -o genomic_engine
```

### 4. Run

```bash
./genomic_engine
```

---

## 📌 Results Summary

* Efficient handling of large genomic sequences
* Strong **space–time trade-off optimization**
* Demonstrates practical use of **succinct data structures in bioinformatics**

---

## 🔗 Repository Link

Add your GitHub repo link here

---

## 👤 Author

**Satyajeet Kumar**
M.Tech Computational and Data Sciences, IISc

---

## ⭐ Future Improvements

* Support for compressed suffix structures
* Parallel query processing
* Integration with real-time genomic pipelines

---
