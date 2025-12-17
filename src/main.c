#include <stdio.h>
#include <string.h>
#include "sysinfo.h"
#include "display.h"

int main(int argc, char **argv) {
    // Обработка аргументов
    if (argc > 1 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        print_help();
        return 0;
    }
    
    // Сбор данных
    CPUInfo cpu = get_cpu_info();
    MemoryInfo mem = get_memory_info();
    DiskInfo disk = get_disk_info();
    
    // Вывод
    print_system_info(&cpu, &mem, &disk);
    
    return 0;
}
