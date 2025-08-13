# Modern C++ Guide (C++11 → C++23)

[![CI](https://img.shields.io/badge/CI-GitHub%20Actions-inactive.svg)](#)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

An **end-to-end**, **example-driven** exploration of Modern C++ (C++11–C++23):
language features, STL updates, best practices, pitfalls, migration notes, and real code.

> **Audience:** Developers with a C++ background who want to adopt modern standards effectively.

---

## Table of Contents
- [Why This Guide?](#why-this-guide)
- [Scope & Roadmap](#scope--roadmap)
- [How to Use](#how-to-use)
- [Directory Structure](#directory-structure)
- [Examples](#examples)
- [Best Practices](#best-practices)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

---

## Why This Guide?
Modern C++ introduced major leaps in expressiveness, safety, and performance:
`auto`, `range-based for`, move semantics, `constexpr`, `concepts`, `ranges`, `coroutines`, and more.  

This project explains:
- **What** a feature is
- **When and why** to use it
- **Common traps** to avoid

---

## Scope & Roadmap
- **Versions covered:** C++11, C++14, C++17, C++20, C++23  
- **For each version:**
  - Key language features (with examples and pitfalls)
  - STL updates
  - Performance & safety notes
  - Migration tips
- **Planned deep dives:** Ranges, Coroutines, Modules, Error handling, Performance checklist

---

## How to Use
- Browse `docs/cppXX/` for version-specific details  
- Use `cheatsheet.md` in each folder for quick reference  
- Compile and run examples:
  ```bash
  g++ -std=c++17 -O2 examples/cpp17/structured_bindings.cpp -o sb && ./sb
