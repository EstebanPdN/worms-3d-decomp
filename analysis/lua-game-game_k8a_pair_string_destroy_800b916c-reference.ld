/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_pair_string_destroy_800b916c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_heap_release = 0x80209920;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k8a_pair_string_destroy_800b916c 0x800b916c : { *(.text.w3d_k8a_pair_string_destroy_800b916c) }
  .sdata 0x804adde4 (NOLOAD) : {
    . = 0x0; w3d_heap_804adde4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
