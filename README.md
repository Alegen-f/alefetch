# alefetch

Minimal system information tool written in C.

## Features
- CPU information (model, cores, usage)
- Memory usage (used/total, percentage)
- Disk usage (root partition)
- Fast execution (< 0.01s)
- No external dependencies

## Installation

### From source:
```bash
git clone https://github.com/Alegen-f/alefetch
cd alefetch
make
sudo make install  # optional

# Basic usage
alefetch

# Show help
alefetch --help
alefetch -h

# Requirements

- Linux kernel 2.6+

- GCC or Clang compiler

- Standard C library (glibc or musl)

# Example output:
CPU: AMD Ryzen 5 4600H (6C/12T) @ 48%
RAM: 9.5/14 GiB (68%)
SSD: 25/136 GiB (18%) [██████░░░░░░░░░░░░░░]

# Building
make          # compile
make clean    # remove build artifacts
make install  # install to /usr/local/bin
make uninstall # remove installed binary

# Why this project?
This project was created to:

    Learn system programming in C

    Understand how Linux exposes system information

    Practice writing portable, efficient code

    Create a useful tool with minimal dependencies

# Comparison with other fetch tools

    Neofetch: 10,000+ lines, many dependencies, slow startup

    Fastfetch: 5,000+ lines, optimized but complex

    alefetch: < 500 lines, no dependencies, instant startup
