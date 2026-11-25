/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80039b6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801FE220 = 0x801fe220;
fn_802EF234 = 0x802ef234;
fn_802EF2FC = 0x802ef2fc;
fn_802EF9C0 = 0x802ef9c0;
fn_802EFD7C = 0x802efd7c;
lbl_80373FE8 = 0x80373fe8;
SECTIONS {
  .text.w3d_auto_80039b6c 0x80039b6c : { *(.text.w3d_auto_80039b6c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
