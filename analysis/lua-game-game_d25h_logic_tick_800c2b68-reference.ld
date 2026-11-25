/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_logic_tick_800c2b68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8006e71c = 0x8006e71c;
fn_800c31f0 = 0x800c31f0;
fn_800c3224 = 0x800c3224;
fn_800c335c = 0x800c335c;
fn_800fcea0 = 0x800fcea0;
fn_8015f5a0 = 0x8015f5a0;
fn_8015fd1c = 0x8015fd1c;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
lbl_803831d8 = 0x803831d8;
lbl_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d25h_logic_tick_800c2b68 0x800c2b68 : { *(.text.w3d_d25h_logic_tick_800c2b68) }
  .sdata 0x804ae6ac (NOLOAD) : {
    . = 0x0; lbl_804ae6ac = .;
    . = 0x4; lbl_804ae6b0 = .;
    . = 0x30; lbl_804ae6dc = .;
    . = 0x38; lbl_804ae6e4 = .;
    . = 0x40; lbl_804ae6ec = .;
    . = 0x48; lbl_804ae6f4 = .;
    . = 0x80; lbl_804ae72c = .;
    . = 0x30a8; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
