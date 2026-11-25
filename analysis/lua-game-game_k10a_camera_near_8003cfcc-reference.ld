/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10a_camera_near_8003cfcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_80178c48 = 0x80178c48;
w3d_fn_801f6c2c = 0x801f6c2c;
SECTIONS {
  .text.w3d_k10a_camera_near_8003cfcc 0x8003cfcc : { *(.text.w3d_k10a_camera_near_8003cfcc) }
  .rodata 0x80374484 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; w3d_environment_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
