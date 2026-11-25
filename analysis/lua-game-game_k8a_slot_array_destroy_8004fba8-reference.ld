/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_slot_array_destroy_8004fba8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80210abc = 0x80210abc;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_vtable_8040eae0 = 0x8040eae0;
SECTIONS {
  .text.w3d_k8a_slot_array_destroy_8004fba8 0x8004fba8 : { *(.text.w3d_k8a_slot_array_destroy_8004fba8) }
  .sdata 0x804aaa04 (NOLOAD) : {
    . = 0x0; w3d_global_804aaa04 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
