/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35a_camera_group_8008ed58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35a_apply_80091970 = 0x80091970;
sol35a_finish_8007bc2c = 0x8007bc2c;
SECTIONS {
  .text.sol35a_camera_group_8008ed58 0x8008ed58 : { *(.text.sol35a_camera_group_8008ed58) }
  .sdata 0x804ae5e4 (NOLOAD) : {
    . = 0x0; sol35a_world_804ae5e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
