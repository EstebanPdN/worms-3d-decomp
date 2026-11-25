/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8c_camera_801a0a1c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a0b80 = 0x801a0b80;
fn_801f69ec = 0x801f69ec;
lbl_803a9b14 = 0x803a9b14;
lbl_803a9b18 = 0x803a9b18;
lbl_803a9b1c = 0x803a9b1c;
lbl_803a9b20 = 0x803a9b20;
SECTIONS {
  .text.f8c_camera_801a0a1c 0x801a0a1c : { *(.text.f8c_camera_801a0a1c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
