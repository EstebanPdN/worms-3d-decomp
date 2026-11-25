/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d42a_listener_from_camera_80035528)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
f4c_normalize_801f6c2c = 0x801f6c2c;
SECTIONS {
  .text.w3d_d42a_listener_from_camera_80035528 0x80035528 : { *(.text.w3d_d42a_listener_from_camera_80035528) }
  .rodata 0x8037339c : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
