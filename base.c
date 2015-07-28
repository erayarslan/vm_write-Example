// This code is fuckin' template. It does not work $düzgün.
// Because 'kodumn Apple'ı

#include <stdio.h>
#include <mach/mach_init.h>
#include <sys/sysctl.h>
#include <mach/mach_vm.h>
#include <unistd.h>
#define PID 1309

int main() {
  mach_port_t process_to_write;
  kern_return_t error;

  if(getuid() && geteuid()) {
    printf("You need to be root to vm_write!\n");
  } else{
    error = task_for_pid(mach_task_self(), PID, &process_to_write);

    if ((error != KERN_SUCCESS) || !MACH_PORT_VALID(process_to_write)) {
      printf("Error getting the process!\n");
    }
    
    mach_port_name_t task;
    vm_map_offset_t vmoffset;
    vm_map_size_t vmsize;
    uint32_t nesting_depth = 0;
    struct vm_region_submap_info_64 vbr;
    mach_msg_type_number_t vbrcount = 16;
    kern_return_t kr;

    if ((kr = mach_vm_region_recurse(process_to_write, &vmoffset, &vmsize,
                                    &nesting_depth,
                                    (vm_region_recurse_info_t)&vbr,
                                    &vbrcount)) != KERN_SUCCESS) 
    {
      printf("Error");
    }

    printf("%p\n", (void *) (uintptr_t)vmoffset);
  }
  
  return 0;
}
