// sysinfo.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include "sysinfo.h"

CPUInfo get_cpu_info(void) {
    CPUInfo cpu = {0};
    
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (!fp) return cpu;
    
    char line[256];
    int processor_count = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "model name", 10) == 0) {
            char *colon = strchr(line, ':');
            if (colon) {
                strncpy(cpu.model, colon + 2, sizeof(cpu.model) - 1);
                cpu.model[strcspn(cpu.model, "\n")] = 0;
            }
        } else if (strncmp(line, "cpu cores", 9) == 0) {
            sscanf(line, "cpu cores : %d", &cpu.cores);
        } else if (strncmp(line, "siblings", 8) == 0) {
            sscanf(line, "siblings : %d", &cpu.threads);
        } else if (strncmp(line, "processor", 9) == 0) {
            processor_count++;
        }
    }
    
    fclose(fp);
    
    if (cpu.threads == 0) {
        cpu.threads = processor_count;
    }
    
    return cpu;
}

MemoryInfo get_memory_info(void) {
    MemoryInfo mem = {0};
    
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) return mem;
    
    char line[256];
    long mem_total = 0, mem_free = 0, buffers = 0, cached = 0;
    
    while (fgets(line, sizeof(line), fp)) {
        if (mem_total == 0) sscanf(line, "MemTotal: %ld kB", &mem_total);
        if (mem_free == 0) sscanf(line, "MemFree: %ld kB", &mem_free);
        if (buffers == 0) sscanf(line, "Buffers: %ld kB", &buffers);
        if (cached == 0) sscanf(line, "Cached: %ld kB", &cached);
    }
    
    fclose(fp);
    
    if (mem_total > 0) {
        long used_kb = mem_total - mem_free - buffers - cached;
        mem.total_gb = mem_total / (1024 * 1024);  // KB → GB
        mem.used_gb = used_kb / (1024 * 1024);
        mem.percent = (float)used_kb / mem_total * 100.0f;
    }
    
    return mem;
}

DiskInfo get_disk_info(void) {
    DiskInfo disk = {0};
    struct statvfs vfs;
    
    if (statvfs("/", &vfs) == 0) {
        unsigned long long total = vfs.f_blocks * vfs.f_frsize;
        unsigned long long free = vfs.f_bfree * vfs.f_frsize;
        unsigned long long used = total - free;
        
        disk.total_gb = total / (1024 * 1024 * 1024);
        disk.used_gb = used / (1024 * 1024 * 1024);
        disk.percent = (float)used / total * 100.0f;
        strncpy(disk.filesystem, "Root", sizeof(disk.filesystem) - 1);
    }
    
    return disk;
}
