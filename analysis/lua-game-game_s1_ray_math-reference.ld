/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80041838)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_800bdb5c = 0x800bdb5c;
w3d_origin_80427408 = 0x80427408;
w3d_spheres_804273ec = 0x804273ec;
w3d_sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_fn_80041838 0x80041838 : { *(.text.w3d_fn_80041838) }
  .text.w3d_fn_800419cc 0x800419cc : { *(.text.w3d_fn_800419cc) }
  .rodata 0x803747c0 : { *(.rodata) }
  .sdata 0x804aa950 (NOLOAD) : {
    . = 0x0; w3d_exclude_804aa950 = .;
    . = 0x6e68; w3d_radius_804b17b8 = .;
    . = 0x6e90; w3d_context_804b17e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
