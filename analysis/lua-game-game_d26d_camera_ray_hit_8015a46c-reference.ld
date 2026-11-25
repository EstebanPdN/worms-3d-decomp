/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_camera_ray_hit_8015a46c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
compute_800bd920 = 0x800bd920;
level_80178df0 = 0x80178df0;
test_800b0824 = 0x800b0824;
traceNormal_8043ae38 = 0x8043ae38;
tracePoint_8043ae20 = 0x8043ae20;
update_80178d28 = 0x80178d28;
SECTIONS {
  .text.d26d_camera_ray_hit_8015a46c 0x8015a46c : { *(.text.d26d_camera_ray_hit_8015a46c) }
  .rodata 0x803a4210 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; traceFrac_804b1764 = .;
    . = 0x20; traceReady_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
