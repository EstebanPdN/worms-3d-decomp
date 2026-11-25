/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801dfdac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801E199C = 0x801e199c;
fn_801E4C14 = 0x801e4c14;
fn_801E6F04 = 0x801e6f04;
fn_801FE1D8 = 0x801fe1d8;
fn_801FE1F8 = 0x801fe1f8;
fn_80209890 = 0x80209890;
fn_80209968 = 0x80209968;
fn_80209A70 = 0x80209a70;
fn_8020FCB4 = 0x8020fcb4;
fn_80210990 = 0x80210990;
fn_802134FC = 0x802134fc;
lbl_8036561C = 0x8036561c;
lbl_80419388 = 0x80419388;
lbl_804193D8 = 0x804193d8;
SECTIONS {
  .text.w3d_auto_801dfdac 0x801dfdac : { *(.text.w3d_auto_801dfdac) }
  .text.w3d_auto_80209b2c 0x80209b2c : { *(.text.w3d_auto_80209b2c) }
  .text.w3d_auto_80209b78 0x80209b78 : { *(.text.w3d_auto_80209b78) }
  .text.w3d_auto_8020a09c 0x8020a09c : { *(.text.w3d_auto_8020a09c) }
  .sdata 0x804ab864 (NOLOAD) : {
    . = 0x0; lbl_804AB864 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
