/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801e71e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801E8CCC = 0x801e8ccc;
fn_8020FC60 = 0x8020fc60;
fn_802134FC = 0x802134fc;
lbl_80417048 = 0x80417048;
lbl_80417070 = 0x80417070;
lbl_80417190 = 0x80417190;
lbl_804171B8 = 0x804171b8;
SECTIONS {
  .text.w3d_auto_801e71e4 0x801e71e4 : { *(.text.w3d_auto_801e71e4) }
  .text.w3d_auto_801e8b04 0x801e8b04 : { *(.text.w3d_auto_801e8b04) }
  .sdata 0x804b18e0 (NOLOAD) : {
    . = 0x0; lbl_804B18E0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
