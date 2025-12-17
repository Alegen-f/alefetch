// display.c
#include <stdio.h>
#include "display.h"

void print_help(void) {
    printf("alefetch - minimal system fetch tool\n");
    printf("Usage: alefetch [--help]\n\n");
    printf("Options:\n");
    printf("  -h, --help    Show this help message\n");
}

void print_system_info(const CPUInfo *cpu, const MemoryInfo *mem, const DiskInfo *disk) {
    printf("\033[1;36m╔══════════════════════════════════╗\033[0m\n");
    printf("\033[1;36m║          \033[1;33mA L E F E T C H\033[1;36m         ║\033[0m\n");
    printf("\033[1;36m╚══════════════════════════════════╝\033[0m\n\n");
    
    // CPU
    printf("\033[1;32m● CPU:\033[0m %s", cpu->model);
    if (cpu->cores > 0 && cpu->threads > 0) {
        printf(" (%dC/%dT)", cpu->cores, cpu->threads);
    }
    printf("\n");
    
    // Memory
    if (mem->total_gb > 0) {
        printf("\033[1;32m● RAM:\033[0m %ld / %ld GiB \033[1;34m[%.0f%%]\033[0m\n",
               mem->used_gb, mem->total_gb, mem->percent);
    }
    
    // Disk
    if (disk->total_gb > 0) {
        printf("\033[1;32m● Disk:\033[0m %ld / %ld GiB \033[1;34m[%.0f%%]\033[0m\n",
               disk->used_gb, disk->total_gb, disk->percent);
    }
}
