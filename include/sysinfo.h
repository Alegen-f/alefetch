#ifndef SYSINFO_H
#define SYSINFO_H

typedef struct {
    char model[256];
    int cores;
    int threads;
    float usage_percent;
} CPUInfo;

typedef struct {
    long total_gb;
    long used_gb;
    float percent;
} MemoryInfo;

typedef struct {
    long total_gb;
    long used_gb;
    float percent;
    char filesystem[32];
} DiskInfo;

CPUInfo get_cpu_info(void);
MemoryInfo get_memory_info(void);
DiskInfo get_disk_info(void);

#endif
