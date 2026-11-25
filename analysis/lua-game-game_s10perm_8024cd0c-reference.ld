/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8024cd0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801B4E94 = 0x801b4e94;
lbl_8041B898 = 0x8041b898;
SECTIONS {
  .text.w3d_auto_8024cd0c 0x8024cd0c : { *(.text.w3d_auto_8024cd0c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
