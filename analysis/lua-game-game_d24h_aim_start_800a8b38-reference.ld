/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_aim_start_800a8b38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a93fc = 0x800a93fc;
fn_800fc230 = 0x800fc230;
fn_800fc2f0 = 0x800fc2f0;
fn_800fc43c = 0x800fc43c;
fn_800fc5dc = 0x800fc5dc;
fn_80131b50 = 0x80131b50;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_802e7e5c = 0x802e7e5c;
lbl_80381840 = 0x80381840;
lbl_80381854 = 0x80381854;
lbl_8038186c = 0x8038186c;
lbl_80381880 = 0x80381880;
lbl_80381898 = 0x80381898;
lbl_803818a8 = 0x803818a8;
lbl_803818bc = 0x803818bc;
lbl_803818d0 = 0x803818d0;
SECTIONS {
  .text.w3d_d24h_aim_start_800a8b38 0x800a8b38 : { *(.text.w3d_d24h_aim_start_800a8b38) }
  .rodata 0x803818e8 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
