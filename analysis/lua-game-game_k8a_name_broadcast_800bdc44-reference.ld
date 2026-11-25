/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_name_broadcast_800bdc44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_800608d4 = 0x800608d4;
w3d_groups_8043bb64 = 0x8043bb64;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k8a_name_broadcast_800bdc44 0x800bdc44 : { *(.text.w3d_k8a_name_broadcast_800bdc44) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
