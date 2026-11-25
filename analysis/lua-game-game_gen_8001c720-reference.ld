/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_address_8001c720)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_8001c844 = 0x8001c844;
w3d_fn_8001c960 = 0x8001c960;
w3d_fn_80020548 = 0x80020548;
w3d_fn_800205e8 = 0x800205e8;
w3d_fn_8002225c = 0x8002225c;
w3d_fn_800222b8 = 0x800222b8;
w3d_fn_80022c2c = 0x80022c2c;
w3d_fn_80022c6c = 0x80022c6c;
w3d_fn_800233b0 = 0x800233b0;
w3d_fn_8002345c = 0x8002345c;
w3d_global_8035fa60 = 0x8035fa60;
w3d_global_8035fa90 = 0x8035fa90;
w3d_global_8035fac0 = 0x8035fac0;
w3d_global_8035faf0 = 0x8035faf0;
w3d_global_8035fb20 = 0x8035fb20;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_owner_list_remove = 0x8020fd2c;
w3d_registry_list_8035fa60 = 0x8035fa60;
w3d_registry_list_8035fa90 = 0x8035fa90;
w3d_registry_list_8035fac0 = 0x8035fac0;
w3d_registry_list_8035faf0 = 0x8035faf0;
w3d_registry_list_8035fb20 = 0x8035fb20;
w3d_state_register = 0x8020fd04;
SECTIONS {
  .text.w3d_address_8001c720 0x8001c720 : { *(.text.w3d_address_8001c720) }
  .text.w3d_registry_unlink_8001c72c 0x8001c72c : { *(.text.w3d_registry_unlink_8001c72c) }
  .text.w3d_registry_create_8001c770 0x8001c770 : { *(.text.w3d_registry_create_8001c770) }
  .text.w3d_registry_release_8001c7d0 0x8001c7d0 : { *(.text.w3d_registry_release_8001c7d0) }
  .text.w3d_registry_retain_8001c82c 0x8001c82c : { *(.text.w3d_registry_retain_8001c82c) }
  .text.w3d_address_80020424 0x80020424 : { *(.text.w3d_address_80020424) }
  .text.w3d_registry_unlink_80020430 0x80020430 : { *(.text.w3d_registry_unlink_80020430) }
  .text.w3d_registry_create_80020474 0x80020474 : { *(.text.w3d_registry_create_80020474) }
  .text.w3d_registry_release_800204d4 0x800204d4 : { *(.text.w3d_registry_release_800204d4) }
  .text.w3d_registry_retain_80020530 0x80020530 : { *(.text.w3d_registry_retain_80020530) }
  .text.w3d_constant_800214b0 0x800214b0 : { *(.text.w3d_constant_800214b0) }
  .text.w3d_empty_800214b8 0x800214b8 : { *(.text.w3d_empty_800214b8) }
  .text.w3d_set_80021838 0x80021838 : { *(.text.w3d_set_80021838) }
  .text.w3d_address_80022138 0x80022138 : { *(.text.w3d_address_80022138) }
  .text.w3d_registry_unlink_80022144 0x80022144 : { *(.text.w3d_registry_unlink_80022144) }
  .text.w3d_registry_create_80022188 0x80022188 : { *(.text.w3d_registry_create_80022188) }
  .text.w3d_registry_release_800221e8 0x800221e8 : { *(.text.w3d_registry_release_800221e8) }
  .text.w3d_registry_retain_80022244 0x80022244 : { *(.text.w3d_registry_retain_80022244) }
  .text.w3d_address_80022ac8 0x80022ac8 : { *(.text.w3d_address_80022ac8) }
  .text.w3d_registry_unlink_80022ad4 0x80022ad4 : { *(.text.w3d_registry_unlink_80022ad4) }
  .text.w3d_registry_create_80022b18 0x80022b18 : { *(.text.w3d_registry_create_80022b18) }
  .text.w3d_registry_release_80022b78 0x80022b78 : { *(.text.w3d_registry_release_80022b78) }
  .text.w3d_registry_retain_80022bd4 0x80022bd4 : { *(.text.w3d_registry_retain_80022bd4) }
  .text.w3d_constant_80022d64 0x80022d64 : { *(.text.w3d_constant_80022d64) }
  .text.w3d_address_8002328c 0x8002328c : { *(.text.w3d_address_8002328c) }
  .text.w3d_registry_unlink_80023298 0x80023298 : { *(.text.w3d_registry_unlink_80023298) }
  .text.w3d_registry_create_800232dc 0x800232dc : { *(.text.w3d_registry_create_800232dc) }
  .text.w3d_registry_release_8002333c 0x8002333c : { *(.text.w3d_registry_release_8002333c) }
  .text.w3d_registry_retain_80023398 0x80023398 : { *(.text.w3d_registry_retain_80023398) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
