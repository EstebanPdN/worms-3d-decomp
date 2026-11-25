/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_resize_refs_801ee78c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802086dc = 0x802086dc;
fn_80208994 = 0x80208994;
SECTIONS {
  .text.w3d_resize_refs_801ee78c 0x801ee78c : { *(.text.w3d_resize_refs_801ee78c) }
  .text.w3d_resize_refs_801eeb58 0x801eeb58 : { *(.text.w3d_resize_refs_801eeb58) }
  .text.w3d_write_lines_8020863c 0x8020863c : { *(.text.w3d_write_lines_8020863c) }
  .text.w3d_write_lines_802088f4 0x802088f4 : { *(.text.w3d_write_lines_802088f4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
