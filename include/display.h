#ifndef DISPLAY_H
#define DISPLAY_H

#include "sysinfo.h"

void print_help(void);
void print_system_info(const CPUInfo *cpu, const MemoryInfo *mem, const DiskInfo *disk);

#endif
