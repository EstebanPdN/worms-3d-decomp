/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_800600d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_800e5bb8 = 0x800e5bb8;
w3d_handle_member_destroy_801265a4 = 0x801265a4;
w3d_heap_release = 0x80209920;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_fn_800600d4 0x800600d4 : { *(.text.w3d_fn_800600d4) }
  .text.w3d_fn_8006096c 0x8006096c : { *(.text.w3d_fn_8006096c) }
  .sdata 0x804adde4 (NOLOAD) : {
    . = 0x0; w3d_heap_804adde4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
